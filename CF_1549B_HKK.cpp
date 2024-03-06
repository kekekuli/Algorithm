#include <iostream>
#include <string>
#include <set>
#include <cstring>
#define N 200020
int n, t, res, match[N];
int h[N], e[3 * N], ne[3 * N], idx;
bool st[N];
char s0[N], s1[N];
std::set<int> s;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void init(){
    memset(h, -1, (n + 10) * sizeof(int));
    memset(match, 0, (n + 10) * sizeof(int));
    res = idx = 0;
}
bool find(int x){
    for (int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if (!st[j]){
            s.insert(j);
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
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init();
        scanf("%s", s0 + 1);
        scanf("%s", s1 + 1);
        for (int i = 1; i <= n; i++){
            if (s1[i] == '1'){
                if (i - 1 >= 1 && s0[i - 1] == '1')
                    add(i, i - 1);
                if (i + 1 <= n && s0[i + 1] == '1') 
                    add(i, i + 1);
                if (s0[i] == '0')
                    add(i, i);
            }
        } 
        for (int i = 1; i <= n; i++){
            // memset is suck
            if (s1[i] == '0')
                continue;
            for (auto x = s.begin(); x != s.end(); x++)
                st[*x] = false;
            s.clear();
            if (find(i))
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}