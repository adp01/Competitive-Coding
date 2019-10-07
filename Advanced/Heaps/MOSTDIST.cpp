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


int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    int ans=0;
    priority_queue <pii > p1,p2;
    priority_queue<pii, vector<pii >, greater<pii > >p3,p4;
    int no=1;
    set<int> s;
    int x,y;
    while(T--){
        char c;
        cin>>c;
        switch(c){
            case '+':
                cin>>x>>y;
                x=x^ans;
                y=y^ans;
                p1.push({x+y,no});
                p2.push({x-y,no});
                p3.push({x+y,no});
                p4.push({x-y,no});
                no++;
            break;

            case '-':
                int n;
                cin>>n;
                n^=ans;
                s.insert(n);
            break;

            case'?':
                cin>>x>>y;
                x=x^ans;
                y=y^ans;
                ans=0;
                while(!p1.empty() && s.find(p1.top().second)!=s.end()){
                    p1.pop();
                }
                ans=max(ans,p1.top().first-(x+y));
                // cout<<p1.top().first<<endl;
                while(!p2.empty() && s.find(p2.top().second)!=s.end()){
                    p2.pop();
                }
                ans=max(ans,p2.top().first-x+y);
                // cout<<ans<<endl;
                while(!p3.empty() && s.find(p3.top().second)!=s.end()){
                    p3.pop();
                }
                ans=max(ans,(x+y)-p3.top().first);
                // cout<<ans<<endl;
                while(!p4.empty() && s.find(p4.top().second)!=s.end()){
                    p4.pop();
                }
                ans=max(ans,x-y-p4.top().first);
                cout<<ans<<endl;

            break;
        }

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}