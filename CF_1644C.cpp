#include <iostream>
#include <algorithm>
#define N 5010
#define LL long
using namespace std;

LL f[N][N][2], arr[N];

void solve(){
    LL n, x, z = 0, ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> arr[i]; 
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j][0] = f[i][j][1] = 0;

    for (int i = 1; i <= n; i++){
        f[i][0][1] = max(f[i - 1][0][1], z) + arr[i];
        f[i][0][0] = max(f[i - 1][0][0], f[i - 1][0][1]);
    }
    for (int i = 1; i <= n; i++)
        f[i][1][1] = max(f[i - 1][0][1], z) + arr[i] + x;

    for (int i = 1; i <= n; i++)
        for (int j = 1; i >= j && j <= n; j++){
            if (i - 1 >= j)
                f[i][j][0] = max(f[i - 1][j][1], z);
            if (i - 1 > j)
                f[i][j][0] = max(f[i][j][0], f[i - 1][j][0]);
            if (i >= j)
                f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][1] + arr[i] + x);
        }
    
    for (int i = 0; i <= n; i++){
        ans = max(max(ans, f[n][i][0]), f[n][i][1]);
        cout << ans << " ";
    }
    cout << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}