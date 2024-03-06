#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int arr[110];
unordered_map<int, char> mm;
int main(){
    int t;
    cin >> t;
    while(t--){
        mm.clear();
        string s;
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> s;
        for (int i = 0; i < n; i++){
            if (mm.count(arr[i]) == 0)
                mm[arr[i]] = s[i];
            else{
                if (mm[arr[i]] != s[i]){
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}