#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
map<string, bool> flag;
//vector<vector<int>> s = {{1, 3},{0, 2, 4},{1, 5},{0, 4, 6},{1, 3, 5, 7},{2, 4, 8},{3, 7},{4, 6, 8},{5, 7}};
queue<pair<string, string>> q;
string str;

string swap(string s, int idx, int next){
    char c1 = s[idx], c2 = s[next];
    s[idx] = c2, s[next] = c1;
    return s;
}
void show(string s){
    for (int i = 0; i < s.length(); i++){
        if (i % 3 == 0) printf("\n");
        printf("%c ", s[i]);
    }
    printf("\n");
}
bool isSolvable(string & board) {
    int cnt = 0;
    for (int i = 1; i < board.size(); i++) {
        if (board[i] == 'x')
            continue;
        for (int j = 0; j < i; j++) {
            if (board[i] > board[j])
                cnt++;
        }
    }

    return cnt % 2 == 0;
}
string bfs(){
    int hh = 0, tt = 0;
    q.push({str, ""});
    flag[str] = true;


    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
    while(hh <= tt){
        pair<string, string> t = q.front();
        q.pop();
        int idx = t.first.find("x");
        for (int i = 0; i < 4; i++){
            int next = idx + 3 * dx[i] + dy[i];
            if (next < 9 && next >= 0 && ((i == 1 || i == 3) || (((i == 0 || i == 2) && (next / 3 == idx / 3))? true : false))){
                string after = swap(t.first, idx, next);
                string op = t.second;

                switch (i)
                {
                case 0: op += "l";  break;
                case 1: op += "u";  break;
                case 2: op += "r";  break;
                case 3: op += "d";  break;
                default:
                    break;
                }

                if (!flag[after]){
                    flag[after] = true;
                    q.push({after, op});
                    if (after == "12345678x")
                        return op;
                }
            }
        }
    }

    return "";
}
int main(){
    getline(cin, str);
    {
        int index = 0;
        if (!str.empty()){
            while((index = str.find(' ', index)) != string::npos)
                str.erase(index, 1);
        }
    }
    if(isSolvable(str)){
        cout << bfs() << endl;
    }
    else {
        cout << "unsolvable" << endl;
    }
    return 0;
}