#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "algorithm"
#include "string"

using namespace std;

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    inline bool is_empty(vector<ListNode*>& lists){
        for(auto& n : lists){
            if( n != nullptr ){
                return false;
            }
        }

        return true;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if( lists.size() == 0)return nullptr;
        ListNode* ret = new ListNode(0);
        ListNode* p = ret;

        int size = lists.size();

        for(int i = size-1;i>=0;--i){
            if(lists[i]==nullptr){
                lists.erase(lists.begin()+i);
            }
        }
        
        size = lists.size();

        while(size>0){
            int val = INT_MAX;
            int idx = -1;
        
            for (size_t i = 0; i < size; i++)
            {            
                if(lists[i]->val < val) {
                    val = lists[i]->val;
                    idx = i;
                }
            }

            if( idx >= 0 ){
                p->next = lists[idx];
                p = p->next;
                lists[idx] = lists[idx]->next;

                if(lists[idx] == nullptr){
                    lists.erase(lists.begin() + idx);
                    --size;
                }
            }                       
        }

        return ret->next;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto m = new ListNode(3);
    m->next = new ListNode(99);
    
    s.mergeKLists(vector<ListNode*>({
        nullptr,
        m,
        new ListNode(1),
        
    }));
    return 0;
}
