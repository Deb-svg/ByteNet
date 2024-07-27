#ifndef BYTENET_NETWORK_H
#define BYTENET_NETWORK_H

#include <functional>
#include <string>
#include "bytenet.h"

namespace bytenet {

// Forward declaration of the Connection class
class Connection;

// The Server class handles incoming connections and server operations
class Server {
public:
    // Constructor for the Server class
    Server(Network &network, const std::string &address, int port);
    ~Server();

    // Starts the server
    void start();

    // Registers a callback to be called when a new connection is established
    void onConnect(std::function<void(Connection&)> callback);

private:
    Network &network_;
    std::string address_;
    int port_;
    std::function<void(Connection&)> onConnectCallback_;
};

// The Connection class represents an individual connection
class Connection {
public:
    // Returns the remote address of the connection
    std::string getRemoteAddress() const;

private:
    std::string remoteAddress_;
};

} // namespace bytenet

#endif // BYTENET_NETWORK_H
