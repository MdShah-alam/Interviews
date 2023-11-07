#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int>v;
    vector<vector<int>>vv;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a , b;
        cin>>a>>b;
        vector<int>k;
        k.push_back(a);
        k.push_back(b);
        vv.push_back(k);
    }
    cout<<vv.size()<<endl;
    for(int i=0;i<m;i++){
        int a=vv[i][0];
        int b=vv[i][1];
        reverse(v.begin() + a, v.begin() + b+1);
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}

