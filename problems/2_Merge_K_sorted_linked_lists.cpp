// this program is made to merge k sorted linked lists
// made by : ahmed mohamed taha
// id : 20210033

// input format : 
// at the first line the program will ask you to enter k which is the number of nodes
// next line will be n which is the number of numbers in the first node
// next n lines will be the values that you want to insert in the first node
// and repeat till inserting all nodes
// ****values must be sorted in the nodes****

// output format :
// one line conatin sorted values from the all nodes

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;

    node(){
        val = 0;
        next = nullptr;
    }
};

// print list function
void prt_ls(node* head);

// check if the arr of nodes is empty or not
bool is_not_empty(node** arr,int k);

// merge lists function
node* merge_lists(node ** t_arr, int k);


int main(){
    int k;
    cout << "please enter # of nodes : ";   cin >> k;
    node** arr = new node*[k];
    for(int i = 0; i < k; i++){
        int n;
        cout << "please enter # of elements for node numder " << i + 1<< " : ";    cin >> n;
        node* curr = arr[i];
        for(int j = 0; j < n; j++){
            int num;
            cout << "please enter number : ";   cin >> num;
            node* temp = new node();
            temp -> val = num;
            if(!j){
                curr = arr[i] = temp;
                continue;
            }
            curr -> next = temp;
            curr = curr->next;
        }
    }

    cout << "\nthe answer is : ";
    node* ans = merge_lists(arr, k);
    prt_ls(ans);
}




void prt_ls(node* head){
    if(head == nullptr)
        return;
    cout << head->val << ' ';
    prt_ls(head->next);
}



bool is_not_empty(node** arr,int k){
    for(int i = 0; i < k; i++){
        if(arr[i] != nullptr)
            return 1;
    }
    return 0;
}



node* merge_lists(node** arr, int k){
    node* ans = nullptr;
    node* curr = nullptr;
    int taken = 0, min = 1e8;

    while (is_not_empty(arr, k)){

        for(int i = 0; i < k; i++){
            if(arr[i] != nullptr && arr[i]->val < min){
                min = arr[i]->val;
                taken = i;
            }
        }

        node* added = new node();
        added -> val = arr[taken]->val;
        min = 1e8;

        if(ans == nullptr){
            ans = curr = added;

            node* del = arr[taken];
            arr[taken] = arr[taken]->next;
            delete del;
            continue;
        }
        
        curr -> next = added;
        curr = curr -> next;

        node* del = arr[taken];
        arr[taken] = arr[taken]->next;
        delete del;
    }    
    return ans;
}