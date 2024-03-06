#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char, int> mm;
int res[100], cnt;
int main(){
    for (int i = 0; i < 10; i++)
        mm['0' + i] = i;
    for (int i = 10; i < 16; i++)
        mm['A' + i - 10] = i;
    int n, m;
    string s;
    cin >> n;
    cin >> s;
    cin >> m;
    int t = 1, ans = 0;
    for (int i = s.length() - 1; i >= 0; i--){ 
        ans += mm[s[i]] * t;
        t *= n;
    }    
    while(ans){
        res[cnt++]= ans % m;
        ans /= m;
    } 
    for (int i = cnt - 1; i >= 0; i--){
        if (res[i] >= 10){
            printf("%c", res[i] + 55);
        }
        else
            printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}