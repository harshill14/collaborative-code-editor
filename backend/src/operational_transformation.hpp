#pragma once

#include <string>

struct Operation {
    int position;
    std::string text;
    bool is_insert;

    static Operation from_json(const std::string& json_str);
};

class OperationalTransformation {
public:
    void apply_operation(std::string& doc, const Operation& op);
};
