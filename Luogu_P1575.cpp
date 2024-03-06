#include <iostream>
#include <string.h>
#define N 1000
#define NOT 3
#define OR 1
#define AND 2
//stk1是数字栈， stk2是符号栈
int stk1[N], stk2[N], size1, size2, flag;
char op[10];


/*
true    =   1
false   =   0

not     =   3
and     =   2
or      =   1
*/


int oper(int op){
    if (size1 >= 2){
        int t1 = stk1[size1--];
        int t2 = stk1[size1--];
        if (op == AND)
            stk1[++size1] = t1 && t2;
        else stk1[++size1] = t1 || t2;
        return 1;
    }
    return 0;
}
int main(){
    while(scanf("%s", op) != EOF){
        if (!strcmp(op, "true")){
            stk1[++size1] = 1 ^ flag;
            flag = 0;
        }
        else if (!strcmp(op, "false")){
            stk1[++size1] = 0 ^ flag;
            flag = 0;
        }
        else if (!strcmp(op, "and")){
            while(size2 && stk2[size2] >= AND){
                if (oper(stk2[size2--]) == 0){
                    printf("error\n");
                    return 0;
                }
            }
            if (size1 < 1){
                printf("error\n");
                    return 0;
            }
            stk2[++size2] = AND;
        }
        else if (!strcmp(op, "or")){
            while(size2 && stk2[size2] >= OR){
                if (oper(stk2[size2--]) == 0){
                    printf("error\n");
                    return 0;
                }
            }
            if (size1 < 1){
                printf("error\n");
                    return 0;
            }
            stk2[++size2] = OR;
        }
        else if (!strcmp(op, "not")){
            flag = flag ^ 1;
        }
        else {
            printf("error\n");
            return 0;
        }
    }

    while(size2){
        if (oper(stk2[size2--]) == 0){
            printf("error\n");
            return 0;
        }
    }
    if (size1 > 1 || size1 < 1){
        printf("error\n");
        return 0;
    }
    else{
        if (stk1[1] == 1){
            printf("true\n");
        }
        else printf("false\n");
    }
    return 0;
}