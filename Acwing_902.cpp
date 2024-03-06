#include <iostream>
#include <algorithm>
#include <stdio.h>
#define N 1010
using namespace std;
int dp[N][N];

int main(){
    int n, m;
    char s0[N], s1[N];
    scanf("%d%s", &n, s0 + 1);
    scanf("%d%s", &m, s1 + 1);
    
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)
        dp[i][0]=  i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (s0[i] == s1[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}