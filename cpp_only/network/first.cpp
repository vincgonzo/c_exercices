#include <iostream>
#include <chrono>
#include <thread>

#define ASIO_STANDALONE

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::vector<char> vBuffer(10 * 1024);

void grabSomeData(asio::ip::tcp::socket& socket){
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()), 
        [&](std::error_code ec, std::size_t len){
            if(!ec){
                std::cout << "\n\nRead " << len << " bytes\n\n";
                for(int i = 0; i < len; i++)
                    std::cout << vBuffer[i];

                grabSomeData(socket);
            }
        }
    );
}

int main()
{
    asio::error_code ec;

    // Create a "context" - essentially the platform specific int
    asio::io_context context;

    // give some fake job to asio so context doesn't finished
    asio::io_context::work idleWork(context);

    // Start context
    std::thread thrContext = std::thread([&]() { context.run(); });

    // address where to connect
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 7890);

    // socket creation
    asio::ip::tcp::socket socket(context);

    // Tell socket to try & connect
    socket.connect(endpoint, ec);

    // Handle error on connection
    if(!ec)
        std::cout << "Connected" << std::endl;
    else    
        std::cout << "Failed to connect to address :\n" << ec.message() << std::endl;

    if(socket.is_open()){
        grabSomeData(socket);

        std::string sRequest = 
        "GET /index.html HTTP/1.1\r\n"
        "Host: david-barr.co.uk\r\n"
        "Connection: close \r\n\r\n";

        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
        
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);

        context.stop();
        if(thrContext.joinable()) thrContext.join();        
    }


    return 0;
}


