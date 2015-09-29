#define CLIENT_INC
#include "sockets.h"

int sockfd;

int main(int argc, char** argv) {
	struct hostent* server;
	char message[BUFFER_SIZE];
	int bytes_read;
	int port;
	struct sockaddr_in serv_addr;
	int sd;
	struct hostent *host;
	struct sockaddr_in addr;
	SSL_METHOD *method;
	SSL_CTX *ctx;
	SSL *ssl;
	char buf[1024];
	char* hostname;

	if (argc != 3) {
		printf("Usage: ./client serverName portNum\n");
		exit(1);
	}
	port = atoi(argv[2]);
	hostname = argv[1];
	if (port <= 0 || port > 65535) {
		printf("Invalid port number\n");
		exit(1);
	}

	SSL_library_init();
	OpenSSL_add_all_algorithms(); // Load cryptos
	SSL_load_error_strings(); // load error messages 
	method = SSLv3_client_method();
	if (ctx == NULL) {
		ERR_print_errors_fp (stderr);
		printf("Abort1");
		abort();
	}
	if ((host = gethostbyname(hostname)) == NULL) {
		perror(hostname);
		printf("Abort2");
		abort();
	}
	sd = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = *(long*) (host->h_addr);
	if (connect(sd, &addr, sizeof(addr)) != 0) {
		close(sd);
		perror(hostname);
		printf("Abort3");
		abort();
	}

	ssl = SSL_new(ctx); // create new SSL connection 
	SSL_set_fd(ssl, sd); // attach the socket description  
	if (SSL_connect(ssl) <= 0) { // connection 
		ERR_print_errors_fp (stderr);
	} else {
		char *msg = "HELLOWORLD";

		printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
		SSL_write(ssl, msg, strlen(msg)); // encrypt and send  
	}
	close(sd);
	SSL_CTX_free(ctx);

	return 0;
}
