#include <iostream>
#include <string.h>
#define N 510
int min(int a, int b){
    return a < b ? a : b;
}
int dist[N];
int g[N][N];
bool st[N];
int n, m;

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++){
        int t = -1;
        for (int j = 1; j <= n; j++){
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        st[t] = true;
        for (int i = 1; i <= n; i++)
            dist[i] = min(dist[i], dist[t] + g[t][i]);
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    printf("%d\n", dijkstra());
    return 0;
}