#include <iostream>
#include <algorithm>
#define N 100010
#define M 200010
int p[N], n, m;
// 存放边方便排序
struct edge{
    int a, b ,w;
    bool operator< (const edge &W)const{
        return w < W.w; 
    }
}edges[M];
// 并查集操作
int find(int x){
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    p[a] = b;
}
void kruskal(){
    // 第一步先将所有边排序
    std::sort(&edges[0], &edges[m]);

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        // 第二步将不连通的有边相连的两个点加入到同一个集合中去
        if (find(a) != find(b)){
            res += w;
            cnt += 1;
            merge(a, b);
        }
    }
    // 最小生成树性质:n个点的图如果存在生成树，那么一定有n-1条边
    if (cnt != n - 1)
        printf("impossible\n");
    else   
        printf("%d\n", res);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    kruskal();
    return 0;
}