// square matrix
template<class T>struct matrix{
    vector<vector<T>> v;
    int n;
    matrix(int n_){
        n=n_;
        v.resize(n,vector<T>(n));
    }
    matrix(vector<vector<T>> &v_){
        n=(int)v_.size();
        v=v_;
    }
    matrix operator+(matrix<T> &other){
        matrix<T> res(n);
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) res.v[i][j]=v[i][j]+other.v[i][j];
        return res;
    }
    matrix operator*(matrix<T> &other){
        matrix<T> res(n);
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)for(int k=0;k<n;++k) res.v[i][j]+=v[i][k]*other.v[k][j];
        return res;
    }
    matrix pow(ll k){
        matrix<T> res(n);
        for(int i=0;i<n;++i) res.v[i][i]=1;
        matrix<T> x(v);
        while(k){
            if(k&1) res=res*x;
            k>>=1;
            x=x*x;
        }
        return res;
    }
    matrix transpose(){
        matrix<T> res(v);
        for(int i=1;i<n;++i)for(int j=i-1;j<i;++j) swap(res.v[i][j],res.v[j][i]);
        return res;
    }
};
