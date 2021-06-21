//
//  main.cpp
//  Threaded Binary Tree
//
//  Created by Kanishka Mishra on 6/20/21.
//

#include <iostream>
using namespace std ;

class node{
public:
    int data;
    node *left;
    node *right;
    int lchild;
    int rchild;
    node(){
        left=right=NULL;
        lchild=rchild=0;
    }
};

class Tree:public node{
    node *root;
    node *head;
public:
    Tree(){
        head=new node();
        root=NULL;
    }
    void create();
    
};


void Tree::create(){
    int no_of_nodes,data;
    node *temp;
    temp=root;
    cout<<"Enter total number of nodes: ";
    cin>>no_of_nodes;
    for(int i=0;i<no_of_nodes;i++){
        node* new_node=new node();
        cout<<"Enter data: ";
        cin>>data;
        new_node->data=data;
        if(root==NULL){
            root=new_node;
            new_node->left=head;
            new_node->right=head;
        }
        else{
            temp=root;
            while(1){
                if(data<temp->data){
                    if(temp->lchild==0){
                        new_node->left=temp->left;
                        temp->left=new_node;
                        temp->lchild=1;
                        new_node->right=temp;
                        break;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                if(data>temp->data){
                    if(temp->rchild==0){
                        new_node->right=temp->right;
                        temp->right=new_node;
                        new_node->left=temp;
                        temp->rchild=1;
                        break;
                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
        }
    }
}


int main() {
    Tree tree;
    tree.create();
    cout<<endl;
    cout<<endl;
}
