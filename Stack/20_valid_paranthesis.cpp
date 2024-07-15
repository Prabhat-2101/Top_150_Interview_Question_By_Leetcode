class Solution {
public:
    bool is_open_bracket(char ch){
        if(ch=='(' or ch=='{' or ch=='[') return true;
        return false;
    }
    bool isValid(string str) {
        int size = str.length();
        if(size<=1 or size%2==1) return false;
        stack<char> st;
        unordered_map<char,char> umap;
        umap[')'] = '('; umap[']'] = '['; umap['}']='{';
        for(const char ch: str){
            bool is_open = is_open_bracket(ch);
            if(st.empty() && !is_open) return false;
            if(is_open) {
                st.push(ch);
            }else{
                char top = st.top();;
                if(top==umap[ch]) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};