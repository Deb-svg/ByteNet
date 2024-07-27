#ifndef BYTENET_BYTENET_H
#define BYTENET_BYTENET_H

#include <string>

namespace bytenet {

// Forward declaration of the Connection class
class Connection;

// The Network class manages the overall network operations and event loop
class Network {
public:
    Network();
    ~Network();

    // Starts the network event loop
    void run();
};

} // namespace bytenet

#endif // BYTENET_BYTENET_H
