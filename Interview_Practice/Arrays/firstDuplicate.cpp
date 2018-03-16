int firstDuplicate(std::vector<int> a) 
{
    for(int i = 0; i < a.size(); i++)
        a[i]--;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[a[i] % a.size()] >= a.size())
            return a[i] % a.size() + 1;
        a[a[i] % a.size()] += a.size();
    }
    return -1;
}
