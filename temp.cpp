
#include<bits/stdc++.h>
using namespace std;

bool helper(string A, vector<string> &B){
    int n = A.size();
    if (n == 0)
        return 0;
    int d = B.size();

    if (d == 0)
        return 1;
        
    unordered_set<string> set;

    int max_word_len = 0;
    for (auto s : B)
    {
        set.insert(s);
        max_word_len = max(max_word_len, s.size());
    }

    int i = 0;
    int len = 1;

    while (i < n && len <= max_word_len)
    {

        if (set.find(A.substr(i, len)) != set.end())
        { //found in dict{
            i = len + i;
            len = 1;
        }

        len++;
    }

    if (len >= max_word_len + 1)
        return false;

    return true;
}

int main()
{
    string A = "myinterviewtrainer";
    vector<string> B = {"trainer", "my", "interview"};
    cout << helper(A,B);
    return 0;
}
