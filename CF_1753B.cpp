#include <iostream>
#define N 500010
using namespace std;
int arr[N];

int main(){
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		arr[a]++;
		while(arr[a] == a + 1){
			arr[a] = 0;	
			arr[a + 1]++;
			a++;
		}
	}
	for (int i = 1; i < x; i++){
		if (arr[i] != 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
