#include "bytenet/network.h"
#include <iostream>

namespace bytenet {

Server::Server(Network &network, const std::string &address, int port)
    : network_(network), address_(address), port_(port) {
    std::cout << "Server created at " << address << ":" << port << std::endl;
}

Server::~Server() {
    // Cleanup code for Server
    std::cout << "Server destroyed" << std::endl;
}

void Server::start() {
    // Implementation of starting the server
    std::cout << "Server started at " << address_ << ":" << port_ << std::endl;
    // TODO: Add actual server start logic here
}

void Server::onConnect(std::function<void(Connection&)> callback) {
    onConnectCallback_ = callback;
    std::cout << "Connection callback registered" << std::endl;
    // TODO: Add logic to invoke callback on new connection
}

std::string Connection::getRemoteAddress() const {
    return remoteAddress_;
}

} // namespace bytenet
