class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0,j=0;
        int s1 = nums1.size(),s2 = nums2.size();
        vector<int> res;
        while(i < s1 && j<s2){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<s1)
            res.push_back(nums1[i++]);
        while(j<s2)
            res.push_back(nums2[j++]);
        int size = res.size();
        if(size&1)
            return res[size/2];
        return ((double)(res[size/2-1]+res[size/2]))/2;
    }
};