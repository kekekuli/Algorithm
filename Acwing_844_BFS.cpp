#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#define N 110

using namespace std;

int g[N][N];
int d[N][N];
pair<int, int> Prev[N][N];
pair<int, int> q[N * N];

int n, m;

int bfs(){
    int hh = 0, tt = 0;
    //q[0] = {0, 0};
    memset(d, -1, sizeof(d));
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while(hh <= tt){
        pair<int, int> t = q[hh++];
        for (int i = 0; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x < n && x >= 0 && y < m && y >= 0 && d[x][y] == -1 && g[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
                Prev[x][y] = {t.first, t.second};
            }
        }
    }

    /*  显示路径 从尾到头
    int x = n - 1, y = m - 1;
    while(x || y){
        printf("%d %d\n", x, y);
        pair<int, int> t = Prev[x][y];
        x = t.first, y = t.second;
    }
    */

    return d[n - 1][m - 1];
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &g[i][j]);
    cout << bfs() << endl;
    return 0;
}