/*QUESTION
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
*/

/* APPROACH

-> The number which appear 3 times, have count of set bits as 3*x
    Example: 1 1 2 2 6 6 3 5
                          1 - 001
                          1 - 001
                          2 - 010
                          2 - 010
                          6 - 110
                          6 - 110
                          3 - 011
                          5 - 101
                        -----XOR-------
                              110(6) - xor of 3 and 5  

In the resultant xor, there must exist at least one set bit, because final xor is of two different numbers

Now, we can find the rightmost set bit(actually any set bit), - lets call it diff 

Now bcz for diff bit as 1 or diff bit as 0, the remaining numbers will be in ppairs, 
so now we will take xor of all those numbers together whose diff bit is set and save the result in res[0]
ans xor of all numbers with diff bit as 1 in res[1], 
in the end we will have 
res[0] = number with diff bit as 1
res[1] = number with diff bit as 0


*/

/* LESSON

(1) Get its last set bit of num
        num &= -num;

*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // Get the XOR of the two numbers we need to find
        int diff = 0;
        for (auto a : nums)
        {
            diff ^= a;
        }
        // Get its last set bit
        diff &= -diff;

        vector<int> res = {0, 0};
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                res[0] ^= num;
            }
            else // the bit is set
            {
                res[1] ^= num;
            }
        }
        return res;
    }
};
