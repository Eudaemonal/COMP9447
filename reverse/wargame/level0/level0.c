#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 100
#define PORT	5000	

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
	int n;
	int pid;
    char *name[2];
	char buf[BUFSIZE];
    char *string1 = "Password: ";
    char *string2 = "Correct password! Dropping to shell.\n";
    char *string3 = "Incorrect! Try again.\n";

    write(fildes, string1, strlen(string1));

    bzero(buf, BUFSIZE);
    n = read(fildes, buf, BUFSIZE);

	if(n==10){
    	write(fildes, string2, strlen(string2));

		pid = fork();
		if(pid) return;   // Parent process

		dup2 (fildes, 0);
		dup2 (fildes, 1);
		dup2 (fildes, 2);

		name[0] = "/bin/sh";
		name[1] = NULL;
		execve(name[0], name, NULL);
	}
	else{
    	write(fildes, string3, strlen(string3));
      	shutdown(fildes, 2);
	}
    
    return;

}








