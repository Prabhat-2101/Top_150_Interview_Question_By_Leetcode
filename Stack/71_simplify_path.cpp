class Solution {
public:
    string simplifyPath(string str) {
        stringstream ss(str); 
        string token;  vector<string> cmds;
    
        while (getline(ss, token, '/')) { 
            cmds.push_back(token); 
        }
        stack<string> st;
        for(const string cmd: cmds){
            if(cmd=="." || cmd==""){
                continue;
            }else if(cmd==".."){
                if(!st.empty()) st.pop();
            }else{
                st.push(cmd);
            }
        }
        string result = "";
        while(!st.empty()){
            string cmd = st.top();st.pop();
            result = '/' + cmd + result;
        }
        return result.length()>0?result:"/";
    }
};