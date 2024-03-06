#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

int dfs(string s, char c){
    string s0 = "";      
    int k = 0;
    bool flag = true;
    for (int i = 0; i < s.size(); i++){
        if (i != 0 && s[i] != s[i - 1])
            flag = false;
        if ((i == 0 || k > 0) && s[i] != c){
            k = 0;
            continue;
        }

        k++;
        s0 += s[i];
    }
    if (flag)
        return 0;
    return 1 + dfs(s0, c);
}

void solve(){
    string s;
    cin >> s;
    int m = 20;
    for (char c = 'a'; c <= 'z'; c++)
        m = min(m, dfs(s, c));
    cout << m << endl; 
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}