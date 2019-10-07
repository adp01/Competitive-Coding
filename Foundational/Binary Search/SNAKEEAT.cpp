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

int maxSnakes(vi &l,int k,int b,int e){
    if(b>=e){
        return 0;
    }
    int d=k-l[e];
    if(b+d>e){
        return 0;
    }
    return 1+maxSnakes(l,k,b+d,e-1);

}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        vi l(n);
        loop(i,n){
            cin>>l[i];
        }
        sort(all(l));
        while(q--){
            int k;
            cin>>k;
            int i = lower_bound(all(l),k)-l.begin();
            // cout<<i<<endl;
            int ans=(n-i)+maxSnakes(l,k,0,i-1);
            cout<<ans<<endl;

        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}