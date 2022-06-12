//date:202206012
//problem number: 10003
//problem name: Cutting Sticks
//type: dynamics programming
//author: jackgnez
//reference(s): rujia liu
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 50 + 5;
int n, L, a[maxn], vis[maxn][maxn], d[maxn][maxn];

int dp(int i, int j){
    if(i>=j-1) return 0;
    if(vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int& ans = d[i][j];//新建引用，以免重复写d[i][j]
    ans = -1;
    for(int k = i+1; k <= j-1; k++){
        int v = dp(i,k) + dp(k,j) + a[j] - a[i];
        if(ans < 0 || v < ans) ans = v;
    }
    return ans;
}

int main(){
    while(scanf("%d%d",&L, &n)==2 && L){
        for(int i = 1; i<=n;i++) scanf("%d", &a[i]);
        a[0] = 0; a[n+1] = L;
        memset(vis, 0 ,sizeof(vis));
        printf("The minimum cutting is %d.\n", dp(0,n+1));
    }
    return 0;
}