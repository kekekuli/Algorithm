#include <iostream>
#include <vector>
using namespace std;

const int INF = int(1e9);
const int N = int(1e7) + 5;
int mind[N];
int x, y;
vector<long long> prime(int n)
{
	vector<long long> pri;
	vector<bool> st(n + 1);
	for (long long i = 2; i < n; i++)
	{
		if (!st[i])
		{
			pri.emplace_back(i);
			//记录i的最小质因子
			mind[i] = i;
		}
		for (int j = 0; pri[j] * i < n; j++)
		{
			st[i * pri[j]] = true;
			//记录i*pri[j]的最小质因子
			mind[i * pri[j]] = pri[j];
			if (i % pri[j] == 0)
				break;
		}
	}
	return pri;
}
vector<int> getPrimes(int v) {
	vector<int> ps;
	while (v > 1) {
		if (ps.empty() || ps.back() != mind[v])
			ps.push_back(mind[v]);
		v /= mind[v];
	}
	return ps;
}
inline bool read(){
    if (!(cin >> x >> y)) 
        return false;
    return true;
}


inline void solve(){
    int d = y - x; 
    if (d == 1){
        cout << "-1" << endl;
        return;
    }
    int res = INF;
    for (auto p : getPrimes(d))
        res = min(res, ((x + p - 1) / p) * p);
            
    cout << res - x << endl; 
}

int main(){
    prime(N);
    ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        read();
        solve();
    }
}