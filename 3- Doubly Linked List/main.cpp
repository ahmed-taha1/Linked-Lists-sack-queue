#include "doublyLinkedList.cpp"

int main(){
    doublyLinkedList<string> list;
    list.insertAtHead("hello");
    list.insertAtHead("world");
    list.insertAtHead("!");
    list.insertAtTail("hello");
    list.insertAtTail("world");
    list.forwardTraversal();
    cout << "insertion \n";
    list.insertAt(2, "ahmed");
    list.forwardTraversal();
    list.insertAfter(1, "taha");
    list.forwardTraversal();
    list.reverse();
    list.forwardTraversal();
}