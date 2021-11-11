#include <stdio.h>
int a[10]={31,21,51,4,8,20,44,73,23,99};
void quicksort(int left,int right){
    int i,j,t,pivot,k;
    if(left > right) return;
    pivot = a[left];
    i = left;
    j = right;
    while(i!=j){
        //先从右边往左
        while(a[j]>=pivot && i < j)
            j--;
        //再从左往右
        while(a[i]<=pivot && i < j)
            i++;
        if(i<j){
            t=a[i];a[i]=a[j];a[j]=t;
        }
    }
    //将基数归位
    a[left] = a[i];
    a[i] = pivot;
    for(k=0;k<10;k++){
        printf("%d ",a[k]);

    }
    printf("\n");
    quicksort(left,i-1);
    quicksort(i+1,right);
    return ;
}
int main(){
    int i;
    quicksort(0,9);
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    getchar();
    return 0;
}