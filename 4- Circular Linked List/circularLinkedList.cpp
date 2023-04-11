#include "circularLinkedList.h"

template<typename T>
Node<T>::Node(){
    value = T();
    next = NULL;
    prev = NULL;
}

template<typename T>
circularLinkedList<T>::circularLinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

template<typename T>
void circularLinkedList<T>::insertAtHead(const T& val){
    Node<T>* temp = new Node<T>();
    temp -> value = val;
    if(head == NULL){
        head = tail = temp;
        size++;
        return;
    }
    // curcial part
    temp->prev = tail;
    tail->next = temp;

    temp -> next = head;
    head -> prev = temp;
    head = temp;
    size++;

}

template<typename T>
void circularLinkedList<T>::insertAtEnd(const T& val){
    Node<T>* temp = new Node<T>();
    temp -> value = val;

    if(head == NULL){
        head = tail = temp;
        size++;
        return;
    }

    // curcial part
    temp->next = head;
    head->prev = temp;

    temp -> prev = tail;
    tail -> next = temp;
    tail = temp;
    size++;

}

template<typename T>
void circularLinkedList<T>::insertAt(const int& ind, const T& val){
    if(ind >= size || ind < 0){
        cout << "out of range\n";
        return;
    }

    if(ind == 0){
        insertAtHead(val);
        return;
    }
    else if(ind == size - 1){
        insertAtEnd(val);
        return;
    }

    Node<T>* curr = head;
    Node<T>* temp = new Node<T>();
    temp -> value = val;

    for(int i = 0; i < ind; i++)
        curr = curr->next;

    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev->next = temp;
    curr->prev = temp;
    size++;
}

template<typename T>
void circularLinkedList<T>::insertAfter(const int& ind, const T& val){
    if(ind >= size - 1 || ind < -1){
        cout << "out of range\n";
        return;
    }

    if(ind == 0){
        insertAtHead(val);
        return;
    }
    else if(ind == size - 2){
        insertAtEnd(val);
        return;
    }

    Node<T>* curr = head;
    Node<T>* temp = new Node<T>();
    temp -> value = val;

    for(int i = 0; i < ind; i++)
        curr = curr->next;

    temp->next = curr->next;
    temp->prev = curr;
    curr->next->prev = temp;
    curr->next = temp;
    size++;
}

template<typename T>
void circularLinkedList<T>::removeAtHead(){
    if(head == NULL){
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    head->prev = tail;
    delete temp;
    size--;
}

template<typename T>
void circularLinkedList<T>::removeAtEnd(){

    if(tail == NULL){
        return;
    }

    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = head;
    delete temp;
    size--;

}

template<typename T>
void circularLinkedList<T>::removeAt(const int& ind){
    if(ind >= size || ind < 0)
        return;
    
    if(ind == 0){
        removeAtHead();
        return;
    }

    if(ind == size - 1){
        removeAtEnd();
        return;
    }

    Node<T>* curr = head;
    for(int i = 0; i < ind; i++)
        curr = curr->next;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    size--;
}

template<typename T>
T circularLinkedList<T>::retriveAt(const int& ind) const{
    if(ind >= size || ind < 0)
        return T();
    Node<T>* curr = head;
    for(int i = 0; i < ind; i++)
        curr = curr -> next;
    return curr -> value;
}

template<typename T>
void circularLinkedList<T>::replaceAt(const int& ind, const T& val){
    if(ind >= size || ind < 0)
        return;
    Node<T>* curr = head;
    for(int i = 0; i < ind; i++)
        curr = curr -> next;
    curr -> value = val;
}

template<typename T>
bool circularLinkedList<T>::isExist(const T& val) const{
    Node<T>* curr = head;
    while(curr != NULL){
        if(curr -> value == val)
            return true;
        curr = curr -> next;
    }
    return false;
}

template<typename T>
bool circularLinkedList<T>::isItemAtEqual(const int& ind, const T& val) const{
    if(ind >= size || ind < 0)
        return false;
    Node<T>* curr = head;
    for(int i = 0; i < ind; i++)
        curr = curr -> next;
    return curr -> value == val;
}

template<typename T>
void circularLinkedList<T>::swapp(const int& ind1, const int& ind2){
    if(ind1 >= size || ind1 < 0 || ind2 >= size || ind2 < 0)
        return;
    Node<T>* curr1 = head;
    Node<T>* curr2 = head;
    for(int i = 0; i < ind1; i++)
        curr1 = curr1 -> next;
    for(int i = 0; i < ind2; i++)
        curr2 = curr2 -> next;
    swap(curr1->value, curr2->value);
}

template<typename T>
void circularLinkedList<T>::reverse(){
    Node<T>* curr1 = head;
    Node<T>* curr2 = tail;
    while (curr1 != curr2){
        swap(curr1->value, curr2->value);
        if(curr1->next == curr2)
            break;
        curr1 = curr1->next;
        curr2 = curr2->prev;
    }
}

template<typename T>
bool circularLinkedList<T>::isEmpty() const{
    return size == 0;
}

template<typename T>
int circularLinkedList<T>::circularLinkedListSize() const{
    return size;
}

template<typename T>
void circularLinkedList<T>::clear(){
    while(head != NULL){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template<typename T>
void circularLinkedList<T>::print() const{
    Node<T>* Curr = head;
    while (Curr != NULL){
        cout << Curr -> value << " ";
        Curr = Curr->next;
    }
    cout << endl;
}