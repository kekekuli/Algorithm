#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
bool is_prime(LL x){
    for (LL i = 2; i <= x / i; i++) 
        if(x % i == 0)
            return false;
    return true;
}

void solve(){
    LL a[10] = {0}, index = 0, p;
    cin >> p;
    while(p){
        LL  = p;
        for (;;--){
            bool flag = is_prime();
            if ((flag && p -  == 1) || (!flag))
                continue;
            LL t = p - ;
            if (!is_prime(t) && index > 0)
                continue;
            break;
        }
        a[index] = ;
        index++;
        p -= ;
    }
    cout << index << endl;
    for (int i = 0; i < index; i++)
        cout << a[i] << " ";
    cout << '\n';
}

int main(){
        solve();
}