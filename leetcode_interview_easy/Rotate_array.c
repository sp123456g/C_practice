
void rotate(int* nums, int numsSize, int k){
    
    if(numsSize ==0)
        return;
    int times = k%numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,times-1);
    reverse(nums,times,numsSize-1);
}

void reverse(int* arr,int start,int end){
    
    while(start<end){
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
