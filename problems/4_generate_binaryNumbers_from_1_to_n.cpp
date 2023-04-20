#include <bits/stdc++.h>
using namespace std;
void genBinaryNumbers(int n){
    queue<string> qu;
    qu.push("1");
    while(n != 0){
        string s1 = qu.front();
        qu.pop();
        cout << s1 << " ";
        string s2 = s1;
        qu.push(s1 + "0");
        qu.push(s1 + "1");
        n--;
    }
}
int main() {
    cout<<"enter a number:";
    int n;
    cin>>n;
    genBinaryNumbers(n);
}