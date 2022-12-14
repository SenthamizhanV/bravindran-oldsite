/* fpont 12/99 */
/* pont.net    */
/* tcpClient.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h> /* close */

#define SERVER_PORT 5500
#define MAX_MSG 100

int main (int argc, char *argv[]) {

  int sd, rc, i,j;
  struct sockaddr_in localAddr, servAddr;
  struct hostent *h;
  
  if(argc < 3) {
    printf("usage: %s <server> <data1> <data2> ... <dataN>\n",argv[0]);
    exit(1);
  }

  h = gethostbyname(argv[1]);
  if(h==NULL) {
    printf("%s: unknown host '%s'\n",argv[0],argv[1]);
    exit(1);
  }

  servAddr.sin_family = h->h_addrtype;
  memcpy((char *) &servAddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
  servAddr.sin_port = htons(SERVER_PORT);

  //TODO Create a socket
  
  if(sd<0) {
    perror("cannot open socket ");
    exit(1);
  }

  /* bind any port number */
  localAddr.sin_family = AF_INET;
  localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  localAddr.sin_port = htons(0);
  
  //TODO Bind the socket
  
  if(rc<0) {
    printf("%s: cannot bind port TCP %u\n",argv[0],SERVER_PORT);
    perror("error ");
    exit(1);
  }
				
  // TODO connect to server
  
  if(rc<0) {
    perror("cannot connect ");
    exit(1);
  }

  for(j=10000; j > 0; j--){
  for(i=2;i<argc;i++) {
    
    rc = send(sd, argv[i], strlen(argv[i]) + 1, 0);
    
    if(rc<0) {
      perror("cannot send data ");
      close(sd);
      exit(1);
    
    }

    printf("%s: data%u sent (%s)\n",argv[0],i-1,argv[i]);

   
  }
  }

return 0;
  
}

