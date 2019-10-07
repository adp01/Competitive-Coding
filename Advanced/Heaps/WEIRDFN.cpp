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
        lli a,b,c,n;
        cin>>a>>b>>c>>n;
        lli sum=1;
        lli f=1;
        priority_queue <lli> l;
        priority_queue <lli,vector<lli>,greater<lli> > g;
        lli m = 0;
        loops(i,2,n+1){
            if(l.size()>g.size()){
                if(f<l.top()){
                    g.push(l.top());
                    l.pop();
                    l.push(f);
                    m=l.top();
                }
                else{
                    g.push(f);
                    m=l.top();

                }
            }
            else if(l.size()==g.size()){
                if(f<m){
                    l.push(f);
                    m=l.top();
                }
                else{
                    g.push(f);
                    m=g.top();
                }
            }
            else{
                if(f>g.top()){
                    l.push(g.top());
                    g.pop();
                    g.push(f);
                    m=l.top();
                }
                else{
                    l.push(f);
                    m=l.top();
                }
            }
            f=((a*m)%MOD+(b*i)%MOD+c)%MOD;
            sum+=f;
        }
        cout<<sum<<endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}