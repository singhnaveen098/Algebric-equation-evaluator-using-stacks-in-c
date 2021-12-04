#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include "operation.h"

char  *InfixToPostfix(char *source, char *destination){
    int j=0;
    char x;
    for(int i=0;source[i]!='\0';i++){
        if(source[i]==' ')continue;
        else if(source[i]=='('||source[i]=='{'||source[i]=='[')push(source[i]);
        else if(isoperator(source[i])){
            if(top==NULL){
                push(source[i]);
            }
            else{
                if(!rassociate(source[i])){
                    x=pop();
                    while(isoperator(x) == 1 && prec(x)>= prec(source[i])){
                        destination[j++]=x;
                        destination[j++]=' ';
                        x=pop();
                    }
                    push(x);
                    push(source[i]);
                }
                else{
                   x=pop();
                    while(isoperator(x) == 1 && prec(x)>prec(source[i])){
                        destination[j++]=x;
                        destination[j++]=' ';
                        x=pop();
                    }
                    push(x);
                    push(source[i]);
                }
            }
        }
        else if(source[i]==')'){
            x=pop();
            while(x!='('){
                 destination[j++]=x;
                 destination[j++]=' ';
                 x=pop();
            }
        }
        else if(source[i]=='}'){
            x=pop();
            while(x!='{'){
                 destination[j++]=x;
                 destination[j++]=' ';
                 x=pop();
            }
        }
        else if(source[i]==']'){
            x=pop();
            while(x!='['){
                 destination[j++]=x;
                 destination[j++]=' ';
                 x=pop();
            }
        }
        else{
            while(source[i]!=' '){
                if(prec(source[i])>=0||source[i]=='\0')break;
                destination[j++]=source[i];
                i++;
            }
            i--;
            destination[j++]=' ';
        }
    }
    while(top!=NULL){
        char x = pop();
        if(x=='(')continue;
        destination[j++]=x;
        destination[j++]=' ';
    }
    destination[--j]='\0';
    return destination;
}

char  *InfixToPrefix(char *source, char *destination){
    int j=0;
    char x;
    for(int i=strlen(source)-1;i>=0;i--){
        if(source[i]==' ')continue;
        else if(source[i]==')'||source[i]=='}'||source[i]==']')push(source[i]);
        else if(isoperator(source[i])){
            if(top==NULL)push(source[i]);
            else{
                if(rassociate(source[i])){
                    x=pop();
                    while(isoperator(x) == 1 && prec(x)>= prec(source[i])){
                        destination[j++]=x;
                        destination[j++]=' ';
                        x=pop();
                    }
                    push(x);
                    push(source[i]);
                }
                else{
                   x=pop();
                    while(isoperator(x) == 1 && prec(x)>prec(source[i])){
                        destination[j++]=x;
                        destination[j++]=' ';
                        x=pop();
                    }
                    push(x);
                    push(source[i]);
                }
            }
        }
        else if(source[i]=='('){
            x=pop();
            while(x!=')'){
                 if(x=='\0')break;
                 destination[j++]=x;
                 destination[j++]=' ';
                 x=pop();
            }
        }
        else if(source[i]=='{'){
            x=pop();
            while(x!='}'){
                 if(x=='\0')break;
                 destination[j++]=x;
                 destination[j++]=' ';
                 x=pop();
            }
        }
        else if(source[i]=='['){
            x=pop();
            while(x!=']'){
                 if(x=='\0')break;
                 destination[j++]=x;
                 destination[j++]=' ';
                 x=pop();
            }
        }
        else{
            while(source[i]!=' '){
                if(prec(source[i])>=0||source[i]=='\0')break;
                destination[j++]=source[i];
                i--;
            }
            i++;
            destination[j++]=' ';
        }
    }
    while(top!=NULL){
        destination[j++]=pop();
        destination[j++]=' ';
    }
    destination[j]='\0';
    strrev(destination);
    memmove(destination, destination + 1, strlen(destination));
    return destination;
}

