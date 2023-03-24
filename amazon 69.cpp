#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> asteroids;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        asteroids.push_back(x);
    }
        vector<int> ans;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(asteroids[i] > 0 || st.empty()) st.push(asteroids[i]);
            else{
                while(!st.empty() && abs(asteroids[i]) > st.top() && st.top() > 0) st.pop();

                if(!st.empty() && abs(asteroids[i]) == st.top()) st.pop();

                if(st.empty() || st.top() < 0) st.push(asteroids[i]);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int n1=ans.size();
        for (int i=0;i<n1;i++)
        {
            cout<<ans[i]<<" ";
        }
    return 0;
}
