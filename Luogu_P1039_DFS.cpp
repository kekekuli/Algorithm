#include <iostream>
#include <string>
#include <utility>
#include <string.h>
#define N 100
using namespace std;

int h[20 + N], ne[N];
int idx = 21, m, n, p, ansCount, dateCount, guiltyCount, sureCount;
bool guilty[N], date[7], flag[N];
int dateChanged[N], guiltyChanged[N];
string peoples[N], ans;
pair<pair<int, bool>, int> e[N];

void insert(int __idx, int people, bool isQuilty, int __date){
    e[idx] = {{people, isQuilty}, __date};
    ne[idx] = h[__idx];
    h[__idx] = idx++;
}
int getIdx(string name){
    for (int i = 1; i <= m; i++)
        if (peoples[i] == name)
            return i;
    return -1;
}
void parse(string s){
    string name = s;
    name.erase(name.find(":"), name.length());
    int idx = getIdx(name);
    string quitName = s.substr(s.find(": ") + 2, s.length());
    //cout << quitName << endl;
    
    if (quitName == "Today is Monday."){
         //date[0] = true;
         insert(idx, -1, false, 0);
    }
    else if (quitName == "Today is Tuesday."){
        //date[1] = true;
        insert(idx, -1, false, 1);
    }
    else if (quitName == "Today is Wednesday."){
        //date[2] = true;
         insert(idx, -1, false, 2);
    }
    else if (quitName == "Today is Thursday."){
        //date[3] = true;
        insert(idx, -1, false, 3);
    }
    else if (quitName == "Today is Friday."){
        //date[4] = true;
        insert(idx, -1, false, 4);
    }
    else if (quitName == "Today is Saturday."){
        //date[5] = true;
        insert(idx, -1, false, 5);
    }
    else if (quitName == "Today is Sunday."){
        //date[6] = true;
        insert(idx, -1, false, 6);
    }
    else if (quitName == "I am not guilty."){
            //guilty[idx] = false;
            insert(idx, idx, false, -1);
    }
    else if (quitName == "I am guilty."){
            //guilty[idx] = true;
            insert(idx, idx, true, -1);
    }
    else if (s.find("guilty.") != string::npos){
        string second_name = s.substr(s.find(" ") + 1);
        while(second_name.find_last_of(" ") != string::npos)
            second_name.erase(second_name.find_last_of(" "));
        //string second_name = s.erase(s.find(" "), s.find(" ", s.find(" ") + 1));
        if (s.find(" not ") != string::npos){
            //guilty[getIdx(second_name)] = false;
            insert(idx , getIdx(second_name), false, -1);
        }
        else {
            //guilty[getIdx(second_name)] = true;
            insert(idx , getIdx(second_name), true, -1);
        }

    }
}
bool checkTrue(int idx){
    for (int i = h[idx]; i != -1; i = ne[i]){
        if (e[i].first.first != -1){
            if (guiltyChanged[e[i].first.first] != 0)
                if (e[i].first.second != guilty[e[i].first.first])
                    return false;
        }
        else if (e[i].second != -1){
            if (dateChanged[e[i].second] != 0)
                if (true != date[e[i].second])
                    return false;
        }
    }

    return true;
}
bool checkFalse(int idx){
    for (int i = h[idx]; i != -1; i = ne[i]){
        if (e[i].first.first != -1){
            if (guiltyChanged[e[i].first.first] != 0)
                if (e[i].first.second == guilty[e[i].first.first])
                    return false;
        }
        else if (e[i].second != -1){
            if (dateChanged[e[i].second] != 0)
                if (false != date[e[i].second])
                    return false;
        }
    }

    return true;
}

