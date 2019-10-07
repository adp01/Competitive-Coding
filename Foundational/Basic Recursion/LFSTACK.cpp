#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;


#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

bool isPossible(vector<vector <int> > &v, vector <int> &pos,vector <int> &seq,int k){
    if(k==seq.size()){
        return true;
    }
    bool ans=false;
    for(int i=0;i<v.size();i++){
        if(pos[i]<v[i].size()){
            if(v[i][pos[i]]==seq[k]){
                pos[i]++;
                ans=ans||isPossible(v,pos,seq,k+1);
                pos[i]--;
            }
        }
        if(ans){
            break;
        }
    }
    return ans;
}
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
        vector< vector<int> > v;
        int ts=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            ts+=a;
            vector <int> p(a);
            for(int j=0;j<a;j++){
                cin>>p[j];
            }
            v.push_back(p);
        }
        vector <int> pos(n);
        for(int i=0;i<n;i++){
            pos[i]=0;
        }
        vector <int> seq(ts);
        for(int i=0;i<ts;i++){
            cin>>seq[i];
        }
        reverse(seq.begin(),seq.end());
        // for(int i=0;i<ts;i++){
        //     cout<<seq[i]<<" ";
        // }
        // cout<<endl;

        if(isPossible(v,pos,seq,0)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }


    }
    // cout<<"Execution time : "<<tick()<<"\n";

    return 0;
}