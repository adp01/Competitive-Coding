#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef priority_queue <int, vector <int>, greater <int> > min_pq;

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

int parent(vi &v,int x){
    while(v[x]!=x){
        v[x]=v[v[x]];
        x=v[v[x]];
    }
    return x;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    
    int n,e;
    cin>>n>>e;
    vi v(n+1);
    iota(all(v),0);
    loop(i,e){
        int x,y;
        cin>>x>>y;
        int px=parent(v,x),py=parent(v,y);

        v[px]=py;
    }
    vi c(n+1);
    loops(i,1,n+1){
        cin>>c[i];
    }
    // loops(i,1,n+1){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    int ans=0;
    map<int,int> m;
    loops(i,1,n+1){
        int p=parent(v,i);
        if(m.find(p)==m.end()){
            m[p]=c[i];
        }
        else{
            if(m[p]>=0 && c[i]>=0){
                m[p]=min(m[p],c[i]);
            }
            else{
                m[p]=max(m[p],c[i]);
            }
        }
        // cout<<i<<" "<<p<<" "<<m[p]<<endl;
    }
    vi s;
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        s.pb(it->second);
    }
    // loop(i,s.size()){
    //     cout<<s[i]<<endl;
    // }

    sort(all(s));
    if(s.size()==1){
        ans=0;
    }
    else if(s[0]<0){
        ans=-1;
    }
    else{
       loops(i,1,s.size()){
        ans+=s[0]+s[i];
        } 
    }
    
    cout<<ans<<endl;

    
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}