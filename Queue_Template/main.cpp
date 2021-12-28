#include "Queue.h"
#include <iostream>

int main() {
    Queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
    }
    std::cout << "Front - " << q.front() << " Back - " << q.back() << "\n";
    q.pop();
    std::cout << "Front - " << q.front() << " Back - " << q.back() << "\n";
    return 0;
}
