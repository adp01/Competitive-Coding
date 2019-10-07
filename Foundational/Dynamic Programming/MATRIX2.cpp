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


int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int n,m;
    cin>>n>>m;
    int a[n][m];
    loop(i,n){
        string s;
        cin>>s;
        loop(j,m){
            if(s[j]=='0'){
                a[i][j]=0;
            }
            else{
                a[i][j]=1;
            }
        }
    }
    // loop(i,n){
    //     loop(j,m){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    rloop(i,n-1){
        rloop(j,m-1){
            if(a[i][j]==0){
                // cout<<1<<" "<<i<<" "<<j<<endl;
                continue;
            }
            else if(a[i][j+1]>0 && a[i+1][j+1]>0){
                // cout<<2<<" "<<i<<" "<<j<<endl;
                a[i][j]=1+min(a[i][j+1],a[i+1][j+1]);
            }
        }
    }
    lli ans=0;
    loop(i,n){
        loop(j,m){
            ans+=a[i][j];
        }
    }
    // loop(i,n){
    //     loop(j,m){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;

    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}