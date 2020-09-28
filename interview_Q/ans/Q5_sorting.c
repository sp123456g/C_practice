#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

void quick_sort(int*,int,int);
void bubble_sort(int*);
void merge_sort(int*,int,int);
void merge(int*,int,int,int);
void bucket_sort(int*);

void printArr(int*);
int main(){

    int array[10] = {1,5,4,3,67,444,67,42,63,2};
    printArr(array);
//    quick_sort(array,0,SIZE-1);
//    bubble_sort(array);
//    merge_sort(array,0,SIZE-1);
    bucket_sort(array);
    printArr(array);
}

void printArr(int* input){

    for(int i=0;i<SIZE;i++)
        printf("%d ",input[i]);
    printf("\n");
}

void quick_sort(int* input,int front,int end){

    int pivot;
    int p_l;
    int p_r;
    int tmp;
    if(front<end){
        pivot = front;
        p_l   = front;
        p_r   = end;

        while(p_l<p_r){
            while(input[p_l]<=input[pivot] && p_l < end)
                p_l++;
            while(input[p_r]>input[pivot] && p_r > front)
                p_r--;

            if(p_l<p_r){
                tmp = input[p_r];
                input[p_r] = input[p_l];
                input[p_l] = tmp;
            }
        }

            tmp = input[pivot];
            input[pivot] = input[p_r];
            input[p_r] = tmp;

            quick_sort(input,front,p_r-1);
            quick_sort(input,p_r+1,end);
    }
}

void bubble_sort(int* input){

    int flag = 0;
    int tmp;
    for(int i=0;i<SIZE;i++){
        flag = 0;
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

    int arr_l[mid-front+1];
    int arr_r[end-(mid+1)+1];
    int l_size=0,r_size=0;

    for(int i=front;i<=mid;i++)
        arr_l[l_size++] = input[i];
    for(int i=mid+1;i<=end;i++)
        arr_r[r_size++] = input[i];

    int p_r=0,p_l=0;
    for(int i=front;i<=end;i++){
        if(p_r==r_size)
            input[i] = arr_l[p_l++];
        else if(p_l==l_size)
            input[i] = arr_r[p_r++];
        else if(arr_l[p_l]<arr_r[p_r])
            input[i] = arr_l[p_l++];
        else 
            input[i] = arr_r[p_r++];
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

    int* bucket = calloc(max-min+1,sizeof(int));

    for(int i=0;i<SIZE;i++)
        bucket[input[i]-min]++;

    for(int i=0,j=0;i<(max-min+1);){
    
        if(bucket[i]!=0){
            input[j] = i+min;
            bucket[i]--;
            j++;
        }
        else
            i++;
    }
}
