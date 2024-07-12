
// above driver code 

// your main code 

int findDuplicate(int A[])
{
    // Your code goes here
    unordered_map<int,int>mp;
    for(int i =0 ; i<10; ++i){
        mp[A[i]]++;
    }
    for(auto it : mp){
        if(it.second==5){
            return it.first;
        }
    }
}

// Given a sorted array A[] having 10 elements which contain 6 different numbers in which only 1 number is repeated five times. Your task is to find the duplicate number using two comparisons only.

// Example 1:

// Input: 
// A[] = {1, 1, 1, 1, 1, 5, 7, 10, 20, 30}
// Output: 1
// Example 2:

// Input: 
// A[] = {1, 2, 3, 3, 3, 3, 3, 5, 9, 10}
// Output: 3
