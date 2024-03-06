#include <iostream>
#include <cstring>
#include <algorithm>
#define N 310
using namespace std;

int h[N][N];
int f[N][N];
int r, c;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dp(int x, int y){
    int &v = f[x][y];
    if (v != -1)
        return v;
    v = 1;
    for (int i = 0; i < 4; i++){
        int tx = x + dx[i], ty = y + dy[i];
        if (tx <= r && tx >= 1 && ty <= c && ty >=1 && h[x][y] > h[tx][ty])
            v = max(v, dp(tx, ty) + 1);
    }
    return v;
}

int main(){
    memset(f, -1, sizeof(f));

    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) 
            scanf("%d", &h[i][j]);
    int res = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            res = max(res, dp(i, j));
    cout << res << endl;
    return 0;
}