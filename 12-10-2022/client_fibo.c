#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sv, cl;
    sv.sin_family = AF_INET;
    sv.sin_port = htons(atoi(argv[2]));
    sv.sin_addr.s_addr = inet_addr(argv[1]);

    int len = sizeof(struct sockaddr_in);

    connect(net_socket, (struct sockaddr *)&sv, len);
    int num;

    int n; 
    n = recv(net_socket, &num, 199, 0);
    printf("Received from server: %d\n", num);

    int a = 0, b = 1, c;
    if (num < 1)
        printf("%d ", a);
    else if (num < 2) {
        printf("%d %d ", a, b);
    } else {
        printf("%d %d ", a, b);
        for (int i=2; i<num; i++) {
            c = a + b;
            a = b;
            b = c;
            printf("%d ", c);
        }
    }

    printf("\n");
    close(net_socket);

    return 0;
}