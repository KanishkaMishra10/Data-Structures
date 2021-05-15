//
//  main.cpp
//  DFS Prim's Algo
//
//  Created by Kanishka Mishra on 5/5/21.

//Write a program in C to implement prims algorithm for a given directed Graph.

#include <iostream>
using namespace std;

#define INF 9999999

int matrix[10][10];

void create_matrix(int arr[10][10],int vertices){
    int cost;
    char ans;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(i==j){
                arr[i][j]=0;
                continue;
            }
            while(1){
                cout<<endl;
                cout<<"Is this edge directed from "<<i+1<<" -> "<<j+1<<"? Y/N? ";
                cin>>ans;
                if(ans=='Y' || ans=='y'){
                    cout<<"Enter cost: ";
                    cin>>cost;
                    arr[i][j]=cost;
                    break;
                }
                if(ans=='N' || ans=='n'){
                    arr[i][j]=0;
                    break;
                }
            }
        }
    }
}

void display(int arr[10][10],int vertices){
    
    for(int i=0;i<vertices;i++){
        cout<<"\nFor Vertex "<<i+1<<" \n";
        for(int j=0;j<vertices;j++){
            if(matrix[i][j]){
                cout<<""<<i+1<<" -> "<<j+1<<" Cost ("<<matrix[i][j]<<") , ";
            }
        }
    }
    
}

int main() {
  int no_edge,selected[20],x,y,V,sum=0;  // number of edge
    
    for(int i=0;i<20;i++){
        selected[i]=0;
    }
  

  // set number of edge to 0
  no_edge = 0;

    cout<<"Enter number of vertices: ";
    cin>>V;
    selected[0] = 1;
    
    create_matrix(matrix, V);
    display(matrix, V);

  cout << "\n\nEdge"<< " : "<< "Weight"<<endl;
    
  while (no_edge < V - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && matrix[i][j]) {  // not in selected and there is an edge
            if (min > matrix[i][j]) {
              min = matrix[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
      sum=sum+matrix[x][y];
    cout << x+1 << " - " << y+1 << " :  " << matrix[x][y];
    cout << endl;
    selected[y] = 1;
    no_edge++;
  }
    cout<<"\nThe total cost is: "<<sum<<endl;

  return 0;
}
