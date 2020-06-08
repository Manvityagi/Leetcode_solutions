class Solution
{
public:
    vector<int> peopleIndexes(vector<vector<string>> &favs)
    {
        const int n = favs.size();
        for (int i = 0; i < n; i++)
            sort(begin(favs[i]), end(favs[i]));

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool isSubset = false;
            for (int j = 0; j < n && !isSubset; j++)
            {
                if (i == j)
                    continue;
                if (favs[i].size() > favs[j].size())
                    continue; // without this pruning, it will almost double time
                isSubset = includes(begin(favs[j]), end(favs[j]), begin(favs[i]), end(favs[i]));
            }
            if (!isSubset)
                ans.push_back(i);
        }
        return ans;
    }
};