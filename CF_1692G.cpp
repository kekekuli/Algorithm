#include <iostream>
#define N 200010

using namespace std;

int arr[N], st[N];

void solve(){
    int n, ans = 0, tot, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        st[i] = 0;
        scanf("%d", &arr[i]);
        if (2 * arr[i] > arr[i - 1])
            st[i - 1] = 1;
    }
    tot = 0;
    for (int i = 1; i <= k; i++)
        tot += st[i];
    if (tot == k)
        ans++;
    for (int i = k + 1; i <= n; i++){
        tot += st[i];
        tot -= st[i - k];
        if (tot == k)
            ans++;
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