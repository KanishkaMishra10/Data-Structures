//
//  main.cpp
//  BFS Graph
//
//  Created by Kanishka Mishra on 5/12/21.
//

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

class queue{
    int queues[20];
    int front,rear,size;
public:
    queue(){
        front=rear=-1;
    }
    bool isfull(){
        if(rear==19){
            return true;
        }
        else{
            return false;
        }
    }

    bool isempty(){
        if(front<0 || front>rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int a){
        if(isfull()){
            exit(1);
        }
        else{
            if(front==-1){
                front++;rear++;
                queues[rear]=a;
            }
            else{
                rear++;
                queues[rear] = a;
            }
        }
    }

    void dequeue(){
        if(isempty()){
            cout<<"Empty\n";
        }
        else{
            //int data=queue[front];
            front++;
        }
    }
    
    int peek(){
        return queues[front];
    }
};

void graph::BFS(int v){
    for(int i=0;i<20;i++){
        visited[i]=0;
    }
    Node *w;
    queue q;
    visited[v]=1;
    q.enqueue(v);
    cout<<v<<"\t";
    
    while(!q.isempty()){
        v=q.peek();
        q.dequeue();
        while((w=search(v))!=NULL){
            q.enqueue(w->vertex);
            visited[w->vertex]=1;
            cout<<w->vertex<<"\t";
        }
    }
}

int main() {
    for(int i=0;i<20;i++){
        visited2[i]=0;
    }
    
    int ans,num;
    cout<<"Enter number of vertices: ";
    cin>>num;
    graph gph(num);
                cout<<"\nEnter starting vertex: ";
                cin>>ans;
                gph.BFS(ans);
    
    return 0;
}
