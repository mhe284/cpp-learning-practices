#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>

/* Week 8 Ex: Implement a callback list using std::function and lambdas. */

class Callbacks {
private:
    std::vector<std::pair<int, std::function<void()>>> callbacks_;
    int next_id_ = 0;
public:

    //Add callbacks
    int add(const std::function<void()>& callback) {
        callbacks_.push_back(std::make_pair(++next_id_, callback));
        return next_id_;
    }

    //Remove callbacks
    bool remove(int id) {
        auto it = std::find_if(callbacks_.begin(), callbacks_.end(),
            [id](const auto& pair) { return pair.first == id; });
        
        if (it != callbacks_.end()) {
            callbacks_.erase(it);
            return true;
        }
        return false;
    }

    //Call callbacks
    void invoke() {
        for (const auto& [id, callback] : callbacks_) {
            callback();
        }
    }

    // Get number of registered callbacks
    int size() const {
        return callbacks_.size();
    }
};

// Example usage
int main() {
    Callbacks callbacks;

    // Add some callbacks using lambdas
    int id1 = callbacks.add([]() {
        std::cout << "Callback 1 called\n";
    });

    int id2 = callbacks.add([]() {
        std::cout << "Callback 2 called\n";
    });

    // Invoke all callbacks
    std::cout << "Invoking " << callbacks.size() << " callbacks:\n";
    callbacks.invoke();

    // Remove one callback
    callbacks.remove(id1);

    // Add another callback
    callbacks.add([]() {
        std::cout << "Callback 3 called\n";
    });

    // Invoke remaining callbacks
    std::cout << "\nInvoking " << callbacks.size() << " callbacks:\n";
    callbacks.invoke();

    return 0;
}