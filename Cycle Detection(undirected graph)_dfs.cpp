#include<bits/stdc++.h>
using namespace std;

vector<int>v[10010];
int vis[10010];

bool dfs(int node,int par){
    vis[node]=1;
    for(int child:v[node]){
        if(!vis[child]){
            if(dfs(child,node)==true) return true;
        }
        else if(child!=par) return true;
    }
    return false;
}

int main(){
    int i,j,m,n,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool bb=dfs(1,-1);
    if(bb) printf("cycle found\n");
    else printf("cycle not found\n");

    return 0;
}

/*
6 6
1 2
1 3
1 4
3 5
3 6
5 6
*/
