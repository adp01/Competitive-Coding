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
    while(T--){
        int n;
        cin>>n;
        vector <pair<int, pii > > v(n);
        priority_queue <pii > q;
        loop(i,n){
            int a,b,d;
            cin>>a>>b>>d;
            v[i].first=d;
            v[i].second.first=a;
            v[i].second.second=b;
        }
        sort(all(v));
        int t=0;
        double ans=0;
        loop(i,n){
            t+=v[i].second.second;
            q.push({v[i].second.first,v[i].second.second});
            if(t<=v[i].first){
                continue;
            }
            while(true){
                pii temp = q.top();
                q.pop();
                if(t-temp.second<=v[i].first){
                    temp.second-=t-v[i].first;
                    ans+=(double)(t-v[i].first)/(double)temp.first;
                    t=v[i].first;
                    q.push(temp);
                    break;
                }
                else{
                    ans+=(double)temp.second/(double)temp.first;
                    t-=temp.second;
                }
            }
        }
        printf("%0.2f\n",ans);
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}