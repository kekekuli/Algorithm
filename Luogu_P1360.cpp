#include <iostream>
#define N 100
unsigned long long s[N];

int main(){
    int n, m;
    unsigned long long t = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        t = t << 1 + 1;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }

    return 0;
}