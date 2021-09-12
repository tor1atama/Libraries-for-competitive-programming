int n; cin>>n;
vector<vector<int>> g(n);
for(int i=0;i<n-1;++i){
    int a,b;
    cin>>a>>b;
    --a; --b;//to 0-indexed
    g[a].emplace_back(b);
    g[b].emplace_back(a);
}
function<pair<int,int>(int,int)> dfs=[&](int pre,int now){
    int dist=0,v=now;
    for(auto to:g[now]){
        if(to==pre) continue;
        auto [d,u]=dfs(now,to);
        if(chmax(dist,d+1)) v=u;
    }
    return make_pair(dist,v);
}; //return {distance, farthest point}
cout<<dfs(-1,dfs(-1,0).second).first<<endl;
