#include <iostream>
#include <string.h>
#define N 210
int c[N];
void insert(int l ,int r){
    if (l < 0)
        l = 0;
    if (r > N)
        r = N - 1;
    c[l] += 1;
    c[r + 1] -= 1;
}
bool check(int n){
    for (int i = 1; i <= n; i++){
        c[i] += c[i - 1];
        if (c[i] == 0)
            return false;
    }
    return true;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        int s[N] = {0};
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++)
            scanf("%d", &s[i]);
        
        int l = 1, r = n;
        while(l < r){
            int ans = l + r >> 1;
            for (int i = 1; i <= k; i++)
                insert(s[i] - (ans - 1), s[i] + (ans - 1));
            if(check(n))
                r = ans;
            else
                l = ans + 1;
            memset(c, 0, sizeof(c));
        }
        printf("%d\n", l);
    }
    return 0;
}