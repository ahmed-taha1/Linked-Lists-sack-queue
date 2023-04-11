#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T value;
    Node<T>* next;
    Node<T>* prev;
    Node();
};

template<typename T>
class circularLinkedList{
protected:
    int size;
    Node<T>* tail;
    Node<T>* head;
public:
    circularLinkedList();
    ~circularLinkedList();
    void insertAtHead(const T& val);
    void insertAtEnd(const T& val);
    void insertAt(const int& ind, const T& val);
    void insertAfter(const int& ind, const T& val);
    void removeAtHead();
    void removeAtEnd();
    void removeAt(const int& ind);
    T retriveAt(const int& ind) const;
    void replaceAt(const int& ind, const T& val);
    bool isExist(const T& val) const;
    bool isItemAtEqual(const int& ind, const T& val) const;
    void swapp(const int& ind1, const int& ind2);
    void reverse();
    bool isEmpty() const;
    int circularLinkedListSize() const;
    void clear();
    void print() const;
};