#include <iostream>
#include <bytenet/bytenet.h>
#include <bytenet/network.h>

int main() {
    // Create a network object
    bytenet::Network network;

    // Create a server object bound to localhost on port 8080
    bytenet::Server server(network, "127.0.0.1", 8080);

    // Register a callback to handle new connections
    server.onConnect([](bytenet::Connection& conn) {
        std::cout << "New connection from: " << conn.getRemoteAddress() << std::endl;
    });

    // Start the server
    server.start();

    // Run the network event loop
    network.run();

    return 0;
}
