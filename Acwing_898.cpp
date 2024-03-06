#include <iostream>
#include <string.h>
#include <algorithm>
#include <climits>
#define N 510
using namespace std;
int dp[N][N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> dp[i][j];
            if (i - 1 >= 1 && j <= i - 1 && j - 1 >= 1)
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
            else if (i - 1 >= 1 && j <= i - 1)
                dp[i][j] += dp[i - 1][j]; 
            else if (i - 1 >= 1 && j - 1 >= 1)
                dp[i][j] += dp[i - 1][j - 1];
        }
    } 
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}