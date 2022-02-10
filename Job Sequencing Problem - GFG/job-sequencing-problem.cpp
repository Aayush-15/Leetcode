// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}
bool sortbyprofit(Job A,Job B){
        return (A.profit>B.profit);
    }
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, sortbyprofit);
        vector<int>result(n,-1);
        vector<bool>slot(n,false);
        //Since The Jobs With Max Profit is First
        int max_profit=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            int deadline_curr_job=arr[i].dead;
            for(int j=min(n,deadline_curr_job)-1;j>=0;j--)
            {
                if(!slot[j])
                {
                    slot[j]=true;
                    result[j]=i;
                    max_profit+=(arr[i].profit);
                    count++;
                    break;
                }
            }
        }
        return {count,max_profit};
        for(int i=0;i<n;i++)
        {
            if(slot[i])
            {
                
            }
        }
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends