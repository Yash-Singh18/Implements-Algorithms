#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    public:
    node(int data1,node* next1,node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }

    public:
    node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

node* arraytoll(vector<int>& arr){
    if(arr.size()==0) return nullptr;

    node* head= new node(arr[0]);
    node* mover=head;

    for(int i=1;i<arr.size();i++){
        mover->next= new node(arr[i],nullptr,mover);
        mover=mover->next;
    }

    return head;
}

node* insertatbegin(node* head,int value){
    if(head==nullptr){
        return new node(value);
    }


    head->prev=new node(value,head,nullptr);
    head=head->prev;

    return head;
}

node* dltstart(node*& head){
    if(head==nullptr) return nullptr;
    else if(head->next==nullptr){
        delete head;
        return nullptr;
    }


    head=head->next;
    delete head->prev;
    head->prev=nullptr;

    return head;
}

node* insertend(node* head,int value){
    if(head==nullptr){
        head=new node(value);
        return head;
    }

    node* temp=head;

    while(temp->next!=nullptr) temp=temp->next;
    temp->next=new node(value,nullptr,temp);
    return head;
}

node* dltend(node* head){
    if(head==nullptr) return head;
    else if(head->next==nullptr){
        delete head;
        return nullptr;
    }


    node* temp=head;

    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->prev->next=nullptr;
    delete temp;


    return head;
}

void printdll(node* head){
    node* temp=head;

    while(temp!=nullptr){
        cout<< temp->data << " <-->" ;
        temp=temp->next;
    }
    cout<< "NULL" << endl;
}


int main(){
    // creating a ll
    // array to ll
    vector<int> arr;
    int choice=1;
    
    while(1){
        cout<< "type 1 to create a newnode something else to stop:\n";
        cin>> choice;
        if(choice!=1) break;

        int temp;
        cout<< "Enter the node value:\n";
        cin>> temp;

        arr.push_back(temp);
    }

    node* head=arraytoll(arr);


    while(1){
        int choice;
        cout<<"0 - Insert a newnode at beginning\n1 - Delete start\n2 - Insert at end\n3 - Delete end\n4 - Insert at position\n9 - Print the dll\n";
        cin>> choice;
        
        switch(choice){
            case 0:
                int val;
                cout<< "Enter the value you want to insert:\n";
                cin>> val;
                head=insertatbegin(head,val);
                break;
            case 1:
                dltstart(head);
                break;
            case 2:
                int val;
                cout<< "Enter the value you want to insert:\n";
                cin>> val;
                insertend(head,val);
                break;
            case 3:
                dltend(head);
                break;
            case 4:
                int pos;
                cout<< "Enter the position you want to insert new node at:\n";
                cin>> pos;
                int val;
                cout<< "Enter the value you want to insert:\n";
                cin>> val;

                // insertpos(head,val,pos);
                break;
                
            case 9:
                printdll(head);
                break;
            default:
                return 0;
        }
    }
}