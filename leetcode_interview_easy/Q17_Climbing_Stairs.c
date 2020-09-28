
int climbStairs(int n){

    int a1 = 1;
    int a2 = 2;
    if(n==1)
        return a1;
    if(n==2)
        return a2;
    int a3;
    for(int i=3;i<=n;i++){
        a3 = a1+a2;
        a1 = a2;
        a2 = a3;
    }
    return a3;
}
