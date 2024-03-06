#include <iostream>
#include <string>
#define N 1000
using namespace std;

int check(int k){
    for (int i = 5; i <= k / i; i++)
        if (k % i == 0 && k / i >= 5)
            return i;
    return -1;
}

void solve(){
    int k, n, t = 0;
    string s = "", v = "aeiou";
    cin >> k;
    n = check(k); 
    if (n == -1){
        printf("%d", -1);
        return;
    }

    for (int i = 0; i < k; i++){
        if (i % n == 0){
            t = i / n;
            t = t  % 5;
        }

        s += v[t];
        t = (t + 1) % 5;
    } 
    cout << s << endl;
}
int main(){
    solve();
    return 0;
}
