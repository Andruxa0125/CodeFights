vector<string> pressingButtons(string digits) 
{
    vector<string> res;
    if(digits.size() == 0)
        return res;
    string cur = "";
    unordered_map<char, vector<char>> map;
    map['2'] = {'a', 'b', 'c'};
    map['3'] = {'d', 'e', 'f'};
    map['4'] = {'g', 'h', 'i'};
    map['5'] = {'j', 'k', 'l'};
    map['6'] = {'m', 'n', 'o'};
    map['7'] = {'p', 'q', 'r', 's'};
    map['8'] = {'t', 'u', 'v'};
    map['9'] = {'w', 'x', 'y', 'z'};
    helper(digits, 0, cur, res, map);
    return res;

}
    
void helper(string digits, int start, string& cur, vector<string>& res,
            unordered_map<char, vector<char>>& m)
{
    if(start == digits.size())
    {
        res.push_back(cur);
        return;
    }
    for(auto& ch : m[digits[start]])
    {
        cur.push_back(ch);
        helper(digits, start + 1, cur, res, m);
        cur.pop_back();
    }
}