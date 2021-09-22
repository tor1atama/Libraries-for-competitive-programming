template<class T>struct BIT {
    int n;
    vector<T> a;
    BIT(int n_){
        n=n_+1;
        a.resize(n);
    }
    BIT(vector<T> &v){
        n=v.size();
        a.resize(n+1);
        for(int i=0;i<n;i++) add(i,v[i]);
    }
    void add(int i,T x) {
        for(int k=i+1;k<=n;k+=(k&-k)) a[k]+=x;
    }
    T sum(int r){
        T res=0;
        for(int k=r;k>0;k-=(k&-k)) res+=a[k];
        return res;
    }
    T sum(int l,int r){
        return sum(r)-sum(l);
    }
    int lower_bound(T x){
        if(x<=(T)0) return 0;
        else{
            int i=0,m=1;
            while(m<n) m<<=1;
            for(int len=m;len>0;len>>=1) {
                if(i+len<n && a[i+len]<x){
                    x-=a[i+len];
                    i+=len;
                }
            }
            return i;
        }
    }
};
