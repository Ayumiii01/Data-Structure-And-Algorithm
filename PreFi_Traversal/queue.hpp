
#include "node.hpp"

class Queue {
public:
    virtual void enqueue(node* n) = 0;
    virtual void dequeue() = 0;
    virtual node* front() = 0;
    virtual bool empty() = 0;

    virtual ~Queue() {}
};
