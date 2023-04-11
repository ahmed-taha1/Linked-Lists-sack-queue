#include "../2- Single Linked List/SingleLinkedList.cpp"

template <typename T>
class Stack: protected SingleLinkedList<T>{
    public:
        Stack();
        ~Stack();
        void push(const T& val);
        T pop();
        T top() const;
        bool isEmpty() const;
        int stackSize() const;
        void clear();
        void print() const;
};