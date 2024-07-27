#include <iostream>
#include <bytenet/bytenet.h>
#include <bytenet/network.h>

int main() {
    // Create a network object
    bytenet::Network network;

    // Create a connection object
    bytenet::Connection connection;

    // Create a client object bound to the server address and port
    // This assumes you have a suitable constructor in your Connection class
    std::string serverAddress = "127.0.0.1";
    int serverPort = 8080;

    // Connect to the server
    // This assumes your Connection class has a connect method
    try {
        connection.connect(serverAddress, serverPort);
        std::cout << "Connected to server at " << serverAddress << ":" << serverPort << std::endl;

        // Send a message to the server
        std::string message = "Hello, Server!";
        connection.send(message);
        std::cout << "Message sent: " << message << std::endl;

        // Close the connection
        connection.close();
        std::cout << "Connection closed" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
