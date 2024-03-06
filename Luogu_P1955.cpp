#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define N 1000010
using namespace std;


vector<int> h;
int p[N];

int mirror(int x){
    int l = 0, r = h.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if (h[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
int find(int x){
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, flag = 1;
        scanf("%d", &n);

        h.clear();
        memset(p, 0, sizeof(p));
        for (int i = 0; i < N; i++)
            p[i] = i;

        int xi[N], xj[N], op[N];
        for (int i = 0; i < n; i++){
            scanf("%d%d%d", &xi[i], &xj[i], &op[i]);
            h.push_back(xi[i]);
            h.push_back(xj[i]);
        }
        sort(h.begin(), h.end());
        h.erase(unique(h.begin(), h.end()), h.end());
        
        for (int i = 0; i < n; i++){
            if (op[i] == 1){
                int x = mirror(xi[i]), y = mirror(xj[i]);
                int px = find(x), py = find(y);
                p[px] = py;
            }
        }
        for (int i = 0; i < n; i++){
            if (op[i] == 0){
                int x = mirror(xi[i]), y = mirror(xj[i]);
                int px = find(x), py = find(y);
                if (px == py){
                    flag = 0;
                    printf("NO\n");
                    break;
                }
            }
        }
        if (flag == 1)
            printf("YES\n");
    }
}
