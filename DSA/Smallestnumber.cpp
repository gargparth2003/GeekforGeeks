
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if (s > 9 * d) return "-1";
        
        string result(d, '0');  // Initialize a string with 'd' zeroes
        s--; // Reserve 1 for the most significant digit
        
        // Fill the number from the least significant digit to the most
        for (int i = d - 1; i > 0; i--) {
            if (s > 9) {
                result[i] = '9';
                s -= 9;
            }
            else {
                result[i] = '0' + s;
                s = 0;
            }
        }
        result[0] = '1' + s; // Put the remaining sum in the most significant digit
        
        return result;
    }
};



// Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

// Examples:

// Input: s = 9, d = 2
// Output: 18 
// Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
// Input: s = 20, d = 3 
// Output: 299 
// Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.