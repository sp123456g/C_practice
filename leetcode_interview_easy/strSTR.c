int strStr(char * haystack, char * needle){

    int h_size = strlen(haystack);
    int n_size = strlen(needle);
    
    if(n_size>h_size)
        return -1;
    if(n_size==0)
        return 0;
    int temp=0;int j=0;
    for(int i=temp;i<h_size;){
        if(haystack[i]==needle[j]){
            j++;
            i++;
        }
        else{
            temp++;
            i=temp;
            j=0;
        }
        if(j==n_size)
            return temp;
    }
    return -1;
}
