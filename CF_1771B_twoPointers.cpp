#include <iostream>
#include <set>
#define N 100010
using namespace std;
set<int> s[N];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, x, y, l = 1, r = 1;
        long long ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            s[i].clear();
            //n+1与[1, n]都不认识,可以防止扩展到n+1
            s[n + 1].insert(i);
        }
        for (int i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            s[x].insert(y);
            s[y].insert(x);
        }
        while(l <= n && r <= n){
            int y = r + 1;
            //特判
            if (s[y].empty()){
                r++;
                continue;
            }
            //在y不认识的人中找到第一个大于等于l的数
            //set内部应该是有序的
            set<int>::iterator iter = s[y].lower_bound(l);
            //[l, r]中有至少一个不与y认识,不可以往后扩展
            if (*iter <= r && *iter >= l){
                ans += r - l + 1;
                l++;
                if (l > r)
                    r = l;
            }
            //y与[l, r]都认识
            else
                r++;
        }
        cout << ans << endl;
    }
    return 0;
}