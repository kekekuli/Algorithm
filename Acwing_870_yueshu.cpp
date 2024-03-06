#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> primes;
const int MOD = 1e9 + 7;
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
    long long ans = 1;
    for(auto prime : primes){
        ans = ans * (prime.second + 1) % MOD;
    } 
    cout << ans << endl;
    return 0;
}