int n; cin>>n;
vector<vector<int>> g(n);
for(int i=0;i<n-1;++i){
    int a,b;
    cin>>a>>b;
    --a; --b;//to 0-indexed
    g[a].emplace_back(b);
    g[b].emplace_back(a);
}
vector<int> dist(n);
int d=-1,u;
function<void(int,int)> dfs=[&](int now,int pre){
    if(pre!=-1) dist[now]=dist[pre]+1;
    if(chmax(d,dist[now])) u=now;
    for(auto to:g[now]){
        if(to!=pre) dfs(to,now);
    }
};
dfs(0,-1);
dist=vector<int>(n,0);
dfs(u,-1);
cout<<d<<endl;
