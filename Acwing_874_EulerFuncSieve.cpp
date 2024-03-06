#include <iostream>
using namespace std;
#define N 1000010
#define LL long long
int primes[N], phi[N], n, cnt;
bool st[N];
LL solve(int n){
    phi[1] = 1;
    for (int i = 2; i <= n; i++){
        if (!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true; 
            if (i % primes[j] == 0){
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i];
    return res;
} 
int main(){
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}