char  *PostfixToPrefix(char *source, char *destination){
    char op1[256],op2[256];
    char temp[2];
    for(int i=0;source[i]!='\0';i++){
        temp[0]=source[i];
        temp[1]='\0';
        if(source[i]==' ')continue;
        else if(!isoperator(source[i])){
            strcpy(destination,temp);
            i++;
            while(source[i]!=' '){
                if(prec(source[i])>=0||source[i]=='\0')break;
                temp[0]=source[i];
                temp[1]='\0';
                strcat(destination,temp);
                i++;
            }
            i--;
            strcat(destination," ");
            spush(destination);
        }
        else if(isoperator(source[i])){
            if(isbinary(source[i])){
                strcpy(op1,spop());
                strcpy(op2,spop());
                strcpy(destination,temp);
                strcat(destination," ");
                strcat(destination,op2);
                strcat(destination,op1);
                spush(destination);
            }
            else{
                strcpy(op1,spop());
                strcpy(destination,temp);
                strcat(destination," ");
                strcat(destination,op1);
                spush(destination);
            }
        }
    }
    strcpy(destination,stop->data);
    destination[strlen(destination)-1]='\0';
    return destination;
}

char  *PrefixToPostfix(char *source, char *destination){
    char op1[256],op2[256];
    char temp[2];
    for(int i=strlen(source)-1;i>=0;i--){
        temp[0]=source[i];
        temp[1]='\0';
        if(source[i]==' ')continue;
        else if(!isoperator(source[i])){
            strcpy(destination,temp);
            i--;
            while(source[i]!=' '){
                if(prec(source[i])>=0||source[i]=='\0')break;
                temp[0]=source[i];
                temp[1]='\0';
                strcat(destination,temp);
                i--;
            }
            i++;
            strrev(destination);
            strcat(destination," ");
            spush(destination);
        }
        else if(isoperator(source[i])){
            if(isbinary(source[i])){
                strcpy(op1,spop());
                strcpy(op2,spop());
                strcpy(destination,op1);
                strcat(destination,op2);
                strcat(destination,temp);
                strcat(destination," ");
                spush(destination);
            }
            else{
                strcpy(op1,spop());
                strcpy(destination,op1);
                strcat(destination,temp);
                strcat(destination," ");
                spush(destination);
            }
        }
    }
    strcpy(destination,stop->data);
    destination[strlen(destination)-1]='\0';
    return destination;
}

char  *PostfixToInfix(char *source, char *destination){
    char op1[256],op2[256];
    char temp[2];
    for(int i=0;source[i]!='\0';i++){
        temp[0]=source[i];
        temp[1]='\0';
        if(source[i]==' ')continue;
        else if(!isoperator(source[i])){
            strcpy(destination,temp);
            i++;
            while(source[i]!=' '){
                if(prec(source[i])>=0||source[i]=='\0')break;
                temp[0]=source[i];
                temp[1]='\0';
                strcat(destination,temp);
                i++;
            }
            i--;
            strcat(destination," ");
            spush(destination);
        }
        else if(isoperator(source[i])){
            if(isbinary(source[i])){
                strcpy(op1,spop());
                strcpy(op2,spop());
                strcpy(destination,"(");
                strcat(destination," ");
                strcat(destination,op2);
                strcat(destination,temp);
                strcat(destination," ");
                strcat(destination,op1);
                strcat(destination,")");
                strcat(destination," ");
                spush(destination);
            }
            else{
                strcpy(op1,spop());
                strcpy(destination,"(");
                strcat(destination," ");
                strcat(destination,temp);
                strcat(destination," ");
                strcat(destination,op1);
                strcat(destination,")");
                strcat(destination," ");
                spush(destination);
            }
        }
    }
    strcpy(destination,stop->data);
    destination[strlen(destination)-1]='\0';
    return destination;
}

char  *PrefixToInfix(char *source, char *destination){
    char op1[256],op2[256];
    char temp[2];
    for(int i=strlen(source)-1;i>=0;i--){
        temp[0]=source[i];
        temp[1]='\0';
        if(source[i]==' ')continue;
        else if(!isoperator(source[i])){
            strcpy(destination,temp);
            i--;
            while(source[i]!=' '){
                if(prec(source[i])>=0||source[i]=='\0')break;
                temp[0]=source[i];
                temp[1]='\0';
                strcat(destination,temp);
                i--;
            }
            i++;
            strrev(destination);
            strcat(destination," ");
            spush(destination);
        }
        else if(isoperator(source[i])){
            if(isbinary(source[i])){
                strcpy(op1,spop());
                strcpy(op2,spop());
                strcpy(destination,"(");
                strcat(destination," ");
                strcat(destination,op1);
                strcat(destination,temp);
                strcat(destination," ");
                strcat(destination,op2);
                strcat(destination,")");
                strcat(destination," ");
                spush(destination);
            }
            else{
                strcpy(op1,spop());
                strcpy(destination,"(");
                strcat(destination," ");
                strcat(destination,temp);
                strcat(destination," ");
                strcat(destination,op1);
                strcat(destination,")");
                strcat(destination," ");
                spush(destination);
            }
        }
    }
    strcpy(destination,stop->data);
    destination[strlen(destination)-1]='\0';
    return destination;
}

