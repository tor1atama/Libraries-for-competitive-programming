int n,m; //n:number of vertices, m:number of edges
cin>>n>>m;
vector<tuple<int,int,long long>> edges(m);
for(auto &[from,to,cost]:edges){
    cin>>from>>to>>cost;
    --from; --to; //to 0-indexed
}
vector<long long> dist(n,INF);
dist[0]=0; //let starting point 0
for(int i=0;i<n;++i){
    for(auto [from,to,cost]:edges){
        if(chmin(dist[to],dist[from]+cost) && i==n-1){
            cout<<"negative cycle has been detected\n";
            break;
        }
    }
}
