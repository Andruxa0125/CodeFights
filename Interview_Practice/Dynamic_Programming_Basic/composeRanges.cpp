std::vector<std::string> composeRanges(std::vector<int> nums) 
{
    vector<string> res;
    if(nums.size() == 0)
        return res;
    int size = nums.size();
    
    for(int i = 0; i < size; i++)
    {
        int start = i;
        int end = i;
        while(end + 1 < size && nums[end] + 1 == nums[end + 1])
        {
            end++;
        }
        if(start == end)
            res.push_back(to_string(nums[start]));
        else
            res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        i = end;
    }
    return res;
}
