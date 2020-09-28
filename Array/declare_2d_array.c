#include <stdio.h>
#include <malloc.h>
const int num = 3;

int main() {
	int **a = (int**)malloc(num*sizeof(int*));
	for (int i = 0; i < num; i++) 
		a[i] = (int*)malloc(num*sizeof(int)); 
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) 	
			printf("%p ", &a[i][j]); //輸出元素的地址 
		printf("\n");
	}
	for (int i = 0; i < num; i++) //記得釋放空間
		free(a[i]);
	free(a);
	return 0;
} 
