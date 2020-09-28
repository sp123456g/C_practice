

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    int size_out=0;
    int* output =NULL;
    int p_end;
    int p_short=0;
    if(nums1Size>nums2Size){
        output = (int*)malloc(sizeof(int)*nums2Size);
        p_end = nums1Size-1;
        
        for(int p_short=0;p_short<nums2Size;p_short++){
            for(int i=0;i<=p_end;i++){
                if(nums1[i]==nums2[p_short]){
                    output[size_out]=nums1[i];
                    nums1[i] = nums1[p_end];
                    p_end--;
                    size_out++;
                    break;
                }
            }
        }
    }
    else{
        output = (int*)malloc(sizeof(int)*nums1Size);
        p_end = nums2Size-1;
        
        for(int p_short=0;p_short<nums1Size;p_short++){
            for(int i=0;i<=p_end;i++){
                if(nums2[i]==nums1[p_short]){
                    output[size_out]=nums2[i];
                    nums2[i] = nums2[p_end];
                    p_end--;
                    size_out++;
                    break;
                }
            }
        }
    }
    
    
    
    *returnSize = size_out;
    return output;
}
