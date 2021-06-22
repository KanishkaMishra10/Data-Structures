//
//  main.cpp
//  DS Tree 2
//
//  Created by Kanishka Mishra on 4/6/21.
//Write a menu driven program in C to a. Create a binary search tree b. search & Delete the node

#include <iostream>
#include <stdlib.h>

using namespace std;

int num;

class node{
public:
    node *left;
    int data;
    node *right;
    node(){
        left=right=NULL;
    }
};

class BinarySearchTree:public node{
    int static count;
    node* root;
    node *search(node *root,int value);
    void levelOrderTraversal(node *root);
    void count_nodes(node *);
    void count_leaf_nodes(node *);
public:
    void create();
    node *search(int value);
    void delete_node(int n);
    bool printLevel(node *root,int level);
    void levelOrderTraversal();
    bool check_empty();
    void count_nodes();
    void count_leaf_nodes();
};

int BinarySearchTree::count=0;

void BinarySearchTree::create(){
    node *temp, *newnode;
    int elm;
    cout<<"Enter number of nodes: ";
    cin>>num;
    for(int i=0;i<num;i++){
        newnode=new node();
        cout<<"Enter data: ";
        cin>>elm;
        newnode->data=elm;
        if(root==NULL){
            root=newnode;
        }
        else{
            temp=root;
            while(1){
                if(elm<temp->data){
                    if(temp->left==NULL){
                        temp->left=newnode;
                        break;
                    }
                    else
                        temp=temp->left;
                }
                else{
                    if(temp->right==NULL){
                        temp->right=newnode;
                        break;
                    }
                    else
                        temp=temp->right;
                }
            }
        }
    }
}
int search_level=0;
node *BinarySearchTree::search(node *root,int value){
    if(root!=NULL){
        if(root->data==value){
            cout<<"Level: "<<search_level<<endl;
            return root;
        }
        if(value<root->data){
            search_level++;
            return search(root->left, value);
        }
        else{
            search_level++;
            return search(root->right, value);
        }
    }
    return NULL;
}

node *BinarySearchTree::search(int value){
    return search(root,value);
}

void BinarySearchTree::delete_node(int n){
    node *temp, *parent=NULL,*father, *replace, *son;
    temp=root;          //temp holds the node to be deleted
    
    //to search the node to be deleted
    while((temp!=NULL) && (temp->data!=n)){
        if(n<temp->data){   //to find if the data is in the left sub tree
            parent=temp;    //parent points towards the parent of the node to be deleted
            temp=temp->left;
        }
        else{
            parent=temp;    //if data is in the right sub tree
            temp=temp->right;
        }
    }
    //if node is not present
    if(temp==NULL){
        cout<<"Number not found!\n"<<endl;
        exit(1);
    }
    
    //case: when the node has only right child
    if(temp->left==NULL){
        replace=temp->right;
    }
    //case: only left child
    else if(temp->right==NULL)
        replace=temp->left;
    //case: has both children
    else{
        //finds the smallest element from the right sub tree of the node to replace
        father=temp;
        replace=temp->right;
        son=replace->left;
        while(son!=NULL){
            father=replace;
            replace=son;
            son=replace->left;
        }
        if(father!=temp){
            father->left=replace->right;
            replace->right=temp->right;
        }
        //making the left part of the node to be replaced point to the left part of the node to be deleted. i.e. connecting left node of the node to be deleted to the replacable node
        replace->left=temp->left;
    }
    
    //substituting replace node at the position of the node being deleted
    if(parent==NULL)    //if the node to be deleted is the root node
        root=replace;
    else{
        if(temp==parent->left)
            parent->left=replace;
        else
            parent->right=replace;
    }
    
    //deletes the node
    delete(temp);
}

bool BinarySearchTree::printLevel(node *root,int level){
    if(root==NULL)
        return false;
    if(level==1){
        cout<<root->data<<"  ";
        return true;
    }
    bool left = printLevel(root->left,level-1);
    bool right = printLevel(root->right,level-1);
    
    return left || right;   //or is used coz if only one child is present it still moves onto check the next level
}

void BinarySearchTree::levelOrderTraversal(node *root){
    int level =1;
    cout<<"Level "<<level-1<<" : ";
    while(printLevel(root, level)){
        cout<<"\nLevel "<<level<<" : ";
        level++;
    }
    cout<<"NULL \n\n";
}

void BinarySearchTree::levelOrderTraversal(){
    levelOrderTraversal(root);
}

bool BinarySearchTree::check_empty(){
    if(root==NULL){
        return true;
    }
    return false;
}

void BinarySearchTree::count_nodes(node *root){
    if(root!=NULL){
        count++;
        count_nodes(root->left);
        count_nodes(root->right);
    }
    else{
        return;
    }
}

void BinarySearchTree::count_nodes(){
    count_nodes(root);
    cout<<"Total number of nodes: "<<count;
}
    
int main(){

    int ans,choice,value;
    node *result;
    BinarySearchTree bst;
    do{
        cout<<"\n 1: Create A binary Search Tree \n 2: Search an element\n 3: To delete a node \n 4: To count total nodes. \n";
        cin>>choice;
        switch(choice){
            case 1:
                bst.create();
                cout<<"Tree successfully created! \n\n";
                bst.levelOrderTraversal();
                break;
            case 2:
                if(bst.check_empty()){
                    cout<<"Tree is Empty!\n";
                    break;
                }
                else{
                    cout<<"Enter value you want to search: ";
                    cin>>value;
                    result=bst.search(value);
                    if(result==NULL){
                        cout<<"Element not found!\n";
                    }
                       else{
                           cout<<"Element found! \n";
                    }
                    break;
                }
            case 3:
                if(bst.check_empty()){
                    cout<<"Tree is Empty!\n";
                    break;
                }
                else{
                    cout<<"Enter value you want to delete: ";
                    cin>>value;
                    bst.delete_node(value);
                    cout<<"Node successfully deleted! \n\n";
                    bst.levelOrderTraversal();
                    break;
                }
            case 4:
                bst.count_nodes();
                cout<<endl;
                break;
            default:
                cout<<"Inavlid Choice! \n";
        }
        cout<<"Run again: 1-YES, 0-NO \n";
        cin>>ans;
    }while(ans==1);
}
