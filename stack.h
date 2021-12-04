#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


typedef struct node{                    //implementing stacks by linked list.
    char data;                          //stack for char data type
    struct node *next;
}node;

typedef struct dnode{                   //different stacks for different data types
    double data;                        //stack for double data type
    struct dnode *next;
}dnode;

typedef struct snode{
    char data[256];                      //stack for string data type
    struct snode *next;
}snode;

extern node* top;                       // declaration of different top node for different stacks globally.
extern snode* stop;
extern dnode* dtop;

char val[256];

void push(char data);                   // function to push data in char type stack
char pop();                             // function to pop data from char type stack

void dpush(double data);                // function to push data in double type stack
double dpop();                          // function to pop data from double type stack

void spush(char* data);                 // function to push data in string type stack
char* spop();                           // function to pop data from string type stack

int prec(char val);                     // function to check precendence of operators
int isoperator(char x);                 // function to check if x is operator or not
int rassociate(char x);                 // function to check associativity of x
int isbinary(char x);                   // function to check if operator is binary or not

#endif // STACK_H_INCLUDED
