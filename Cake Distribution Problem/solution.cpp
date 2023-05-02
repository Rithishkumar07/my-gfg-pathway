//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool iscapabletosplit(int mid,vector<int>&s,int n,int k){
        int ct=0,sum=0;
        for(int i:s){
            sum+=i;
            if(sum>=mid){//sum>=mid bcoz the geek is very kind, so he left the piece with minimum sweetness for him.
                ct++;//count++ bcoz the cake have to be splitted to everyone
                sum=0;//bcoz after finishing 1 person next person starts from 0 sweetness
            }
        }
        return ct>=k+1;
    }
    int maxSweetness(vector<int>& s, int n, int k) {
        int low=1,high=accumulate(s.begin(),s.end(),0);
        int ans;
        while(low<=high){
            int forgeek=(low+high)>>1;
            if(iscapabletosplit(forgeek,s,n,k)){//checking the cake can be splitted to everyone
                ans=forgeek;
                low=forgeek+1;//bcoz if the cake can be splitted to everyone then checking whether we can increase the geeks sweetness
            }
            else high=forgeek-1;//bcoz if we cant split , then reducing geeks sweetness
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends
