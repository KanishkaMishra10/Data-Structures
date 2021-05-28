//
//  main.c
//  FDS LAB 9.2
//
//  Created by Kanishka Mishra on 11/21/20.
//Infix to Postfix

#include <stdio.h>
#include <string.h>

char stack[30];
int top=-1;

void push(char n)
{
        top++;
        stack[top]=n;
}

char pop()
{
    if(top==-1){
        return -1;
    }
    else{
        char data=stack[top];
        top--;
        return data;
    }
}

int priority(char s){
    if(s=='(')
        return 0;
    if(s=='+' || s=='-')
        return 1;
    if(s=='*' || s=='/')
        return 2;
    if(s=='^')
        return 3;
    return 0;
}


int main(){
    char string[30],x;
    int i=0;
    printf("\n\nEnter the Infix form: ");
    scanf("%s",string);
    int len=strlen(string);
    
    while(i<len){
        if(string[i]>='a' && string[i]<='z'){
            printf("%c",string[i]);
        }
        else if(string[i]=='('){
            push(string[i]);
        }
        else if(string[i]==')'){
            while((x=pop())!='('){
                printf("%c",x);
            }
        }
        else{
            while(priority(stack[top])>=priority(string[i])){
                printf("%c",pop());
            }
            push(string[i]);
        }
        i++;
    }
    while(top!=-1){
            printf("%c",pop());
    }
     
    printf("\n\n");
    return 0;
}
