bool containsDuplicate(int* nums, int numsSize){
    
    
    if(numsSize<=1)
        return false;
    
    int min = nums[0];
    int max = nums[0];
    

    
    for(int i=0;i<numsSize;i++){
        if(nums[i]<min)
            min = nums[i];
        else if( nums[i]>max)
            max = nums[i];
    }
    
    int* h_table = calloc(max-min+1,sizeof(int));
    
    for(int i=0;i<numsSize;i++){
        int idx = nums[i]-min;
        if(h_table[idx]!=0)
            return true;
        else
            h_table[nums[i]-min] = 1;
    }
    
    return false;
}
