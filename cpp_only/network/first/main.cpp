#include <iostream>
#include <chrono>
#include <thread>

#define ASIO_STANDALONE

#define EEN 1 
#define TWEE 2

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#include "flag_displayer.h"

std::vector<char> vBuffer(10 * 1024);

void grabSomeData(asio::ip::tcp::socket& socket){
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()), 
        [&](std::error_code ec, std::size_t len){
            if(!ec){
                std::string pattern = "404 - Page Not Found";
                std::string buffer;
                for(int i = 0; i < len; i++)
                    buffer += vBuffer[i];

                size_t pos = buffer.find(pattern);
                if(pos != std::string::npos){
                    // std::cout << "Pattern found !!!" << std::endl;
                    asio_nsense();
                }else{
                    std::cout << "Your close but something is not found ;)" << std::endl;
                }

                grabSomeData(socket);
            }
        }
    );
}

int main(int argc, char* argv[])
{
    std::vector<std::string> env_variables = {
        "xhere_is_z_flag",
        "could_u_give_it",
        "give_my_z_key",
        "do_the_magik_plz"
    };

    std::vector<std::string> params_variables = {
        "Th1s_1$_4_c4ll",
        "Fr0m_Th3_b1n4rY",
        "T0_d3st1n4t10n",
        "c4ll1ng_0p3r4t0r"
    };
    
    if (argc > 1) {

        std::string first_param = argv[1];
        std::string checkstr = "Checking %s";
        std::cout << "Checking '" << first_param << "'" << std::endl;
        if (first_param == params_variables[(TWEE * TWEE) - EEN]) {
            std::cout << "calling init ?" << std::endl;
            asio::error_code ec;
            std::string ip_address = "127.0.0.1";
            std::string port_str = "32687"; // Port as a string

            // Convert the string port to an integer
            unsigned short port = std::stoi(port_str); 
            const char* env_init = std::getenv("ENV_INIT");

            // Check if ENV_INIT is set
            if (env_init != nullptr) {
               

                // Now check if its value is xhere_is_z_flag
                if (std::string(env_init) == env_variables[TWEE]) {
                    std::cout << "init: Ok." << std::endl;
                    unsigned short port = std::stoi(port_str);
                    asio::io_context context;
                    // give some fake job to asio so context doesn't finished
                    asio::io_context::work idleWork(context);
                    // Start context
                    std::thread thrContext = std::thread([&]() { context.run(); });
                    // address where to connect
                    asio::ip::tcp::endpoint endpoint(asio::ip::make_address(ip_address, ec), port);
                    // socket creation
                    asio::ip::tcp::socket socket(context);
                    // Tell socket to try & connect
                    socket.connect(endpoint, ec);

                    // Handle error on connection
                    if(!ec)
                        std::cout << "Connected" << std::endl;
                    else    
                        std::cout << ec.message() << std::endl;

                    if(socket.is_open()){
                        grabSomeData(socket);

                        std::string sRequest = 
                        "GET /index.html HTTP/1.1\r\n"
                        "Host: cscbe-localhost.edu.be\r\n"
                        "Connection: close \r\n\r\n";


                        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
                        
                        using namespace std::chrono_literals;
                        std::this_thread::sleep_for(200ms);

                        context.stop();
                        if(thrContext.joinable()) thrContext.join();        
                    }

                } else {
                    std::cout << "you guest right but it is the wrong cable.." << std::endl;
                }
            }else{
                std::cout << "missing cables..." << std::endl;
            } 
        } 
    }
    
    // Create a "context" - essentially the platform specific int
    

    return 0;
}


