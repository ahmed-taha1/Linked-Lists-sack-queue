#include "ArrayBasedList.cpp"

int main(){
    ArrayBasedList<int> list(5);
    list.insert(1);
    list.insert(2);
    list.print();
}