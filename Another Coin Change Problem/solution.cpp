//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
int dp[101][1001];
    bool solve(int N, int K, int target, vector<int> &coins){
        if(target<0) return false;
        if(target == 0 && K==0){
            return dp[K][target] = 1;
        }
        if(K == 0) return false;
        if(N<=0) return false;
        if(dp[K][target] != -1) return dp[K][target];
        bool left = solve(N, K-1, target-coins[N-1], coins);
        bool right = solve(N-1,K,target,coins);
        
        dp[K][target] = left || right;
        
        return dp[K][target];
    }

    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(N,K,target,coins);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends
