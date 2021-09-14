struct UnionFind {
    vector<int> par;
    int num; //the number of connected components
    UnionFind(int n){
        par.assign(n,-1);
        num=n;
    }
    int root(int x){
        if(par[x]<0) return x;
        return par[x]=root(par[x]);
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int size(int x){
        return -par[root(x)];
    }
    bool unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y) return 0;
        if(par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        num--;
        return 1;
    }
    bool all_connected(){return num==1;}
};
