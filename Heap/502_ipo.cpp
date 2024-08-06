class Solution {
public:
    int findMaximizedCapital(int k, int currCap, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        for(int i=0;i<profits.size();i++){
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());
        priority_queue<int> pq;
        int idx=0;
        for(int i=0;i<k;i++){
            while(idx<profits.size() && arr[idx].first <= currCap){
                pq.push(arr[idx].second);
                idx += 1;
            }
            if(pq.size()==0) break;
            currCap += pq.top(); pq.pop();
        }
        return currCap;
    }
};