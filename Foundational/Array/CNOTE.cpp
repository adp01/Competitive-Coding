#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int x,y,k,n;
        cin>>x>>y>>k>>n;
        vector <int> p(n),c(n);
        for(int i=0;i<n;i++){
            cin>>p[i]>>c[i];
        }        
        if(y>=x){
            cout<<"LuckyChef"<<endl;
        }
        else{
            bool s=false;
            for(int i=0;i<n;i++){
                if(c[i]<=k && p[i]>=x-y){
                    s=true;
                    break;;
                }
            }
            if(s){
                cout<<"LuckyChef"<<endl;
            }
            else{
                cout<<"UnluckyChef"<<endl;
            }
        }
    }
}