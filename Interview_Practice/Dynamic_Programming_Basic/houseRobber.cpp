int houseRobber(std::vector<int> nums) 
{
    vector<int> res(nums.size() + 1);
    // insert one fake zeros at the end
    int size = nums.size();
    if(size == 0)
        return 0;
    res[size] = 0;
    res[size - 1] = nums[size - 1];
    for(int j = size - 2; j >= 0; j--)
    {
        res[j] = max(nums[j] + res[j + 2],
                     res[j + 1]);
    }
    return res[0];
}
