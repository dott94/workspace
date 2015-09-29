#define SERVER_INC
#include "sockets.h"

int main(int argc, char** argv) {
	int port;
	int bytes_read;
	int input_idx;
	char buffer[BUFFER_SIZE];
	char** input;
	SSL_CTX* ctx;
	int server;
	int len;
	int client;
	SSL_METHOD *method;
	struct sockaddr_in addr;
	int sd;

	if (argc != 2) {
		printf("Usage: ./server portNum\n");
		exit(1);
	}
	port = atoi(argv[1]);
	if (port <= 0 || port > 65535) {
		printf("Invalid port number\n");
		exit(1);
	}

	SSL_library_init();
	OpenSSL_add_all_algorithms(); // load  all cryptos 
	SSL_load_error_strings(); // load all error messages 
	method = (SSL_METHOD*) SSLv3_server_method(); // create new server-method 
	ctx = SSL_CTX_new(method); // create new context from method 
	if (ctx == NULL) {
		ERR_print_errors_fp (stderr);
		abort();
	} 
	//set the local certificate 
	if (SSL_CTX_use_certificate_file(ctx, "cacert.pem", SSL_FILETYPE_PEM)
			<= 0) {
		ERR_print_errors_fp (stderr);
		abort();
	}
	// set the private key from KeyFile ) 
	if (SSL_CTX_use_PrivateKey_file(ctx, "private.pem", SSL_FILETYPE_PEM)
			<= 0) {
		ERR_print_errors_fp (stderr);
		abort();
	}
	if (!SSL_CTX_check_private_key(ctx)) {
		fprintf(stderr, "Private key does not match the public certificate\n");
		abort();
	}

	server = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(server, &addr, sizeof(addr)) != 0) {
		perror("can't bind port");
		abort();
	}
	if (listen(server, 10) != 0) {
		perror("Can't configure listening port");
		abort();
	}

	while (1) {
		struct sockaddr_in addr;
		len = sizeof(addr);
		SSL *ssl;
		fprintf(stderr, "waiting for client on port %d", port);
		client = accept(server, &addr, &len); /* accept connection as usual */
		bytes_read = read(server, buffer, sizeof(buffer));	
		buffer[bytes_read] = '\0';
		printf("Client msg: \"%s\"\n", buffer);
		
		
		/*What is still needed*/
		/*parses the incomming stuff (connect message) */
		/*send back the response message*/
		/*connect to the server with the infirmation that was in the connect message*/
		/*client code here*/
		/*loop to read incomming messages and write to file, pass along to server*/
		/*need to listen to stuff comming from server, write to file and pass to client*/
		
				
		ssl = SSL_new(ctx); 
		SSL_set_fd(ssl, client); 
		if (SSL_accept(ssl) <= 0) { 
			ERR_print_errors_fp (stderr);
		} else {
			bytes_read = SSL_read(ssl, buffer, sizeof(buffer)); 
			if (bytes_read > 0) {
				buffer[bytes_read] = 0;
				printf("Client msg: \"%s\"\n", buffer);
			} else
				ERR_print_errors_fp (stderr);
		}
		sd = SSL_get_fd(ssl); 
		SSL_free(ssl); 
		close(sd);
		

	}
	close(server); 
	SSL_CTX_free(ctx);

	return 0;
}
