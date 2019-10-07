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

    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int c=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]<=d){
            c++;
            i+=1;
        }
    }
    cout<<c<<endl;
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}