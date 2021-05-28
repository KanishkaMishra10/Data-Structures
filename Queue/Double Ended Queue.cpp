//
//  main.cpp
//  DeQueue
//
//  Created by Kanishka Mishra on 8/16/20.
//  Copyright © 2020 Kanishka Mishra. All rights reserved.



#include <iostream>

using namespace std;

class dequeue{
    int array[10];
    int front;
    int rear;
    int size;
public:
    dequeue(int size){
        front=-1;
        rear=0;
        this->size=size;
    }
    void insertfront(int a);
    void deletefront();
    void insertrear(int num);
    void deleterear();
    bool isfull();
    bool isempty();
    void display();
};

bool dequeue::isfull(){
    return ((front==0 && rear==size-1) || rear==front-1);
}

bool dequeue::isempty(){
    return ( front==-1);
}

void dequeue::insertfront(int a){
    if(isfull()){
        cout<<"ERROR! OVERLOAD."<<endl;
    }
    else{
        if(front==-1) { //inserting first element
            front++;
        }
        else if(front==0){
            front=size-1;
        }
        else{
            front--;
        }
        array[front]=a;
    }
    display();
}

void dequeue::insertrear(int num){
    if(isfull()){
        cout<<"ERROR! OVERLOAD."<<endl;
    }
    else{
        if(front==-1){
            front++;
        }
        else if(rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        array[rear]=num;
    }
    cout<<"\n";
    display();
}

void dequeue::deletefront(){
    int data;
    if(isempty()){
        cout<<"Queue Empty!"<<endl;
    }
    else{
        data=array[front];
        if(front==rear){
            front=-1;
            rear=0;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        cout<<"Deleted Element is: "<<data<<endl;
    }
    display();
}

void dequeue::deleterear(){
    int data;
    if(isempty()){
        cout<<"Queue Empty!"<<endl;
    }
    else{
        data=array[rear];
        if(front==rear){
            front=-1;
            rear=0;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        cout<<"Deleted Element is: "<<data<<endl;
    }
    display();
}

void dequeue::display(){
    if(front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    cout<<"Elements in queue are: "<<endl;
    if(rear>=front){
        for(int i=front;i<=rear;i++){
            cout<<array[i]<<"\t";
        }
    }
    else{
        for(int i=front;i<size;i++){
            cout<<array[i]<<"\t";}
        {for(int i=0;i<=rear;i++)
                cout<<array[i]<<"\t";
        }
    }
    cout<<"\n Front index: \n"<<front;
    cout<<"\n Rear Index: \n"<<rear;
    cout<<"\n";
}

int main(){
    int choice,ans,size1,num;
    cout<<"Enter the size of the queue: ";
    cin>>size1;
    dequeue DQ(size1);
    do{
        cout<<"Choose 1 to Insert at front"<<"\n"<<"Choose 2 to Insert at rear"<<"\n"<<"Choose 3 to Delete from front "<<endl;
        cout<<"Choose 4 to Delete from rear"<<"\n"<<"Choose 5 to Display \n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Insert element: ";
                cin>>num;
                DQ.insertfront(num);
                break;
            case 2:
                cout<<"Insert element: ";
                cin>>num;
                DQ.insertrear(num);
                break;
            case 3:
                DQ.deletefront();
                break;
            case 4:
                DQ.deleterear();
                break;
            case 5:
                DQ.display();
                break;
            default:
                cout<<"Invalid Choice!"<<"\n";
        }
        cout<<"To run again: 1-YES 0-NO"<<endl;
        cin>>ans;
    }while(ans==1);
}
