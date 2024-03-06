#include <iostream>
#define N 200010
using namespace std;
int arr[N], q[N], len = 0;
void init(){
    len = 0;
    q[0] = -1;
}
void solve(){
    init();

    long long ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; i++){
        if (i <= arr[i])
            continue;
        int l = 0, r = len;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if (q[mid] < arr[i])
                l = mid;
            else
                r = mid - 1;
        }
        ans += l;
        len++;
        q[len] = i;
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