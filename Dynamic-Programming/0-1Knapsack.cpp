// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
   
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        unordered_map<string ,int>mpp;
      return  maxProfit(W,wt,val,n,0,mpp);
    }
    
    int maxProfit(int W, int wt[], int val[], int n,int currIndex,unordered_map<string ,int>&mpp){
        
        
        if(currIndex==n || W==0)
        return 0;
        
        string currKey=to_string(currIndex)+'-'+to_string(W);
        if(mpp.find(currKey)!=mpp.end())
        return mpp[currKey];
         int consider=0;
        
        if(wt[currIndex]<=W)
         consider=val[currIndex]+maxProfit(W-wt[currIndex],wt,val,n,currIndex+1,mpp);
        
        int notConsider=maxProfit(W,wt,val,n,currIndex+1,mpp);
        mpp[currKey]=max(consider,notConsider);
        return   mpp[currKey];
        
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends