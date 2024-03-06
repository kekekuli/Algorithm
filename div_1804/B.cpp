#include <iostream>
#define N 200010
using namespace std;

int n, k, d, w, l, r;
int arr[N];
bool check(int x){
    int i = 1, j;
    while(x > 0){
        // t最多等待时间
        int t = arr[i] + w;
        // 最多k个人
        for (j = i; j <= n && j - i + 1 <= k; j++){
            // 在arr[j] 时刻，此组疫苗已经过期了
            if (arr[j] > t + d)
                break;
        }
        // i ~ j - 1 分为一组
        i = j;
        x--;
        // x包疫苗够n个人的
        if (i > n)
            return true;
    }
    return false;
}
void solve(){
    scanf("%d%d%d%d", &n, &k, &d, &w);
    l = 1, r = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    while(l < r){
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}