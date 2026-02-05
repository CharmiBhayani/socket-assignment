#define _WIN32_WINNT 0x0600
#include<iostream>
#include<winsock2.h>
#include<ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PORT 54000

int main(){

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET clientSocket;
    sockaddr_in serverAddr{};

    char buffer[1024] = {0};
    string clientName = "Client_CPP";
    int clientNumber;

    cout<<"Enter the Number (1-100): ";
    cin>>clientNumber;

    clientSocket = socket(AF_INET, SOCK_STREAM,0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET,"127.0.0.1",&serverAddr.sin_addr);

    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    string message = clientName + " " + to_string(clientNumber);
    send(clientSocket, message.c_str(),message.size(),0);

    recv(clientSocket, buffer, sizeof(buffer),0);
    string reply(buffer);

    string serverName;
    int serverNumber;
    sscanf(reply.c_str(),"%s %d",buffer,&serverNumber);
    serverName=buffer;

    cout<<"CLient Name: "<<clientName<<endl;
    cout << "Server Name: " << serverName << endl;
    cout << "Client Number: " << clientNumber << endl;
    cout << "Server Number: " << serverNumber << endl;
    cout << "Sum: " << clientNumber + serverNumber << endl;

    closesocket(clientSocket);
    WSACleanup();

}
#ifdef _WIN32
#include <windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}
#endif