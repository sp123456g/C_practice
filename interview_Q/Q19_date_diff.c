//give two date, calculate day different of two date

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calDiff(int,int,int,int,int,int);
int calDays(int,int,int);
int main(){
    //2020/1/5
    int year1=2020;
    int month1=7;
    int day1=15;

    //2019/12/31
    int year2=2019;
    int month2=8;
    int day2=12;

    int day = calDiff(year1,month1,day1,year2,month2,day2);

    printf("total_day different=%i\n",day);
}

int calDiff(int year1,int month1,int day1,int year2,int month2,int day2){

    int total_day1 = calDays(year1,month1,day1);
    int total_day2 = calDays(year2,month2,day2);
    
    return(abs(total_day2-total_day1));
}

int calDays(int year,int month,int day){

    int month_day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int day_total=0;
    //year
    if(year>1){
        day_total+=(year-1)*365+floor((year-1)/4);
    }

    //month 
        for(int i=0;i<month-1;i++){
            if(i==1){
                if(year%4==0)
                    month_day[1] = 29;
                else
                    month_day[1] = 28;
            }
            day_total+=month_day[i];
        }

        day_total+=day;
        
        return day_total;
}
