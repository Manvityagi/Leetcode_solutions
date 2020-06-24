//for topological sort , graph should be directed acyclic
class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &arr)
    {
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        vector<int> ans;

        for (auto &i : arr)
        {
            g[i[1]].emplace_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (q.size())
        {
            int u = q.front();
            q.pop();
            ans.emplace_back(u);
            for (int &i : g[u])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.emplace(i);
            }
        }

        if (ans.size() != n)
            return vector<int>();
        return ans;
    }
};