/*
 * 有#1,#2,#3个盒子，手上有编号为1,2,3的三张扑克牌，要把扑克牌放入到盒子里，一个盒子放一张，有多少种放法。
 * 采用深度优先算法，深度优先关键在于解决“当下如何做”，这一步解决后进行下一步。
 * */

#include "stdio.h"
//c语言的全局变量在没赋值前默认值为0；所以a和book数组内容为0
int a[10],book[10];
int n;//有几个盒子几张牌
// step表示站在第几个盒子里
void dfs(int step){
    int i;
    //如果站在第n+1个盒子前，就表示前n个盒子已经放好牌
    if(step==n+1) {

        for ( i = 1; i <= n; ++i){
            printf("%d", a[i]);
        }
        printf("\n");
        return;
    }
    //此时放在第step个盒子前，按照1,2,3,...的顺序尝试
    for ( i = 1; i <=n; ++i) {
        //判断扑克牌i是否还在手上,0表示在手上
        if(book[i]==0){
            //开始尝试使用扑克牌i
            a[step] = i;//将第i号扑克牌放入第step个盒子里
            book[i]=1;//表示第i号扑克牌不在手上了
            //第step个盒子已经放好扑克牌，接下来走到下一个盒子面前。
            dfs(step+1);
            book[i] = 0;//将刚才尝试的扑克牌收回！！！
        }
    }
    return;
}



int main(){
    printf("please input a num between 0 and 9 :");
    scanf("%d",&n);
    printf("%d boxes and %d cards are as follows: \n",n,n);
    dfs(1);//首先站到第一个盒子面前
    return 0;

}