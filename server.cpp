#include<iostream>
#include<cstring>
#include<unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PORT 54000

int main(){

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket,clientSocket;
   

    sockaddr_in serverAddr{}, clientAddr{};
    int clientSize = sizeof(clientAddr);
    char buffer[1024] = {0};

    string serverName = "Server_CPP";
    int serverNumber=50;

    //socket creation
    serverSocket = socket(AF_INET, SOCK_STREAM,0);
    if(serverSocket == -1){
        cerr<<"Socket creation Failed!\n";
        return 1;
    }

    //socket initialization
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    //bind    
    if(bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr))<0){
        cerr<<"Bind failed!\n";
        return 1;
    }

    //listen
    listen(serverSocket,5);
    cout<<"Server is listening on Port "<<PORT<<"..\n";

    //accept
    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
    cout<<"CLient connected!\n";

    //receive
    recv(clientSocket, buffer,sizeof(buffer),0);
    string received(buffer);

    string clientName;
    int clientNumber;
    sscanf(received.c_str(), "%s %d",buffer,&clientNumber);
    clientName=buffer;

    cout<<"Client Name: "<< clientName<<endl;
    cout<<"Server Name: "<< serverName<<endl;

    if(clientNumber < 1 || clientNumber > 100){
        cout<< "Invalid number received. Server shutting down.\n";
        close(clientSocket);
        close(serverSocket);
        return 0;
    }

    cout<<"Client Number: "<<clientNumber<<endl;
    cout<<"Server Number: "<<serverNumber<<endl;
    cout<<"Sum: "<<clientNumber + serverNumber << endl;

    string reply = serverName + " " + to_string(serverNumber);
    send(clientSocket, reply.c_str(),reply.size(),0);

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}

#ifdef _WIN32
#include <windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}
#endif
