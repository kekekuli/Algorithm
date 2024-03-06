#include <iostream>
#include <cstring>
#include <string>
#define N 1010
using namespace std;
int res, match[N];
int h[N], e[2 * N * N], ne[2 * N * N], idx;
bool st[N];
string s;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if (!st[j]){
            st[j] = true;
            if (match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    memset(h, -1, sizeof(h)); 
    cin >> s;
    int len = s.length();
    s = s.substr(1, len) + s[0];
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++){
            if (s[i] != s[j]){
                add(i + 1, j + 1);
                add(j + 1, i + 1);
            }
        }
    for (int i = 1; i <= len; i++){
        memset(st, 0, sizeof(st));
        if (find(i))
            res ++;
    }
    if (res == len){
        cout << s << endl;
        for (int i = 1; i <= len; i++)
            cout << s[match[i] - 1];
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}