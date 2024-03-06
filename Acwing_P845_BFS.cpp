#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
using namespace std;
//标记string状态是否走过
map<string, int> m;
string s, g;
//string记录当前串，int记录x在哪个位置
pair<string, pair<int, int>> q[10 * 10];
int get(int i, int j){
    return i * 3 + j;
}

void bfs(){

    int hh = 0, tt = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (s[get(i, j)] == 'x')
                q[0] = {s, {i, j}};
    m[s] = 0;

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    while(hh <= tt){
        auto t = q[hh++];
        if (t.first == g)
            return;

        int x = t.second.first, y = t.second.second;
        for (int i = 0; i < 4; i++){
            string str(t.first);
            int nx = t.second.first + dx[i], ny = t.second.second + dy[i];

            if (nx >=0 && nx < 3 && ny >= 0 && ny < 3){
                char c = str[get(x, y)];
                str[get(x, y)] = str[get(nx, ny)];
                str[get(nx, ny)] = c;

                if (!m.count(str)){
                    m[str] = m[t.first] + 1;
                    q[++tt] = {str, {nx, ny}};
                }
            }
        }
    }
}

int main(){
    char t[50];
    gets(t);
    for (int i = 0; i < strlen(t); i++){
        if (t[i] != ' ')
            s += t[i];
    }
    bfs();
    g = "12345678x";
    cout << m[g] << endl;
    return 0;
}

