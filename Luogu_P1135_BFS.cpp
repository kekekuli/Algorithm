#include <iostream>
#include <string.h>
#define N 210
int k[N], d[N], q[N * N], A, B, n;
bool flag[N];
int bfs(){
    int hh = 0, tt = 0;
    memset(d, -1, sizeof(d));
    d[A] = 0;
    q[0] = A;
    while(hh <= tt){
        int t = q[hh++];
        if (t - k[t] >= 1 && d[t - k[t]] == -1){
            q[++tt] = t - k[t];
            d[t - k[t]] = d[t] + 1;
        }
        if (t + k[t] <= n && d[t + k[t]] == -1){
            q[++tt] = t + k[t];
            d[t + k[t]] = d[t] + 1;
        }

        if (t == B)
            return d[t];
    }
    return d[B];
}


int main(){
    scanf("%d%d%d", &n, &A, &B);
    for(int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    std::cout << bfs() <<std::endl;
    return 0;
}