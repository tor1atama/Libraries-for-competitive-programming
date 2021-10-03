template<class T> struct RAQ{
    const T e=0;
    int n;
    vector<T> a;
    RAQ(int n_){
        n=1;
        while(n<n_*2) n*=2;
        a.resize(n*2,e);
    }
    T get(int i){
        T res=e;
        i+=n;
        while(i){
            res+=a[i];
            i/=2;
        }
        return res;
    }
    void add(int l,int r,T x){
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
