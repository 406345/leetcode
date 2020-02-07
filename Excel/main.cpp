#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;

struct CALMeta
{
    int r;
    char c;
    vector<string> cals;
};
class Excel
{
public:
    int h, w;
    int **matrix;
    vector<CALMeta> cals;

    void print()
    {
        printf("=======================\n");
        for (size_t i = 0; i < h; i++)
        {
            for (size_t j = 0; j < w; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    Excel(int H, char W)
    {
        h = H;
        w = W - 'A' + 1;
        matrix = new int *[H] { 0 };
        for (size_t i = 0; i < H; i++)
        {
            matrix[i] = new int[w]{0};
        }
    }

    void set(int r, char c, int v)
    {
        if (cals.size() > 0)
        {
            int idx = 0;
            int tid = -1;
            for (auto &cal : cals)
            {
                if (cal.c == c && cal.r == r)
                {
                    tid = idx;
                    break;
                }
                ++idx;
            }

            if (tid >= 0)
                cals.erase(cals.begin() + tid);
        }

        matrix[r - 1][c - 'A'] = v;
        for(auto& cal: cals)
            runcal(cal);
    }

    int get(int r, char c)
    {
        return matrix[r - 1][c - 'A'];
    }

    int sum(int r, char c, vector<string> strs)
    {
        CALMeta m;
        m.c = c;
        m.r = r;
        m.cals = vector<string>(strs);
        cals.push_back(m);
        runcal(m);
        auto ret = this->get(r, c);
        return ret;
    }

    void runcal(CALMeta &cal)
    {
        int all = 0;
        for (auto &cmd : cal.cals)
        {
            int r = cal.r;
            int c = cal.c;
            auto sp = cmd.find(':');
            if (sp != -1)
            {
                auto colA = cmd[0];
                auto n1 = atoi(cmd.substr(1, sp - 1).data());
                auto colB = cmd[sp + 1];
                auto n2 = atoi(cmd.substr(sp + 2, cmd.length() - sp - 1).data());
                auto row = atoi(cmd.data() + 1);

                int ret = 0;
                for (int i = n1; i <= n2; i++)
                {
                    for (int j = colA; j <= colB; j++)
                    {
                        ret += this->matrix[i - 1][j - 'A'];
                    }
                }

                all += ret;
            }
            else
            {
                auto col = cmd[0];
                auto row = atoi(cmd.data() + 1);
                auto t = this->matrix[row - 1][col - 'A'];
                all += t;
                // this->matrix[r-1][c-'A'] = t;
                //this->set(r, c, t);
            }
        }
        this->matrix[cal.r - 1][cal.c - 'A'] = all;
    }
};

int main(int argc, char const *argv[])
{
    int ret = 0;
    // Excel s(3, 'C');
    // s.sum(1,'A',vector<string>({"A2"}));
    // s.print();
    // s.set(2,'A',1);
    // s.print();

    // Excel s(5, 'E');
    // s.set(1, 'A', 1);
    // s.print();
    // s.sum(2, 'B', vector<string>({"A1"}));
    // s.print();
    // s.set(2, 'B', 0);
    // s.print();
    // ret = s.get(2, 'B');
    // s.set(1, 'A', 5);
    // s.print();
    // ret = s.get(2, 'B');

    Excel s(5, 'E');
    s.set(1, 'A', 5);
    s.print();
    s.set(1, 'B', 3);
    s.print();
    s.set(1, 'C', 2);
    s.print();
    s.sum(1, 'C', vector<string>({"A1", "A1:B1"}));
    s.print();
    s.set(1, 'B', 5);
    s.print();
    s.sum(1, 'B', vector<string>({"A1:A5"}));
    s.print();
    s.set(5, 'A', 10);

    s.print();
    s.sum(3, 'C', vector<string>({"A1:C1", "A1:A5"}));

    s.print();
    s.set(3, 'A', 3);

    s.print();

    return 0;
}
