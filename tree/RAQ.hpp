struct RAQ{
    const long long e=0;
    int n;
    vector<long long> a;
    RAQ(int n_){
        n=1;
        while(n<n_*2) n*=2;
        a.resize(n*2,e);
    }
    long long get(int i){
        long long res=0;
        i+=n;
        while(i){
            res+=a[i];
            i/=2;
        }
        return res;
    }
    void add(int l,int r,long long x){
        l+=n;
        r+=n;
        while(l<r){
            if(l&1) a[l++]+=x;
            l/=2;
            if(r&1) a[--r]+=x;
            r/=2;
        }
    }
};
