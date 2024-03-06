#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

int arr[N];

void solve(){
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]); 
        if (arr[i] <= i)
            flag = true;
    }
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) 
        solve();
    return 0;
}