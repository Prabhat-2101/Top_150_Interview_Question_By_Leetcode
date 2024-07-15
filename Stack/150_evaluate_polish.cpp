class Solution {
public:
    bool is_operation(string op){
        return (op=="+" or op=="-" or op=="*" or op=="/");
    }
    int operation(int v1, int v2, string op){
        if(op=="+") return v1 + v2;
        if(op=="-") return v1 - v2;
        if(op=="*") return v1 * v2;
        return v1 / v2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        if(tokens.size()<0) return 0;
        if(tokens.size()==1) return stoi(tokens[0]);
        for(const string it: tokens){
            if(is_operation(it)){
                int t1 = st.top(); st.pop();
                int t2 = st.top(); st.pop();
                int res = operation(t2,t1,it);
                st.push(res);
            }else{
                int value = stoi(it);
                st.push(value);
            }
        }
        return st.top();
    }
};