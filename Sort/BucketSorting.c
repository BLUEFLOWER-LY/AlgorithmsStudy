#include <stdio.h>
/*
这个简单桶排序的时间复杂度为 m + n + m + n
--->O(2*(M+N)) = O(M+N)
缺点就是遇到需要输出所对应的编号就无法了
11+5+11+5
*/
int main(){
    int a[11],i,j,k;
    for(i=0;i<11;i++){
        a[i]=0;
    }
    for(i=0;i<5;i++){
        scanf("%d",&k);
        a[k]++;
    }
    for(i=0;i<11;i++){
        for(j=0;j<a[i];j++){
            printf("%d",i);
        }
    }
    getchar();
    return 0;
}