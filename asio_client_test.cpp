#include <chrono>
#include <iomanip>
#include <iostream>

#include <string>

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::vector<char> vBuffer(20 * 1024);

void getData(asio::ip::tcp::socket &socket) {
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
        [&](std::error_code ec, std::size_t len)
        {
            if(ec) return;

            std::cout << "\n\nRead " << len << " bytes\n\n";

            for (int i = 0; i < len; i++)
            {
                std::cout << vBuffer[i];
            }

            getData(socket);
            
        }
    );
}

int main() {

    int const DEST_PORT = 80;
    char const *DEST_ADDR = "192.168.0.11";
    
    asio::error_code ec;

    asio::io_context context;

    asio::io_context::work idleWork(context);

    std::thread threadContext = std::thread( [&]() { context.run(); });

    asio::ip::tcp::endpoint dest(asio::ip::make_address(DEST_ADDR, ec), DEST_PORT);

    asio::ip::tcp::socket socket(context);

    socket.connect(dest, ec);

    if (ec) {
        std::cout << "Failed to connect to " << DEST_ADDR << std::endl << ec.message() << std::endl;
        threadContext.detach();
        return -1;
    }

    std::cout << "Connected!" << std::endl;

    if (!socket.is_open()) {
        std::cout << "Failed to open Socket at Port " << DEST_PORT << std::endl;
        threadContext.detach();
        return -1;
    }

    getData(socket);

    std::string request = 
        "GET /index.html HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "Connection: close\r\n\r\n";

    socket.write_some(asio::buffer(request.data(), request.size()), ec);

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2000ms);
    
    threadContext.detach();
    return 0;
}
