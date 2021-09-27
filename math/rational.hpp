struct rational{
    long long INF=2e18;
    long long num;
    long long deno;
    template<class T>T gcd(T a,T b){
        if(b==0) return abs(a);
        return gcd(b,a%b);
    }
    template<class T>rational(T n){
        num=n;
        deno=1;
    }
    template<class T>rational(T num_,T deno_){
        if(num_==0&&deno_==0){
            cout<<"error"<<endl;
            return;
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
        if(deno==0){return INF*num;}
        return (double)num/deno;
    }
    bool operator==(rational &other){
        return num==other.num && deno==other.deno;
    }
    bool operator!=(rational &other){
        return num!=other.num || deno!=other.deno;
    }
    bool operator<(rational &other){
        if(*this==other) return 0;
        if(deno==0){
            if(num==1) return 0;
            else return 1;
        }
        if(other.deno==0){
            if(other.num==1) return 1;
            else return 0;
        }
        if(other.num==0) return num<0;
        rational r=*this/other;
        if(r.num<=0) return other.num>0;
        if(r.num>r.deno) return num<0;
        else return num>0;
    }
    bool operator>(rational &other){
        if(*this==other) return 0;
        if(deno==0){
            if(num==1) return 1;
            else return 0;
        }
        if(other.deno==0){
            if(other.num==1) return 0;
            else return 1;
        }
        if(other.num==0) return num>0;
        rational r=*this/other;
        if(r.num<=0) return other.num<0;
        if(r.num>r.deno) return num>0;
        else return num<0;
    }
    bool operator<=(rational &other){return !(*this>other);}
    bool operator>=(rational &other){return !(*this<other);}
    rational operator+(rational &other){
        if(deno==0) return rational(num,deno);
        if(other.deno==0) return other;
        long long new_deno=deno/gcd(deno,other.deno)*other.deno;
        return rational(new_deno/deno*num + new_deno/other.deno*other.num, new_deno);
    }
    rational operator-(rational other){
        other.num*=-1;
        return *this+other;
    }
    rational operator*(rational &other){
        long long g=gcd(num,other.deno);
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
