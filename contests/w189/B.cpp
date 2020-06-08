#define MP make_pair
class Solution
{
public:
    static bool compare(pair<string, int> &p1, pair<string, int> &p2)
    {
        if (p1.first.size() < p2.first.size();)
        {
            return p1.second < p2.second;
        }
        return p1.first.size() < p2.first.size();
    }

    string arrangeWords(string txt)
    {
        vector<pair<string, int>> words;
        int st = 0;
        txt[0] = tolower(txt[0]);
        int cnt = 0;
        for (int i = 0; i < txt.size(); i++)
        {
            if (txt[i] == ' ' || i == txt.size() - 1)
            {
                if (i == txt.size() - 1)
                    words.push_back({txt.substr(st, i - st + 1), cnt++});
                else
                    words.push_back({txt.substr(st, i - st), cnt++});
                st = i + 1;
            }
        }

        sort(words.begin(), words.end(), compare);

        words[0][0] = toupper(words[0][0]);
        string ans;
        for (int i = 0; i < words.size(); i++)
        {
            ans += words[i];
            if (i != words.size() - 1)
                ans += ' ';
        }
        return ans;
    }
};