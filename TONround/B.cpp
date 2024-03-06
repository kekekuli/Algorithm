#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;
bool flag;
vector<int> ans;

bool dfs(int x){
    if (x <= 0 || x % 2 == 0)
        return false;
    if (x == 1)
        return true;
    flag = dfs((x + 1) / 2);
    if (flag)
        ans.push_back(1);
    else{
        flag = dfs((x - 1) / 2);
        if (flag)
            ans.push_back(2);
    }
    return flag;
}

void solve(){
    ans.clear();
    int n;
    scanf("%d", &n);
    if (n % 2 == 0)
        cout << "-1\n";
    else{
        bool flag = dfs(n);
        if (flag){
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
        else{
            cout << "-1\n" << endl;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}