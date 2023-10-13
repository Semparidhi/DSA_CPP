class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int i=0;
       int max_length=INT_MIN;
       int zero_cnt=0;
       for(int j=0;j<nums.size();j++){
           if(nums[j]==0){
               zero_cnt++;
           }
           // if zero_cnt greater than the given value expand the window
           while(zero_cnt>k){
               if(nums[i]==0){ // move the start pointer 
                   zero_cnt--;
               }
               i++;
           }
           // keep track of longest subarray with k number of zeros;
           max_length=max(max_length,j-i+1);

       } 
       return max_length;
    }
};