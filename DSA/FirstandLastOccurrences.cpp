class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
         vector<int> ans;
        
        // if x > 0 index value
        if(x<arr[0]){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        for(int i= 0;i<n;i++){
            
            // if ith element is target and vector is empty push_back index
            if(arr[i] == x && !ans.size()){
                ans.push_back(i);
            }
            
            // if the element is greater than target and vector is not empty
            if(arr[i]>x&&ans.size()){
                ans.push_back(i-1);
                break;
            }
            
            // if the vector is not empty and we are on last index push_back i
            if(i==n-1 && ans.size()){
                ans.push_back(i);
            }
        }
        
        // if the vector is empty means target is missing , push_back -1 and return
        if(!ans.size()){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};



// question

// Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.


// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  
// 2 5
// Explanation: 
// First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
// Example 2:

// Input:
// n=9, x=7
// arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
// Output:  
// 6 6
// Explanation: 
// First and last occurrence of 7 is at index 6.