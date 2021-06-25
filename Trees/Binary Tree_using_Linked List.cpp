//
//  main.cpp
//  DS Trees 1
//
//  Created by Kanishka Mishra on 2/24/21.
//

/* Write a menu driven program in C to
 a. Create a binary tree
 b. Recursive  and  non-recursive  tree  traversals:  inorder,  preorder  and post order */

#include <iostream>

using namespace std;
int num;

class node{
public:
    node *left;
    char data;
    node *right;
    node(){
        left=right=NULL;
    }
};

class Tree:public node{
    node *root;
    void preorder(node * currentnode);
    void inorder(node * currentnode);   //private declaration to keep the root node as private
    void postorder(node * currentnode);
    node * copy(node *,node *);
    node * mirror(node *,node *);
public:
    Tree(){
        root=NULL;
    }
    void create();                            //creates a tree
    void preorder();                          //Function for Pre-Order Traversal
    void inorder();                           //Function for In-Order Traversal
    void postorder();                         //Function for Post-Order Traversal
    int check();                              //to check if a tree is empty or not
    void nonrec_preorder();
    void nonrec_inorder();
    void nonrec_postorder();
    bool printLevel(node *root,int level);
    void levelOrderTraversal(node *root);
    void levelOrderTraversal();
    void copy(Tree &t);                        //Function to copy a tree
    void mirror(Tree &t);                      //Function to form a mirror view of a tree
};

