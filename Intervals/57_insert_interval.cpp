class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.size()<=1) return arr;
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        int start = arr[0][0],end = arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] <= end){
                end = max(end , arr[i][1]);
            }else{
                result.push_back({start,end});
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        result.push_back({start,end});
        return result;
    }
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& narr) {
        vector<vector<int>> result;
        if(arr.size()==0) {
            result.push_back(narr);
            return result;
        }
        sort(arr.begin(),arr.end());
        int idx = 0;
        while(idx<arr.size() && narr[0]>arr[idx][1]){
            idx += 1;
        }
        if(idx<arr.size()) arr.insert(arr.begin()+idx+1,narr);
        else arr.push_back(narr);
        return merge(arr);
    }
};