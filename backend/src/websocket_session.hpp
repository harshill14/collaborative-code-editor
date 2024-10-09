#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include "doc_manager.hpp"

class WebsocketSession : public std::enable_shared_from_this<WebsocketSession> {
public:
    explicit WebsocketSession(tcp::socket socket);
    void start();

private:
    void do_read();
    void on_read(boost::system::error_code ec, std::size_t bytes_transferred);
    void on_write(boost::system::error_code ec, std::size_t bytes_transferred);

    boost::beast::websocket::stream<boost::asio::ip::tcp::socket> ws_;
    boost::beast::multi_buffer buffer_;
    DocManager& doc_manager_;
};
