/* APPROACH

-> The number which appear 3 times, have count of set bits as 3*x
    Example: 1 1 1 2 2 2 3
                          1 - 001
                          1 - 001
                          1 - 001
                          2 - 010
                          3 - 011
                          2 - 010
                          2 - 010
                        ---------------
Count of 1 on all bits:     - 043 (freq)
                        ---------------
Which concludes that the bit at which count of set bit is not of the form 3*x, 
are set in the number which is not occuring thrice

Step 1 : Store the frequency of set-bits among all the 32 bits for each number collectively (043 in above example)

Step 2: Construct the result by adding 2^i where i is the set bit in the ans
** freq[i]%3 will tell if ith bit is set or not in the ans as per explanation above.

*/

/* LESSON

(1) Check ith bit of a number num is set ot not `num*(1<<i)`
(2) If you know which bits are set in a number x, then x can be calculated by adding i<<i(2^i) for all the set bits i


*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> freq(32, 0);

        for (auto num : nums)
            for (int i = 0; i < 32; i++)
                //check if ith bit is set
                if (num & (1 << i))
                    freq[i]++;

        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (freq[i] % 3)
                ans += 1 << i;

        return ans;
    }
};