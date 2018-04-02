std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> a) 
{
    int start = 0;
    int sum = 0;
    vector<int> v{-1};
    for(int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        while(sum > s)
        {
            sum -= a[start++];
        }
        if(sum == s)
        {
            if(v.size() == 1 || (i - start > v[1] - v[0]))
            {
                v[0] = start + 1;
                if(v.size() == 1)
                    v.push_back(i + 1);
                else
                    v[1] = i + 1;
            }
        }
    }
    return v;
}
