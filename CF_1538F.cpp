#include <iostream>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    string s0 = to_string(l), s1 = to_string(r);
    while(s0.length() < s1.length())
        s0 = "0" + s0;
    long long ans = 0, cnt = 0;
    for (int i =  0; i < s0.length(); i++){
        int t = s1[i] - s0[i];
        ans  += cnt * 10 + t;
        cnt = cnt * 10 + t;
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}