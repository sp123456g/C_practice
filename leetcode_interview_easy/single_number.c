
int singleNumber(int* nums, int numsSize){
    
    int total=0;
    for(int i=0;i<numsSize;i++)
        total = total^nums[i];
    
    return total;
}
