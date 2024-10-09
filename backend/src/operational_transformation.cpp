#include "operational_transformation.hpp"
#include <nlohmann/json.hpp>

Operation Operation::from_json(const std::string& json_str) {
    auto json = nlohmann::json::parse(json_str);
    return Operation{
        json["position"],
        json["text"],
        json["is_insert"]
    };
}

void OperationalTransformation::apply_operation(std::string& doc, const Operation& op) {
    if (op.is_insert) {
        doc.insert(op.position, op.text);
    } else {
        doc.erase(op.position, op.text.length());
    }
}
