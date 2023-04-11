#include "Stack.h"

template <typename T>
Stack<T>::Stack(){
    SingleLinkedList<T>();
}

template <typename T>
Stack<T>::~Stack(){
    SingleLinkedList<T>::~SingleLinkedList();
}

template <typename T>
void Stack<T>::push(const T& val){
    SingleLinkedList<T>::insertAtHead(val);
}

template <typename T>
T Stack<T>::pop(){
    T val = SingleLinkedList<T>::head->val;
    SingleLinkedList<T>::removeAtHead();
    return val;
}

template <typename T>
T Stack<T>::top() const{
    return SingleLinkedList<T>::head->val;
}

template <typename T>
bool Stack<T>::isEmpty() const{
    return SingleLinkedList<T>::isEmpty();
}

template <typename T>
int Stack<T>::stackSize() const{
    return SingleLinkedList<T>::linkedListSize();
}

template <typename T>
void Stack<T>::clear(){
    SingleLinkedList<T>::clear();
}

template <typename T>
void Stack<T>::print() const{
    SingleLinkedList<T>::print();
}
