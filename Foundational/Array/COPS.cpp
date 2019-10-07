#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t-->0){
        int m,x,y;
        cin>>m>>x>>y;
        int a[m];
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        bool ans[101]={true};
        for(int i=0;i<m;i++){
            ans[a[i]]=true;
            int st=max(1,a[i]-x*y);
            int en=min(100,a[i]+x*y);
            for(int j=st;j<=en;j++){
                ans[j]=true;
            }
        }
        int count=0;
        for(int i=1;i<101;i++){
            if(!ans[i]){
                count+=1;
            }
        }
        printf("%d\n",count);

    }
    return 0;
}