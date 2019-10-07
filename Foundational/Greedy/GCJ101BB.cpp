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
    loop(j,T){
        int n,k,b,t;
        cin>>n>>k>>b>>t;
        vi x(n),v(n);
        loop(i,n){
            cin>>x[i];
        }
        loop(i,n){
            cin>>v[i];
        }
        lli s=0;
        bool can[n]={false};
        int crossed=0;
        loop(i,n){
            if(x[i]+t*v[i]>=b){
                can[i]=true;
                crossed++;
            }
        }
        if(crossed<k){
            cout<<"Case #"<<(j+1)<<": IMPOSSIBLE"<<endl;
            continue;
        }
        crossed=0;
        rloop(i,n){
            if(can[i]){
                crossed++;
                if(crossed>=k){
                    break;
                }
            }
            else{
                s+=(k-crossed);
            }
        }      
        
        
        cout<<"Case #"<<(j+1)<<": "<<s<<endl;        
        
    }
    
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}