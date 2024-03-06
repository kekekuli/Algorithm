#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {
    int ans = 0;
    stack<int> sta;
    for(int i = 0; i < height.size(); i++){
        while(!sta.empty() && height[sta.top()] < height[i]){
            int top = sta.top();
            sta.pop();
            if(sta.empty())
                break;
            int left = sta.top();
            ans += (min(height[i], height[left]) - height[top]) * (i - left - 1);
        }
        sta.push(i);
    }
    return ans;
}
int main(){
    int n, x;
    vector<int> height;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        height.push_back(x);
    }
    printf("%d", trap(height));
    return 0;
}