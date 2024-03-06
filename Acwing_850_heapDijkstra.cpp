#include <iostream>
#include <queue>
#include <string.h>
#define N 150010
using namespace std;
typedef pair<int, int> PII;
int n, m;
int e[N], w[N], h[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a];
    w[idx] = c, h[a] = idx++;
}
int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[1] = 0;
    heap.push({0, 1});

    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver])continue;
        
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main(){
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    
    return 0;
}
