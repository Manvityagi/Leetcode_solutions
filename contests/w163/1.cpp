
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> copy(r, vector<int>(c));
    copy = grid;

    while (k--)
    {
        grid[0][0] = grid[r - 1][c - 1];
        for (int i = 0; i < r; i++)
        {
            if (i < r - 1)
            {
                grid[i + 1][0] = copy[i][c - 1];
            }
            for (int j = 0; j < c - 1; j++)
            {
                grid[i][j + 1] = copy[i][j];
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        copy = grid;
        k--;
    }

    return grid;
}

int main()
{
    vector<vector<int>> grid = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
    int k = 4;
    vector<vector<int>> ans = shiftGrid(grid, k);
    int r = ans.size();
    int c = ans[0].size();
    cout << "ans " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
