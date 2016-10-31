#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define PORT	6000	

/**********************************/
void challenge_entry(int fildes);




/***************** main *****************/
int main(int argc, char **argv) {
  int parentfd; /* parent socket */
  int childfd; /* child socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */

  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */



  portno = PORT;

  /* 
   * socket: create the parent socket 
   */
  parentfd = socket(AF_INET, SOCK_STREAM, 0);



  optval = 1;
  setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));


  bzero((char *) &serveraddr, sizeof(serveraddr));

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)portno);


  bind(parentfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));


  listen(parentfd, 10);

  clientlen = sizeof(clientaddr);
  while (1) {

    childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);

	challenge_entry(childfd);

  }
}


/***************** challenge_entry *****************/
void challenge_entry(int fildes){
	char buf[BUFSIZE];
	int n; /* message byte size */


    bzero(buf, BUFSIZE);
    n = read(fildes, buf, BUFSIZE);
    printf("server received %d bytes: %s", n, buf);
    
    n = write(fildes, buf, strlen(buf));

    close(fildes);

}








