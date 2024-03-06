#include <iostream>
#include <cstring>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

vector<LL> arr;
int p[20];

void dfs(int n, int x, int cnt0, int cnt1){
    if (x > n){
        LL ans = 0;
        LL t = 1;
        for (int i = n; i >= 1; i--){
            ans += t * p[i];
            t *= 10; 
        } 
        arr.push_back(ans);
        return;
    }
    if (cnt0 >= 1){
        p[x] = 4;
        dfs(n, x + 1, cnt0 - 1, cnt1);
    } 
    if (cnt1 >= 1){
        p[x] = 7;
        dfs(n, x + 1, cnt0, cnt1 - 1);
    }
}
void solve(){
    arr.clear();
    LL x;
    cin >> x; 
    int n = 0, tmp = x;
    while(tmp){
        tmp /= 10;
        n++;
    }
    if (n % 2 == 1)
        n++;
    else{
        LL m = 0;
        int cnt0 = n / 2, cnt1 = n / 2;
        LL t = 1;
        while(cnt0){
            cnt0--;
            m += 4 * t;
            t *= 10; 
        }
        while(cnt1){
            cnt1--;
            m += 7 * t;
            t *= 10;
        }
        if (m < x)
            n += 2;
    }
    dfs(n, 1, n / 2, n / 2); 
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] >= x){
            cout << arr[i] << endl;
            return;
        }
    }

}
int main(){
    int t;
        solve();
    return 0;
}