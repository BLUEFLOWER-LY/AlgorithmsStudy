/*
 * 炸弹人游戏体现枚举算法
 * 规则：#代表墙  G代表敌人  .代表空地，只有一颗炸弹，炸弹可以杀伤范围内的所有敌人
 *  运行步骤：
 *  1.输入13,13。
 *  2.输入地图。
 * */
/*      地图：
            #############
            #GG.GGG#GGG.#
            ###.#G#G#G#G#
            #.......#..G#
            #G#.###.#G#G#
            #GG.GGG.#.GG#
            #G#.#G#.#.###
            ##G...G.....#
            #G#.#G###.#G#
            #...G#GGG.GG#
            #G#.#G#G#.#G#
            #GG.GGG#G.GG#
            #############
*/
#include "stdio.h"
int main(){
    char a[20][20];//规定地图大小不超过20*20
    int i,j,sum,max=0,p,q,x,y,n,m;
//    读入n行和m列
    printf("Please enter the number of {rows} and {columns}, separated by {,}\n");
    scanf("%d,%d",&n,&m);
//    n=13;m=13;
//    读入第n字符
    printf("Please enter the map\n");
    for ( i = 0; i <= n-1; i++) {
        scanf("%s",a[i]);
    }
//    双重循环枚举地图上的每个点
    for ( i = 0; i <= n-1; i++) {
        for ( j = 0; j <= m-1; j++) {
//            首先判断这个点是不是平地，是平地才可以放炸弹
            if(a[i][j]=='.'){
                sum=0;//用来计可以消灭敌人是数量
                //将当前坐标i，j复制到新变量中，以便统计上下左右可以消灭的敌人数
                //向上统计
                x=i;y=j;
                while (a[x][y]!='#')//判断是不是墙
                {
                    //如果是敌人则计数
                    if(a[x][y]=='G') sum++;
                    x--;
                }
                //向下统计
                x=i;y=j;
                while (a[x][y]!='#')
                {
                    if(a[x][y]=='G') sum++;
                    x++;
                }
                //向左统计
                x=i;y=j;
                while (a[x][y]!='#')
                {
                    if(a[x][y]=='G') sum++;
                    y--;
                }
                //向右统计
                x=i;y=j;
                while (a[x][y]!='#')
                {
                    if(a[x][y]=='G') sum++;
                    y++;
                }
                //更新map的值
                if(sum>max){
                //如果当前点所能消灭的敌人总数大于map，则更新map
                max=sum;
                //并用q，p记录当前坐标
                p=i;q=j;
                }
                printf("(%d,%d) can destory %d enemies\n",i,j,sum);
            }
        }
    }
    printf("Put the bomb on (%d,%d), and you can destroy up to %d enemies",p,q,max);
    return 0;
}