# socket-assignment
TCP server-client project using cpp

Objective:

The objective of this assignment is to understand and implement communication between a client and a server using TCP sockets in C++. The programs exchange data and compute the sum of numbers sent between them.

Overview:

This project consists of two programs:
Client Program — Sends its name and an integer to the server.
Server Program — Receives the data, processes it, and sends a response back.
Both programs communicate using TCP protocol over a specified port number.

Working of the Program:
**Client Side**
The client asks the user to enter an integer between 1 and 100.
It creates a TCP socket.
The client connects to the server using the server’s IP address and port number.
It sends a message containing:
  Client name
  Entered number
The client waits for a response from the server.
After receiving the server’s name and number, it displays:
  Client name
  Server name
  Client number
  Server number
  Sum of both numbers
The client closes the socket and terminates.

**Server Side**
The server creates a TCP socket.
It binds the socket to a port number (greater than 5000).
The server listens for incoming client connections.
When a client connects, the server:
Receives the client’s name and number
Displays the client’s name and server’s name
The server selects its own integer between 1 and 100.
It displays:
  Client’s number
  Server’s number
  Sum of the numbers
The server sends back its name and number to the client.
If the received number is outside the range 1–100, the server closes all sockets and terminates.

Technologies Used:
Programming Language: C++
Networking Library: Winsock API
Communication Protocol: TCP

How to Compile and Run:
Compilation
g++ server.cpp -o server.exe -lws2_32
g++ client.cpp -o client.exe -lws2_32
Execution
1.Run the server program first:
server.exe
2.Open a second terminal and run the client program:
client.exe

Concepts Demonstrated:
TCP Socket Programming
Client–Server Architecture
Data Transmission using send() and recv()
IP Addressing and Port Communication
Winsock API usage in C++

Conclusion:
This project successfully demonstrates communication between a client and server using TCP sockets in C++. The assignment covers socket creation, connection establishment, data exchange, and proper termination conditions.
