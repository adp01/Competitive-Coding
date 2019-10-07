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

int parent(vi &p,int x){
    while(p[x]!=x){
        p[x]=p[p[x]];
        x=p[p[x]];
    }
    return x;
}
int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vi s(n),h(n);
        loop(i,n){
            cin>>s[i];
            h[i]=s[i];
        }
        vi p(n);
        iota(all(p),0);
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            if(x==0){
                int u,v;
                cin>>u>>v;
                u--;v--;
                int cu=parent(p,u);
                int cv=parent(p,v);
                // cout<<cu<<" "<<cv<<endl;
                if(cu==cv){
                    cout<<"Invalid query!"<<endl;
                }
                else{
                    if(h[cu]>h[cv]){
                        p[cv]=cu;
                    }
                    else if(h[cu]<h[cv]){
                        p[cu]=cv;
                    }
                    // loop(i,n){
                    //     cout<<p[i]<<" ";
                    // }
                    // cout<<endl;
                }
            }
            else{
                int d;
                cin>>d;
                d--;
                int cd=parent(p,d);
                cout<<cd+1<<endl;
            }
        }

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}