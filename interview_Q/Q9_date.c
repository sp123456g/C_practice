//Q9: write a function to calculate the date after x days front today

#include <stdio.h>
#include <stdlib.h>

void check_date(int*,int,int*);
int main(){

    int today[] = {2019,8,12};
    int ans[3];
    check_date(today,338,ans);

    printf("Ans=%i/%i/%i\n",ans[0],ans[1],ans[2]);

    return 0;
}

void check_date(int* today,int duration,int* output){

    int month_day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year = today[0];
    int month = today[1];
    int day = today[2];

    int left = duration+day;

    if(year%4==0)
        month_day[1] = 29;
    else
        month_day[1] = 28;

    while(left>month_day[month-1]){
        if(month==2){
            if(year%4==0)
                month_day[1] = 29;
            else 
                month_day[1] = 28;

            left-=month_day[month-1];
            month++;
        }
        else{
            left-=month_day[month-1];
            month++;
        }    
        if(month==13){
            year++;
            month=1;
        }
    }
    output[0] = year;
    output[1] = month;
    output[2] = left;
}
