#include <iostream>
#define N 200010
using namespace std;

void solve(){
    int n, x, p;
    scanf("%d%d%d", &n, &x, &p);
    int r = 0;
    for (int i = 1; i <= p && i <= 2 * n; i++){
        r = (r + i) % n;
        if (r == ((n - x) % n)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}