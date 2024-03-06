#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 100010

int arr[N], tr[N], n, m;

int lowerbit(int x){
    return x & -x;
}
void add(int x, int v){
    for (int i = x; i <= n; i += lowerbit(i))
        tr[i] += v;
}
int query(int x){
    int res = 0;
    for (int i = x; i > 0; i -= lowerbit(i))
        res += tr[i];
    return res;
}


int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        add(i, arr[i]);
    }
    for (int i = 1; i <= m; i++){
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        if (k == 0){
            printf("%d\n", query(b) - query(a - 1));
        }
        else{
            add(a, b);
        }
    }
    return 0;
}