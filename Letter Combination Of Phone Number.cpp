
#include <iostream>
#include<vector>
using namespace std;

vector<char>v2{ 'a','b', 'c' };
vector<char>v3{ 'd','e', 'f' };
vector<char>v4{ 'g','h', 'i' };
vector<char>v5{ 'j','k', 'l' };
vector<char>v6{ 'm','n', 'o' };
vector<char>v7{ 'p','q', 'r', 's' };
vector<char>v8{ 't', 'u', 'v' };
vector<char>v9{ 'w','x', 'y','z' };
vector<char>res;
vector<string> ans;



void dfs(vector<vector<char>> v, int ind) {
    if (ind > v.size()-1) return;
    for (auto it : v[ind]) {
        res.push_back(it);
        dfs(v, ind + 1); 
        if (res.size() == v.size())
            ans.emplace_back(res.begin(), res.end());

        res.pop_back();
       
    }
   
}

class Solution {
public:
    vector<vector<char>>buttons{ v2,v3,v4,v5,v6,v7,v8,v9 };
    vector<vector<char>> v;
    vector<string> letterCombinations(string digits) {
        res.clear();
        ans.clear();
        if (digits.size() == 0)
            return ans;
        for (auto it : digits) {
            int ind = it - '0';
            v.emplace_back(buttons[ind - 2]);
        }
        dfs(v, 0);
        return ans;
    }

};
int main()
{
    Solution obj;
    obj.letterCombinations("23");
    for (auto it : ans)
        cout << it << " ";
   
}

