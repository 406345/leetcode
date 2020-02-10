#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    set<string> banlist;
    unordered_map<string, int> wordmap;
    void to_lower(char *w, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if ('A' <= w[i] && w[i] <= 'Z')
            {
                w[i] = w[i] - 'A' + 'a';
            }
        }
    }
    vector<string> slipt_word(string &param)
    {
        int left = 0;
        int right = 0;
        int size = param.length();
        int ms = 0;
        vector<string> ret;
        char buf[20];
        while (left <= right && right < size)
        {
            if ('a' <= param[right] && param[right] <= 'z' ||
                'A' <= param[right] && param[right] <= 'Z')
            {
                ++right;
            }
            else
            {
                if (left != right)
                {
                    string w = param.substr(left, right - left);
                    to_lower((char *)w.data(), w.size());
                    ret.push_back(w);
                }
                ++right;
                left = right;
            }
        }
        if (left != right)
        {
            string w = param.substr(left, right - left);
            to_lower((char *)w.data(), w.size());
            ret.push_back(w);
        }

        return ret;
    }
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        int left = 0;
        int right = 0;
        int size = paragraph.length();
        int ms = 0;
        string ret;

        for (auto &bw : banned)
        {
            banlist.insert(bw);
        }

        auto words = this->slipt_word(paragraph);

        for (auto &word : words)
        {
            if (banlist.find(word) != banlist.end())
            {
                continue;
            }
            auto count = wordmap[word] + 1;
            wordmap[word] = count;

            if (count > ms)
            {
                ms = count;
                ret = word;
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n", s.mostCommonWord("Bob", vector<string>({})));
    printf("%d\n", s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", vector<string>({"hit"})));

    return 0;
}
