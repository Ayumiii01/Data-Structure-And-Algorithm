
#include "queue.hpp"
#include <iostream>
using namespace std;

class ArrayQueue : public Queue {
private:
    node* data[100];
    int frontIndex;
    int count;

public:
    ArrayQueue() {
        frontIndex = 0;
        count = 0;
    }

    void enqueue(node* n) override {
        if (count == 100) {
            cout << "Queue is full!\n";
            return;
        }

        int rear = (frontIndex + count) % 100;
        data[rear] = n;
        count++;
    }

    void dequeue() override {
        if (empty()) {
            return;
        }

        frontIndex = (frontIndex + 1) % 100;
        count--;
    }

    node* front() override {
        if (empty()) {
            return nullptr;
        }

        return data[frontIndex];
    }

    bool empty() override {
        return count == 0;
    }
};
