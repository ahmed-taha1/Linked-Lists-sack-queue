#include "ArrayBasedList.cpp"

int main(){
    ArrayBasedList<string> list(5);
    list.insert("hello");
    list.insert("world");
    list.print();
}