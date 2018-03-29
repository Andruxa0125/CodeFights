int kthLargestElement(std::vector<int> nums, int k) 
{
    priority_queue<int, std::vector<int>, std::greater<int> > myHeap;
    for(int i = 0; i < k; i++)
    {
        myHeap.push(nums[i]);
    }
    for(int i = k; i < nums.size(); i++)
    {
        if(myHeap.top() < nums[i])
        {
            myHeap.pop();
            myHeap.push(nums[i]);
        }
    }
    return myHeap.top();
}
