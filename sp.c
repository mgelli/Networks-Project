#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define MAXLINE 4096 /*max text line length*/
#define SERV_PORT 8888  //3000 /*port*/

int
main(int argc, char **argv)
{
 int sockfd;
 struct sockaddr_in servaddr;
 char sendline[MAXLINE], recvline[MAXLINE];
 char requestFrame[5]; 
 //FILE*fps,fpd;
 char reqF[1025],sendF[1025],recvF[1025];
 int lenReR,lenSF,lenReF;
 
 //basic check of the arguments
 //additional checks can be inserted
 if (argc !=4) {
  perror("Usage: TCPClient <./sp data_file log_file cps server_add");
  exit(1);
 }

 //Create a socket for the client
 //If sockfd<0 there was an error in the creation of the socket
 if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {
  perror("Problem in creating the socket");
  exit(2);
 }

 //Creation of the socket
 memset(&servaddr, 0, sizeof(servaddr));
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr= inet_addr(argv[3]);//(argv[1]);
 servaddr.sin_port =  htons(SERV_PORT); //convert to big-endian order
 //int cli_Id = argv[2];
 //Connection of the client to the socket
 if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr))<0) {
  perror("Problem in connecting to the server");
  exit(3);
 }

 FILE*fps = fopen(argv[1],"r");
 FILE*fpd = fopen(argv[2],"w");
 
 if(fps == NULL){
	 printf("Error Opening file : %s",argv[1]);
	 exit(1);
 }
 else {
	 while(fgets(sendline, MAXLINE, fps) != NULL){    
	 	if(strncmp(sendline,"Frame",5)){
			fputs("Send request to send ",fpd); 
			fputs(sendline,fpd);
			fputs("Received permission to send ",fpd);
			fputs(sendline,fpd);
            send(sockfd, sendline, strlen(sendline), 0);
			fputs("Send data (via cps) ",fpd);
			fputs(sendline,fpd);
		    }
        else{	
             int i;		
			for(i = 0; i < 2; i++){
				fgets(sendline, MAXLINE, fps) ;
			   recv(sockfd, recvline,MAXLINE,0);
			   //printf("%s "Data received ( via cps)");fputs(recvline, stdout);
			   fputs(recvline,fpd);
			}
		 }
	 }
	 fclose(fps);
	 fclose(fpd);

 }
 exit(0);
}