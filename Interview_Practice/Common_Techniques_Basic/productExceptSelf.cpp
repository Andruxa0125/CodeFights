int productExceptSelf(std::vector<int> nums, int m) 
{
    int size = nums.size();
    vector<int> temp(size, 1);
    int fromBegin = 1;
    int fromEnd = 1;
    
    for(int i = 0; i < size; i++)
    {
        temp[i] = (temp[i] % m * fromBegin) % m;
        fromBegin = (fromBegin * (nums[i] % m)) % m;
        temp[size - 1 - i] = (temp[size - 1 - i] % m * fromEnd) % m;
        fromEnd = (fromEnd * (nums[size - 1 - i] % m)) % m;
    }
    int answer = 0;
    for(auto& n : temp)
        answer = (answer + (n % m)) % m;
    return answer;
}
