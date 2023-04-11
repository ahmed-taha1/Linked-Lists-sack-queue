#include "Stack.cpp"

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    cout << s.pop() << endl;
    s.print();
    cout << s.top() << endl;
    s.print();
    cout << s.isEmpty() << endl;
}