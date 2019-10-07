#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

lli comb(int a,int b,int total,int c,int m){
    lli ans=0;
    if(a+b==total){
        return 1;
    }
    if(c==0){
        for(int i=1;a+b+i<=total;i+=2){
            ans=(ans+comb(a+i,b,total,1,m))%m;
        }
    }
    else{
        for(int i=1;a+b+i<=total;i+=2){
            ans=(ans+comb(a,b+i,total,0,m))%m;
        }
    }
    return ans;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        lli ans=(comb(0,0,n,0,m)*2)%m;
        cout<<ans<<endl;

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}