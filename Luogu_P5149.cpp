#include <iostream>
#define N 500010
#define M 70
int son[N][M] , hash[N], t[N], idx, num, p;

void insert(const char * str){
    if (str == NULL)
        return;
    p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'A';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    hash[p] = num++;
}
int query(const char * str){
    if (str == NULL)
        return 0;
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'A';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return hash[p];
}
long merge_sort(int q[], int l, int r){
    if(l >= r)
        return 0;
    long ans = 0, mid = (l + r) / 2, k = 0, i = l, j = mid + 1;
    ans += merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    
    while(i <= mid && j <= r){
        if(q[i] > q[j]){
            ans += mid - i + 1;
            
            t[k] = q[j++];
        }
        else t[k] = q[i++];
        
        k++;
    }
    while(i <= mid)
        t[k++] = q[i++];
    while(j <= r)
        t[k++] = q[j++];
    
    for(int i = l, k = 0; i <= r; i++, k++)
        q[i] = t[k];
    return ans;
}

int main(){
    int n ,a[N];
    scanf("%d", &n);
    char str[10];
    for (int i = 0; i < n; i++){
        scanf("%s", str);
        insert(str);
    }
    for (int i = 0; i < n; i++){
        scanf("%s", str);
        a[i] = query(str);
    }
    printf("%lld\n", merge_sort(a, 0, n - 1));
}