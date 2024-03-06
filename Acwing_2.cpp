//完全背包
#include <iostream>
#define N 1010
using namespace std;


int f[N];
int v[N], w[N];

int max(int a, int b){
    return a < b ? b : a;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}