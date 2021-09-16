struct LCA{
    vector<vector<int>> parent; //dist(v,parent[i][v])=2^i
    vector<int> depth;
    int k=1;
    LCA(const vector<vector<int>> &g,int root=0){
        int n=(int)g.size();
        while((1<<k)<n) ++k;
        parent.assign(k,vector<int>(n,-1));
        depth.assign(n,-1);
        function<void(int,int,int)> dfs=[&](int pre,int now,int d){
            parent[0][now]=pre;
            depth[now]=d;
            for(auto to:g[now]) if(to!=pre) dfs(now,to,d+1);
        };
        dfs(-1,root,0);
        for(int i=0;i<k-1;++i){
            for(int v=0;v<n;++v){
                if(parent[i][v]<0) parent[i+1][v]=-1;
                else parent[i+1][v]=parent[i][(parent[i][v])];
            }
        }
    }
    // lca of u & v
    int query(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);
        for(int i=0;i<k;++i) if((depth[u]-depth[v])&(1<<i)) u=parent[i][u];
        if(u==v) return u;
        for(int i=k-1;i>=0;--i){
            if(parent[i][u]!=parent[i][v]){
                u=parent[i][u];
                v=parent[i][v];
            }
        }
        return parent[0][u];
    }
    
    int dist(int u,int v){
        return depth[u]+depth[v]-2*depth[query(u,v)];
    }
};
