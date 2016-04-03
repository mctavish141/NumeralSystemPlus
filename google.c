//
//  main.c
//  SocketIP
//
//  Created by Serhii Kopach on 17.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main () {
    char *hostname = "google.com";
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;
    
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("%s\n", "--- Get host by name failed.");
        return 1;
    }
    
    addr_list = (struct in_addr**) he->h_addr_list;
    
    for (int i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }
    
    printf("%s resloved to %s\n", hostname, ip);
    
    return 0;
}
