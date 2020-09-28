// CPP program to modify a bit at position 
// p in n to b. 
#include <stdio.h> 

// Returns modified n. 
int modifyBit(int n, int p, int b) 
{ 
	int mask = 1 << p; 
	return (n & ~mask) | ((b << p) & mask); 
} 
int modifyBit1(int n, int p, int b){
    int mask = 1<<p;
    return((n & ~mask) | (b<<p));
}

// Driver code 
int main() 
{ 
    printf("%d\n",modifyBit(6,2,0));
    printf("%d\n",modifyBit(6,5,1));
    printf("\n");
    printf("%d\n",modifyBit1(6,2,0));
    printf("%d\n",modifyBit1(6,5,1));
	return 0; 
} 

