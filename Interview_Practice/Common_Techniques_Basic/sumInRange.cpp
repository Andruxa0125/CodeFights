int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) 
{
    vector<int> sums = {nums[0]};
    for(int i = 1; i < nums.size(); i++)
    {
        sums.push_back(sums[sums.size() - 1] + nums[i]);
    }
    long res = 0;
    for(auto& q : queries)
    {
        res += long(sums[q[1]] - sums[q[0]] + nums[q[0]]);
    }
    int mod = int((pow(10,9) + 7));
    res = res % long((pow(10,9) + 7));
    return res > 0 ? res : res + long(mod);
}
