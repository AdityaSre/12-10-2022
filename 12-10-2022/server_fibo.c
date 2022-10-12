#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sv, cl;
    sv.sin_family = AF_INET;
    sv.sin_port = htons(0);
    sv.sin_addr.s_addr = inet_addr("0.0.0.0");

    int len = sizeof(struct sockaddr_in);
    bind(net_socket, (struct sockaddr *) &sv, len);

    getsockname(net_socket, (struct sockaddr *)&sv, &len);
    printf("Port: %d\n", ntohs(sv.sin_port));

    listen(net_socket, 10);
    int num;

    int fd, n;

    while (1) {
        len = sizeof(struct sockaddr_in);
        fd = accept(net_socket, (struct sockaddr *)&cl, &len);
        scanf("%d", &num);
        write(fd, &num, sizeof(num));
        close(fd);
    }

    close(net_socket);
    return 0;
}