#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
ListNode* solve(vector<int> v) {

    ListNode* itln;
    vector<int>::iterator it = v.end() - 1;
    ListNode* ln = new ListNode(*it);
    itln = ln;
    it--;
    while (it >= v.begin()) {
        itln->next = new ListNode(*it);
        itln = itln->next;
        if (it == v.begin())
            break;
        it--;
    }

    return ln;
}
vector<int> reverse(vector<int> v) {
    vector<int>::iterator it1, it2;
    it1 = v.begin();
    it2 = v.end() - 1;
    int y = 1;
    while (it1 < v.begin() + (v.size() / 2)) {
        swap(it1, it2);
        iter_swap(it1, it2);
        it2 = v.end() - 1 - y;
        it1 = v.begin() + y;
        y++;
    }
    return v;
}
vector<int> sum(vector<int>v1, vector<int>v2) {
    vector<int>::iterator it1, it2;
    it1 = v1.end() - 1;
    it2 = v2.end() - 1;

    while (it2 >= v2.begin()) {
        int sum = *it1 + *it2;
        if (sum > 9) {

            *it1 = sum % 10;
            if (it1 != v1.begin()) {   
                ++* (it1 - 1);
            }

            else {
                cout << "inserted";
                v1.insert(v1.begin(), 1);
            }

        }
        else {
            cout << "sum\n";
            *it1 = sum;
        }
        if (it2 == v2.begin())
            break;
        it2--;
        it1--;
    }
    for (auto it : v1)
        cout << it << " ";
    cout << endl;
    for (int i=v1.size()-1; i>=0; i--)
    {
        if (v1[i] > 9) {
            v1[i] = 0;

            if (i >0 ) 
                ++v1[i - 1];
            
            else {
                v1.insert(v1.begin(), 1);
                cout<<"inserted\n";
            }
        }
            
    }
    return v1;
}
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        ListNode* nextit;
        nextit = l1;
        while (nextit != nullptr) {
            v1.push_back(nextit->val);
            nextit = nextit->next;
        }


        nextit = l2;
        while (nextit != nullptr) {
            v2.push_back(nextit->val);
            nextit = nextit->next;
        }
        if (v1.size() != 1)
            v1 = reverse(v1);
        if (v2.size() != 1)
            v2 = reverse(v2);
        cout << "ok\n";
        if (v1.size() >= v2.size()) {
            v1 = sum(v1, v2);
            return solve(v1);
        }

        else {
            v2 = sum(v2, v1);
            return solve(v2);
        }
    }
};

int main() {

    vector<int>v1{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int>v2{1 };
    v1 = sum(v1, v2);
    for (auto it : v1)
        cout << it << " ";
    
}