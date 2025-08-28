#include <bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;

    public:
    node(int data1,node* next1){
        data=data1;
        next=next1;
    }
};


void printLL(node* head){
    node* temp=head;

    while(temp!=nullptr){
        cout<< temp->data << "-->";
        temp=temp->next;
    }

    cout<< "NULL";
}

node* insertstart(node* head){
    int val;
    cout<< "Enter value you want to insert:\n";
    cin>> val;

    node* newnode= new node(val,head);

    head=newnode;

    return head;
}

node* dltstart(node* head){
    if(head==nullptr) return nullptr;

    node* temp=head;

    head=head->next;
    delete temp;

    return head;
}

void insertend(node*& head){
    node* temp=head;
    int val;
    cout<< "Enter value you want to insert:\n";
    cin>> val;

    
    node* newnode= new node(val,nullptr);

    if(head==nullptr){
        head=newnode;
        return;
    }

    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}

void dltend(node*& head){
    if(head==nullptr) return;
    else if(head->next==nullptr){
        head=dltstart(head);
        return;
    }

    node* temp=head;

    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    free(temp->next);
    temp->next=nullptr;
}

void insertpos(node*& head){
    int p;
    cout<< "Enter the position:\n";
    cin>> p;

    if(p==1){
        head=insertstart(head);
    }
    else{
        int val;
        cout<< "Enter value you want to insert\n";
        cin>> val;
        int cnt=1;
        node* newnode=new node(val,nullptr);
        node* temp=head;
        while(temp!=nullptr){

              if(cnt==p-1){
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
            temp=temp->next;
            cnt++;
        }
    }
}



void dltpos(node*& head){
    if(head==nullptr) return;

    int pos;
    cout<< "Enter position you want to dlt:\n";
    cin>> pos;

    if(pos==1){
        head = dltstart(head);
        return;
    }
    int cnt=1;

    node* temp=head;



    while(temp!=nullptr){
        if(cnt==pos-1){
            node* store = temp->next;
            temp->next=temp->next->next;    
            delete store;
            return;
        }
        temp=temp->next;
        cnt++;
    }
}

void insertbeforeval(node*& head){
    node* temp=head;


    int val;
    cout<< "Enter the value\n";
    cin>> val;

    if(val==head->data){
       head = insertstart(head);
       return;
    }

    int newval;
    cout<< "Enter the value you want to insert:\n";
    cin>> newval;


    while(temp!=nullptr && temp->next != nullptr && temp->next->data!=val){
        temp=temp->next;
    }

    node* newnode = new node(newval,nullptr);
    if(temp!=nullptr){
        newnode->next=temp->next;
        temp->next=newnode;
    }
}


// void dltbeforeval(node* head){
// - yet to be implemented
// }


int main(){
    node* head=nullptr;
    node* mover=nullptr;
    int choice;
    int n;

    cout<< "Enter number of elements you want to initialize LL with:"<< endl;
    cin>> n;

    if(n>0){
    cout<< "Enter the vals:\n";
        int val;
        cin>> val;
        node* newnode= new node(val,nullptr);
        head=newnode;
        mover=head;

    for(int i=1;i<n;i++){
        int val;
        cin>> val;
        node* newnode1= new node(val,nullptr);
        mover->next=newnode1;
        mover=mover->next;
    }
}



    while(true){
        cout<< "\n1.Insert a Value at the start\n2.Delete Start\n3.Insert at end\n4.Delete end\n5.Insert at position\n6.Delete at position\n7.Insert element before value x\n8.\n9.Print the linked list\nAnything else to stop:\n";
        cin>> choice;
        switch(choice){
        case 1:
            head = insertstart(head);
            break;
        case 2:
            head=dltstart(head);
            break;
        case 3:
            insertend(head);
            break;
        case 4:
            dltend(head);
            break;
        case 5:
            insertpos(head);
            break;
        case 6:
            dltpos(head);
            break;
        case 7:
            insertbeforeval(head);
            break;
        case 8:
            break;
        case 9:
            printLL(head);
            break;
        default:
            return 0;
        }
    }
    return 0;
}