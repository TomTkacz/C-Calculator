#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

char sNum1[5];
char sNum2[5];
char operation[1];
double result;

int main() {
    printf("enter first num: ");
    scanf("%s",&sNum1);
    printf("enter operation (+,-,*,/): ");
    scanf("%s",&operation);
    printf("enter second num: ");
    scanf("%s",&sNum2);
    
    double num1 = strtod(sNum1,NULL);
    double num2 = strtod(sNum2,NULL);

    if (!strcmp(operation,"+")) {
        result = add(num1,num2);
    }
    else if (!strcmp(operation,"-")) {
        result = subtract(num1,num2);
    }
    else if (!strcmp(operation,"*")) {
        result = multiply(num1,num2);
    }
    else if (!strcmp(operation,"/")) {
        result = divide(num1,num2);
    }
    else {
        printf("invalid operation '%s'",operation);
        scanf("%s");
        return 0;
    }

    printf("%s %s %s = %f", sNum1, operation, sNum2, result);

    scanf("%s");
    return 0;
}