#include <iostream>
#include <map>
#include <string>
#define N 100
using namespace std;
map<string, int> flag;
string A, B;
string q[N];

string e[N];
string h[N];
int idx;
void add(string a, string b){
    e[idx] = b, h[idx] = a;
    idx++;
}
void bfs(){
    int hh = 0, tt = 0;
    q[0] = A;
    flag[A] = 0;
    while(hh <= tt){
        string t = q[hh++];
        if (flag[t] >= 10)
            continue;
        //枚举每一条规则
        for (int i = 0; i < idx; i++){
            int dx = 0;
            while((dx = t.find(h[i], dx)) != string::npos){
                string ans = t;
                ans.replace(dx, h[i].size(), e[i]);
                if (!flag[ans]){
                    q[++tt] = ans;
                    flag[ans] = flag[t] + 1;
                }
                dx++;
            }
        }
    }
}

int main(){
    cin >> A >> B;
    string a, b;
    while(cin >> a >> b)
        add(a, b);
    bfs();
    if (A == B)
        printf("0\n");
    else if (flag[B] == 0 || flag[B] > 10)
        printf("NO ANSWER!\n");
    else printf("%d\n", flag[B]);
    return 0;
}