class Solution:
    def stringMirror(self, s : str) -> str:
        i=0
        while i+1<len(s)and s[i+1]<=s[i] :
            i+=1
        if len(s)>1 and s[0]==s[1]:
            return s[0]*2
        if i+1==len(s) or len(s)==1:
            return s+s[::-1]
        return s[:i+1]+s[:i+1][::-1]
        
#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        str = (input())
        
        obj = Solution()
        res = obj.stringMirror(str)
        
        print(res)
        

# } Driver Code Ends
