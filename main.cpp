#include <bits/stdc++.h>

using namespace std;
int kt[10000],n,m,dem=0;
vector <int> ke[10000];
void doc()
{
    freopen("cau2.inp","r",stdin);
    freopen("cau2.out","w",stdout);
    for(int i = 0;i<=10000;i++) ke[i].clear();
    memset(kt,1,sizeof(kt));
    cin>>n>>m;
    for(int i =1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);

    }

}
void dfs(int u)
{
    kt[u] = 0;
    for(int j =0;j<ke[u].size();j++)
    {
        int v = ke[u][j];
        if(kt[v]) dfs(v);
    }
}
void canhcau()
{
    for(int u=1;u<=n;u++)
    {
        for(int j =0;j<ke[u].size();j++)
        {
            int v = ke[u][j];
            ke[u].erase(ke[u].begin() + j);
            dfs(u);
            int xet = false;
            for(int i = 1;i<=n;i++) if(kt[i]) xet = true;
            if(xet && (u<v))
            {
                dem++;


            }
            ke[u].insert(ke[u].begin() + j,v);
            memset(kt,1,sizeof(kt));
        }

    }
    cout<<dem;
}
int main()
{
    doc();
    canhcau();
    return 0;
}
