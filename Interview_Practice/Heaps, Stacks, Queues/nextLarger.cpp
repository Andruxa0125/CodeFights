std::vector<int> nextLarger(std::vector<int> a) 
{
    stack<int> st;
    vector<int> result;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() < a[i])
            st.pop();
        if(st.empty())
            result.push_back(-1);
        else
            result.push_back(st.top());
        st.push(a[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}
