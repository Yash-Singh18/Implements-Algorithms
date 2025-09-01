#include <bits/stdc++.h>
using namespace std;

struct node{
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
};


void printLL(node* head){
    node* temp=head;

    while(temp!=nullptr){
        cout<< temp->data << "-->";
        temp=temp->next;
    }

    cout<< "NULL";
}

void insertstart(node*& head){
    int val;
    cout<< "Enter value you want to insert:\n";
    cin>> val;
    node* newnode= new node(val,head,nullptr);

    if(head!=nullptr) head->prev=newnode;
    head=newnode;
}

void dltstart(node*& head){
    if(head==nullptr) return;
    else if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }

    node* temp=head;

    head=temp->next;
    head->prev=nullptr;
    delete temp;
}

void insertend(node*& head){
    node* temp=head;
    int val;
    cout<< "Enter value you want to insert:\n";
    cin>> val;

    
    node* newnode= new node(val,nullptr,nullptr);

    if(head==nullptr){
        head=newnode;
        return;
    }

    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
}

void dltend(node*& head){
    if(head==nullptr) return;
    if(head->next==nullptr){
        dltstart(head);
        return;
    }

    node* temp=head;

    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->prev->next=nullptr; 
    delete temp;
}

void insertpos(node*& head){
    int p;
    cout<< "Enter the position:\n";
    cin>> p;

    if(p==1){
        insertstart(head);
    }
    else{
        int val;
        cout<< "Enter value you want to insert\n";
        cin>> val;
        int cnt=1;
        node* newnode=new node(val,nullptr,nullptr);
        node* temp=head;
        while(temp!=nullptr){

              if(cnt==p){
                newnode->prev=temp->prev;
                newnode->next=temp;
                temp->prev->next=newnode;
                temp->prev=newnode;
                return;
            }
            temp=temp->next;
            cnt++;
        }
        // inserting at the end need to implemented
    }
}



void dltpos(node*& head){
    if(head==nullptr) return;

    int pos;
    cout<< "Enter position you want to dlt:\n";
    cin>> pos;

    if(pos==1){
        dltstart(head);
        return;
    }
    int cnt=1;

    node* temp=head;



    while(temp!=nullptr){
        if(cnt==pos){
            temp->prev->next=temp->next;
            if(temp->next!=nullptr)
                temp->next->prev=temp->prev;
            delete temp;
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

    if(val == head->data){
        int newval;
        cout << "Enter the value you want to insert:\n";
        cin >> newval;

        node* newnode = new node(newval, head,nullptr);
        head->prev=newnode;
        head = newnode;
        return;
    }

    int newval;
    cout<< "Enter the value you want to insert:\n";
    cin>> newval;


    while(temp!=nullptr && temp->next != nullptr && temp->next->data!=val){
        temp=temp->next;
    }

    node* newnode = new node(newval,nullptr,nullptr);
    if(temp!=nullptr){
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        temp->next->next->prev=newnode;
    }
}


void dltval(node*& head){
     if(head==nullptr) return;
     
    
     int val;
     cout<< "Enter the value:\n";
     cin>> val;
     
    if(head->data==val){
       node* temp=head;
       head=temp->next;
       head->prev=nullptr;
       delete temp;
       return;
    }
     node* temp=head;

     while(temp!=nullptr){

        if(temp->data==val){

            if(temp->next==nullptr) dltend(head);
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                return;
            }
        }
        temp=temp->next;
}
}


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
        node* newnode= new node(val,nullptr,nullptr);
        head=newnode;
        mover=head;

    for(int i=1;i<n;i++){
        int val;
        cin>> val;
        node* newnode1= new node(val,nullptr,mover);
        mover->next=newnode1;
        mover=mover->next;
    }
}



    while(true){
        cout<< "\n1.Insert a Value at the start\n2.Delete Start\n3.Insert at end\n4.Delete end\n5.Insert at position\n6.Delete at position\n7.Insert element before value x\n8.Delete node with value x\n9.Print the linked list\nAnything else to stop:\n";
        cin>> choice;
        switch(choice){
        case 1:
            insertstart(head);
            break;
        case 2:
            dltstart(head);
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
            dltval(head);
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