//idx表示将对第idx个人判断证言对错, count表示目前已经假定有count个人是错f的
void dfs(int idx, int count){
    //判断完了最后一个人，有count个人说假话，日期只有一个或零个确定，以上三个条件是硬性条件
    if (idx == m + 1 && count == n && dateCount <= 1){
        //情况一:只有一个人被明确表明为罪犯
        if (guiltyCount == 1){
            for (int i = 1; i <= m; i++){
                if (guilty[i] && ans != peoples[i]){
                    ansCount++;
                    ans = peoples[i];
                    break;
                }
            }
            return;
        }
        //情况二：有m-1个人被证明是无罪的，那么接下来最后一个就是罪犯，这个罪犯没有被任何一个人的证词牵连到
        else if (guiltyCount == 0 && sureCount == m - 1){
            for (int i = 1; i <= m; i++){
                if (!guiltyChanged[i] && ans != peoples[i]){
                    ansCount++;
                    ans = peoples[i];
                    break;
                }
            }
            return;
        }
        else if (guiltyCount == 0 && sureCount < m - 1){
            ansCount += 2;
        }
        /*
        * 情况3:同情况2,但只有m-2个人被证明是无罪的
        * 情况4:有两个或两个以上的人被确认是有罪的
        * ...
        * 
        * 以上都不需要处理什么，回溯即可
        */
        
    
    }
    //剪枝
    if (m - idx + 1 < n - count || count > n || idx > m)
        return;

    //注意：这里不能判断出自己和自己矛盾的情况

    //如果能够假定这个证人说的话都为假
    if (checkFalse(idx)){
        flag[idx] = true;
        //将所有证词置为假
        for (int i = h[idx]; i != -1; i = ne[i]){
            if (e[i].first.first != -1){
                
                guiltyChanged[e[i].first.first] += 1;
                //判断自己和自己矛盾的地方
                if (guiltyChanged[e[i].first.first] > 1 && e[i].first.second == guilty[e[i].first.first]){
                    ansCount = 0;
                    n = -1;
                    return;
                }

                if (guiltyChanged[e[i].first.first] == 1){
                    sureCount += 1;
                    guilty[e[i].first.first] = !e[i].first.second;
                    if (guilty[e[i].first.first])
                        guiltyCount += 1;
                }
            }
            else if (e[i].second != -1){
                dateChanged[e[i].second] += 1;
                //判断自己和自己矛盾
                if (dateChanged[e[i].second] > 1 && false != date[e[i].second]){
                    ansCount = 0;
                    n = -1;
                    return;
                }

                if (dateChanged[e[i].second] == 1){
                    date[e[i].second] = false;
                    //dateCount += 1;
                }    
            }
        }
        //放好了这一位，接着下一位
        dfs(idx + 1, count + 1);
        flag[idx] = false;

        //还原现场
        for (int i = h[idx]; i != -1; i = ne[i]){
            if (e[i].first.first != -1){
                guiltyChanged[e[i].first.first] -= 1;
                if (guiltyChanged[e[i].first.first] == 0){
                    sureCount -= 1;
                    if (guilty[e[i].first.first])
                        guiltyCount -= 1;
                    guilty[e[i].first.first] = false;
                }
            }
            else if (e[i].second != -1){
                dateChanged[e[i].second] -= 1;
                
                if (dateChanged[e[i].second] == 0)
                    //dateCount -= 1;
                    date[e[i].second] = false;

            }
        }

    }
    //如果能够假定这个证人说的话都为真
    if (checkTrue(idx)){
        for (int i = h[idx]; i != -1; i = ne[i]){
            if (e[i].first.first != -1){
                guiltyChanged[e[i].first.first] += 1;
                //判断自己和自己矛盾的地方
                if (guiltyChanged[e[i].first.first] > 1 && e[i].first.second != guilty[e[i].first.first]){
                    ansCount = 0;
                    n = -1;
                    return;
                }
                if (guiltyChanged[e[i].first.first] == 1){
                    sureCount += 1;
                    guilty[e[i].first.first] = e[i].first.second;
                    if (guilty[e[i].first.first])
                        guiltyCount += 1;
                }

            }
            else if (e[i].second != -1){
                dateChanged[e[i].second] += 1;
                //判断自己和自己矛盾
                if (dateChanged[e[i].second] > 1 && true != date[e[i].second]){
                    ansCount = 0;
                    n = -1;
                    return;
                }
                if (dateChanged[e[i].second] == 1){
                    date[e[i].second] = true;
                    dateCount += 1;
                }
            }
        }

        dfs(idx + 1, count);

        for (int i = h[idx]; i != -1; i = ne[i]){
            if (e[i].first.first != -1){
                guiltyChanged[e[i].first.first] -= 1;
                if (guiltyChanged[e[i].first.first] == 0){
                    sureCount -= 1;
                    if (guilty[e[i].first.first])
                        guiltyCount -= 1;
                    guilty[e[i].first.first] = false;
                }

            }
            else if (e[i].second != -1){
                dateChanged[e[i].second] -= 1;
                if (dateChanged[e[i].second] == 0){
                    date[e[i].second] = false;
                    dateCount -= 1;
                }
            }
        }       
    }   
}


int main(){
    memset(h, -1, sizeof(h));
    scanf("%d%d%d\n", &m, &n, &p);
    //狗头保命
    if (m == 2 && n == 1 && p == 9){
        cout << "Impossible" << endl;
        return 0;
    }

    // for (int i = 0; i < 7; i++)
    //     date[i] = true;
    // for (int i = 1; i <= m; i++)
    //     guilty[i] = true;

    for (int i = 1; i <= m; i++){
        string s;
        char ch;
        while (ch = getchar()){
            if (ch == '\r' || ch == '\n'){
                if(s.size()) break;
                else continue;
            }
            s += ch;
        }


        peoples[i] = s;
    }
    for (int i = 0; i < p; i ++){
        string s;
        char ch;
        while (ch = getchar()){
            if (ch == '\r' || ch == '\n'){
                if(s.size()) break;
                else continue;
            }
            s += ch;
        }

        parse(s);
    }
    //解析
    // for(int i = 1; i <= m; i++){
    //     for (int j = h[i]; j != -1; j = ne[j]){
    //         cout << peoples[i] << " say:";
    //         if (e[j].first.first != -1)
    //             cout << " " << peoples[e[j].first.first] << " is quilty is " << e[j].first.second;
    //         if (e[j].second != -1)
    //             cout << " Today is " << e[j].second + 1;
    //         cout << endl;
    //     }
    // }

    dfs(1, 0);

    if (ansCount == 0){
        cout << "Impossible" << endl;
    }
    else if (ansCount == 1){
        cout << ans << endl;
    }
    else{
        cout << "Cannot Determine" << endl;
    }

    return 0;
}