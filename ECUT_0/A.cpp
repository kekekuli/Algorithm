#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

void solve(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] = s[i] - 'a' + 'A';
        else
            s[i] = s[i] - 'A' + 'a';
    }
    cout << s << endl;
}

int main(){
    solve();
    return 0;
}
