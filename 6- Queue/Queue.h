#include "../3- Doubly Linked List/doublyLinkedList.cpp"

template <typename T>
class Queue: protected doublyLinkedList<T>{
    public:
        Queue();
        ~Queue();
        void enqueue(const T& val);
        T dequeue();
        T first() const;
        bool isEmpty() const;
        int queueSize() const;
        void clear();
        void print() const;
};