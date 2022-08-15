#!/usr/bin/perl

require("cgi-lib.pl");

$prefix = "/home/cs313/public_html/feedback/";
$lockprefix="/tmp/";

&ReadParse;

if ($in{'response'})
{
        $got_lock=0;
        foreach $loop (1..5){
                if (-e $lockprefix."cs313_post.lock") {sleep 1;}
                else{
                        open(LOCK,"> $lockprefix"."cs313_post.lock");
                        close LOCK;
                        $got_lock=1;
                        break;
                }
        }
        if (!$got_lock) {
                   if ((-M "$lockprefix"."cs313_post.lock") > 0.02) {
                      unlink(<"$lockprefix"."cs313_post.lock">);
                      open(LOCK,"> $lockprefix"."cs313_post.lock");
                      close LOCK;
                      }
                   else {
                   print &PrintHeader;
                   print "The server is busy. Please try posting after a while.
Your post has been reproduced below. Copy this post so that you needn't type in
the whole thing again.<p>\n";
                   $in{'response'}=~s/</&lt;/g;
                   $in{'response'}=~s/>/&gt;/g;
                   print "<hr><br> $in{'response'} \n<br><hr>\n";
                   #print "Location: $baseurl","busy.html\n\n";
                   exit;
                   }
                }
        $got_lock=0;

        open(FP1,"< $prefix"."feedback.html");
	open(FP,"> $prefix".$$.".tmp");
        $in{'response'}=~s/<[^>]*>//g;
        $in{'response'} =~ s/(http|ftp|gopher)(:\/\/)([^ \n]*)/<a href="\1\2\3"
target="_top">\1\2\3<\/a>/g;
        $in{'response'}=~s/\n$//;
        $in{'response'}=~s/\n/<br>\n/g;
	$line=<FP1>;
	while($line !~ "<!-- New Responses Here -->") {
         print FP $line;
        }
	print FP "<li> ";
	print FP $in{'response'},"</p>\n<br>\n";
	@lines=<FP1>;
	print FP @lines;
	close FP;
	close FP1;

	if (-s "$prefix".$$.".tmp"){
        rename("$prefix".$$.".tmp","$prefix"."feedback.html");
        chmod 0600,"$prefix"."feedback.html";
        }
        else {
                unlink("$prefix".$$.".tmp");
                }
        unlink("$lockprefix"."cs313_post.lock");
	print "Location: http://www.cs.iitm.ernet.in/~cs313/feedback/\n\n";


}
else {
        print "Location: http://www.cs.iitm.ernet.in/~cs313/feedback/\n\n";
}

