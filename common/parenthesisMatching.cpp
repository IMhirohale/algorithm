class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(int i = 0; i < s.size(); ++i)
        {
            char ch = s.at(i);
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if(st.size() > 0 && ((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{')))
                st.pop();
            else
                return false;
        }

        return st.size() == 0;
    }
};
