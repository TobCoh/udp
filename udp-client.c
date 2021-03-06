/*
 * udp-client.c
 *
 *  Created on: Sep 25, 2018
 *      Author: tobias
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 8888



int main(void ){

	struct sockaddr_in si_other;
	int s, i, slen=sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];

	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
		fprintf(stderr, "socket failed \n");
	}
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);

	if(inet_aton(SERVER, &si_other.sin_addr) == 0){
		fprintf(stderr, "inet_aton() failed \n");
		exit(1);
	}
	while(1)
	{
		printf("Enter message : ");
		gets(message);

		if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen)==-1){
			fprintf(stderr, "send failed \n");
		}
//		memset(buf, '\0', BUFLEN);
//
//		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == -1){
//			fprintf(stderr, "recv failed \n");
//		}
//		puts(buf);
	}

	close(s);
	return 0;
}
