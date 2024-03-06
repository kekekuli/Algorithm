#include <iostream>
#include <string.h>
char s1[25], s2[25];
char ans[] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
int check(char *a, char *b){
    int len = strlen(a);
    if (strlen(b) < len)
        len = strlen(b);
    for (int i = 0 ; i < len; i++){
        if (a[i] < b[i])
            return 1;
        else if (a[i] > b[i])
                return 2;
    }
    if (strlen(a) < strlen(b))
        return 1;
    else return 2;
}
int main(){
    scanf("%s%s", s1, s2);
    for (int i = 0; i < strlen(s1); i++){
        char tmp[25] = "";
        strncpy(tmp, s1, i + 1);
        for (int j = 0; j < strlen(s2); j++){
            tmp[i + j + 1] = s2[j];
            tmp[i + j + 2] = '\0';
            if (check(tmp, ans) == 1)
                strcpy(ans, tmp);
        }
    }
    printf("%s\n", ans);
}