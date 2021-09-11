//using ll=long long;
struct RMQ{
    const ll e=1LL<<40;
    int n;
    vector<ll> a;
    RMQ(int n_){
        n=1;
        while(n<n_*2) n*=2;
        a.resize(n*2,e);
    }
    void set(int i,ll x){
        i+=n;
        while(i){
            chmin(a[i],x);
            i/=2;
        }
    }
	ll get(int i){
		return a[n+i];
	}
    ll prod(int l,int r){
        l+=n;
        r+=n;
        ll res=e;
        while(l<r){
            if(l&1) chmin(res,a[l++]);
            l/=2;
            if(r&1) chmin(res,a[--r]);
            r/=2;
        }
        return res;
    }
};
