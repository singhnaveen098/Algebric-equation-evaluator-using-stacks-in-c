#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "stack.h"

node* top=NULL;
snode* stop=NULL;
dnode* dtop=NULL;

void push(char data){
    node *ptr=(node *)malloc(sizeof (node));
    if (ptr==NULL){
        printf("Stack is full.\n");
    }
    else{
        ptr->data=data;
        ptr->next=top;
        top=ptr;
    }
}

char pop(){
    if(top==NULL){
        return '\0';
    }
    else{
        node *n=top;
        char val=top->data;
        top=top->next;
        free(n);
        return val;
    }
}

void dpush(double data){
    dnode *ptr=(dnode *)malloc(sizeof (dnode));
    if (ptr==NULL){
        printf("Stack is full.\n");
    }
    else{
        ptr->data=data;
        ptr->next=dtop;
        dtop=ptr;
    }
}

double dpop(){
    if(dtop==NULL){
        return INT_MIN;
    }
    else{
        dnode *n=dtop;
        double val=dtop->data;
        dtop=dtop->next;
        free(n);
        return val;
    }
}

void spush(char* data){
    snode *ptr=(snode *)malloc(sizeof (snode));
    if (ptr==NULL){
        printf("Stack is full.\n");
    }
    else{
        strcpy(ptr->data,data);
        ptr->next=stop;
        stop=ptr;
    }
}

char* spop(){
    if(stop==NULL){
        return NULL;
    }
    else{
        snode *n=stop;
        strcpy(val,stop->data);
        stop=stop->next;
        free(n);
        return val;
    }
}

int prec(char val){
    if(val=='+'||val=='-')return 0;
    else if(val=='*'||val=='/')return 1;
    else if(val=='^')return 2;
    else if(val=='@'||val=='#')return 3;
    else if(val=='{'||val=='['||val=='('||val=='}'||val==']'||val==')')return 4;
    return -1;
}

int isoperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='@'||x=='#')return 1;
    else return 0;
}

int rassociate(char x){
    if(x=='^'||x=='@'||x=='#')return 1;
    else return 0;
}

int isbinary(char x){
    if(x=='@'||x=='#')return 0;
    else return 1;
}
