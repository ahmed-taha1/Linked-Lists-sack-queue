#include <iostream>
#include <queue>
using namespace std;

template<typename T>
void printQueue(std::queue<T> q){
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

template<typename T>
T findMinElement(std::queue<T> q){
    T mn = q.front();
    while (!q.empty()){
        mn = min(mn,q.front());
        q.pop();
    }
    return mn;
}

template<typename T>
void removeMinElement(std::queue<T>& q,const T& minElement){
    int i = 0 ;
    queue<T> temp = q;
    int size = q.size();
    while (!temp.empty()){
        if(temp.front() == minElement){
           break;
       }
        temp.pop();
        i++;
    }
    for (int j = 0; j <= size-1; ++j) {
        if(j != i)
            q.push(q.front());
        q.pop();
    }
}
template<typename T>
void sortQueue(std::queue<T>& q){
    queue<T>sortedQueue ;
    int size = q.size();
    while (sortedQueue.size() < size){
        T min = findMinElement(q);
        sortedQueue.push(min);
        removeMinElement(q,min);
    }
    q = sortedQueue;
}
int main() {
    queue<int>q;
    q.push(3);
    q.push(15);
    q.push(2);
    q.push(4);
    cout<<"BEFORE SORTING:\n";
    printQueue(q);
    cout<<"\n===================================\n";
    sortQueue(q);
    cout<<"AFTER SORTING:\n";
    printQueue(q);
    cout<<"\n===================================\n";

    queue<int>q2;
    q2.push(9);
    q2.push(1);
    q2.push(2);
    q2.push(1);

    cout<<"BEFORE SORTING:\n";
    printQueue(q2);
    cout<<"\n===================================\n";
    sortQueue(q2);
    cout<<"AFTER SORTING:\n";
    printQueue(q2);
    cout<<"\n===================================\n";

}
