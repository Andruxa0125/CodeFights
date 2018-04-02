int climbingStairs(int n)
{
    if(n <= 0 )
        return 0;
    
    vector<int> res(n + 1);
    
    res[1] = 1;
    res[2] = 2;
    
    for(int i = 3; i <= n; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n];
}
