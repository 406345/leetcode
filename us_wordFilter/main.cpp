#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"

using namespace std;

class WordFilter
{
public:
    unordered_map<string, set<int>> pre_map;
    unordered_map<string, set<int>> suf_map;
    vector<string> words;
    WordFilter(vector<string> &words)
    {

        this->words = words;
        int size = words.size();
        for (size_t i = 0; i < size; i++)
        {
            auto w = words[i];
            int wsize = w.size();
         
            for (int j = 0; j < wsize; j++)
            {
                pre_map[w.substr(0, j + 1)].insert(i);
            }

            for (int j = wsize-1; j >= 0;j--)
            {
                suf_map[w.substr(j, wsize-j)].insert(i);
            }
        }
    }

    int f(string prefix, string suffix)
    { 
        auto& v1 = pre_map[prefix];
        auto& v2 = suf_map[suffix];

        int max = -1;

        if(prefix.empty() && !suffix.empty())
        {
            if(v2.size()>0){
                max = *(--v2.end());
            }
        }
        else if(!prefix.empty() && suffix.empty())
        {
            if(v1.size()>0){
                max = *(--v1.end());
            }
        }
        else if(!prefix.empty() && !suffix.empty())
        {
            for (auto &k : v1)
            {
                auto t = v2.find(k);

                if (t != v2.end())
                {
                    if (max < *t)
                    {
                        max = *t;
                    }
                }
            }
        }

        return max;
    }
};

int main(int argc, char const *argv[])
{
    WordFilter s(vector<string>({"pop"}));
    printf("%d\n", s.f("", "op"));
    printf("%d\n", s.f("", "p"));
    printf("%d\n", s.f("", ""));

    return 0;
}
