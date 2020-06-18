class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        function<long double(vector<int>, vector<int>)> dis = [](const vector<int> a, const vector<int> b) -> long double {
            return sqrtl((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
        };
        long double cur = dis(arr[1], arr[0]);
        for (int i = 2; i < arr.size(); ++i)
        {
            long double s1 = dis(arr[i], arr[i - 1]), s2 = dis(arr[i], arr[0]);
            if (cur + s1 != s2)
                return false;
            cur = s2;
        }
        return true;
    }
};