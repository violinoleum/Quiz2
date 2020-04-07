/**
 * Quiz 2
 * Kerry Tu
 * kt25566
 * 4/6/2020
 */

#include <stdio.h>

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
    printf("Should return 0: %d\n",sumsTo(array2,n,k,v));


    k=0;
    printf("Should return 0: %d\n",sumsTo(array,n,k,v));

    v=0;
    printf("Should return 1: %d\n",sumsTo(array,n,k,v));

    return 0;
}

int sumsTo(int array[], int size, int nums, int total){
    if(nums==0 && total==0) //if finished
        return 1;
    if(size==0 || (nums==0 && total>0)) //if no more to add and no sum found
        return 0;

    int num = array[0];
    array++;
    size--;
    int keepNum = sumsTo(array,size,nums,total); //don't use num in total
    int addNum; //use num in total
    if(total>=num)
        addNum = sumsTo(array,size,nums-1,total-num);
    else
        addNum = 0;

    if(addNum==1 || keepNum==1)
        return 1;
    return 0;
}