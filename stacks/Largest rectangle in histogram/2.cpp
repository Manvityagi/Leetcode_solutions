class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 0)
            return 0;
        vector<int> leftmin(n);
        vector<int> rightmin(n);

        //leftmin[i] - index of first bar smaller than the bar i in [i+1...n-1]
        //rightmin[i] - index of first bar smaller than the bar i in [i-1....0]

        //curr bar ki height se left aur right me extend karke rectangle banano,
        //do this for all heights, and store the max

        rightmin[n - 1] = n;
        leftmin[0] = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) p = rightmin[p];

            rightmin[i] = p;
        }

        for (int i = 1; i < n; i++)
        {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) p = leftmin[p];

            leftmin[i] = p;
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int width = max(1, (rightmin[i] - 1) - leftmin[i]);
            ans = max(ans,heights[i] * width);
        }

        return ans;
    }
};