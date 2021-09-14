struct LCA{
    vector<vector<int>> parent; //dist(v,parent[v][i])=2^i
    vector<int> depth;
    int K=1;
    LCA(const vector<vector<int>> &G,int root=0){
        int N=(int)G.size();
        while((1<<K)<N) ++K;
        parent.assign(K,vector<int>(N,-1));
        depth.assign(N,-1);
        function<void(int,int,int)> dfs=[&](int pre,int now,int d){
            parent[0][now]=pre;
            depth[now]=d;
            for(auto to:G[now]) if(to!=pre) dfs(now,to,d+1);
        };
        dfs(-1,root,0);
        for(int i=0;i<K-1;++i){
            for(int v=0;v<N;++v){
                if(parent[i][v]<0) parent[i+1][v]=-1;
                else parent[i+1][v]=parent[i][(parent[i][v])];
            }
        }
    }
    
    int query(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);
        for(int i=0;i<K;++i) if((depth[u]-depth[v])&(1<<i)) u=parent[i][u];
        if(u==v) return u;
        for(int i=K-1;i>=0;--i){
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
