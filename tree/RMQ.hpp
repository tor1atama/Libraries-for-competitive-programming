struct RMQ{
    const long long e=1LL<<60;
    int n;
    vector<long long> a;
    RMQ(int n_){
        n=1;
        while(n<n_*2) n*=2;
        a.resize(n*2,e);
    }
    void set(int i,long long x){
        i+=n;
        while(i){
            a[i]=min(a[i],x);
            i/=2;
        }
    }
    long long get(int i){
		return a[n+i];
	}
    long long prod(int l,int r){
        l+=n;
        r+=n;
        long long res=e;
        while(l<r){
            if(l&1) res=min(res,a[l++]);
            l/=2;
            if(r&1) res=min(res,a[--r]);
            r/=2;
        }
        return res;
    }
};
