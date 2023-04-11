#include "SingleLinkedList.h"

template<typename T>
SingleLinkedList<T>::SingleLinkedList(){
    head = nullptr;
    size = 0;
}

template<typename T>
void SingleLinkedList<T>::insertAtHead(const T& val){
    node* temp = new node;
    temp->val = val;
    temp->next = head;
    head = temp;
    size++;
}

template<typename T>
void SingleLinkedList<T>::insertAtTail(const T& val){
    node* temp = new node;
    temp->val = val;
    temp->next = nullptr;
    if(head == nullptr){
        head = temp;
    }
    else{
        node* temp2 = head;
        while(temp2->next != nullptr){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    size++;
}

template<typename T>
void SingleLinkedList<T>::insertAt(const T& val, const int& index){
    if(index < 0 || index > size){
        cout << "Index out of range" << endl;
        return;
    }
    if(index == 0){
        insertAtHead(val);
    }
    else if(index == size){
        insertAtTail(val);
    }
    else{
        node* temp = new node;
        temp->val = val;
        node* temp2 = head;
        for(int i = 0; i < index - 1; i++){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
        size++;
    }
}

template<typename T>
void SingleLinkedList<T>::removeAtHead(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<typename T>
void SingleLinkedList<T>::removeAtTail(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        size--;
        return;
    }
    node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    size--;
}

template<typename T>
void SingleLinkedList<T>::removeAt(const int& index){
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return;
    }
    if(index == 0){
        removeAtHead();
    }
    else if(index == size - 1){
        removeAtTail();
    }
    else{
        node* temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        size--;
    }
}

template<typename T>
void SingleLinkedList<T>::replaceAt(const T& val, const int& index){
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return;
    }
    node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    temp->val = val;
}

template<typename T>
bool SingleLinkedList<T>::isExist(const T& val) const{
    node* temp = head;
    while(temp != nullptr){
        if(temp->val == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<typename T>
bool SingleLinkedList<T>::isItemAtEqual(const T& val, const int& index) const{
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return false;
    }
    node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->val == val;
}

template<typename T>
void SingleLinkedList<T>::swapp(const int& index1, const int& index2){
    if(index1 < 0 || index1 >= size || index2 < 0 || index2 >= size){
        cout << "Index out of range" << endl;
        cout << "index1: " << index1 << " index2: " << index2 << endl;
        return;
    }
    node* temp1 = head;
    for(int i = 0; i < index1; i++){
        temp1 = temp1->next;
    }
    node* temp2 = head;
    for(int i = 0; i < index2; i++){
        temp2 = temp2->next;
    }

    swap(temp1->val, temp2->val);
}

template<typename T>
void SingleLinkedList<T>::clear(){
    while(head != nullptr){
        removeAtHead();
    }
}

template<typename T>
void SingleLinkedList<T>::print() const{
    node* temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
