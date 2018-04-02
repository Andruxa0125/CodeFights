int arrayMaxConsecutiveSum2(std::vector<int> a) 
{
    // [-2, 2, 5, -11, 6]
    // [1, -2, 3, -4, 5, -3, 2, 2, 2]
    // 
    // max = 3
    int res = numeric_limits<int>::min();
    int cur = 0;
    // consider the case with just one element
    for(auto& n : a)
    {
        cur += n;
        res = max(res, cur);
        if(cur < 0)
            cur = 0;
    }
    return res;
}
