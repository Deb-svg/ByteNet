#include <gtest/gtest.h>
#include "bytenet/network.h"

// Mock class to test the Server
class MockConnection : public bytenet::Connection {
public:
    MockConnection(const std::string& address) {
        remoteAddress_ = address;
    }
};

// Test fixture for the Server class
class ServerTest : public ::testing::Test {
protected:
    bytenet::Network network;
    bytenet::Server server;

    ServerTest()
        : server(network, "127.0.0.1", 8080) {
    }
};

// Test for server creation
TEST_F(ServerTest, Creation) {
    EXPECT_NO_THROW({
        bytenet::Server testServer(network, "192.168.1.1", 9090);
    });
}

// Test server start
TEST_F(ServerTest, StartServer) {
    // Expect no exceptions during start
    EXPECT_NO_THROW({
        server.start();
    });
}

// Test connection callback registration
TEST_F(ServerTest, ConnectionCallback) {
    bool callbackCalled = false;

    server.onConnect([&](bytenet::Connection& conn) {
        callbackCalled = true;
        EXPECT_EQ(conn.getRemoteAddress(), "192.168.1.1");
    });

    // Simulate a connection
    MockConnection conn("192.168.1.1");

    // This is where you would typically invoke the callback
    // Here, we simulate it manually for testing
    if (callbackCalled) {
        // Trigger the callback manually for testing purposes
        server.onConnectCallback_(conn);
    }

    EXPECT_TRUE(callbackCalled);
}

// Test connection remote address
TEST(ConnectionTest, GetRemoteAddress) {
    bytenet::Connection conn;
    std::string testAddress = "10.0.0.1";

    // Set the remote address using a mock constructor
    conn = bytenet::Connection(testAddress);
    EXPECT_EQ(conn.getRemoteAddress(), testAddress);
}
