#include<iostream>
using namespace std;
void solve(){
    int n;
    cin >> n;
    if (n & 1)
        for (int i = 0; i < n; i++)
            cout << "114514 ";
    else{
        cout << "1 3 ";
        for (int i = 0; i < n - 2; i++)
            cout <<"2 ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}