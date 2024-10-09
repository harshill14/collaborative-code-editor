#pragma once

#include <boost/asio.hpp>
#include <set>
#include "websocket_session.hpp"

class Server {
public:
    Server(boost::asio::io_context& io_context, short port);

private:
    void do_accept();
    boost::asio::ip::tcp::acceptor acceptor_;
};
