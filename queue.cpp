#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> queue;
    int head;
    int tail;
    int capacity;

public:
    Queue(int capa = 10) : capacity(capa + 1), head(0), tail(0), queue(capa+1) {}

    void enqueue(int num) {
        if (isFull()) {
            resize(capacity * 2);
        } queue[tail] = num;
        tail = (tail + 1) % capacity;
        
       
    }

    void dequeue() {
        if (!isEmpty()) {
            head = (head + 1) % capacity;
            if (size() < capacity / 4) {
                resize(capacity / 2);
            }
        }
    }

    bool isEmpty() const {
        return head == tail;
    }

    bool isFull() const {
        return (tail + 1) % capacity == head;
    }

    int size() const {
        return (tail - head + capacity) % capacity;
    }

    void resize(int newCapacity) {
        std::vector<int> newQueue(newCapacity + 1);
        int j = 0;
        for (int i = head; i != tail; i = (i + 1) % capacity) {
            newQueue[j++] = queue[i];
        }
        head = 0;
        tail = j;
        capacity = newCapacity + 1;
        queue = std::move(newQueue);
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue: ";
        int i = head;
        while (i != tail) {
            std::cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display(); // Output: Queue: 1 2 3

    q.dequeue();
    q.display(); // Output: Queue: 2 3

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display(); // Output: Queue: 2 3 4 5 6 7 8

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display(); // Output: Queue: 6 7 8

    return 0;
}
