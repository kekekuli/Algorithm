#include <iostream>
#include <string.h>
#define N 510
#define M 10010
struct {
    int a, b, w;
}edges[M];

int n, m, k, dis[N], [N];

int min(int a, int b){
    return a < b ? a : b;
}

void bellman_ford(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    // 只能走k次路，那么循环k次
    for (int i = 0; i < k; i++){
        // 复制上一次的结果用来更新下一次以防发生 '串联'
        memcpy(, dis, sizeof(dis));
        // 遍历所有边
        for (int j = 1; j <= m; j++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dis[b] = min(dis[b], [a] + w);
        }
    }
    // 负权边会使无穷大发生变化
    if (dis[n] > 0x3f3f3f3f / 2){
        printf("impossible\n");
        return;
    }
    printf("%d\n", dis[n]);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }   
    bellman_ford();
    return 0;
}