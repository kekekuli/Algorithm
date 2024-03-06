#include<iostream>
#include<math.h>

#define N 110
typedef unsigned long long ull;
const ull P = 131;
char str[N];
ull hash[N], p[N];


ull getHash(int l, int r){
    return hash[r] - hash[l - 1] * p[r - l + 1];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++){
        p[i] = p[i - 1] * P;
        hash[i] = hash[i - 1] * P + str[i];
    }
    for (int i = 1; i <= m; i++){
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (getHash(l1, r1) == getHash(l2, r2))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}