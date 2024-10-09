#include "server.hpp"

int main() {
    try {
        boost::asio::io_context io_context;
        Server server(io_context, 9002);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
