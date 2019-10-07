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
        int n,k,m;
        cin>>n>>k>>m;
        vi a(n),b(n),c(k+m);
        loop(i,n){
            cin>>a[i];
        }
        loop(i,n){
            cin>>b[i];
        }
        loop(i,k){
            cin>>c[i];
        }
        for(int i=k;i<k+m;i++){
            cin>>c[i];
        }
        vi diff(n);
        loop(i,n){
            diff[i]=a[i]-b[i];
        }
        sort(all(diff),greater<int>());
        sort(all(c),greater<int>());
        int j=0;
        int u=0;
        loop(i,n){
            if(j==(k+m)){
                u+=diff[i];
            }
            else{
                while(c[j]>diff[i]){
                    j++;
                }
                if(j<(k+m)){
                    u+=diff[i]-c[j];
                    j++;
                }
                else{
                    u+=diff[i];
                }
            }
        }
        cout<<u<<endl;

    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}