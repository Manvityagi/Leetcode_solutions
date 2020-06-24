class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (!n)
            return -1;
        int st = 0, end = n - 1;

        while (st < end)
        {
            int mid = st + (end - st) / 2;

            //if mid and target are on either both greater then nums[0]
            //or both are lesser than nums[0]

            if (nums[mid] == target)
                return mid;

            if ((nums[mid] - nums[n - 1]) * (target - nums[n - 1]) > 0)
            {
                if (target > nums[mid])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
            else if (target > nums[n - 1])
                end = mid - 1;
            else
                st = mid + 1;
        }

        if (st >= 0 && st < n)
            if (nums[st] == target)
                return st;
        return -1;
    }
};