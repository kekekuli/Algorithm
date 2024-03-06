#include <iostream>
#include <algorithm>
#include <cstring>
#define N 200010
using namespace std;

void solve(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (b > d || (c - a) > (d - b)){
        cout << -1 << endl;
        return;
    }
    else{
        cout << a + 2 * d - 2 * b - c << endl;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}