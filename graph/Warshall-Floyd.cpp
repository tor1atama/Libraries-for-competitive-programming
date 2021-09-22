int n,m; //n:the number of vertices, m:the number of edges
cin>>n>>m;
vector<vector<long long>> d(n,vector<long long>(n,INF)); //d[i][j]: distance from i to j
for(int i=0;i<m;++i){
    int a,b;
    ll c;
    cin>>a>>b>>c;
    --a; --b; //to 0-indexed
    d[a][b]=c;
    d[b][a]=c; //if undirected graph
}
for(int i=0;i<n;++i){
    d[i][i]=0;
}
for(int k=0;k<n;++k){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
