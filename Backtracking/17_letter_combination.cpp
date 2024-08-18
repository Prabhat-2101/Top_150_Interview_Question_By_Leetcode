class Solution {
private:
    void solve(string str,vector<string>& res,string tmp,int i,string map[]){
        if(i>=str.length()){
            res.push_back(tmp);
            return ;
        }
        string keypad = map[str[i]-'0'];
        for(int it=0;it<keypad.length();it++){
            tmp.push_back(keypad[it]);
            solve(str,res,tmp,i+1,map);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string map[10] = {"","","abc","def","ghi",
                            "jkl","mno","pqrs","tuv","wxyz"}; 
        vector<string> res;
        if(digits.length() == 0)
            return res;
        string temp;
        solve(digits,res,temp,0,map);   
        return res;
    }
};