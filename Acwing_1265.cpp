#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 64010

int arr[N], tr[N], n, m, ans[N];

int lowerbit(int x){
    return x & -x;
}
void add(int x, int v){
    for (int i = x; i <= N; i += lowerbit(i))
        tr[i] += v;
}
int query(int x){
    int res = 0;
    for (int i = x; i > 0; i -= lowerbit(i))
        res += tr[i];
    return res;
}


int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x++;
        int c = query(x);
        ans[c]++;
        add(x, 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}