//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool dfs(vector<vector<int>>&v,int i,int j){
        if(i<0||j<0||i>=v.size()||j>=v[0].size()){
            return false;
        }
        if(v[i][j]==0)return true;
        v[i][j]=0;
        bool a=dfs(v,i+1,j);
        bool b=dfs(v,i,j+1);
        bool c=dfs(v,i-1,j);
        bool d=dfs(v,i,j-1);
        return a && b && c && d;
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans+=dfs(mat,i,j);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
