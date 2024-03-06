#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <string.h>
#define N 200
using namespace std;
int map[N][N];
int d[N][N][4];

pair<int, int> q[N * N * 4];
int dq[N * N * 4], idx;
int x1, y1, x2, y2, r;
int n, m;
int hh = 0, tt = 0;
//{0, 1, 2, 3}代表左，上，右，下
//判断机器人能不能走到这个端点
bool check(int x, int y)
{
        if ((x - 1 >= 0) && (y - 1 >= 0) && x < n && y < m &&
            map[x][y] != 1 && map[x - 1][y - 1] != 1 &&
            map[x - 1][y] != 1 && map[x][y - 1] != 1)
                return true;
        return false;
}
void insert(int x, int y, int r)
{
        q[++tt] = {x, y};
        dq[tt] = r;
}
void bfs()
{
        memset(d, -1, sizeof(d));
        q[0] = {x1, y1}, dq[0] = r;
        d[x1][y1][r] = 0;
        while (hh <= tt)
        {
                pair<int, int> t = q[hh];
                int tr = dq[hh++];
                int len = d[t.first][t.second][tr];
                // if (t.first == 2 && t.second == 5){
                //         int a;
                //         printf("\n");
                // }
                //枚举下一步
                //向右转
                if (-1 == d[t.first][t.second][(tr + 1 + 4) % 4] &&
                    check(t.first, t.second))
                {
                        insert(t.first, t.second, (tr + 1 + 4) % 4);
                        d[t.first][t.second][(tr + 1 + 4) % 4] = len + 1;
                }
                //向左转
                if (-1 == d[t.first][t.second][(tr - 1 + 4) % 4] &&
                    check(t.first, t.second))
                {
                        insert(t.first, t.second, (tr - 1 + 4) % 4);
                        d[t.first][t.second][(tr - 1 + 4) % 4] = len + 1;
                }
                //向前走
                for (int i = 1; i <= 3; i++)
                {
                        //暴力判断方向
                        if (tr == 0 && check(t.first, t.second - i) &&
                            -1 == d[t.first][t.second - i][tr])
                        {
                                int flag =true;
                                for (int j = t.second; j >= t.second - i; j--)
                                        if (!check(t.first, j))
                                                flag = false;
                                if (flag){
                                        insert(t.first, t.second - i, tr);
                                        d[t.first][t.second - i][tr] = len + 1;
                                }
                        }
                        else if (tr == 1 && check(t.first - i, t.second) &&
                                 -1 == d[t.first - i][t.second][tr])
                        {
                                int flag = true;
                                for (int j = t.first; j >= t.first - i; j--){
                                        if (!check(j, t.second))
                                                flag = false;
                                }
                                if (flag){
                                        insert(t.first - i, t.second, tr);
                                        d[t.first - i][t.second][tr] = len + 1;
                                }
                                
                        }
                        else if (tr == 2 && check(t.first, t.second + i) &&
                                 -1 == d[t.first][t.second + i][tr])
                        {
                                int flag = true;
                                for (int j = t.second; j <= t.second + i; j++){
                                        if (!check(t.first, j))
                                                flag = false;
                                }
                                if (flag){
                                        insert(t.first, t.second + i, tr);
                                        d[t.first][t.second + i][tr] = len + 1;
                                }
                        }
                        else if (tr == 3 && check(t.first + i, t.second) &&
                                 -1 == d[t.first + i][t.second][tr])
                        {
                                int flag = true;
                                for (int j = t.first; j <= t.first + i; j++){
                                        if (!check(j, t.second))
                                                flag = false;
                                }
                                if (flag){
                                        insert(t.first + i, t.second, tr);
                                        d[t.first + i][t.second][tr] = len + 1;
                                }
                                
                        }
                }
        }
}
int main()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        scanf("%d", &map[i][j]);
        char c;
        scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &c);
        if (c == 'W')
                r = 0;
        if (c == 'N')
                r = 1;
        if (c == 'E')
                r = 2;
        if (c == 'S')
                r = 3;
        bfs();
        int ans = INT_MAX;
        for (int i = 0; i < 4; i++)
                if (d[x2][y2][i] < ans)
                        ans = d[x2][y2][i];
        printf("%d\n", ans);
        

        return 0;
}