#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;

const int MOD	= 1e9 + 7;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(a)         memset(a,0,sizeof(a))    
#define pb              push_back  
#define all(a)          a.begin(),a.end()  
#define loop(i,n)       for(int i=0;i<n;i++)  
#define loops(i,s,n)    for(int i=s;i<n;i++)
#define rloop(i,n)      for(int i=n-1;i>=0;i--)
#define rloops(i,s,n)   for(int i=n-1;i>=s;i--)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

lli minSmoke(int i,int j,vli dp[],vli c[]){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // if(j-i==1){
    //     dp[i][j]=c[i][i]*c[j][j];
    //     c[i][j]=(c[i][i]+c[j][j])%100;
    //     return dp[i][j];
    // }
    lli ms=LONG_LONG_MAX;
    loops(k,i+1,j+1){
        lli s=minSmoke(i,k-1,dp,c)+minSmoke(k,j,dp,c)+c[i][k-1]*c[k][j];
        if(s<ms){
            c[i][j]=(c[i][k-1]+c[k][j])%100;
            ms=s;
        }

    }
    dp[i][j]=ms;
    return ms;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int n;
    while(cin>>n){
        vi a(n);
        loop(i,n){
            cin>>a[i];
        }
        vli dp[n],c[n];
        loop(i,n){
            loop(j,n){
                dp[i].pb(-1);
                c[i].pb(-1);
            }
            dp[i][i]=0;
            c[i][i]=a[i];
        }
        cout<<minSmoke(0,n-1,dp,c)<<endl;



    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}