class stack{        //for non-recursive traversal
    int top;
    node* item[20];
public:
    stack(){
        top=-1;
    }
    void push(node* p){
        item[++top]=p;
    }
    bool isFull(){
        if(top==num){
            return true;
        }
        else{
            return false;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    node* pop(){
        if(isEmpty()){
            cout<<"Stack is empty!";
            return NULL;
        }
        else{
            return item[top--];
        }
    }
};

int Tree::check(){
    if(root==NULL){
        return 1;
    }
    else
        return 0;
}

void Tree::create(){
    int num;
    char elm;
    char ans;
    node *temp;
    cout<<"Enter number of nodes: ";
    cin>>num;
    for(int i=0;i<num;i++){
        node *new_node=new node();
        cout<<"Enter data: ";
        cin>>elm;
        new_node->data=elm;
        if(root==NULL){
            root=new_node;
        }
        else{
            temp=root;
            while(1){
                cout<<"\nEnter element at " <<temp->data<<"'s left or right (L/R) ? ";
                cin>>ans;
                if(ans == 'l' || ans == 'L' ){
                    if(temp->left==NULL){
                        temp->left=new_node;
                        cout<<"Element added! \n\n";
                        break;
                    }
                    else{
                        temp=temp->left;
                        cout<<"Node already present! "<<endl;
                    }
                }
                else if(ans =='r' || ans == 'R'){
                    if(temp->right==NULL){
                        temp->right=new_node;
                        cout<<"Element added! \n\n";
                        break;
                    }
                    else{
                        temp=temp->right;
                        cout<<"Node already present! "<<endl;
                    }
                }
                else{
                    cout<<"Invalid choice! Choose L/R."<<endl;
                }
            }
        }
    }
}

void Tree::preorder(){  //recursive has internal stack
    preorder(root);
}

void Tree::preorder(node * currentnode){
    if(currentnode!=NULL){
        cout<<currentnode->data;
        cout<<"  ";
        preorder(currentnode->left);
        preorder(currentnode->right);
    }
}

void Tree::inorder(){
    inorder(root);
}

void Tree::inorder(node * currentnode){
    if(currentnode!=NULL){
        inorder(currentnode->left);
        cout<<currentnode->data;
        cout<<"  ";
        inorder(currentnode->right);
    }
}

void Tree::postorder(){
    postorder(root);
}

void Tree::postorder(node * currentnode){
    if(currentnode!=NULL){
        postorder(currentnode->left);
        postorder(currentnode->right);
        cout<<currentnode->data;
        cout<<"  ";
    }
}

void Tree::nonrec_inorder(){
    node *temp=root;
    stack s;
    cout<<"\nThe non-recursive in-order traversal is: \n";
    while(1){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;    //traversing towards left
        }
        if(s.isEmpty()){
            break;
        }
        temp = s.pop();
        cout<<temp->data;
        cout<<"  ";
        temp=temp->right;
    }
}

void Tree::nonrec_preorder(){
    node *temp=root;
    stack s;
    cout<<"The non-recursive pre-order traversal is: \n";
    while(1){
        while(temp!=NULL){
            cout<<temp->data;
            cout<<"  ";
            s.push(temp);
            temp=temp->left;
        }
        if(s.isEmpty()){
            break;
            //cout<<"It is empty!";
        }
        temp = s.pop();
        temp=temp->right;
    }
}

void Tree::nonrec_postorder(){          //LRD
    node *temp=root;
    node *t;
    stack s1,s2;
    cout<<"The non-recursive post-order traversal is: \n";
    s1.push(temp);
    while(s1.isEmpty() == false){
        temp=s1.pop();
        s2.push(temp);
        //pushing every root node's  left and right child onto stack 1
        /* can not interchange left part push & right part push because in stack 2 first data is stored of right child and then left child*/
        if(temp->left!=NULL){
            s1.push(temp->left);
        }
        if(temp->right!=NULL){
            s1.push(temp->right);
        }
    }
    while(s2.isEmpty()==false){
        t=s2.pop();
        cout<<t->data;
        cout<<"  ";
    }
}


bool Tree::printLevel(node *root,int level){
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

void Tree::levelOrderTraversal(node *root){
    int level =1;
    cout<<"Level "<<level-1<<" : ";
    while(printLevel(root, level)){
        cout<<"\nLevel "<<level<<" : ";
        level++;
    }
    cout<<"NULL \n\n";
}

void Tree::levelOrderTraversal(){
    levelOrderTraversal(root);
}

void Tree::copy(Tree &t){
    t.root=copy(root,t.root);
}

node * Tree::copy(node *root,node *root2){
    if (root!=NULL){
        root2 = new node();
        root2->data=root->data;
        root2->left=copy(root->left,root2->left);
        root2->right=copy(root->right,root2->right);
        return root2;
    }
    else
        return NULL;
}

void Tree::mirror(Tree &t){
    t.root=mirror(root,t.root);
}

node * Tree::mirror(node *root,node *root2){
    if (root!=NULL){
        root2 = new node();
        root2->data=root->data;
        root2->left=mirror(root->right,root2->left);
        root2->right=mirror(root->left,root2->right);
        return root2;
    }
    else
        return NULL;
}

int main() {
    int choice,ans;
    Tree tree;
    do{
        cout<<"\n 1: To create Tree \n 2: To traverse Tree recursively \n 3: To traverse tree non-recursively \n"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                tree.create();
                tree.levelOrderTraversal();
                break;
            case 2:
                if(tree.check()){
                    cout<<"Tree is Empty! \n";
                }
                else{
                    do{
                        cout<<"\t 1: Preorder \n\t 2: Inorder \n\t 3: Postorder \n"<<endl;
                        cin>>choice;
                        switch(choice){
                            case 1:
                                tree.preorder();
                                break;
                            case 2:
                                tree.inorder();
                                break;
                            case 3:
                                tree.postorder();
                                break;
                            default:
                                cout<<"Invalid choice!"<<endl;
                        }
                        cout<<"\n\n\tRun again traverse loop: 1-YES, 0:NO \n";
                        cin>>ans;
                    }while(ans==1);
                }
                break;
            case 3:
                if(tree.check()){
                    cout<<"Tree is empty!\n";
                }
                else{
                    do{
                        cout<<"\t 1: Preorder \n\t 2: Inorder \n\t 3: Postorder \n"<<endl;
                        cin>>choice;
                        switch(choice){
                            case 1:
                                tree.nonrec_preorder();
                                break;
                            case 2:
                                tree.nonrec_inorder();
                                break;
                            case 3:
                                tree.nonrec_postorder();
                                break;
                            default:
                                cout<<"Invalid choice!"<<endl;
                        }
                        cout<<"\n\n\tRun again traverse loop: 1-YES, 0:NO \n";
                        cin>>ans;
                    }while(ans==1);
                }
                break;
            default:
                cout<<"Invalid Choice! \n";
        }
        cout<<"Run again Program : 1-YES, 0:NO ";
        cin>>ans;
    }while(ans==1);
    return 0;
}
