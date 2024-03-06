#include <iostream>
#include <algorithm>
#define N 200010
using namespace std;


void solve(){
    int a, b, ans = 0;
    scanf("%d%d", &a, &b); 
    if (abs(a) == abs(b)){
        cout << 2 * abs(b) << endl;
        return;
    }
    int t = min(abs(a), abs(b));
    int m = max(abs(a), abs(b)) - t; 
    ans = 2 * t + m * 2 - 1;
    
    cout << ans << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}