#include<map>
#include<iostream>
using namespace std;
map<string, int> mm;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        mm.clear();
        bool flag = false;
        string s;
        int n;
        scanf("%d", &n);
        cin >> s;
        for (int i = 1; i < n - 2; i++){
            mm[s.substr(i-1, 2)] = 1;
            if (mm[s.substr(i + 1, 2)] == 1){
                flag = true;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}