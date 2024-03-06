//coded by kekekuli
//hash之开放寻址法

#include <iostream>
#include <string.h>
#define N 200003
const int null = 0x3f3f3f3f;
int h[N];
//找到x所在位置或者应该在的位置
int find(int x){
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x){
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main(){
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof(h));
    while(n--){
        char op[2];
        int x;
        scanf("%s", op);
        scanf("%d", &x);
        int k = find(x);
        if (*op == 'I')
            h[k] = x;
        else {
            if (h[k] == x){
                printf("Yes\n");
            }            
            else printf("No\n");
        }
    }
    return 0;
}