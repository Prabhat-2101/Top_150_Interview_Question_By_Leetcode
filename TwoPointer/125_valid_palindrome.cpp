class Solution {
public:
    bool isPalindrome(string str) {
        string temp = "";
        for(char ch: str){
            if(ch>='A' && ch<='Z') ch = ch + 32;
            if(ch>='a' && ch<='z') temp += ch;
            else if(ch>='0' && ch<='9') temp += ch;
        }
        if(temp=="" || temp.length()==1) return true;
        int left = 0,right = temp.length() - 1;
        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }
            left++;right--;
        }
        return true;
    }
};