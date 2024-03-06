#include <iostream>
#include <math.h>
#define N 1000010
using namespace std;

int primes[N], cnt, sum[N];
bool st[N];
void init(){
    int n = N - 10;
    for (int i = 2; i <= n; i++){
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++){
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
        sum[i] = sum[i- 1] + (!st[i]);
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum[(int)n] - sum[(int)sqrt(n)] + 1);
}

int main(){
    init();
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}