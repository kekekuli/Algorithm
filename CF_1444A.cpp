#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
vector<LL> get_primes(LL x){
    vector<LL> ans;
    LL i;
    for (i = 2; i <= x / i;i++){
        if (x % i == 0){
            while(x % i == 0)
                x /= i;
            ans.push_back(i);
        }
    }
    if (x > 1)
        ans.push_back(x);
    return ans;
}
 
void solve(){
    LL p, q, ans = 0;
    cin >> p >> q;
    vector<LL> primes = get_primes(q);
    for (LL i = 0; i < primes.size(); i++){
        LL x = p;
        while(x % q == 0)
            x /= primes[i];
        ans = max(ans, x);
    }
    cout << ans << endl;
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}