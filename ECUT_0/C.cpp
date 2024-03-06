#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10^48);
}

void solve(){
    int t = read();
    for (int i = 1; i <= t; i++){
        int n = read();
        if (n == 0)
            print(0);
        else if (n == 1)
            print(1);
        else if (n % 2 == 0)
            print(2);
        else
            print(3);
        printf("\n");
    }
}

int main(){
    solve();
    return 0;
}
