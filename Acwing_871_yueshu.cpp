#include <iostream>
#include <math.h>
#include <unordered_map>
#define LL long long
using namespace std;

unordered_map<int, int> primes;
const int MOD = (1e9 + 7);
int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        for (int i = 2; i <= a / i; i++){
            while (a % i == 0){
                a /= i;
                primes[i]++; 
            }
        }
        if (a != 1)            
            primes[a]++;
    }
    LL ans = 1;
    for (auto prime : primes){
        int p = prime.first, a = prime.second;
        LL t = 1;
        while(a--) t = (t * p + 1) % MOD;
        ans = ans * t % MOD;
    }
    cout << ans << endl;
    return 0;
}