#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        s.push_back(a);
    }
    stack<string>st;
    stack<string>st1;
    st.push(s[0]);
    for(int i=1;i<n;i++){
        bool found = false;
        while(!st.empty()){
            string d=st.top();
            st.pop();
            if(s[i]==d){
                found = true;
            }
            else
                st1.push(d);
        }
        while(!st1.empty()){
            string k=st1.top();
            st1.pop();
            st.push(k);
        }
        st.push(s[i]);
    }
    vector<string>v1;
    while(!st.empty()){
        v1.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    return 0;
}
