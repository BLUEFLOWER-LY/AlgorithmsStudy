/*
 * 快速排序：
 * 一般设置第一个数为基准数，j指向最后一个数，i指向第一个数
 * 先从最后一个数往前走，找到小于基准数就停下来
 * 然后从第一个数往后走，找到大于基准数就停下来
 * 交换两个数的位置
 * 然后又从j的位置开始往前走，找到小于基准数并停下来
 * 又从i的位置开始往后走，找到大于基准数并停下来
 * 交换两个数的位置...重复上述步骤
 * 直到 i = j 的时候，将基准数与 i、j 现在同时指向的这个数交换。
 * 完成一轮排序，把一串数以基准数为中心，分割成两个子串。
 * 然后又以左串的第一个数为基准数重复上述步骤。直到最后一个数。
 * 又以右串的第一个数为基准数重复上述步骤，直到最后一个数
 * */
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