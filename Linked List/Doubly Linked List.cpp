//
//  main.cpp
//  DS Doubly linked list
//
//  Created by Kanishka Mishra on 2/23/21.
//

#include <iostream>

using namespace std;


class Node{
public:
    int data;
    Node *prev,*next;
};

class List:public Node{
public:
    Node *head,*temp;       //only used as a pointer no memory allocation
    List(){
        head=NULL;
        temp=NULL;
    }
    void create();
    void display();
    void insert_start();
    void insert_end();
    void insert_pos();
    void delete_start();
    void delete_end();
    void delete_pos();
    void reverse();
    int count();
    friend void concatenate(List l1,List l2);
};

void List::create(){
    int num,elm;
    cout<<"\nEnter number of Nodes: ";
    cin>>num;
    for(int i=0;i<num;i++){
        Node *new_node = new Node;      //memory gets allocated to new_node
        cout<<"Enter Element: ";
        cin>>elm;
        new_node->data=elm;
        new_node->next=NULL;
        new_node->prev=NULL;
         
        if(head==NULL){
            head=new_node;
            temp=new_node;
        }
        else{
            temp->next=new_node;
            new_node->prev=temp;
            temp=temp->next;    //traversing statement
        }
    }
}

int List::count(){
    int n=0;
    Node *temp;
    temp=head;
    while(temp){
        n++;
        temp=temp->next;
    }
    return n;
}

void List::display(){
    temp=head;
    //cout<<"Head: "temp->data;
    if(head==NULL){
        cout<<"List is empty!"<<endl;
    }
    else{
        cout<<"List 1: ";
        while(temp!=NULL){
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void List::insert_start(){
    int num;
    Node *new_node = new Node;
    cout<<"Enter the value: ";
    cin>>num;
    new_node->data=num;
    new_node->prev=NULL;
    new_node->next=head;       //can't interchange statements
    head->prev=new_node;
    head=new_node;
    display();
}

void List::insert_end(){
    int num;
    Node *new_node = new Node;
    Node *temp;
    temp = head;
    cout<<"Enter the value: ";
    cin>>num;
    new_node->data=num;
    new_node->next=NULL;
    while(temp->next!=NULL){    //points to the last node
        temp=temp->next;
    }
    new_node->prev=temp;
    temp->next=new_node;
    display();
}

void List::insert_pos(){
    int position,num;
    Node *new_node = new Node;
    Node *temp;
    cout<<"\nEnter the position: ";
    cin>>position;
    if((position<=0) || (position > count())){
        cout<<"Position invalid"<<endl;
    }
    else{
        cout<<"\n Enter the value: ";
        cin>>num;
        new_node->data=num;
        new_node->next=NULL;
        temp=head;
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
        new_node->next=temp->next;      //can't inter change statements
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next->prev=new_node;
        display();
    }
}

void List::delete_start(){
    Node *temp;
    temp=head;
    if(head==NULL){
        cout<<"List is Empty!"<<endl;
    }
    else{
        head=head->next;
        head->prev=NULL;
        delete(temp);
        cout<<"Node Deleted! "<<endl;
        //temp=head;
        display();
    }
}

void List::delete_end(){
    Node *end;
    Node *temp;
    temp=head;
    if(head==NULL){
        cout<<"List is Empty!"<<endl;
    }
    else if(temp->next==NULL){
        head=NULL;
        delete(temp);
        cout<<"\nNode deleted"<<endl;
        display();
    }
    else{
        while(temp->next->next!=NULL){  //points to the last 2nd node
            temp=temp->next;
        }
        end=temp->next;         //points towards the end node
        temp->next=NULL;
        delete(end);
        cout<<"Node Deleted! "<<endl;
        display();
    }
}

void List::delete_pos(){
    Node *del,*q;
    Node *temp;
    int n;
    temp=head;
    if(head==NULL){
        cout<<"List is Empty!"<<endl;
    }
    cout<<"\nEnter the position of node you want to delete: ";
    cin>>n;
    if((n<=0) || (n > count()))
    {
        cout<<"\nInvalid position"<<endl;
    }
    else if(n==1)
    {
        q=head;
        head=head->next;
        delete(q);
        cout<<"Node Deleted! "<<endl;
        //cout<<"\nNode deleted";
        display();
    }
    else if(n==count()){
        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }
        del=temp->next;
        temp->next=NULL;
        delete(del);
        cout<<"Node Deleted! "<<endl;
        display();
        
    }
    else{
        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }
        del=temp->next;
        temp->next=del->next;   //OR temp->next=temp->next->next
        del->next->prev=temp;
        delete(del);
        cout<<"Node Deleted! "<<endl;
        display();
    }
}

void List::reverse(){
    Node *forward,*curr,*back;
    forward=head;
    curr=NULL;
    while(forward!=NULL){
        back=curr;
        curr=forward;
        forward=forward->next;
        curr->next=back;
        curr->prev=forward;
    }
    head=curr;
    cout<<"\n";
    display();
}

void concatenate(List l1,List l2){
    Node *temp;
    temp=l1.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l2.head;
    l2.head->prev=temp;
}


int main(){
    int num,ans,ins,ans1;
    List l1,l2;
    do{
        cout<<"\n Enter 1 to Create List \n Enter 2 to Insert element \n Enter 3 to Delete element \n Enter 4 to Reverse the list \n Enter 5 to Display the List \n Enter 6 to concatenate. \n Enter 7 to exit.\n";
        cin>>num;
        switch(num){
            case 1:
                l1.create();
                l1.display();
                break;
            case 2:
                do{
                    cout<<"\n\t Enter 1 to Insert at Front \n\t Enter 2 to insert at a Position \n\t Enter 3 to insert at the end\n";
                    cin>>ins;
                    switch(ins){
                        case 1:
                            l1.insert_start();
                            break;
                        case 2:
                            l1.insert_pos();
                            break;
                        case 3:
                            l1.insert_end();
                            break;
                        default:
                            cout<<"Invalid Choice!\n"<<endl;
                    }
                    cout<<"\tRun Insert loop Again 1:YES 0:NO \n";
                    cin>>ans1;
                    }while(ans1==1);
                    break;
            case 3:
                do{
                    cout<<"\n\t Enter 1 to delete at Front \n\t Enter 2 to delete at a Position \n\t Enter 3 to delete at the end \n\n";
                    cin>>ins;
                    switch(ins){
                        case 1:
                            l1.delete_start();
                            break;
                        case 2:
                            l1.delete_pos();
                            break;
                        case 3:
                            l1.delete_end();
                            break;
                        default:
                            cout<<"Invalid Choice!\n"<<endl;
                    }
                    cout<<"\tRun Delete loop Again 1:YES 0:NO \n";
                    cin>>ans1;
                    }while(ans1==1);
                    break;
            case 4:
                l1.reverse();
                break;
            case 5:
                l1.display();
                break;
            case 6:
                cout<<"\n---Create LIST 2 ----\n";
                l2.create();
                concatenate(l1,l2);
                cout<<"\nConcatenated list: ";
                l1.display();
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid Choice!\n";
                }
        cout<<"\nRun Again 1:YES 0:NO --- ";
        cin>>ans;
        }while(ans==1);
    return 0;
}
