#include "Queue.cpp"

int main(){
    Queue<string> q;
    q.enqueue("Ahmed");
    q.enqueue("taha");
    q.enqueue("ismail");
    q.enqueue("magdy");
    q.enqueue("adham");
    q.enqueue("tarek");
    q.print();
    cout << "First: " << q.first() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "First: " << q.first() << endl;
    cout << "isEmpty: " << q.isEmpty() << endl;
}