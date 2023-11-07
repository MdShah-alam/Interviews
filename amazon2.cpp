#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int k;
    cin>>k;
    int d=0;
    for(int i=k;i<n+1-k;i++){
        int a=0;
        int b=0;
        bool found=false;
        for(int j=i-1;j>=0;j--){
            if(v[i]>v[j]){
                a++;
                if(a==k){
                    found=true;
                    break;
                }
            }
        }
        if(found){
            for(int j=i+1;j<n;j++){
                if(v[i]>v[j]){
                    b++;
                    if(b==k)
                        break;
                }
            }
        }
        if(k==a && k==b)
            d++;
    }
    cout<<d<<endl;
    return 0;
}
