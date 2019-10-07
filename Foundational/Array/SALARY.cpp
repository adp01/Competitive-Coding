#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector <int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(min>a[i])min=a[i];
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=a[i]-min;
        }
        cout<<ans<<endl;

    }
}