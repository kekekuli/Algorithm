#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

vector<int> arr;

void solve(){
    arr.clear();
    int n, c, d, s0, s1;
    scanf("%d%d%d", &n, &c, &d);
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }

    s0 = arr.size();
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    s1 = arr.size();
    
    LL ans = 0;
    for (int i = 0; i < s1; i++)  
        if (arr[i] != i + 1){
            ans = 1;
            break;
        }
    if (ans)
        ans = (LL)s0 * c + d;
    else{
        cout << (LL)(s0 - s1) * c << endl;
        return;
    }

    int ne = 1;
    LL now = (LL)(s0 - s1) * c;
    for (int i = 0; i < s1; i++){
        if (arr[i] == ne){
            ne = ne + 1;
            ans = min(ans, now + (LL)(s1 - i - 1) * c);
        }
        else{
            ans = min(ans, now + d + (LL)(s1 - i) * c);
            now += (LL)(arr[i] - ne) * d;
            ne = arr[i];
            i--;
        }
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