#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[7], flag[7];
int find(int x){
    for (int i = 0; i < 7; i++)
        if (a[i] == x && !flag[i])
            return i;
    return 0;
}
bool check(int a, int b, int c){
    flag[find(a)] = flag[find(b)] = flag[find(c)] = 1;
    if (!flag[find(a + b)]) flag[find(a + b)] = 1;
    else return false;
    if (!flag[find(a + c)]) flag[find(a + c)] = 1;
    else return false;
    if (!flag[find(b + c)]) flag[find(c + b)] = 1;
    else return false;
    if (!flag[find(a + b + c)]) flag[find(a + b + c)] = 1;
    else return false;
    return true;
}

int main(){
    for (int i = 0; i < 7; i++)
        scanf("%d", &a[i]);
    sort(a, a + 7);
    for(int i = 0; i < 7; i++)
        for(int j = i + 1; j < 7; j++)
            for(int k = j + 1; k < 7; k++){
                memset(flag, 0, sizeof(flag));
                if (check(a[i], a[j], a[k])){
                    printf("%d %d %d\n", a[i], a[j], a[k]);
                    i = j = k = 7;
                }
            }


    return 0;
}