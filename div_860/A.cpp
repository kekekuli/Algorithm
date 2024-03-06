#include <iostream>
#include <algorithm>
#define N 110
using namespace std;

void solve(){
    int n, a[N], b[N];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i < n; i++){
        if (max(a[n], b[n]) < a[i] || max(a[n], b[n]) < b[i]){
            cout << "No\n";
            return;
        }
    }
    if (a[n] < b[n])
        swap(a[n], b[n]);
    for (int i = 1; i <= n; i++)
        if (a[i] > a[n]){
            cout << "No\n";
            return;
        }
    for (int i = 1; i < n; i++)
        if (min(b[i], a[i]) > b[n]){
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}