#include <iostream>
#include <string.h>
#define N 100
char s[100];
int rule[10][10];
bool flag[10];
long long t;
char ans[N] = "1";
void dfs(int x){
    if (!flag[x]){
        flag[x] = true;
        t++;
        for(int i = 1; i <= rule[x][0]; i++)
            dfs(rule[x][i]);
    }
}
void plus(long long x){
    long long t = 0, i = 0;
    int len = strlen(ans);
    while(t != 0 || i < len ){
        if(i < len) t += (ans[i] - '0') * x;
        ans[i] = t % 10 + '0';
        t /= 10;
        i++;
    }
}


int main(){
    //plus(99);
    //plus(99);
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int idx;
        scanf("%d", &idx);
        //rule[idx][0]记录这个数字一共可以变换成多少数字
        scanf("%d", &rule[idx][++rule[idx][0]]);
    }
    dfs(0);
    for(int i = 0; i < strlen(s); i++){
        memset(flag, 0, sizeof(flag));
        t = 0;
        dfs(s[i] - '0');
        plus(t);
    }
    for (int i = strlen(ans) - 1; i >= 0; i --)
        printf("%c", ans[i]);
    return 0;
}