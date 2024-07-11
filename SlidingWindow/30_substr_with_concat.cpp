/* TC: O(N+M) where N: size of string, M: window size
   Given First approach is not efficient but it is passing 180/181 test cases.
   You can try some modification in the code for AC solution.*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int length = s.length();
        int size = words[0].length();
        int num_words = words.size();
        int win_size = size * num_words;
        
        vector<int> result;int start = 0;
        if(length<win_size) return result;
        
        unordered_map<string,int> word_count;
        for(const string word: words) word_count[word]+=1;
        
        while(start <= length-win_size){
            unordered_map<string,int> tmp_count = word_count;
            int shuru = start; bool flag = true;
            for(int i=0;i<num_words;i++){
                string tmp = s.substr(shuru,size);
                if(tmp_count[tmp]==0){
                    flag = false;
                    break;
                }
                tmp_count[tmp] -= 1;
                shuru += size;
            }
            if(flag) result.push_back(start);
            start += 1;
        }
        return result;
    }
};