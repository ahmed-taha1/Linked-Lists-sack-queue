//
// Created by Ismail Magdy on 16/04/2023.
//
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
    queue<T> Queue;
public:
    void push(const T& element);
    void pop();
    T top()const;
    bool isEmpty()const;
    int size()const;
    void clear();
};

template<typename T>
void Stack<T>::push(const T &element) {
    this-> Queue.push(element);
}

template<typename T>
void Stack<T>::pop() {
    queue<T> temp;
    while (this->size()>1){
        temp.push(this->Queue.front());
        Queue.pop();
    }
    this->Queue = temp;
}

template<typename T>
T Stack<T>::top() const {
    return Queue.back();
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return Queue.empty();
}

template<typename T>
int Stack<T>::size() const {
    return Queue.size();
}

template<typename T>
void Stack<T>::clear(){
    while (Queue.size()){
        Queue.pop();
    }
}

int main(){
    Stack <int> ss;
    ss.push(12);
    ss.push(15);
    ss.push(21);
    ss.pop();
    cout << ss.top() << '\n';
    ss.pop();
    cout << ss.top() << '\n';
    ss.clear();
    cout << ss.size() << '\n';
    cout << ss.isEmpty() << '\n';
}
