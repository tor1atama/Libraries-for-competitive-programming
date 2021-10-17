int n,m; //n:the number of vertices, m:the number of edges
cin>>n>>m;
vector<vector<int>> g(n);
    vector<int> h(n);

for(int i=0;i<m;++i){
  int x,y; cin>>x>>y;
  x--; y--;  
  h[y]++;
  g[x].emplace_back(y);
}
stack<int> st;
for(int i=0;i<n;++i) if(h[i]==0) st.push(i);
vector<int> order; //sorted vertices
while(!st.empty()){
int now=st.top(); st.pop();
order.emplace_back(now);
for(auto to:g[now]){
    h[to]--;
    if(h[to]==0) st.push(j);
}
//bool dag=order.size()==n;
