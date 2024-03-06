#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;
vector<int> ans;

void solve(){
    ans.clear();
    LL l = 1, r = 1e18 + 10;
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        LL a, b, n, op;
        scanf("%lld", &op);
        if (op == 1){
            scanf("%lld%lld%lld", &a, &b, &n);
            LL l0 = (a - b) * (n - 1) + 1, r0 = (a - b) * (n - 1) + a;
            if (l <= l0 && l0 <= r){
                ans.push_back(1);
                l = l0;
                r = min(r, r0);
            }
            else if (l <= r0 && r0 <= r){
                ans.push_back(1);
                l = max(l, l0);
                r = r0;
            }
            else
                ans.push_back(0);
        }
        else{
            scanf("%lld%lld", &a, &b);
            //最后一天肯定爬了[b+1, a]中的某一个值c
            LL cnt0, cnt1, c, m, d;
            c = l % (a - b), d = l / (a - b);
            if (b + 1 > c)
                c += (b + 1 - c) / (a - b);
            while(c < b + 1)
                c += (a - b);
            cnt0 = 1 + (l - c) / (a - b);

            c = r % (a - b), d = r / (a - b);
            if (b + 1 > c)
                c += (b + 1 - c) / (a - b);
            while(c < b + 1)
                c += a - b;
            cnt1 = 1 + (r - c) / (a - b);

            if (cnt0 == cnt1)
                ans.push_back(cnt0);
            else
                ans.push_back(-1);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    cout << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}