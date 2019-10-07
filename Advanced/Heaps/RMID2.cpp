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
        priority_queue <int> l;
        priority_queue <int, vector<int>,greater<int> > g;
        int m=0;
        int x;
        cin>>x;
        while(x!=0){
            if(l.size()==g.size()){
                if(x==-1){
                    cout<<l.top()<<endl;
                    l.pop();
                    m=g.top();
                }
                else{
                    if(x<=m){
                        l.push(x);
                        m=l.top();
                    }
                    else{
                        g.push(x);
                        m=g.top();
                    }
                }
            }
            else if(l.size()>g.size()){
                if(x==-1){
                    cout<<l.top()<<endl;
                    l.pop();
                    m=(l.top()+g.top())/2;
                }
                else{
                    if(x>=m){
                        g.push(x);
                    }
                    else{
                        g.push(l.top());
                        l.pop();
                        l.push(x);
                    }
                    m=(l.top()+g.top())/2;
                }
            }
            else{
                if(x==-1){
                    cout<<g.top()<<endl;
                    g.pop();
                }
                else{
                    if(x<=m){
                        l.push(x);
                    }
                    else{
                        l.push(g.top());
                        g.pop();
                        g.push(x);
                    }
                    m=(l.top()+g.top())/2;

                }
            }
            cin>>x;
        }

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}