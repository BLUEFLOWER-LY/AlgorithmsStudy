/*
 * �����������
 * ���Թ�����,��0,0������������ҵ�+����λ��
 * 0 0 1 0'
 * 0 0 0 0
 * 0 0 1 0
 * 0 1 + 0
 * 0 0 0 1
 * */
#include "stdio.h"
struct note{
    int x;int y;
    int f;//�����ڶ����еı��
    int s;//����
};
int main(){
    struct note que[2501]; //��ͼ��С������ 50 * 50 ���Զ��в��ᳬ��2500��
    int a[51][51] = {0};
    int book[51][51]={0};
    //���ڱ�ʾ�ߵķ��������
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
    //���г�ʼ��
    head=1;
    tail=1;
    //�����в����Թ��������
    que[tail].x=startX;
    que[tail].y=startY;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[startX][startY]=1;
    flag=0;//��������Ƿ�ﵽĿ��㣬0��ʾ��ʱû����1��ʾ���
    //�����в�Ϊ�յ�ʱ��
    while (head<tail){
        //ö���ĸ�����
        for (int k = 0; k <=3; ++k) {
            //������һ���������
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];
            //�ж��Ƿ�Խ��
            if(tx<1 || tx > n || ty<1 ||ty>m)continue;
            //�ж��Ƿ����ϰ�������Ѿ���·����
            if(a[tx][ty] == 0 && book[tx][ty] == 0){
                //���������Ϊ�Ѿ��߹�
                //�����������ÿ����ֻ���һ�Σ����Ժ�������Ȳ�һ��������Ҫ��book���黹ԭ
                book[tx][ty] = 1;
                //�����µĵ㵽������
                que[tail].x=tx;
                que[tail].y=ty;
                //��Ϊ������Ǵ�head��չ�����ģ��������ĸ��ڵ����head
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
        head++;//��һ���������head++���ܶԺ���ĵ��ٽ�����չ
    }
    // ��ӡ������ĩβ���һ��(Ŀ���)�Ĳ���
    // ע��tail��ָ����ж�β(���һλ)����һ��λ�ã���������Ҫ-1
    printf("%d",que[tail-1].s);
    getchar();
    return 0;
}
