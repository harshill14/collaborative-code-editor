# Collaborative Code Editor

A real-time collaborative code editor built with a C++ backend server using WebSockets for real-time communication and an HTML/CSS/JavaScript frontend featuring syntax highlighting powered by CodeMirror. The project implements Operational Transformation (OT) for conflict resolution during concurrent edits.

## Features
- Real-time collaborative editing across multiple clients
- Syntax highlighting for code using CodeMirror
- Conflict resolution using Operational Transformation (OT)
- Asynchronous networking with Boost.Asio
- WebSocket communication between client and server
- Modern C++ features and advanced programming techniques

## Project Structure
```plaintext
collaborative-code-editor/
├── backend/
│   ├── src/
│   │   ├── main.cpp
│   │   ├── server.cpp
│   │   ├── server.hpp
│   │   ├── websocket_session.cpp
│   │   ├── websocket_session.hpp
│   │   ├── doc_manager.cpp
│   │   ├── doc_manager.hpp
│   │   ├── operational_transformation.cpp
│   │   ├── operational_transformation.hpp
│   └── CMakeLists.txt
├── frontend/
│   ├── index.html
│   ├── styles.css
│   ├── script.js
└── README.md
