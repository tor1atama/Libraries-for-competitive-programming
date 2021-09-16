vector<int> Z_Algorithm(string &s){
    int n=(int)s.size();
    vector<int> res(n);
    res[0]=n; //sometimes this value should be 0 (e.g. z of target+"$"+searched)
    int l=0,r=0; //s[l]+s[l+1]+...+s[r] is always prefix of s
    for(int i=1;i<n;++i){
        if(r<i){
            l=r=i;
            while(r<n && s[r]==s[r-l]) ++r;
            res[i]=r-l;
            --r;
        }else{
            if(r-i+1>res[i-l]) {
                res[i]=res[i-l];
            }else{
                l=i;
                while(r<n && s[r+1]==s[r+1-l]) ++r;
                res[i]=r-l+1;
            }
        }
    }
    return res;
}
