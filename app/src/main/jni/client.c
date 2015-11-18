#include "client.h"

struct sockaddr_un setupAddress() {
	struct sockaddr_un address;

	address.sun_family = AF_LOCAL;
	address.sun_path[0] = '\0';
	strcpy(&address.sun_path[1], LOCAL_SOCKET_SERVER_NAME);
	
	return address;
}

int createSocket() {
	int sockfd = socket(PF_LOCAL, SOCK_STREAM, 0);
	if(sockfd < 0) {
		int err = errno;
        LOGD("%s: Cannot open socket: %s (%d)\n",
            __FUNCTION__, strerror(err), err);
        errno = err;
		// perror("createSocket\n");
        exit(1);
	}
	return sockfd;
}

void connectSocket(int sockfd, struct sockaddr_un *address) {
	int len = offsetof(struct sockaddr_un, sun_path) + 1 + strlen(LOCAL_SOCKET_SERVER_NAME);

	int result = connect(sockfd, (struct sockaddr *) address, len);
	if(result == -1) {
		int err = errno;
        LOGD("%s: Cannot open socket: %s (%d)\n",
            __FUNCTION__, strerror(err), err);
        errno = err;
		// perror("connectSocket\n");
		exit(1);
	}
}

int socketSend(char * msg) {
	int sockfd;
	int len;
	struct sockaddr_un address;

	address = setupAddress();
	sockfd = createSocket();
	connectSocket(sockfd, &address);

	write(sockfd, msg, strlen(msg));
	close(sockfd);
	
	// LOGD("sent.");

	return 0;
}