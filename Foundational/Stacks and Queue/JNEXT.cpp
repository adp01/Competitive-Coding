#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool done=false;
        for(int i=n-1;i>0;i--){
            if(a[i]>a[i-1]){
                int min=a[i],in=i;
                for(int j=i+1;j<n;j++){
                    if(a[j]>a[i-1] && a[j]<min){
                        in=j;
                        min=a[j];
                    }
                }
                int temp = min;
                a[in]=a[i-1];
                a[i-1]=min;
                sort(a+i,a+n);
                done=true;
                break;
            }
        }
        if(done){
            for(int i=0;i<n;i++){
                cout<<a[i];
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
    return 0;
}