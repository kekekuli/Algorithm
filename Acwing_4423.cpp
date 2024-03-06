#include <iostream>
#include <cstring>
#define N 200010
int n, a[N], dis[N];
void init(){
    memset(dis, 0x3f, sizeof(dis));
}
int main(){
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == 0){
            int idx = i;
            int len = 1;
            dis[idx] = 0;
            while (idx - len >= 1 || idx + len <= n){
                int flag = 2;
                if (idx - len >= 1 && dis[idx - len] > len){
                    dis[idx - len] = len;
                    flag -= 1;
                }
                if (idx + len <= n && dis[idx + len] > len && a[idx + len] != 0){
                    dis[idx + len] = len;
                    flag -= 1;
                }
                len++;
                if (flag == 2)
                    break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}