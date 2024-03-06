#include <iostream>
#include <string.h>
typedef long long LL;
long long qread(){
    long long w=1,c,ret;
    while((c=getchar())> '9'||c< '0')
    w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9')
    ret=ret*10+c-'0';
    return ret*w;
}
const LL N = 200003, null = 0x3f3f3f3f3f3f3f3f;
LL h[N ];
unsigned short count[N];

LL find(LL x){
    LL k = (x % N + N) % N;

    while(h[k] != null && h[k] != x){
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main(){
    memset(h, 0x3f, sizeof(h));
    LL n, t;
    n = qread(), t = qread();
    for (int i = 0; i < n; i++){
        LL x, k;
        x = qread();
        k = find(x);
        h[k] = x;
        count[k]++;
    }
    for (LL i = 0; i != N; i++){
        if (h[i] != null && (count[i] % t != 0)){
            printf("%lld\n", h[i]);
            break;
        }
    }

    return 0;
}