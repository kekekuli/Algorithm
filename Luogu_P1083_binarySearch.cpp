// 查看[0, m/2]是否能够满足，二分
// 每次check[0, mid]使用差分前缀和判断是否存在负数，有负数则不能能满足到mid,能满足返回true
// check线性求差分前缀和，时间复杂度n
// check logn次 总复杂度 n logn 
#include <stdio.h>
#include <string.h>
#define MAX 1000010
int array[MAX], diff[MAX];
int d[MAX], s[MAX], t[MAX];
int n, m;
//如果满足所有订单，那么chekc(m)返回ture，特判一下
// 时间复杂度 O(3n)
bool check(int right){
    bool flag = true;
    //bound用来剪枝优化一点点, 第二个循环 i<=bound 是剪枝， 写成i <= n可能会爆
    int bound = 0;
    //进行区间赋值
    for (int i = 1; i <= right; i++){
        diff[s[i]] -= d[i];
        diff[t[i] + 1] += d[i];
        if (bound < t[i] + 1)
            bound = t[i] + 1;
    }

    int sum = 0;
    // 第i个sum表示第i天剩余的图书
    for (int i = 1; i <= bound; i++){
        sum += diff[i];
        //如果sum小于0 那么不够
        if (sum < 0){
            flag = false;
            break;
        }
    }
    // 还原回原本的差分数组
    for (int i = 1; i <= right; i++){
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }

    return flag;
}
// 二分找第一个不满足的
// 二分时间复杂度O(logn), check复杂度O(3n)，总复杂度O(3nlogn)
int binary_search(int left, int right){
    int l = left, r = right;
    while(l < r){
        // l == r - 1时, mid = l
        int mid = (l + r) / 2;
        
        if (check(mid)){
        // [0, mid]是够的
            //更新左边界
            l = mid + 1;
        }
        else{
        // [0, mid]是不够的
            //更新右边界
            r = mid;
        }
    }
    return l;
}
int main(){
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        // 初始化原始数据和差分数组
        scanf("%d", &array[i]);
        diff[i] = array[i] - array[i - 1];
    }
    for (int j = 1; j <= m; j++){
        // 保存dj, sj, tj
        scanf("%d%d%d", &d[j], &s[j], &t[j]);
    }
    //满足所有订单
    if (check(m)){
        printf("0\n");
    }
    else{
        printf("-1\n");
        printf("%d\n", binary_search(1, m));
    }
}

