//
//  main.cpp
//  DS Assignment 2
//
//  Created by Kanishka Mishra on 2/16/21.
//

#include <iostream>
#include <stdlib.h>

using namespace std;


class Node{
public:
    int data;
    Node *next;
};

class List:public Node{
public:
    Node *head, *temp;
    List(){
    head=NULL;
    temp=NULL;
    }
    void create();
    void display();
    void insert_start();
    void insert_pos();
    void insert_end();
    void delete_start();
    void delete_end();
    void delete_pos();
    void reverse();
    int count();
    friend void concatenate(List l1,List l2);
};

int List::count(){
    int n=0;
    Node *temp;
    temp=head;
    if(head==NULL){
        return 0;
    }
    while(temp->next!=head){
        n++;
        temp=temp->next;
    }
    return n;
}

void List::create(){
    int num,elm;
    cout<<"Enter number of Nodes: ";
    cin>>num;
    for(int i=0;i<num;i++){
        Node *new_node = new Node;
        cout<<"Enter Element: ";
        cin>>elm;
        new_node->data=elm;
        new_node->next=NULL;
        if(head==NULL){
            head=new_node;
            temp=new_node;
            new_node->next=head;
        }
        else{
            temp->next=new_node;
            temp=temp->next;    //traversing statement
            new_node->next=head;
        }
    }
}

void List::display(){
    temp=head;
    //cout<<"Head: "temp->data;
    if(head==NULL){
        cout<<"List is empty!"<<endl;
    }
    else{
        cout<<"---Since This is a Circular List, last node also points the value of first node.---"<<endl;
        cout<<"List1 : ";
        while(temp->next!=head){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<temp->data<<" -> ";
        cout<<temp->next->data;
    }
    cout<<endl;
}

void List::insert_start(){
    int num;
    Node *new_node = new Node;
    cout<<"Enter the value: ";
    cin>>num;
    new_node->data=num;
    new_node->next=head;
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_node;
    head=new_node;
}

void List:: insert_end(){
    int num;
    Node *new_node = new Node;
    //Node *temp;
    temp = head;
    cout<<"Enter the value: ";
    cin>>num;
    new_node->data=num;
    new_node->next=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_node;
}


void List::insert_pos(){
    int position,num;
    Node *new_node = new Node;
    //Node *temp;
    cout<<"Enter the position: ";
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
        new_node->next=temp->next;
        temp->next=new_node;
    }
}
    
//circular

void List::delete_start(){
    Node *temp,*q;
    temp=head;
    q=head;
    if(head==NULL){
        cout<<"List is Empty!"<<endl;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        delete(q);
        cout<<"\nNode deleted"<<endl;
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
    else if(temp->next==head){
        head=NULL;
        delete(temp);
        cout<<"\nNode deleted"<<endl;
        cout<<"List1 :";
        display();
    }
    else{
        while(temp->next->next!=head){
            temp=temp->next;
        }
        end=temp->next;         //points towards the end node
        temp->next=head;
        delete(end);
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
        //cout<<"\nNode deleted";
        display();
    }
    else{
        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }
        del=temp->next;
        temp->next=del->next;   //OR temp->next=temp->next->next
        delete(del);
        cout<<"\nNode deleted"<<endl;
        display();
    }
}

void List::reverse(){
    Node *forward,*curr,*back;
    temp=head;
    forward=head;
    curr=NULL;
    if(head==NULL){
        cout<<"List is empty!"<<endl;
    }
    else{
    while(temp->next!=head){
        temp=temp->next;
    }
    curr=temp;
    while(forward->next!=head){
        back=curr;
        curr=forward;
        forward=forward->next;
        curr->next=back;
    }
    back=curr;
    curr=forward;
    forward=forward->next;
    curr->next=back;
    head=curr;
    cout<<"\n";
    display();
    }
}

//delete a node depending upon the given data value by the user.
//insert a node depending upon the data given by the user.

void concatenate(List l1,List l2){
    Node *temp;
    temp=l1.head;
    while(temp->next!=l1.head){
        temp=temp->next;
    }
    temp->next=l2.head;
    Node *temp2;
    temp2=l2.head;
    while(temp2->next!=l2.head){
        temp2=temp2->next;
    }
    temp2->next=l1.head;
}


int main(){
    int num,ans,ins,ans1;
    List l1,l2;
    do{
        cout<<" Enter 1 to Create \n Enter 2 to Insert element \n Enter 3 to Delete element \n Enter 4 to Reverse the list \n Enter 5 to Display the List \n Enter 6 to Concatenate \n Enter 7 to Exit.\n";
        cin>>num;
        switch(num){
            case 1:
                l1.create();
                break;
            case 2:
                do{
                    cout<<"\n\t Enter 1 to Insert at Front \n\t Enter 2 to insert at a position \n\t Enter 3 to insert at the end \n";
                    cin>>ins;
                    switch(ins){
                        case 1:
                            l1.insert_start();
                            l1.display();
                            break;
                        case 2:
                            l1.insert_pos();
                            l1.display();
                            break;
                        case 3:
                            l1.insert_end();
                            l1.display();
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
                    cout<<"\n\t Enter 1 to delete at Front \n\t Enter 2 to delete at a position \n\t Enter 3 to delete at the end \n";
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
                cout<<"Create List 2: \n";
                l2.create();
                concatenate(l1, l2);
                l1.display();
                break;
            case 7:
                exit(1);
            default:
                cout<<"Invalid Choice!";
                }
        cout<<"Run Again 1:YES 0:NO \n";
        cin>>ans;
        }while(ans==1);
    return 0;
}
