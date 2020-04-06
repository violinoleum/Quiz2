#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int sumsTo(int x[], int n, int k, int v);

int main() {
    //Testing
    int array[] = {1,8,6,4,3};
    int n = 5; //nums in array
    int k = 3; //take k nums
    int v = 9; //get total of v
    printf("Should return 0: %d\n",sumsTo(array,n,k,v));

    k=2;
    printf("Should return 1: %d\n",sumsTo(array,n,k,v));

    v=2;
    printf("Should return 0: %d\n",sumsTo(array,n,k,v));

    int array2[] = {};
    printf("Should return 0: %d\n",sumsTo(array,n,k,v));
    return 0;
}

int sumsTo(int x[], int n, int k, int v){
    if(v==0 && k==0)
        return 1;
    if(v!=0 && k==0)
        return 0;
    if(n==0)
        return 0;
    int num1 = 0;
    if(v>=x[0])
        num1 = sumsTo(x+1,n-1,k-1,v-x[0]);
    int num2 = sumsTo(x+1,n-1,k,v);
    return num1+num2>0;

}