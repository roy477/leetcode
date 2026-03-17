class Solution {
public:
    string removeDuplicates(string s) {
       string st= "";
for (char c : s) {
    if (!st.empty() && c == st.back()) {
        st.pop_back();
    } else 
        st.push_back(c);
}
return st; 
    }
};