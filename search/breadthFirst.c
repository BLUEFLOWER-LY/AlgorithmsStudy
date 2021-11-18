/*
 * 广度优先搜索
 * 走迷宫例子,从0,0出发广度优先找到+所在位置
 * 0 0 1 0'
 * 0 0 0 0
 * 0 0 1 0
 * 0 1 + 0
 * 0 0 0 1
 * */
#include "stdio.h"
struct note{
    int x;int y;
    int f;//父亲在队列中的编号
    int s;//步数
};
int main(){
    struct note que[2501]; //地图大小不超过 50 * 50 所以队列不会超过2500个
    int a[51][51] = {0};
    int book[51][51]={0};
    //用于表示走的方向的数组
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int head,tail;
    int i,j,k,n,m,startX,startY,p,q,tx,ty,flag;
//    a[][] = {};
    printf("please input n m\n");
    scanf("%d %d",&n,&m);
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            printf("please input a[%d][%d] \n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("please input startX startY p q\n");
    scanf("%d %d %d %d",&startX,&startY,&p,&q);
    //队列初始化
    head=1;
    tail=1;
    //往队列插入迷宫入口坐标
    que[tail].x=startX;
    que[tail].y=startY;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[startX][startY]=1;
    flag=0;//用来标记是否达到目标点，0表示暂时没到，1表示到达。
    //当队列不为空的时候
    while (head<tail){
        //枚举四个方向
        for (int k = 0; k <=3; ++k) {
            //计算下一个点的坐标
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            //判断是否越界
            if(tx<1 || tx > n || ty<1 ||ty>m)continue;
            //判断是否是障碍物或者已经在路径中
            if(a[tx][ty] == 0 && book[tx][ty] == 0){
                //把这个点标记为已经走过
                //广度优先搜索每个点只入队一次，所以和深度优先不一样，不需要将book数组还原
                book[tx][ty] = 1;
                //插入新的点到队列中
                que[tail].x=tx;
                que[tail].y=ty;
                //因为这个点是从head扩展出来的，所以他的父节点就是head
                que[tail].f=head;
                que[tail].s = que[head].s+1;
                tail++;
            }
            if(tx==p && ty ==q){
                flag = 1;
                break;
            }
        }
        if(flag==1){break;}
        head++;//当一个点结束后，head++才能对后面的点再进行扩展
    }
    // 打印队列中末尾最后一个(目标点)的步数
    // 注意tail是指向队列队尾(最后一位)的下一个位置，所以这需要-1
    printf("%d",que[tail-1].s);
    getchar();
    return 0;
}
