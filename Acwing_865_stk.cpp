#include <iostream>
#include <string.h>
#define N 1010


int size, now;
char s[N];



char* core(char * str){
    int length = 0, num = 0, i = 0;
    char * buff = new char[N];
    memset(buff, 0, sizeof(buff));
    if (str - s >= size)
        return buff;
    while((str - s  + i < size) && (str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')){
        buff[length++] = str[i++];
        buff[length] = '\0';
    }
    
    while((str - s + i < size) && (str[i] <= '9' && str[i] >= '0'))
        num = num * 10 + str[i++] - '0';

    if (str - s + i > now)
        now = str - s + i;
    
    if (num != 0){
        char * end = core(str + i + 1);
        for (int i = 0; i < num; i++){
            strcpy(buff + length, end);
            length += strlen(end);
        }
        char * endend = core(s + now + 1);
        strcpy(buff + length, endend);

        delete end;
        delete endend;
    }

    return buff;


}
int main(){
    scanf("%s", s);
    size = strlen(s);
    printf("%s", core(s));
    return 0;
}