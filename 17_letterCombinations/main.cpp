#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<char, string> keymap;

    Solution()
    {
        keymap['2'] = "abc";
        keymap['3'] = "def";
        keymap['4'] = "ghi";
        keymap['5'] = "jkl";
        keymap['6'] = "mno";
        keymap['7'] = "pqrs";
        keymap['8'] = "tuv";
        keymap['9'] = "wxyz";
    };
    void generate(vector<string> &result, string t, string input, int input_idx)
    {
        int count = keymap[input[input_idx]].size();
        string &sequence = keymap[input[input_idx]];
        int i_count = input.size();

        for (size_t i = 0; i < count; i++)
        {
            t[input_idx] = sequence[i];

            if ((input_idx + 1) < i_count)
            {
                generate(result, t, input, input_idx + 1);
            }
            else
            {
                result.push_back(string(t));
            }
        }
    };

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        int count = digits.size();
        if (count == 0)
            return result;

        string tmp = "";
        tmp.resize(count);

        generate(result, tmp , digits, 0);

        return std::move(result);
    };
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.letterCombinations("23");
    s.letterCombinations("279");

    return 0;
}
