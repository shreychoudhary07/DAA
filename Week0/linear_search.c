#include<stdio.h>

int linearsearch( int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        return i;
    }
    return -1;
}

int main()
{
    int arr[]={3,7,5,9,4,12,24};
    int size=7,element=12;
    int searchIndex=linearsearch(arr,size,element);
    printf("The element %d was found at index %d \n",element,searchIndex);
    return 0;
}