#include<bits/stdc++.h>
using namespace std;

vector<string> text_justification(vector<string> words,int max_wid){
    vector<string> result,temp; int curr_loc = 0;

    while(curr_loc<words.size()){
        int next_loc = curr_loc + 1;
        int curr_len = words[curr_loc].length();
        while(next_loc<words.size()){
            if(curr_len + 1 + words[next_loc].length() > max_wid) break;
            curr_len += (1 + words[next_loc].length());
            next_loc += 1;
        }
        string temp = words[curr_loc];
        int word_count = next_loc - curr_loc - 1;

        if(word_count==0 || next_loc == words.size()){
            for(int i=curr_loc+1;i<next_loc;i++){
                temp += " ";
                temp += words[i];
            }
            for(int i=temp.length();i<max_wid;i++){
                temp += " ";
            }
        }else{
            int space = (max_wid - curr_len) / word_count;
            int extra = (max_wid - curr_len) % word_count;
            for(int i=curr_loc+1;i<next_loc;i++){
                for(int j=space;j>0;j--) temp += " ";
                if(extra>0) {
                    temp += " "; extra--;
                }
                temp += " ";
                temp += words[i];
            }
        }
        result.push_back(temp);
        curr_loc = next_loc;
    } 
    return result;
}

int main(){
    string input;getline(cin,input);
    stringstream ss(input);
    vector<string> input_str;
    string word; 
    int max_wid;cin>>max_wid;
    while (ss >> word)
        input_str.push_back(word);
    
    vector<string> result = text_justification(input_str,max_wid);
    
    for(const string line: result) cout<<line<<"*"<<endl;
    
    return 0;
}