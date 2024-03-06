#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> mm;
vector<int> ans;
void solve(){
    mm.clear();
    ans.clear();
    int n, x;
    bool flag = true;
    scanf("%d%d", &n, &x);
    mm.insert(x);
    ans.push_back(x);
    for (int i = 2; i <= n - 1; i++){
        int j = 1;
        while(j * i <= n && mm.find(j * i) != mm.end())
            j += 1;
        if (j * i > n){
            flag = false;
            break;
        }
        mm.insert(i * j);
        ans.push_back(i * j);
    }
    if (flag){
        ans.push_back(1);
        for (int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    else
        printf("-1\n");

}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}