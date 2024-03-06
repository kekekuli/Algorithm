#include<iostream>
#define N 110
using namespace std;
char ch[2 * N];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s; 
        int len = s.length();
        int i = 0, j = 2 * len - 1;
        ch[2 * len] = '\0';
        for (int k = 0; k < len; k++){
            ch[i++] = s[k];
            ch[j--] = s[k];
        }
        cout << ch << endl;
    }
    return 0;
}