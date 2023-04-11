#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct node{
    T val;
    node* next;
    node(){
        val = 0;
        next = nullptr;
    }
};

template<typename T>
class SingleLinkedList{
    protected:
        node<T>* head;
        int size;
    public:
        SingleLinkedList();
        ~SingleLinkedList();
        void insertAtHead(const T& val);
        void insertAtTail(const T& val);
        void insertAt(const T& val, const int& index);
        void removeAtHead();
        void removeAtTail();
        void removeAt(const int& index);
        void replaceAt(const T& val, const int& index);
        bool isExist(const T& val) const;
        bool isItemAtEqual(const T& val, const int& index) const;
        void swapp(const int& index1, const int& index2);
        bool isEmpty() const;
        int linkedListSize() const;
        void clear();
        void print() const;
};