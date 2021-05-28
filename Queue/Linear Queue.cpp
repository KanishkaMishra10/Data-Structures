//
//  main.cpp
//  linear queue 1
//
//  Created by Kanishka Mishra on 2/8/21.
//

#include <iostream>
using namespace std;

int queue[10];
int front,rear,size;

bool isfull(){
    if(rear==size-1){
        return true;
    }
    else{
        return false;
    }
}

bool isempty(){
    if(front<0 || front<0){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int a){
    if(isfull()){
        cout<<"Queue is full!"<<endl;
    }
    else{
        if(front==-1){
            front++;rear++;
            queue[rear]=a;
        }
        else{
            rear++;
            queue[rear]=a;
        }
    }
}

void dequeue(){
    if(isempty()){
        cout<<"ERROR! Queue is empty!"<<endl;
    }
    else{
        int data=queue[front];
        front++;
        cout<<"Removed number is: "<<data<<endl;
    }
}

void display(){
    if(front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    cout<<"Elements in queue are: "<<endl;
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<"\t";
    }
    cout<<"\n Front index: "<<front;
    cout<<"\n Rear Index: "<<rear;
    cout<<"\n";
}

int main(){
    front=rear=-1;
    int choice,ans,num1;
    
    cout<<"Enter the size: "<<"\n";
    cin>>size;
    do{
        cout<<"Enter 1 for entering a number \n Enter 2 for removing a number \n Enter 3 to Display \n"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the number: "<<endl;
                cin>>num1;
                enqueue(num1);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
        
        cout<<"Run again 1:YES 0:NO"<<endl;
        cin>>ans;
    }while(ans!=0);
}
