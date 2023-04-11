#include "ArrayBasedList.cpp"
int main(){
    ArrayBasedList<string> list(5);
    list.insert("hello");
    list.insert("world");
    list.insertAt("ahmed", 1);
    list.insertAt("taha", 2);
    list.insertAt("al", 0);

    list.print();
}