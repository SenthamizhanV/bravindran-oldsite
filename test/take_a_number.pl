#!/usr/bin/perl

$roll="CS10B013";
require("cgi-lib.pl");

$prefix = "/home2/ravi/public_html/test/";
$lockprefix = "/home2/ravi/public_html/test/";

&ReadParse;
# read(STDIN,$in,$ENV{'CONTENT_LENGTH'});
#  @in = split(/&/,$in);

#$in{'rollnumber'} = "CS05B012";
if ($in{'rollnumber'})
{
	$roll=$in{'rollnumber'};
        $got_lock=0;
        foreach $loop (1..5){
                if (-e $lockprefix."cs6012_post.lock") {sleep 1;}
                else{
                        open(LOCK,"> $lockprefix"."cs6012_post.lock");
                        close LOCK;
                        $got_lock=1;
                        last;
                }
        }
        if (!$got_lock) {
                   if ((-M "$lockprefix"."cs6012_post.lock") > 0.02) {
                      unlink("$lockprefix"."cs6012_post.lock");
                      open(LOCK,"> $lockprefix"."cs6012_post.lock");
                      close LOCK;
                      }
                   else {
                   print &PrintHeader;
                   print "The server is busy. Please try your request after a while.<p>\n";
                   #print "Location: $baseurl","busy.html\n\n";
                   exit;
                   }
                }
        $got_lock=0;


open FILE, "< next_number";

$next_num=<FILE>;

close FILE;

open GOT, "< number_given";
@given=<GOT>;
chomp @given;
close GOT;
foreach(@given){
($a,$b)=split(/ /,$_);
$given{$a}=$b;
}

if (defined $given{$roll}) {
print &PrintHeader;
print "Already assigned question ". $given{$roll}. "\n";}

else { 
open GOT, ">> number_given"; print GOT $roll." ".$next_num."\n";
close GOT;
open FILE, ">next_number";
print FILE $next_num+1;
close FILE;
print &PrintHeader;
print "Do question number ".$next_num."\n"; 
}
unlink("$lockprefix"."cs6012_post.lock");

}
else {
        print "Location: http://www.cse.iitm.ac.in/~ravi/test/sna.html\n\n";
}




