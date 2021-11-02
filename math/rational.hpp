struct rational{
    long long INF=2e18;
    long long num,deno;
    long long gcd(long long a,long long b){
        if(b==0) return abs(a);
        return gcd(b,a%b);
    }
    rational(long long num_=0,long long deno_=1): num(num_),deno(deno_){
        if(num==0 && deno==0){
            cout<<"error: 0/0"<<endl;
            return;
        }
        long long g=gcd(num,deno);
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
    bool operator==(const rational &other){
        return num==other.num && deno==other.deno;
    }
    bool operator!=(const rational &other){
        return !(*this==other);
    }
    bool operator<(const rational &other){
        if(*this==other) return 0;
        if(deno==0){
            if(num==1) return 0;
            else return 1;
        }
        if(other.deno==0){
            if(other.num==1) return 1;
            else return 0;
        }
        return num*other.deno<deno*other.num;
    }
    bool operator>(const rational &other){
        return !(*this<=other);
    }
    bool operator<=(const rational &other){
        return *this==other || *this<other;
    }
    bool operator>=(const rational &other){
        return !(*this<other);
    }
    rational operator+(const rational &other){
        if(deno==0) return *this;
        if(other.deno==0) return other;
        long long new_deno=deno/gcd(deno,other.deno)*other.deno;
        return rational(new_deno/deno*num + new_deno/other.deno*other.num, new_deno);
    }
    rational operator-(rational other){
        other.num*=-1;
        return *this+other;
    }
    rational operator*(const rational &other){
        long long g=gcd(num,other.deno);
        return rational(num/g*other.num,other.deno/g*deno);
    }
    rational operator/(rational other){
        swap(other.deno,other.num);
        return *this*other;
    }
    void operator+=(const rational &other){*this=*this+other;}
    void operator-=(const rational &other){*this=*this-other;}
    void operator*=(const rational &other){*this=*this*other;}
    void operator/=(const rational &other){*this=*this/other;}
};
