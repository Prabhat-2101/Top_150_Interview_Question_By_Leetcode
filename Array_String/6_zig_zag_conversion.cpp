class Solution {
public:
    string convert(string s, int numRows) {
        string str[numRows], ans;
        int j = 0;
        bool x = false;

        if(numRows >= s.size() || numRows == 1)
            return s;

        for(int i = 0; i < s.size(); i++){
            str[j] += s[i];
            if(j == 0)
                x = false;
            if(j == numRows - 1)
                x = true;

            j = (x==true)?j-1:j+1;
        }
        for(int i = 0; i < numRows; i++)
            ans += str[i];

        return ans;
    }
};