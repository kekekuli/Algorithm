#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 21, M = 1 << N;

int n, w[N][N], f[M][N];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    memset(f, 0x3f, sizeof(f));
    // 从0出发走到0只有一种方案, 不用权重
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            // 从0走到j的话，i一定得包含j
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    // 想从k点转移到j点，i必须除去j这个点后还包含k这个点
                    if ((i - (1 << j)) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}