std::vector<int> nearestGreater(std::vector<int> a) 
{
    vector<int> b(a.size(), -1);
    stack<int> st; // stack will contain the indices.
    
    // go from beginning
    for(int i = 0 ; i < a.size(); i++)
    {
        while(!st.empty() && a[i] >= a[st.top()])
        {
            st.pop();
        }
        if(!st.empty())
            b[i] = st.top();
        st.push(i);
    }
    
    // clean the stack
    while(!st.empty())
        st.pop();
    
    // go from end
    for(int i = a.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && a[i] >= a[st.top()])
        {
            st.pop();
        }

        if(!st.empty())
        {
            if(b[i] == -1 || abs(i - st.top()) < abs(i - b[i]))
                b[i] = st.top();
        }
        st.push(i);
    }
    return b;
}
