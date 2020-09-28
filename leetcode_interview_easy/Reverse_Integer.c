int reverse(int x){

    int pop;
    int push=0;
    while(x!=0){
        pop  = x%10;
        x/=10;
        
        if((push==INT_MAX/10 && pop>7) || push>INT_MAX/10)
            return 0;
        if((push==INT_MIN/10 && pop<-8) || push<INT_MIN/10)
            return 0;
        
        push = push*10+pop;
    }
    return push;
}
