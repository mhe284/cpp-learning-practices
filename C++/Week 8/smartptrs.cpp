#include <iostream>
#include <memory>
#include <vector>
#include <string>

/* Week 8 Ex: Build a graph using shared_ptr and observe ownership. */

struct Node {
    std::string name;
    std::vector<std::shared_ptr<Node>> neighbors;

    Node(const std::string& n) : name(n) {}
};

int main() {
    // Create nodes
    auto a = std::make_shared<Node>("A");
    auto b = std::make_shared<Node>("B");
    auto c = std::make_shared<Node>("C");

    // Connect nodes (undirected graph for this example)
    a->neighbors.push_back(b);
    a->neighbors.push_back(c);
    b->neighbors.push_back(a);
    b->neighbors.push_back(c);
    c->neighbors.push_back(a);
    c->neighbors.push_back(b);

    // Observe ownership (reference count)
    std::cout << "a use_count: " << a.use_count() << std::endl;
    std::cout << "b use_count: " << b.use_count() << std::endl;
    std::cout << "c use_count: " << c.use_count() << std::endl;

    // Print neighbors
    for (const auto& neighbor : a->neighbors) {
        std::cout << "A neighbor: " << neighbor->name << std::endl;
    }
}