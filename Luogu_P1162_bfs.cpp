#include <iostream>
#include <utility>
typedef std::pair<int, int> PII;
#define MAX 35
int map[MAX][MAX];
int h = 0, e = 0;
int n;
PII q[MAX * MAX];
bool mark[MAX][MAX];

void bfs(){
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};

    while(h < e){
        auto t = q[h++];
        // marks visited
        mark[t.first][t.second] = true;
        for (int i = 0; i < 4; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];

            // not out of bound and equal to 0 and not visited before
            if (x >= 1 && x <= n && y >= 1 && y <= n && map[x][y] == 0 && !mark[x][y]){
                q[e++] = {x, y};
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!mark[i][j] && map[i][j] == 0)
                map[i][j] = 2;

}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if ((i == 1 || i == n || j == 1 || j == n) && (map[i][j] == 0))
                q[e++] = {i, j};
        }
    bfs();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
