#include "Queue.h"

template <typename T>
Queue<T>::Queue(){
    doublyLinkedList<T>();
}

template <typename T>
Queue<T>::~Queue(){
    doublyLinkedList<T>::~doublyLinkedList();
}

template <typename T>
void Queue<T>::enqueue(const T& val){
    doublyLinkedList<T>::insertAtTail(val);
}

template <typename T>
T Queue<T>::dequeue(){
    T val = doublyLinkedList<T>::head->value;
    doublyLinkedList<T>::removeAtHead();
    return val;
}

template <typename T>
T Queue<T>::first() const{
    return doublyLinkedList<T>::head->value;
}

template <typename T>
bool Queue<T>::isEmpty() const{
    return doublyLinkedList<T>::isEmpty();
}

template <typename T>
int Queue<T>::queueSize() const{
    return doublyLinkedList<T>::doubleLinkedListSize();
}

template <typename T>
void Queue<T>::clear(){
    doublyLinkedList<T>::clear();
}

template <typename T>
void Queue<T>::print() const{
    doublyLinkedList<T>::forwardTraversal();
}
