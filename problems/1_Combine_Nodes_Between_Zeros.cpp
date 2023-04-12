#include "../implementations/3- Doubly Linked List/doublyLinkedList.cpp"

void solve( doublyLinkedList<int>& ls ){

    int size = ls.doubleLinkedListSize(), i = 1, sum = 0;
    ls.removeAtHead();
    while (i < size){

        sum += ls.retriveAt(0);
        i++;
        if(ls.retriveAt(0) == 0){
            ls.insertAtTail(sum);
            sum = 0;
        }
        ls.removeAtHead();
    }

}

int main(){
    doublyLinkedList<int> ls;

    // first test [0, 3, 1, 0, 4, 5, 2, 0]
    cout << "first test's ";
    ls.insertAtTail(0);
    ls.insertAtTail(3);
    ls.insertAtTail(1);
    ls.insertAtTail(0);
    ls.insertAtTail(4);
    ls.insertAtTail(5);
    ls.insertAtTail(2);
    ls.insertAtTail(0);
    cout << "list before solve : ";
    ls.forwardTraversal();


    solve(ls);
    cout << "list after solve : ";
    ls.forwardTraversal();
    

    ls.clear();


    // second test [0, 1, 0, 3, 0, 2, 2, 0]
    cout << "second test's ";
    ls.insertAtTail(0);
    ls.insertAtTail(1);
    ls.insertAtTail(0);
    ls.insertAtTail(3);
    ls.insertAtTail(0);
    ls.insertAtTail(2);
    ls.insertAtTail(2);
    ls.insertAtTail(0);
    cout << "list before solve : ";
    ls.forwardTraversal();


    solve(ls);
    cout << "list after solve : ";
    ls.forwardTraversal();
}