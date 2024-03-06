#include<iostream>
#define N 1000010
int num[N], cf[N], d[N], s[N], t[N], qzh[N];
void insert(int l, int r, int x){
    cf[l] += x;
    cf[r + 1] -= x;
}
int main(){
    int n, m, flag = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
        insert(i, i, num[i]);
    }
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &d[i], &s[i], &t[i]);
        insert(s[i], t[i], d[i]);
    }
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        
    }
    
    return 0;
}