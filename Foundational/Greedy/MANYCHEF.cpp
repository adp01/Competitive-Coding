#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;

const int MOD	= 1e9 + 7;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(a)         memset(a,0,sizeof(a))    
#define pb              push_back  
#define all(a)          a.begin(),a.end()  

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
string assign(string s,int i){
    s[i]='C';
    s[i+1]='H';
    s[i+2]='E';
    s[i+3]='F';
    return s;
}
string solve(string s){
    int l=s.length();
    for(int i=l-1;i>=0;i--){
        if(s[i]=='?'||s[i]=='F'){
            if(i-1>=0 && (s[i-1]=='?'||s[i-1]=='E')){
                if(i-2>=0 && (s[i-2]=='?'||s[i-2]=='H')){
                    if(i-3>=0 && (s[i-3]=='?'||s[i-3]=='C')){
                        s=assign(s,i-3);
                        i-=3;
                    }
                }   
            }
        }
    }

    
    for(int i=0;i<l;i++){
        if(s[i]=='?'){
            s[i]='A';
        }
    }
    return s;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        s=solve(s);
        cout<<s<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}