char  *CheckUnary(char *x, char *y){
    int j=0;
    char z = '\0';
    for(int i=0;x[i]!='\0';i++){
        if (isoperator(x[i])&& (z=='('||z=='['||z=='{'||isoperator(z)||z=='\0')){
            if(x[i]=='+')y[j++]='@';
            else if(x[i]=='-') y[j++]='#';
            else y[j++]=x[i];
        }
        else {
            y[j++]=x[i];
            if(x[i]!=' ')z=x[i];
        }
    }
    y[j]='\0';
    return y;
}

double EvaluatePostFix(char *x){
    double op1,op2;
    double eq;
    for(int i=0;x[i]!='\0';i++){
        int z=0,k=0,count;
        if(x[i]==' ')continue;
        else if(!isoperator(x[i])){
            double num=0;
            while(x[i]!=' '){
                if(prec(x[i])>=0 || x[i]=='\0')break;
                else if(x[i]=='.'){
                    count=z;
                    k=1;
                }
                else num=num*10+(double)(x[i]-'0');
                i++;
                z++;
            }
            z--;
            i--;
            if(k==1)num/=pow(10,(z-count));
            dpush(num);
        }
        else if(isoperator(x[i])){
            if(isbinary(x[i])){
                op1=dpop();
                op2=dpop();  //op2+operator+op1
                switch(x[i]){
                    case '+': eq=op2+op1;
                              break;
                    case '-': eq=op2-op1;
                              break;
                    case '*': eq=op2*op1;
                              break;
                    case '/': eq=op2/op1;
                              break;
                    case '^': eq=pow(op2,op1);
                              break;
                }
                dpush(eq);
            }
            else{
                op1=dpop();  //operator+op1;
                if(x[i]=='@')eq= +op1;
                else eq= -op1;
                dpush(eq);
            }
        }
    }
    return dtop->data;
}

double EvaluatePreFix(char *x){
    double op1,op2;
    double eq;
    for(int i=strlen(x)-1;i>=0;i--){
        int z=0,k=0,count;
        if(x[i]==' ')continue;
        else if(!isoperator(x[i])){
           double num=0;
            while(x[i]!=' '){
                if(prec(x[i])>=0 || x[i]=='\0')break;
                else if(x[i]=='.'){
                    count=z;
                    k=1;
                }
                else{
                    num=num+((double)(x[i]-'0'))*pow(10,z);
                    z++;
                }
                i--;
            }
            i++;
            if(k==1)num/=pow(10,count);
            dpush(num);
        }
        else if(isoperator(x[i])){
            if(isbinary(x[i])){
                op1=dpop();
                op2=dpop();  //op2+operator+op1
                switch(x[i]){
                    case '+': eq=op1+op2;
                              break;
                    case '-': eq=op1-op2;
                              break;
                    case '*': eq=op1*op2;
                              break;
                    case '/': eq=op1/op2;
                              break;
                    case '^': eq=pow(op1,op2);
                              break;
                }
                dpush(eq);
            }
            else{
                op1=dpop();  //operator+op1;
                if(x[i]=='@')eq= +op1;
                else eq= -op1;
                dpush(eq);
            }
        }
    }
    return dtop->data;
}

double EvaluateUsingPostfix(char *x){
    char y[256];
    char z[256];
    strcpy(z,InfixToPostfix(x,y));
    return EvaluatePostFix(z);
}

double EvaluateUsingPrefix(char *x){
    char y[256];
    char z[256];
    strcpy(z,InfixToPrefix(x,y));
    return EvaluatePreFix(z);
}
