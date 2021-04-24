//
//  main.cpp
//  DS Assignment 1
//
//  Created by Kanishka Mishra on 2/9/21.
//

#include <iostream>
#include <stdlib.h>

using namespace std;


class Node{
public:
    int data;
    Node *next;     //self-referencing pointer: that points to whatever it is a part of
};

class List:public Node{
    Node *head1, *temp1;
public:
    List(){
    head1=NULL;
    temp1=NULL;
    }
    int count();
    void create1();
    void display();
    void insert_start();
    void insert_pos();
    void insert_end();
    void delete_start();
    void delete_end();
    void delete_pos();
    void reverse();
    void concatenate(List l1);
};

void List::create1(){
    int num,elm;
    Node *temp1=NULL;
    cout<<"\nEnter number of Nodes: ";
    cin>>num;
    for(int i=0;i<num;i++){
        Node *new_node = new Node;
        cout<<"Enter Element: ";
        cin>>elm;
        new_node->data=elm;
        new_node->next=NULL;
        if(head1==NULL){
            head1=new_node;
            temp1=new_node;
        }
        else{
            temp1->next=new_node;
            temp1=temp1->next;    //traversing statement
        }
    }
}

int List::count(){
    int n=0;
    Node *temp;
    temp=head1;
    while(temp){
        n++;
        temp=temp->next;
    }
    return n;
}

void List::display(){
    temp1=head1;
    //cout<<"Head: "temp->data;
    if(head1==NULL){
        cout<<"List is empty!"<<endl;
    }
    else{
        while(temp1!=NULL){
            cout<<temp1->data<<" -> ";
            temp1=temp1->next;
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
    new_node->next=head1;       //can't interchange statements
    head1=new_node;
    
}

void List:: insert_end(){
    int num;
    Node *new_node = new Node;
    Node *temp;
    temp = head1;
    cout<<"Enter the value: ";
    cin>>num;
    new_node->data=num;
    new_node->next=NULL;
    while(temp->next!=NULL){    //points to the last node
        temp=temp->next;
    }
    temp->next=new_node;
}

void List::insert_pos(){
    int position,num;
    cout<<"\nEnter the position: ";
    cin>>position;
    if((position<=0) || (position > count())){
        cout<<"Position invalid"<<endl;
    }
    else{
            Node *new_node = new Node;
            Node *temp;
            cout<<"\n Enter the value: ";
            cin>>num;
            new_node->data=num;
            new_node->next=NULL;
            temp=head1;
            for(int i=0;i<position-2;i++){
                temp=temp->next;
            }
            new_node->next=temp->next;      //can't inter change statements
            temp->next=new_node;
    }
}
    
void List::delete_start(){
    Node *temp;
    temp=head1;
    if(head1==NULL){
        cout<<"List is Empty!"<<endl;
    }
    else{
        head1=head1->next;
        delete(temp);
    //temp=head;
        cout<<"\nNode deleted"<<endl;
        cout<<"List1 :";
        display();
    }
}

void List::delete_end(){
    Node *end;
    Node *temp;
    temp=head1;
    if(head1==NULL){
        cout<<"List is Empty!"<<endl;
    }
    else if(temp->next==NULL){
        head1=NULL;
        delete(temp);
        cout<<"\nNode deleted"<<endl;
        cout<<"List1 :";
        display();
    }
    else{
        while(temp->next->next!=NULL){  //points to the last 2nd node
            temp=temp->next;
        }
        end=temp->next;         //points towards the end node
        temp->next=NULL;
        delete(end);
        cout<<"\nNode deleted"<<endl;
        cout<<"List1 : ";
        display();
    }
}

void List::delete_pos(){
    Node *del,*q;
    Node *temp;
    int n;
    temp=head1;
    if(head1==NULL){
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
        q=head1;
        head1=head1->next;
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
        cout<<"List1 : ";
        display();
    }
}

void List::reverse(){
    Node *forward,*curr,*back;
    forward=head1;
    curr=NULL;
    while(forward!=NULL){
        back=curr;
        curr=forward;
        forward=forward->next;
        curr->next=back;
    }
    head1=curr;
    cout<<"\n";
    display();
}

//delete a node depending upon the given data value by the user.
//insert a node depending upon the data given by the user.

void List::concatenate(List l1){
    Node *temp;
    temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l1.head1;
}


int main(){
    int num,ans,ins,ans1;
    List l1,l2;
    do{
        cout<<"\n Enter 1 to Create List \n Enter 2 to Insert element \n Enter 3 to Delete element \n Enter 4 to Reverse the list \n Enter 5 to Display the List \n Enter 6 to concatenate. \n Enter 7 to exit.\n";
        cin>>num;
        switch(num){
            case 1:
                l1.create1();
                cout<<"List 1: ";
                l1.display();
                break;
            case 2:
                do{
                    cout<<"\n\t Enter 1 to Insert at Front \n\t Enter 2 to insert at a Position \n\t Enter 3 to insert at the end\n";
                    cin>>ins;
                    switch(ins){
                        case 1:
                            l1.insert_start();
                            cout<<"List1 :";
                            l1.display();
                            break;
                        case 2:
                            l1.insert_pos();
                            cout<<"List1 :";
                            l1.display();
                            break;
                        case 3:
                            l1.insert_end();
                            cout<<"List1 :";
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
                cout<<"List 1: ";
                l1.display();
                break;
            case 6:
                cout<<"\n---Create LIST 2 ----\n";
                l2.create1();
                l1.concatenate(l2);
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
