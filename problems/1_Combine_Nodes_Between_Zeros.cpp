/*this program merges numbers between zeros and add it and remove the zeros*/
// made by : ahmed mohamed taha
// id : 20210033

#include <bits\stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(){
        val = 0;
        next = nullptr;
    }
};

void print_ls(node* n){
    if(n == nullptr)
        return;

    cout << n->val << " ";
    print_ls(n->next);
}

void solve(node*& head){
    int size = 1, i = 1, sum = 0;
    node* curr = head;

    while (curr -> next != nullptr){
        curr = curr -> next;
        size++;
    }
    
    node* tempp = head;
    head = head -> next;
    delete tempp;

    while (i < size){

        sum += head -> val;
        i++;
        if(head -> val == 0){
            node* temppp = new node();
            temppp -> val = sum;
            curr -> next = temppp;
            curr = curr -> next;
            sum = 0;
        }

        node* temp = head;
        head = head -> next;
        delete temp;
    }
}


/* tests */
// 0 3 1 0 4 5 2 0
// 0 1 0 3 0 2 2 0

int main(){
    node* head = nullptr;
    node* curr = nullptr;
    int n;
    cout << "please enter # of values : ";   cin >> n;
    while (n--){
        int num;    cout << "please enter number : "; cin >> num;
        node* temp = new node();
        temp->val = num;
        if(head == nullptr){
            head = temp;
            curr = head;
            continue;
        }
        curr->next = temp;
        curr = curr -> next;
    }
    
    cout << "values before solve : ";
    print_ls(head);
    
    solve(head);
    cout << head->val;
    cout << "\nlist after solve : ";
    print_ls(head);

}