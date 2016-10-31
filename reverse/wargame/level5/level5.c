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
#define PORT	5001

/**********************************/
void challenge_entry(int fildes);
void drop_to_shell(int fildes);
int check_password(char *input);
char ascii_read(int fildes, int *input, int length);

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

	char buf[BUFSIZE];
    char *string1 = "Password: ";
    char *string2 = "Correct password! Dropping to shell.\n";
    char *string3 = "Incorrect! Try again.\n";

    write(fildes, string1, strlen(string1));

    bzero(buf, BUFSIZE);
    n = read(fildes, buf, BUFSIZE);

	if(check_password(buf)){
      write(fildes, string2, strlen(string2));
      drop_to_shell(fildes);

	}
	else{
      write(fildes, string3, strlen(string3));
      shutdown(fildes, 2);
	}
   return;

}




/***************** drop_to_shell *****************/
void drop_to_shell(int fildes){
   int pid;
   char *name[2];

      pid = fork();
      if(pid) return;   // Parent process

      dup2 (fildes, 0);
      dup2 (fildes, 1);
      dup2 (fildes, 2);

      name[0] = "/bin/sh";
      name[1] = NULL;
      execve(name[0], name, NULL);

}

/***************** check_password *****************/
int check_password(char *input){
  int fd;
  char buf[BUFSIZE];


  fd = open("password.txt", 0);

  n = read(fd, buf, BUFSIZE);

  strcmp(input, buf);


}




char ascii_read(int fildes, int *input, int length){


  printf("char is %x\n");

}