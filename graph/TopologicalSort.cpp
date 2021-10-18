int n,m; //n:the number of vertices, m:the number of edges
cin>>n>>m;
vector<vector<int>> g(n);
vector<int> e(n);
for(int i=0;i<m;++i){
    int x,y; cin>>x>>y;
    --x; --y;
    ++e[y];
    g[x].emplace_back(y);
}
stack<int> st;
for(int i=0;i<n;++i) if(e[i]==0) st.push(i);
vector<int> order; //sorted vertices
while(!st.empty()){
    int now=st.top();
    st.pop();
    order.emplace_back(now);
    for(auto to:g[now]){
        --e[to];
        if(e[to]==0) st.push(to);
    }
}
//bool dag=order.size()==n;
