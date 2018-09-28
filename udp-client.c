/*
 * udp-client.c
 *
 *  Created on: Sep 25, 2018
 *      Author: tobias
 */


#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 8888



int main(void* buffer){
	printf("Creating variables \n");
	struct sockaddr_in si_other;
	int s, slen=sizeof(si_other);
	char message[BUFLEN];

	printf("Creating socket \n");
	s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);


	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);


	printf("Enter Message : ");
	gets(message);
	inet_aton(SERVER, &si_other.sin_addr);
	printf("Sending message \n");
	sendto(s, message, sizeof(&message) , 0 , (struct sockaddr *) &si_other, slen);

	close(s);
	return 0;
};
