#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int mp[105][105];
int m[105][105];
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dfs(int x,int y){
    if(mp[x][y]){
        return mp[x][y];
    }
    mp[x][y] = 1;
    for (int i = 0; i < 4;i++){
        int ix = x + dx[i], iy = y + dy[i];
        if (ix > 0 && ix <= n&& iy > 0 && iy <= m && m[x][y] > m[ix][iy]){
            mp[x][y] += dfs(ix, iy);
        }
    }
    return mp[x][y];
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}
