#include "doc_manager.hpp"
#include "operational_transformation.hpp"

DocManager& DocManager::get_instance() {
    static DocManager instance;
    return instance;
}

DocManager::DocManager() : document_("") {}

std::string DocManager::process_operation(const std::string& op_json) {
    std::lock_guard<std::mutex> lock(mtx_);
    // Deserialize operation
    Operation op = Operation::from_json(op_json);

    // Apply operation using OT
    OperationalTransformation ot;
    ot.apply_operation(document_, op);

    // Serialize updated document
    return document_;
}
