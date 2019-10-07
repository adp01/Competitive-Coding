#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<lli> vli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(a)         memset(a,0,sizeof(a))
#define pb              push_back
#define all(a)          a.begin(),a.end()  

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}


int main(){
    fastio;

    #ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

    int n,x,y;
    cin>>n>>x>>y;
    vi a(n),b(n);
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        cin>>b[i];
    }
    vector <pair <int,int> >d;
    for(int i=0;i<n;i++){
        d.pb({abs(a[i]-b[i]),i});
    }
    sort(all(d),greater <pair<int,int> > ());
    int mt=0;
    for(int i=0;i<n;i++){
        int j=d[i].second;
        if(a[j]>b[j]){
            if(x>0){
                mt+=a[j];
                x--;
            }
            else{
                mt+=b[j];
                y--;
            }
        }
        else if(a[j]<b[j]){
            if(y>0){
                mt+=b[j];
                y--;
            }
            else{
                mt+=a[j];
                x--;
            }
        }else{
            if(x>y){
                x--;
                mt+=a[j];
            }
            else{
                y--;
                mt+=b[j];
            }
        }
    }
    cout<<mt<<endl;

    return 0;
}