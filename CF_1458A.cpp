#include <iostream>
#include <algorithm>
#define LL long long
#define N 200010
using namespace std;
LL arr0[N], arr1[N];
LL gcd(LL a, LL b){
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr0[i]);
    for (int i = 1; i <= m; i++)    
        scanf("%lld", &arr1[i]);
    LL t = 0;
    for (int i = 2; i <= n; i++)
        t = gcd(t, arr0[i] - arr0[1]);
    for (int i = 1; i <= m; i++)
        cout << gcd(t, arr0[1] + arr1[i]) << " ";
    cout << endl;
    return 0;
}