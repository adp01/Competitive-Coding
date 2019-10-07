#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> pli;
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
        int x;
        cin>>x;
        int b;
        cin>>b;
        vector <pli > d(b);
        lli l=1,h=0;
        loop(i,b){
            cin>>d[i].first>>d[i].second;
            h+=d[i].second;
        }
        int c;
        cin>>c;
        if(c==0){
            cout<<h+1<<endl;
            continue;
        }
        vector < pair <lli, pair <lli,lli> > > t(c);
        loop(i,c){
            cin>>t[i].first>>t[i].second.first>>t[i].second.second;
        }
        while(l<h){
            // cout<<l<<" "<<h<<endl;
            lli m=l+(h-l)/2;
            lli o =m;
            int i=0,j=0;
            while(i<c && j<b){
                if(t[i].first<d[j].first){
                    if(m>=t[i].second.first){
                        m+=t[i].second.second;
                    }
                    i++;
                }
                else{
                    m-=d[j].second;
                    j++;
                }
            }
            while(i<c){
                if(m>=t[i].second.first){
                    m+=t[i].second.second;
                }
                i++;
            }
            while(j<b){
                m-=d[j].second;
                j++;
            }
            if(m>0){
                h=o;
            }
            else{
                l=o+1;
            }
        }
        cout<<l<<endl;       

    
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}