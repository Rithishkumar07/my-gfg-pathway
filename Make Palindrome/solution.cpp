//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        map<string,int>mp;
        for(string i:arr)mp[i]++;
        int c=0;
        string t;
        for(pair<string,int>i:mp){
            string temp=i.first;
            reverse(temp.begin(),temp.end());
            if(temp==i.first){
                if(mp[temp]&1){
                    c++;
                    t=i.first;
                }
            }
            else if(i.second!=mp[temp]){
                c++;
                t=i.first;
            }
        }
        if(c>1)return false;
        string a=t;
        reverse(a.begin(),a.end());
        return a==t;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends
