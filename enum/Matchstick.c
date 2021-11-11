/*求X+Y=Z，有M（M<=24）根火柴棍，可以拼出多少种组合？
 * XYZ用晶体数码管来表示，例如：0123分别需要6,2,5，5根火柴
 *  ————         ————   ————
 * |    |   |        |      |
 * |    |   |    ————   ————
 *  ————        |           |
 *               ————   ————
 * 加号等号需要2根火柴
 * A!=B，则A+B=C与B+A=C视为不同的等式
 * 所有火柴都需要用上
 * */
//该函数作用是：求一个数所需要的火柴棍数量
#include "stdio.h"
int fun(int x){
    int num = 0;//用来计数的变量
    //用f数组来记录0~9所需要的火柴数量
    int f[10]={6,2,5,5,4,5,6,3,7,6};
    //如果数字的位数大于一位
    while (x/10!=0){
        //获得X的末尾数字并将此数所需的火柴棍累加到num里
        num+=f[x%10];
        x=x/10; //去掉末尾的数字，eg：123-->12
    }
    //加上最后一位数所需要的火柴棍数量
    num+=f[x];
    return num;
}
int main(){
    int x,y,z,matchstickNum,sum=0;
    printf("please input matchstickNum: ");
    scanf("%d",&matchstickNum);
    //开始枚举
    //因为最多有24根火柴，排除+=号所需的4根火柴，数字1要的火柴最少，20根火柴最多能组成10个1，所以XZY里的任何一个数字不能大于1111
    for (x = 0; x <=1111; ++x) {
        for (int y = 0; y <= 1111; ++y) {
            z=x+y;
            if(fun(x)+ fun(y)+ fun(z)==matchstickNum-4){
                printf("%d+%d=%d\n",x,y,z);
                sum++;
            }
        }
    }
    printf("%d matchsticks can have %d combination\n",matchstickNum,sum);
    return 0;
}