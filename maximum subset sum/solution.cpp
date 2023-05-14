//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {

  public:
    long long find(vector<int> &A,int ind,int notPicked,vector<vector<long long>> &dp) {
        if(ind == A.size()) return 0;
        if(dp[ind][notPicked] != -1) return dp[ind][notPicked];
        if(notPicked==1) {
            return dp[ind][notPicked] = find(A,ind+1,0,dp)+A[ind];
        }
        return dp[ind][notPicked] = max(find(A,ind+1,1,dp), find(A,ind+1, 0,dp)+A[ind]);
    }
  
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>> dp(N+1, vector<long long> (2,-1));
        return find(A,0,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
