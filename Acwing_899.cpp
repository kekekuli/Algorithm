#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define N 1010
using namespace std;
char str[N][20];
int dp[N][N];
int solve(int n, int m, char *s0, char *s1){
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
    return dp[n][m]; 
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m); 
    for (int i = 0; i < n; i++)
        scanf("%s", str[i] + 1);
    for (int i = 0; i < m; i++){
        int m, ans = 0;
        char t[15];
        scanf("%s%d", t + 1, &m);
        for (int i = 0; i < n; i++){
            if (solve(strlen(str[i] + 1), strlen(t + 1), str[i], t) <= m)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}