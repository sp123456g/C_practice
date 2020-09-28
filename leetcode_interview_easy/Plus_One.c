

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

    int* output = NULL;
    
    
    int need_more=1;
    for(int i=0;i<digitsSize;i++){
        if(digits[i]!=9){
            need_more = 0;
            break;
        }
    }
    if(need_more){
        digitsSize+=1;
        output = malloc(sizeof(int)*digitsSize);
        output[0] = 1;
        for(int i=1;i<digitsSize;i++)
            output[i] = 0;
    }
    else{
        output = malloc(sizeof(int)*digitsSize);
        digits[digitsSize-1]+=1;
        for(int i=digitsSize-1;i>0;i--){
            
            if(digits[i]>=10){
                digits[i-1]+=1;
                digits[i]-=10;
            }
            else
                break;
        }
        
        
         for(int i=0;i<digitsSize;i++)
            output[i] = digits[i];
    }
        *returnSize = digitsSize;
    return output;
}
