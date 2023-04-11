#include "SingleLinkedList.cpp"

int main(){
    SingleLinkedList<int> list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtHead(4);
    list.insertAtHead(5);
    list.print();
    list.insertAtTail(6);
    list.print();
    list.insertAt(7, 3);
    list.print();
    list.removeAtHead();
    list.print();
    list.removeAtTail();
    list.print();
    list.removeAt(3);
    list.print();
    list.swapp(0, 3);
    list.print();
}