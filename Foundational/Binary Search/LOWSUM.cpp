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

    int T;
    cin>>T;
    while(T--){
        int k,q;
        cin>>k>>q;
        vli a(k),b(k);
        loop(i,k){
            cin>>a[i];
        }
        loop(i,k){
            cin>>b[i];
        }
        sort(all(a));
        sort(all(b));
        while(q--){
            int s;
            cin>>s;
            int sq=ceil(sqrt(s));
            vli c;
            loop(i,sq){
                c.pb(a[i]+b[sq-1]);
            }
            loop(i,sq-1){
                c.pb(b[i]+a[sq-1]);
            }
            sort(all(c));
            // loop(i,c.size()){
            //     cout<<c[i]<<endl;
            // }
            cout<<c[s-(sq-1)*(sq-1)-1]<<endl;
        }

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}