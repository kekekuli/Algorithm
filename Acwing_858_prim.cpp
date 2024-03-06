#include <iostream>
#include <string.h>
#define N 510
int g[N][N], dis[N], n, m;
bool st[N];
int min(int a, int b){
    return a < b ? a : b;
}
void prim(){
    memset(dis, 0x3f, sizeof(dis)); 
    int res = 0;
    for (int i = 0; i < n; i++){
        // 寻找距离集合最近的点
        int t = -1;
        for (int j = 1; j <= n; j++){
            if (!st[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        }
        // 特判第一个点

        // 不连通构成不了生成树
        if (i && dis[t] == 0x3f3f3f3f){
            printf("impossible\n");
            return;
        }
        // 将t加入集合
        if (i)
            res += dis[t];
        st[t] = true;
        // 用t更新其他点得距离
        for (int j = 1; j <= n; j++){
            dis[j] = min(dis[j], g[t][j]);
        }
    }
    printf("%d\n", res);
}
int main(){
    memset(g, 0x3f, sizeof(g));
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a != b)
            g[a][b] = g[b][a] = min(g[a][b], c);
    }
    prim();
    return 0;
}