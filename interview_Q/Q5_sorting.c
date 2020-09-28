//Q5: Write sorting function:
//quick sort 
//merge sort 
//bubble sort 
//bucket sort

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 1000

void quick_sort(int*,int,int);
void bubble_sort(int*);
void merge_sort(int*,int,int);
void merge(int*,int,int,int);
void bucket_sort(int*);

void printArr(int*);
int main(){

    clock_t t1,t2,t3,t4,t5,t6,t7,t8;
    srand(time(NULL));
    int array[SIZE],array1[SIZE],array2[SIZE],array3[SIZE];
    for(int i=0;i<SIZE;i++){
        int num = rand()%500;
        array[i] = num;
        array1[i] = num;
        array2[i] = num;
        array3[i] = num; 
    }
    

    printf("Original Array:\n");
    printArr(array);
    
    printf("quick_sort:\n");
    t1 = clock(); 
    quick_sort(array,0,SIZE-1);
    t2 = clock();
    printArr(array);

    printf("bubble_sort:\n");
    t3 = clock(); 
    bubble_sort(array1);
    t4 = clock();
    printArr(array1);

    printf("merge_sort:\n");
    t5 = clock(); 
    merge_sort(array2,0,SIZE-1);
    t6 = clock();
    printArr(array2);

    printf("bucket_sort:\n");
    t7 = clock(); 
    bucket_sort(array3);
    t8 = clock();
    printArr(array3);



    printf("\n\nTime usage:\nquick sort: %lf\n",(t2-t1)/(double)(CLOCKS_PER_SEC));
    printf("bubble sort:%lf\n",(t4-t3)/(double)(CLOCKS_PER_SEC));
    printf("merge sort: %lf\n",(t6-t5)/(double)(CLOCKS_PER_SEC));
    printf("bucket sort:%lf\n",(t8-t7)/(double)(CLOCKS_PER_SEC));
}

void printArr(int* input){

    for(int i=0;i<SIZE;i++)
        printf("%d ",input[i]);
    printf("\n");
}

void quick_sort(int* input,int front,int end){
    int pivot = front;
    int left = front;
    int right = end;
    int tmp;

    if(front<end){
        while(left<right){
            
            while(input[left]<=input[pivot] && left<end)
                left++;
            while(input[right]>input[pivot] && right>front)
                right--;

            if(left<right){
                tmp = input[left];
                input[left] = input[right];
                input[right] = tmp;
            }
        }

        tmp = input[pivot];
        input[pivot] = input[right];
        input[right] = tmp;

        quick_sort(input,front,right-1);
        quick_sort(input,right+1,end);
    }
}

void bubble_sort(int* input){

    int flag = 0;
    int tmp;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE-1;j++){
            if(input[j]>input[j+1]){
                tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
                flag = 1;
            }
        }
        if(!flag)
            return;
        flag = 0;
    }
}

void merge_sort(int* input,int front,int end){

    if(front<end){
        int mid = front + (end-front)/2;
        merge_sort(input,front,mid);
        merge_sort(input,mid+1,end);

        merge(input,front,mid,end);
    }
}

void merge(int* input,int front,int mid,int end){

    int aryL[mid-front+1];
    int aryR[end-(mid+1)+1];
    int L=0,R=0;
    for(int i=front;i<=mid;i++)aryL[L++]=input[i];
    for(int i=mid+1;i<=end;i++)aryR[R++]=input[i];

    int p_l=0,p_r=0;
    for(int i=front;i<=end;i++){
        if(p_l==L)
            input[i] = aryR[p_r++];
        else if(p_r==R)
            input[i] = aryL[p_l++];
        else if(aryL[p_l]<=aryR[p_r])
            input[i] = aryL[p_l++];
        else 
            input[i] = aryR[p_r++];
    }
}

void bucket_sort(int* input){

    int min = input[0];
    int max = input[0];

    for(int i=0;i<SIZE;i++){
        if(input[i]<min)
            min = input[i];
        else if(input[i]>max)
            max = input[i];
    }

    int b_size = max-min+1;
    int* bucket = calloc(b_size,sizeof(int));

    for(int i=0;i<SIZE;i++)
        bucket[input[i]-min] +=1;

    for(int i=0,j=0;j<b_size;){
        if(bucket[j]!=0){
            input[i] = j+min;
            bucket[j]--;
            i++;
        }
        else 
            j++;
    }
}
