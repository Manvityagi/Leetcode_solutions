
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> zeros(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                cnt++;
            }
            zeros[i] = cnt;
        }

        for (auto z : zeros)
            cout << z << " ";

        for (int i = n - 1; i >= 0; i--)
        {
            if (zeros[i] + i <= n)
            {
                if ((zeros[i] + i) < n)
                    arr[i + zeros[i]] = arr[i];
                if (arr[i] == 0)
                    arr[i + (zeros[i] - 1)] = 0;
            }
        }
    }
};

class Solution
{
public:
    void duplicateZeros(vector<int> &a, int i = 0, int sh = 0)
    {
        for (i = 0; sh + i < a.size(); ++i)
            sh += a[i] == 0;
        for (i = i - 1; sh > 0; --i)
        {
            if (i + sh < a.size())
                a[i + sh] = a[i];
            if (a[i] == 0)
                a[i + --sh] = a[i];
        }
    }
};