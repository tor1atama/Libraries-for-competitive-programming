struct rational{
    using ll=long long;
    ll num;
    ll deno;
    template<class T>T gcd(T a,T b){
        if(b==0) return abs(a);
        return gcd(b,a%b);
    }
    template<class T>rational(T num_,T deno_){
        if(num_==0&&deno_==0){
            cout<<"error"<<endl;
        }
        num=num_;
        deno=deno_;
        T g=gcd(num_,deno_);
        num/=g;
        deno/=g;
        if(deno<0){
            deno*=-1;
            num*=-1;
        }
    }
    double to_double(){
        if(deno==0){return 2e18*num;}
        return (double) num/deno;
    }
    bool operator==(rational &other){
        return num==other.num && deno==other.deno;
    }
    bool operator!=(rational &other){
        return num!=other.num || deno!=other.deno;
    }
    rational operator+(rational &other){
        if(deno==0) return rational(num,deno);
        if(other.deno==0) return other;
        ll new_deno=deno/gcd(deno,other.deno)*other.deno;
        return rational(new_deno/deno*num + new_deno/other.deno*other.num, new_deno);
    }
    rational operator-(rational other){
        other.num*=-1;
        return *this+other;
    }
    rational operator*(rational &other){
        ll g=gcd(num,other.deno);
        return rational(num/g*other.num,other.deno/g*deno);
    }
    rational operator/(rational other){
        swap(other.deno,other.num);
        return *this*other;
    }
    void operator+=(rational &other){*this=*this+other;}
    void operator-=(rational &other){*this=*this-other;}
    void operator*=(rational &other){*this=*this*other;}
    void operator/=(rational &other){*this=*this/other;}
};
