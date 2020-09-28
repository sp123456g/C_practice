
int maxSubArray(int* nums, int numsSize){

        int cur_sum = nums[0];
        int out=nums[0];
        for(int i=1;i<numsSize;i++){
            if(cur_sum+nums[i]<nums[i])
                cur_sum = nums[i];
            else
                cur_sum+=nums[i];
            
            if(cur_sum>out)
                out = cur_sum;
        }
    
        return out;
}
