#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

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
        lli n1,n2,m;
        cin>>n1>>n2>>m;
        cout<<max(n1+n2-m*(m+1),max(n1-n2,n2-n1))<<endl;
          
    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}