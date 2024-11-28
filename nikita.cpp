#include <WinSock2.h>
#include <iostream>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in service;

    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("0.0.0.0");
    service.sin_port = htons(27015);

    int bind_c = bind(sock, (SOCKADDR*)&service, sizeof(service));
    if (bind_c == SOCKET_ERROR) {
        std::cout << "SOCKET_ERROR\n";
        return 0;
    }
    listen(sock, 0);
    accept(sock, NULL, NULL);

    char buff[1024];
    buff[1023] = '\0';
    recv(sock, buff, 1023, 0);
    std::cout << buff << '\n';
    

    
}
