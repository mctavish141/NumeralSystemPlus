#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main () {
    int socket_desc;
    struct sockaddr_in server;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    printf("%s\n", (socket_desc == -1) ? "Socket cannot be created." : "Socket created.");
    
    //server.sin_addr.s_addr = inet_addr("93.73.1.110");
    server.sin_addr.s_addr = inet_addr("216.58.216.46"); // google.com
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    
    // Connect to a remote server
    int connection_result = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));
    printf("%s\n", (connection_result < 0) ? "Connection error." : "Connected.");
    
    // Send some data
    char *message = "GET / HTTP/1.1\r\n\r\n";
    long int send_result = send(socket_desc, message, strlen(message), 0);
    printf("%s\n", (send_result < 0) ? "Send error." : "Data sent.");
    
    // Receive a reply from the server
    char server_reply[2000];
    long int reply_result = recv(socket_desc, server_reply, 2000, 0);
    printf("%s\n", (reply_result < 0) ? "Reply error." : "Data received.");
    
    printf("%s", server_reply);
    
    close(socket_desc);
}
