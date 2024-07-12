class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& pnt) {
        if(pnt.size()<=1) return pnt.size();
        sort(pnt.begin(),pnt.end(),[](vector<int> &a, vector<int> &b){
            if(a[1] == b[1]) return a[0] <= b[0];
            return a[1]<b[1];
        });
        int count = 1, end = pnt[0][1];
        for(int i=1;i<pnt.size();i++){
            if(pnt[i][0] > end) {
                count += 1;
                end = pnt[i][1];
            }
        }
        return count;
    }
};