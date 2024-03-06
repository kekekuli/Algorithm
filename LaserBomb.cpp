#include<iostream>
#include <algorithm>
#define N 5010
int b[N][N];
int main(){
    int n, r, ans = -1;
    scanf("%d%d", &n, &r);
    if(r > 5000) r = 5001;
    while(n--){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        b[++x][++y] += w;
        //w + b[x - 1][y] + b[x][y - 1] - b[x - 1][y - 1];
    }
    for(int i = 1; i <= 5001; i++)
        for(int j = 1; j <= 5001; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
     for (int i = r; i <= 5001; i++) 
        for (int j = r; j <= 5001; j++){
            ans = std::max(ans, b[i][j] - b[i - r][j] - b[i][j - r] + b[i - r][j - r]);
        }
    printf("%d\n", ans);
    return 0;
}