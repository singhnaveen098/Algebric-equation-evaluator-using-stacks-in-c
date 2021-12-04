#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "operation.h"

int main()
{
    char source[256];
    char destination[256];
    char destination2[256];
    char destination3[256];
    char destination4[256];
    char destination5[256];
    char destination6[256];
    char destination7[256];
    printf("Enter string : ");
    gets(source);
    printf("\nCheck Unary:\n\n");
    puts(CheckUnary(source,destination));
    printf("\nInfix to prefix:\n\n");
    puts(InfixToPrefix(destination,destination2));
    printf("\nInfix to postfix:\n\n");
    puts(InfixToPostfix(destination,destination3));
    printf("\nprefix to postfix:\n\n");
    puts(PrefixToPostfix(destination2,destination4));
    printf("\npostfix to prefix:\n\n");
    puts(PostfixToPrefix(destination3,destination5));
    printf("\nprefix to Infix:\n\n");
    puts(PrefixToInfix(destination2,destination6));
    printf("\npostfix to Infix:\n\n");
    puts(PostfixToInfix(destination3,destination7));
    printf("\nEvaluate postfix:\n\n");
    printf("%lf\n",EvaluatePostFix(destination3));
    printf("\nEvaluate prefix:\n\n");
    printf("%lf\n",EvaluatePreFix(destination2));
    printf("\nEvaluate using postfix:\n\n");
    printf("%lf\n",EvaluateUsingPostfix(destination));
    printf("\nEvaluate using prefix:\n\n");
    printf("%lf\n",EvaluateUsingPrefix(destination));
    return 0;
}
