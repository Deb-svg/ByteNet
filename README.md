# ByteNet

ByteNet is a high-performance network library designed to provide efficient and easy-to-use networking capabilities for a variety of applications. Whether you're building a small-scale application or a large-scale distributed system, ByteNet offers the tools you need to create robust and scalable network solutions.

## Features

- **High Performance:** ByteNet is optimized for speed and efficiency, ensuring minimal latency and high throughput.
- **Ease of Use:** Simple and intuitive API that makes network programming accessible to developers of all skill levels.
- **Scalability:** Supports a wide range of network topologies and can easily scale to accommodate growing network demands.
- **Cross-Platform:** Compatible with major operating systems including Linux, Windows, and macOS.
- **Security:** Built-in support for encryption and authentication to secure your network communications.

## Installation

To install ByteNet, follow the steps below:

### Linux (Ubuntu/Debian)

1. **Update your package list:**
    ```bash
    sudo apt update
    ```

2. **Install required dependencies:**
    ```bash
    sudo apt install build-essential libssl-dev
    ```

3. **Clone the ByteNet repository:**
    ```bash
    git clone https://github.com/Deb-svg/ByteNet.git
    cd ByteNet
    ```

4. **Build the project:**
    ```bash
    meson setup build
    meson compile -C build
    ```

5. **Run the tests (optional):**
    ```bash
    meson test -C build
    ```

### Windows

1. **Install required tools:**
   - [Git](https://git-scm.com/download/win)
   - [Visual Studio](https://visualstudio.microsoft.com/) with C++ development tools

2. **Clone the ByteNet repository:**
    ```sh
    git clone https://github.com/Deb-svg/ByteNet.git
    cd ByteNet
    ```

3. **Open the project in Visual Studio and build the solution.**

### macOS

1. **Install required tools:**
    ```bash
    brew install git meson ninja
    ```

2. **Clone the ByteNet repository:**
    ```bash
    git clone https://github.com/Deb-svg/ByteNet.git
    cd ByteNet
    ```

3. **Build the project:**
    ```bash
    meson setup build
    meson compile -C build
    ```

## Running

Commands:

_________________________________________________________________________________
**First make the files executable so we can use the commands**:

``sh
chmod +x cmd/simple_client.cpp
chmod +x cmd/simple_server.cpp

_________________________________________________________________________________

then use:
``sh
./cmd/simple_client.cpp
./cmd/simple_server.cpp

## Usage

After installing ByteNet, you can start using it in your project. Here is a simple example to get you started:

```cpp
#include <bytenet/bytenet.h>

int main() {
    // Initialize ByteNet
    bytenet::Network network;

    // Create a server
    bytenet::Server server(network, "127.0.0.1", 8080);

    // Define a callback for incoming connections
    server.onConnect([](bytenet::Connection& conn) {
        std::cout << "New connection from " << conn.getRemoteAddress() << std::endl;
    });

    // Start the server
    server.start();

    // Run the network event loop
    network.run();

    return 0;
}
```

## Contributing

We welcome contributions from the community! If you'd like to contribute to ByteNet, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes and push them to your fork.
4. Submit a pull request with a detailed description of your changes.

## License

ByteNet is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For questions or comments, please contact [debsvgteam@gmail.com](mailto:debsvgteam@gmail.com).
__________________________________________________________________________________

# *End*
