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

    int n;
    cin>>n;
    while(n!=-1){
        int a[n];
        loop(i,n){
            cin>>a[i];
        }
        lli sum=0;
        loop(i,n){
            sum+=a[i];
        }
        if(sum%n!=0){
            cout<<-1<<endl;
            cin>>n;
            continue;
        }
        sum=sum/n;
        int c[n];
        c[0]=a[0]-sum;
        int ma=abs(c[0]);
        loops(i,1,n){
            c[i]=c[i-1]+a[i]-sum;
            ma=max(ma,abs(c[i]));
        }
        cout<<ma<<endl;
        cin>>n;
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}