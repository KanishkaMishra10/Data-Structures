//
//  main.cpp
//  Graph 1
//
//  Created by Kanishka Mishra on 3/29/21.
//Write a program in C to implement Depth First Search using linked representation of graph.

#include <iostream>
#include <stdlib.h>

using namespace std;

int visited[20];
int visited2[20];

class Node{
public:
    Node *next;
    int vertex;
    Node(){
        next=NULL;
    }
};

class graph:public Node{
    Node *list[20];
    int no_of_vertices;
public:
    graph(int n){
        no_of_vertices=n;
        for(int j=0;j<no_of_vertices;j++){
            list[j]=NULL;
        }
    }
    void create();
    void display();
    void recDFS(int v);
    void non_recDFS(int v);
    int count(int vertex);
    Node* search(int v);
    void BFS(int v);
};

int graph::count(int vertex){
    int found=0;
    Node *temp;
    temp=list[vertex-1];
    while(temp!=NULL){
        temp=temp->next;
        found++;
    }
    return found;
}

Node *graph::search(int v){
    Node *temp=list[v-1];
    while(temp!=NULL){
        if(visited[temp->vertex]==0){
            return temp;
        }
        else{
            temp=temp->next;
        }
    }
    return NULL;
}

void graph::create(){
    Node *temp, *new_node;
    char ans;
    temp=NULL;
    cout<<endl;
    for(int i=0;i<no_of_vertices;i++){
        cout<<endl;
        for(int j=0;j<no_of_vertices;j++){
            if(i==j){
                continue;
            }
            while(1){
                cout<<"Is there an edge between the vertex "<<i+1<<" and "<<j+1<<"? Y/N? ";
                cin>>ans;
                if(ans=='Y' || ans=='y'){
                    new_node=new Node();
                    new_node->vertex=j+1;
                    if(list[i]==NULL){
                        list[i]=temp=new_node;
                        break;
                    }
                    else{
                        temp->next=new_node;
                        temp=new_node;
                        break;
                    }
                }
                if(ans=='N' || ans=='n'){
                    break;
                }
            }
        }
    }
}

void graph::display(){
    Node *temp;
    for(int i=0;i<no_of_vertices;i++){
        cout<<endl;
        cout<<"Vertex "<<i+1<<"->";
        temp=list[i];
        while(temp!=NULL){
            cout<<" V"<<temp->vertex<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
}
    
void graph::recDFS(int v){
    Node *temp;
    visited2[v]=1;
    cout<<v<<"\t";
    temp=list[v-1];
    while(temp!=NULL){
        if(visited2[temp->vertex]==0){
            recDFS(temp->vertex);
        }
        else{
            temp=temp->next;
        }
    }
}

class stack{
    int vertices[20];
    int top;
public:
    stack(){
        top=-1;
    }
    void push(int n)
    {
        if(isFull()){
            cout<<"\n\nThe Stack is full!\n";
        }
        else
        {
            top++;
            vertices[top]=n;
        }
    }

    int pop()
    {
        char data;
        if(isEmpty()){
            exit(1);
        }
        else{
            data=vertices[top];
            top--;
            return data;
        }
    }
    
    bool isFull(){
        if(top==19){
            return true;
        }
        else
            return false;
    }
    
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    int top_elm(){
        return vertices[top];
    }
};


void graph::non_recDFS(int v){
    for(int i=0;i<20;i++){
        visited[i]=0;
    }
    Node *w;
    stack s;
    visited[v]=1;
    s.push(v);
    cout<<v<<"\t";
    
    while(!s.isEmpty()){
        v=s.top_elm();
        while((w=search(v))!=NULL){
            visited[w->vertex]=1;
            cout<<w->vertex<<"\t";
            s.push(w->vertex);
            v=w->vertex;
        }
        s.pop();
    }
}


int main() {
    for(int i=0;i<20;i++){
        visited2[i]=0;
    }
    
    int ans,choice,num;
    cout<<"Enter number of vertices: ";
    cin>>num;
    graph gph(num);
    
    do{
        cout<<"\n----MENU----"<<endl;
        cout<<"\n1: Create \n2: Display \n3: Depth First Search \n";
        cin>>choice;
        
        switch(choice){
            case 1:
                gph.create();
                break;
            case 2:
                gph.display();
                break;
            case 3:
                do{
                    cout<<"\n\t1: Recursive DFS \n\t2: Non-Recursive DFS\n";
                    cin>>choice;
                    switch(choice){
                        case 1:
                            cout<<"\nEnter starting vertex: ";
                            cin>>ans;
                            gph.recDFS(ans);
                            break;
                        case 2:
                            cout<<"\nEnter starting vertex: ";
                            cin>>ans;
                            gph.non_recDFS(ans);
                            break;
                        default:
                            cout<<"Invalid Choice!\n";
                    }
                    cout<<"\n\n\tRun inner loop Again? 1:YES, 0:NO  ";
                    cin>>ans;
                }while(ans==1);
                break;
            default:
                cout<<"Invalid Choice!\n";
                
        }
        cout<<"\n\nRun Again? 1:YES, 0:NO  ";
        cin>>ans;
    }while(ans==1);
    
    return 0;
}
