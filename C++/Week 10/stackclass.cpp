#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> data_;
public:
    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        if (data_.empty()) {
            std::cerr << "Stack is empty (pop)\n";
            return;
        }
        data_.pop_back();
    }

    T& top() {
        if (data_.empty()) {
            std::cerr << "Stack is empty (top)\n";
            static T dummy{};
            return dummy;
        }
        return data_.back();
    }

    const T& top() const {
        if (data_.empty()) {
            std::cerr << "Stack is empty (top)\n";
            static T dummy{};
            return dummy;
        }
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }
};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    std::cout << "Top: " << s.top() << std::endl;
    s.pop();
    std::cout << "Top after pop: " << s.top() << std::endl;
    s.pop();
    s.pop(); // Will print error
    std::cout << "Size: " << s.size() << std::endl;
}