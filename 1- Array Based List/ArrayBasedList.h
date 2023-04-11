#include <bits\stdc++.h>
using namespace std;

template<typename T>
class ArrayBasedList{
    private:
        int max_size;
        int size;
        T* arr;

    public:
        ArrayBasedList();
        ArrayBasedList(const int& mx_size);
        void insert(const T& val);
        void insertAt(const T& val, const int& index);
        T retriveAt(const int& index) const;
        void removeAt(const int& index);
        void replaceAt(const T& val, const int& index);
        bool isItemAtEqual(const T& val, const int& index) const;
        bool isEmpty() const;
        bool isFull() const;
        int listSize() const;
        int maxListSize() const;
        void clear();
        void print() const;
};