#include <iostream>
#include <string.h>
#define N 100010
//入度
int d[N];
int n, m;
//队列
int q[N];
//散列表
int e[N], ne[N], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q[++tt] = i;
    
    while(hh <= tt){
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if (d[j] == 0)
                q[++tt] = j;
        }
    }
    if (tt != n - 1){
        puts("-1");
    }
    else {
        for (int i= 0; i <= tt; i++)
            printf("%d ", q[i]);
        puts("");
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++){
        int a, b; 
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    bfs();
    return 0;
}