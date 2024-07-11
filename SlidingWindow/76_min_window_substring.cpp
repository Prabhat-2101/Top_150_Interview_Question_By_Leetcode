class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="") return t;
        
        unordered_map<char,int> req_count;
        for(const char ch : t) req_count[ch] += 1;

        int have=0,need=req_count.size();
        unordered_map<char,int> win_count;
        pair<int,int> res; res.first = -1,res.second=-1;
        int res_len = INT_MAX,start=0,end=0;

        while(end<s.length()){
            char ch = s[end];
            win_count[ch] += 1;
            if(win_count[ch] == req_count[ch]) have += 1;
            while(have==need){
                int size = (end - start + 1);
                if(size < res_len){
                    res_len = size;
                    res = make_pair(start,end);
                }
                win_count[s[start]] -= 1;
                if(win_count[s[start]] < req_count[s[start]]) have -= 1;
                start += 1;
            }
            end += 1;
        }
        if(res_len==INT_MAX) return "";
        string out = "";
        for(int i=res.first;i<=res.second;i++){
            out += s[i];
        }
        return out;
    }
};