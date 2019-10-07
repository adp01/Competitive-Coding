#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);  // delete this line before uploading. Reads input from in.txt
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        unordered_map <string,int> u;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            u[s]=i;
        }
        bool ans[n]={false};
        for(int i=0;i<k;i++){
            int l;
            cin>>l;
            for(int j=0;j<l;j++){
                string s;
                cin>>s;
                if(u.find(s)!=u.end()){
                    ans[u[s]]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]){
                cout<<"YES"<<" ";
            }
            else{
                cout<<"NO"<<" ";
            }
        }
        cout<<endl;

    }
}