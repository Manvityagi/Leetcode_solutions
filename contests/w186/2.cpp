class Solution
{
public:
    int helper(vector<int> &cardPoints, int k, int st, int end, vector<vector<int>> &table)
    {
        int n = cardPoints.size();
        if (k <= 0 || end < st || st >= n || end < 0 || st < 0 || end >= n)
        {
            return 0;
        }
        if (st == end)
        {
            table[st][end] = cardPoints[st];
            return cardPoints[st];
        }
        if (end == st + 1)
        {
            table[st][end] = max(cardPoints[st], cardPoints[end]);
            return table[st][end];
        }

        if (table[st][end] != -1)
        {
            return table[st][end];
        }

        int op1 = cardPoints[st] + helper(cardPoints, k--, st + 1, end, table);
        int op2 = cardPoints[end] + helper(cardPoints, k--, st, end - 1, table);

        table[st][end] = max(op1, op2);
        return table[st][end];
    }

//     int bot(vector<int> &arr, int k, int n)
//     {
//         int table[n][n];

//         for (int gap = 0; gap < n; ++gap)
//         {
//             for (int i = 0, j = gap; j < n; ++i, ++j)
//             {

//                 if (gap == 0)
//                 {
//                     table[i][j] = arr[i];
//                 }
//                 else if (gap == 1)
//                 {
//                     table[i][j] = max(arr[i], arr[j]);
//                 }
//                 else
//                 {
//                     int x = table[i + 1][j];
//                     int y = table[i][j - 1];
//                     table[i][j] = max(x, y);
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout << table[i][j] << " ";
//             }
//             cout << endl;
//         }

//         return table[0][n - 1];
//     }

    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
         vector<vector<int>> table(n,vector<int>(n,-1));
        // return bot(cardPoints, k, n);

        int ans = helper(cardPoints, k, 0, n - 1, table);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};