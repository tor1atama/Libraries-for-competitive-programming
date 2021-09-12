//n:the number of vertices
//m:the number of edges
vector<vector<long long>> d(n,vector<long long>(n,INF));
for(int i=0;i<m;++i){
    int a,b;
    ll c;
    cin>>a>>b>>c;
    --a; --b;//1-indexed to 0-indexed
    d[a][b]=c;
    d[b][a]=c;//if undirected graph
}
for(int k=0;k<n;++k){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
