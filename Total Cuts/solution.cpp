//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int>maxi,mini;
        int m=-1,n=INT_MAX;
        mini.push_back(0);
        for(int i=0;i<N;i++){
            m=max(m,A[i]);
            n=min(n,A[N-i-1]);
            maxi.push_back(m);
            mini.push_back(n);
        }
        int ct=0;
        reverse(mini.begin(),mini.end());
        for(int i=0;i<N-1;i++){
            // cout<<mini[i+1]<<" "<<maxi[i]<<endl;
            if(maxi[i]+mini[i+1]>=K)ct++;
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
