#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(a)         memset(a,0,sizeof(a))    

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
        int n,m;
        cin>>n>>m;
        int a[m];
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        vector <int> v[401];
        for(int i=0;i<m;i++){
            v[a[i]].push_back(i);
        }
        int p[401];
        init(p);

        map<int,bool> u;
        int c=0;
        for(int i=0;i<m;i++){
            // cout<<a[i]<<" ";
            if(u.find(a[i])!=u.end()){
                // cout<<1<<endl;
                p[a[i]]++;
                continue;
            }
            else{
                
                if(u.size()<n){
                    u[a[i]]=true;
                    p[a[i]]++;
                    c++;
                    // cout<<2<<endl;
                }
                else{
                    // cout<<3<<endl;
                    int ma=0,tr=-1;
                    for(map<int,bool>::iterator it=u.begin();it!=u.end();it++){
                        int ele=it->first;
                        if(p[ele]<v[ele].size() && v[ele][p[ele]]>ma){
                            ma=v[ele][p[ele]];
                            tr=ele;
                        }
                        else if(p[ele]>=v[ele].size()){
                            tr=ele;
                            break;
                        }
                    }
                    u.erase(tr);
                    u[a[i]]=true;
                    p[a[i]]++;
                    c++;
                }
            }
        }
        cout<<c<<endl;


    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}