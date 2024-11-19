#include <iostream>
#include <chrono>

#define ASIO_STANDALONE

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

int main()
{
    asio::error_code ec;

    // Create a "context" - essentially the platform specific int
    asio::io_context context;

    // address where to connect
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("51.38.81.49", ec), 80);

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
        std::string sRequest = 
        "GET /index.html HTTP/1.1\r\n"
        "Host: david-barr.co.uk\r\n"
        "Connection: close \r\n\r\n";

        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
        socket.wait(socket.wait_read); // trick to wait till data where found 


        size_t bytes = socket.available();
        std::cout << "Bytes available: " << bytes << std::endl;

        if(bytes > 0){
            std::vector<char> vBuffer(bytes);
            socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);
            
            for(auto c : vBuffer)
                std::cout << c;
        }
    }


    return 0;
}


