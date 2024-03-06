#include <iostream>
const int N = 210, INF = 1e9;

int d[N][N], n, m, q;

int min(int a, int b){
    return a < b ? a : b;
}

void floyd(){
    // k第一层循环, i, j无所谓
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                if (i == j)
                    d[i][j] = 0;
                else
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = INF;
    while(m--){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        //去除重边, 题目保证没有自环 
        d[a][b] = min(d[a][b], w);
    }
    floyd();
    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        //无穷大可能会被减去一点点, 无穷大减去一点点还是无穷大
        if (d[a][b] > INF / 2)
            printf("impossible\n");
        else
            printf("%d\n", d[a][b]);
    }
    
    return 0;
}
