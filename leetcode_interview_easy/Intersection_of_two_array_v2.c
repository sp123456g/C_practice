
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int min,max,p_out;
    int* out;
    if(nums1Size>nums2Size)
        out = malloc(nums2Size*sizeof(int));
    else
        out = malloc(nums1Size*sizeof(int));
    
    if(nums1Size==0 || nums2Size==0)
        return out;
    
    if(nums1Size>nums2Size){
        
        
        min = nums1[0];
        max = nums1[0];
        for(int i=0;i<nums1Size;i++){
            if(nums1[i]<min)
                min = nums1[i];
            else if(nums1[i]>max)
                max = nums1[i];
        }
            
        int* h_table = calloc(max-min+1,sizeof(int));
             p_out = 0;
        
        for(int i=0;i<nums1Size;i++)
            h_table[nums1[i]-min] +=1;
        
        for(int i=0;i<nums2Size;i++){
            
            if(nums2[i]<=max && nums2[i]>=min){
                if(h_table[nums2[i]-min]!=0){
                    out[p_out++] = nums2[i];
                    h_table[nums2[i]-min]-=1;
                }
            }
        }
    }
    else{
     
        min = nums2[0];
        max = nums2[0];
        for(int i=0;i<nums2Size;i++){
            if(nums2[i]<min)
                min = nums2[i];
            else if(nums2[i]>max)
                max = nums2[i];
        }
        
        int* h_table = calloc(max-min+1,sizeof(int));
             
             p_out = 0;
        
        for(int i=0;i<nums2Size;i++)
            h_table[nums2[i]-min] +=1;
        
        for(int i=0;i<nums1Size;i++){
            
            if(nums1[i]<=max && nums1[i]>=min){
                if(h_table[nums1[i]-min]!=0){
                    out[p_out++] = nums1[i];
                    h_table[nums1[i]-min]-=1;
                }
            }
        }
    }
    
    return out;
}
