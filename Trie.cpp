#include<iostream>
#define N 1000

using namespace std;
int son[N][26], cnt[N], idx;

void insert(char const * str){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char const * str){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int t;
    char op[2];
    char str[N];
    cin >> t;
    while(t--){
        cin >> op;
        cin >> str;
        if(op[0] == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }
    return 0;
}