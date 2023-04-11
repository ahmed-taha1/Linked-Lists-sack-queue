#include "ArrayBasedList.h"

template<typename T>
ArrayBasedList<T>::ArrayBasedList(){
    max_size = 100;
    size = 0;
    arr = new T[max_size];
}


template<typename T>
ArrayBasedList<T>::ArrayBasedList(const int& mx_size){
    max_size = mx_size;
    size = 0;
    arr = new T[max_size];
}

template<typename T>
void ArrayBasedList<T>::insert(const T& val){
    if(isFull()){
        cout << "List is full" << endl;
        return;
    }
    arr[size++] = val;
}

template<typename T>
void ArrayBasedList<T>::insertAt(const T& val, const int& index){
    if(isFull()){
        cout << "List is full" << endl;
        return;
    }
    if(index < 0 || index > size){
        cout << "Index out of range" << endl;
        return;
    }
    for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = val;
    size++;
}

template<typename T>
T ArrayBasedList<T>::retriveAt(const int& index) const{
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return -1;
    }
    return arr[index];
}

template<typename T>
void ArrayBasedList<T>::removeAt(const int& index){
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return;
    }
    for(int i = index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

template<typename T>
void ArrayBasedList<T>::replaceAt(const T& val, const int& index){
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return;
    }
    arr[index] = val;
}

template<typename T>
bool ArrayBasedList<T>::isItemAtEqual(const T& val, const int& index) const{
    if(index < 0 || index >= size){
        cout << "Index out of range" << endl;
        return false;
    }
    return arr[index] == val;
}

template<typename T>
bool ArrayBasedList<T>::isEmpty() const{
    return size == 0;
}

template<typename T>
bool ArrayBasedList<T>::isFull() const{
    return size == max_size;
}

template<typename T>
int ArrayBasedList<T>::listSize() const{
    return size;
}

template<typename T>
int ArrayBasedList<T>::maxListSize() const{
    return max_size;
}

template<typename T>
void ArrayBasedList<T>::clear(){
    size = 0;
}

template<typename T>
void ArrayBasedList<T>::print() const{
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}