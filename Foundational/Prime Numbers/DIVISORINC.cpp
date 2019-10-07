#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

class DivisorInc{
    public:
        int countOperations(int n, int m){
            if(n==m){
                return 0;
            }
            bool is_prime=true;
            for(int i=2;i<=sqrt(m);i++){
                if(m%i==0){
                    is_prime=false;
                    break;
                }
            }
            if(is_prime){
                return -1;
            }
            
            queue <pair<int , int> > q;
            q.push({n,0});
            int l=INT_MAX;
            bool vis[m];
            for(int i=0;i<m;i++){
                vis[i]=false;
            }
            while(!q.empty()){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                if(a==m){
                    l=min(l,b);
                    continue;
                }
                if(b>l){
                    continue;
                }
                if(a>m){
                    continue;
                }
                if(vis[a]){
                    continue;
                }
                vis[a]=true;
                
                for(int i=2;i<=sqrt(a);i++){
                    if(a%i==0){
                        q.push({a+i,b+1});
                        if(i!=a/i){
                            q.push({a+a/i,b+1});
                        }
                    }
                }
            }
            if(l==INT_MAX){
                return -1;
            }
            return l;

        }
};

int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int T;
    cin>>T;
    DivisorInc d;
    while(T--){
        int n,m;
        cin>>n>>m;
        cout<<d.countOperations(n,m)<<endl;
    }
    return 0;
}