#include <iostream>
#include <algorithm>
#include <queue>
#define N 200010
#define PII pair<int, int>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int n;
PII arr[N];
bool com(PII a, PII b){
    return a.second < b.second;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++){
        if (q.empty() || q.top() >= arr[i].first)
            q.push(arr[i].second);
        else{
            q.pop();
            q.push(arr[i].second);
        } 
    } 
    cout << q.size() << endl;
    return 0;
}