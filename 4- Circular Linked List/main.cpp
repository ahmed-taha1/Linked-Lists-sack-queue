#include "circularLinkedList.cpp"

int main(){
    circularLinkedList<string> list;
    list.insertAtHead("hello");
    list.insertAtHead("world");
    list.insertAtHead("!");
    list.insertAtEnd("hello");
    list.insertAtEnd("world");
    list.print();
    cout << "insertion \n";
    list.insertAt(2, "ahmed");
    list.print();
    list.insertAfter(1, "taha");
    list.print();
    list.reverse();
    list.print();
}