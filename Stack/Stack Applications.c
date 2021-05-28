//
//  main.c
//  FDS Stack
//
//  Created by Kanishka Mishra on 10/19/20.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top=-1,num;
int stack[20];

void push1(char n, char stack[])
{
    if(top==num-1){
        printf("\n\nThe Stack is full!\n");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

void push(int n)
{
    if(top==num-1){
        printf("\n\nThe Stack is full!\n");
    }
    else
    {
        top++;
        stack[top]=n;
    }
    printf("\t\t\nTop points at: %d\n",stack[top]);
}

char pop1(char stack[])
{
    char data;
    if(top==-1){
        printf("\n\nThe Stack is empty!\n");
    }
    else{
        data=stack[top];
        top--;
    }
    return data;
}

void pop()
{
    char data;
    if(top==-1){
        printf("\n\nThe Stack is empty!\n");
    }
    else{
        data=stack[top];
        printf("\t\t\nDeleted element: %d",data);
        printf("\n");
        top--;
    }
    printf("\nTop points at: %d\n",stack[top]);
}

void display()
{
    if(top==-1){
        printf("\n\nStack is empty!\n");
    }
    else
    {
        printf("\n\nStack : \n");
        for(int i=top;i>=0;i--){
            printf("%d \t",stack[i]);
        }
        printf("\nTop points at: %d\n",stack[top]);
    }
}

void decimal_to_binary(int n){
    int rem;
    while(n>0){
        rem=n%2;
        n=n/2;
        push(rem);
    }
    display();
}

void parentheses(){
    int found=0;
    char brac;
    char exp[20],stack1[20];
    printf("Enter the Expression: ");
    scanf("%s",exp);
    for(int i=0;i<(strlen(exp));i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push1(exp[i],stack1);
        }
        else{
        if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            brac=pop1(stack1);
            if(brac=='(' && (exp[i]=='}' || exp[i]==']')){
                found=0;
            }
            else if(brac=='{' && (exp[i]==')' || exp[i]==']')){
                found=0;
            }
            else if(brac=='[' && (exp[i]=='}' || exp[i]==')')){
                found=0;
            }
            else {
                found++;
            }
        }
        }
    }
        if(top>=0){
            found=0;
        }
        if(found>=1){
            printf("Expression is Valid \n");
        }
        else{
            printf("Invalid Expression \n");
        }
}


int main(){
    int choice,ans,num1,ans1;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
        do{
            printf("Choose 1 to Implement Stack \n Choose 2 for Decimal to Binary using Stack \n Choose 3 to Check Well Formed Parenthisis \n Choose 4 to Exit \n");
            scanf("%d",&choice);
                switch(choice){
                    case 1:
                        do{
                            printf("\t\tChoose 1 to Push \n\t\t Choose 2 to POP \n \t\tChoose 3 to Display \n \t\tChoose 4 to exit \n");
                            scanf("%d",&choice);
                            switch(choice){
                                case 1:
                                    printf("\t\tEnter the element you want to Insert: ");
                                    scanf("%d",&num1);
                                    push(num1);
                                    break;
                                case 2:
                                    pop();
                                    break;
                                case 3:
                                    display();
                                    break;
                                case 4:
                                    break;
                                default:
                                    printf("\t\t\n Invalid Input!\n");
                                }
                            printf("\t\t\nRun Again stack implementation-  1:YES 0:NO\n");
                            scanf("%d",&ans1);
                        }while(ans1==1);
                        break;
                    case 2:
                        top=-1;
                        printf("Enter the Decimal number: ");
                        scanf("%d",&num1);
                        decimal_to_binary(num1);
                        break;
                    case 3:
                        top=-1;
                        parentheses();
                        break;
                    case 4:
                        exit(0);
                    default:
                        printf("\n Invalid Input!\n");
                }
            printf("Run again 1:YES 0:NO\n");
            scanf("%d",&ans);
        }while(ans!=0);
}
