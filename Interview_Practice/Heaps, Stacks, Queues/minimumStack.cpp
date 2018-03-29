std::vector<int> minimumOnStack(std::vector<std::string> operations) 
{
    stack<int> minStack;
    vector<int> res;
    for(auto& str : operations)
    {
        if(starts_with(str, "push"))
        {
            //cout << "this is the string " << str << endl;
            int num = 0;
            stringstream ss(str);
            string temp = "";
            ss >> temp >> num;
            //cout << "the string is " << temp <<endl; 
            //cout << "the read number is " << num << endl;
            if(minStack.empty() || num <= minStack.top())
                minStack.push(num);
            else if(minStack.top() < num)
                minStack.push(minStack.top());
        }
        else if (starts_with(str, "min"))
        {
            res.push_back(minStack.top());
        }
        else if (starts_with(str, "pop"))
        {
            minStack.pop();
        }
    }
    return res;
}
bool starts_with(string bigString, string smallString)
{
    return bigString.compare(0, smallString.length(), smallString) == 0;
}
