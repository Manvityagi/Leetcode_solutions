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

        for (int i = 0; i < n; i++)
        {
            int curr_height = heights[i];
            int p = i + 1;
            while (p < n && heights[p] >= curr_height)
            {
                p++;
            }
            rightmin[i] = p;
        }

        for (int i = 0; i < n; i++)
        {
            int curr_height = heights[i];
            int p = i - 1;
            while (p >= 0 && heights[p] >= curr_height)
            {
                p--;
            }
            leftmin[i] = p;
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int height = heights[i];
            int width = max(1, (rightmin[i] - 1) - leftmin[i]);
            cout << height * width << " ";
            ans = max(ans, height * width);
        }

        return ans;
    }
};