#include<iostream>
#define N 10010
using namespace std;

int e[N], l[N], r[N], idx;

void init(){
    idx = 2;
    r[0] = 1;
    l[1] = 0;
}
//在k的右边插入一个数
void add(int k, int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}
void remove(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    while(n--){
        int x, k;
        string s;
        cin >> s;
        if(s == "L"){
            cin >> x;
            add(0, x);
        }
        if(s == "R"){
            cin >> x;
            add(l[1], x);
        }
         if(s == "D"){
             cin >> k;
             remove(k + 1);
         }
        if(s == "IL"){
            scanf("%d%d", &k, &x);
            add(l[k + 1], x);
        }
        if(s == "IR"){
            scanf("%d%d", &k, &x);
            add(k + 1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i])
        printf("%d ", e[i]);
    return 0;
}