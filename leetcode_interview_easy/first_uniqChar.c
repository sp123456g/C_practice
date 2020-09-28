

int firstUniqChar(char * s){

    int* table = calloc(27,sizeof(int)); 
    int p=0;
    while(s[p]!='\0'){
        table[(int)s[p]-'a']+=1;
        p++;
    }
    p=0;
    while(s[p]!='\0'){
        if(table[(int)s[p]-'a']==1)
            return p;
        else
            p++;
    }
    return -1;
}
