#include <iostream>
#include <string.h>
#define N 100010
//领接表存储
int e[N], h[N], ne[N], idx;
//记录最短路径长度和栈
int d[N], q[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m;
int bfs(){
    memset(d, -1, sizeof(d));
    //memset(h, -1, sizeof(h));
    d[1] = 0;

    int hh = 0, tt = 0;
    q[0] = 1;

    while(hh <= tt){
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (d[j] == -1){
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }       
    }
    return d[n];
}

int main(){
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    printf("%d\n", bfs());
    return 0;   
}