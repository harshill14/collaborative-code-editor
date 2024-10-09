#include "websocket_session.hpp"

WebsocketSession::WebsocketSession(tcp::socket socket)
    : ws_(std::move(socket)), doc_manager_(DocManager::get_instance()) {}

void WebsocketSession::start() {
    ws_.async_accept([sp = shared_from_this()](boost::system::error_code ec) {
        if (!ec) {
            sp->do_read();
        }
    });
}

void WebsocketSession::do_read() {
    ws_.async_read(buffer_,
        [sp = shared_from_this()](boost::system::error_code ec, std::size_t bytes_transferred) {
            sp->on_read(ec, bytes_transferred);
        });
}

void WebsocketSession::on_read(boost::system::error_code ec, std::size_t bytes_transferred) {
    if (ec == boost::beast::websocket::error::closed) {
        return;
    }
    if (!ec) {
        std::string msg = boost::beast::buffers_to_string(buffer_.data());
        buffer_.consume(buffer_.size());

        // Process message
        auto response = sp->doc_manager_.process_operation(msg);

        // Broadcast to other clients
        ws_.text(ws_.got_text());
        ws_.async_write(boost::asio::buffer(response),
            [sp = shared_from_this()](boost::system::error_code ec, std::size_t bytes_transferred) {
                sp->on_write(ec, bytes_transferred);
            });
    }
}

void WebsocketSession::on_write(boost::system::error_code ec, std::size_t bytes_transferred) {
    if (!ec) {
        do_read();
    }
}
