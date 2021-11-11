/*
 * 深度优先算法--> ABC + XYZ = PQR
 * 用放扑克牌思想来解决这个问题
 *
 * */

#include "stdio.h"
int a[10]; //三位数相加，用十位数组来保存着三个三位数
int book[10],total=0;

void dfs(int step){
    int i;
    if(step==10){
        //判断是否满足等式 ABC + XYZ = PQR
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9]){
            //如果满足要求，则可行解+1，并打印
            total++;
            printf("%d%d%d + %d%d%d = %d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
            return;
        }
    }
        //此时站在第step个盒子面前，按顺序一一尝试
        for (int i = 1; i <= 9; ++i) {
            //判断扑克牌是否还在手上
            if(book[i]==0)
            {
                //开始使用扑克牌
                a[step] = i;
                book[i]=1;
                dfs(step+1);
                book[i]=0;
            }
        }
        return;
    }
int main(){
    dfs(1);
    printf("total = %d",total/2);
    return 0;
}
