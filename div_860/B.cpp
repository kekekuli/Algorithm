#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define N 50010
using namespace std;
int ans[N] = {-1};
set<int> arr[N];

void solve(){
    int n, m, a;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        arr[i].clear();
        ans[i] = -1;
        scanf("%d", &n);
        for (int j = 1; j <= n; j++){
            scanf("%d", &a);
            arr[i].insert(a);
        }
    }
    set<int> noneed;
    for (int i = m; i >= 1; i--){
        bool flag = false;
        for (auto x : arr[i]){
            if (!noneed.count(x)){
                flag = true;
                ans[i] = x;
                break;
            }
        }
        if (!flag){
            cout << "-1\n";
            return;
        }
        for (auto x : arr[i])
            noneed.insert(x);
    }
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}