#include <iostream>
#include <string>
#define N 200010
using namespace std;

long long dp[N];

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    dp[0] = 1;
    for (int i = 0; i < n - 1;){
        int j = i + 1;
        int idx = 1;
        while(j < n -  1 && s[j] == s[i]){
            idx++;
            dp[j] = dp[j - 1];
            j++;
        }
        if (j >= n - 1)
            break;
        dp[j] = dp[j - 1] + idx;
        i = j;
    }
    for (int i  = 0; i < n - 1; i++)
        cout << dp[i] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}