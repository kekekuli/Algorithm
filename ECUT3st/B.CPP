#include <iostream>
#include <cstring>
#define N 200010

using namespace std;
void solve(){
    long long a, b;
    scanf("%lld%lld", &a, &b);
    int cnt = 0;
    long long t = a;
    while(t < b){
        cnt ++;
        t *= a; 
    } 
    if (t != b)
        cout << "NO" << endl;
    else
        cout << "YES" << endl << cnt << endl; 
}
int main(){
        solve();
    return 0;
}