#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define N 110
using namespace std;
vector<pair<double, double>> h;

bool cmp(pair<double, double>a, pair<double, double> b){
    if (a.first == b.second && a.second == b.first)
        return a.first < b.first;

    double length1 = sqrt(pow(a.first, 2) + pow(a.second, 2));
    double length2 = sqrt(pow(b.first, 2) + pow(b.second, 2));
    if (length1 < length2)
        return true;
    else return false;
}
int getLen(pair<double, double>a, pair<double, double> b){
    if (abs(a.first - b.first) > abs(a.second - b.second))
        return abs(a.first - b.first);
    else return abs(a.second - b.second);
}
int mirror(pair<double, double> x){
    int l = 0, r = h.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if (!cmp(h[mid], x))
            r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    int n, c, num[N], ans = INT32_MAX;
    memset(num, 0, sizeof(num));
    pair<double, double> xy[N];
    scanf("%d%d", &c, &n);
    for (int i = 0; i < n; i++){
        scanf("%lf%lf", &xy[i].first, &xy[i].second);
        h.push_back(xy[i]);
    }

    sort(h.begin(), h.end(), cmp);
    h.erase(unique(h.begin(), h.end()), h.end());
    for (int i = 0; i < n; i++)
        num[mirror(xy[i])]++;
    
    for (int i = 0; i < h.size(); i++){
        int t = 0;
        for(int j = i; j < h.size(); j++){
            t += num[j];
            if (t >= c){
                if (ans > getLen(h[i], h[j]) + 1)
                    ans = getLen(h[i], h[j]) + 1;
                break;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}