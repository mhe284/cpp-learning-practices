#include <iostream>
#include <memory>
#include <vector>
#include <string>

/* Week 8 Ex: Manage memory with unique_ptr. */

struct Node {
    std::string name;
    std::vector<std::unique_ptr<Node>> children;

    Node(const std::string& n) : name(n) {}
};

int main() {
    // Create root node with unique_ptr
    auto root = std::make_unique<Node>("Root");

    // Add children using unique_ptr
    root->children.push_back(std::make_unique<Node>("Child1"));
    root->children.push_back(std::make_unique<Node>("Child2"));

    // Print tree structure
    std::cout << root->name << std::endl;
    for (const auto& child : root->children) {
        std::cout << "  " << child->name << std::endl;
    }
}