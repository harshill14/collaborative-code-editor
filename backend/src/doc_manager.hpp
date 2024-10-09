#pragma once

#include <string>
#include <mutex>

class DocManager {
public:
    static DocManager& get_instance();
    std::string process_operation(const std::string& op_json);

private:
    DocManager();
    std::string document_;
    std::mutex mtx_;
};
