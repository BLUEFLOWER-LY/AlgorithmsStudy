#include <stdlib.h>
#include "stdio.h"
/*
 * 链表的插入，排序未完成
 * */

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head,*p,*q,*temp;
    int i,a;
    int n = 3;
    head = NULL;
    printf("Please Enter 3 Num\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &a);
//        动态申请一个空间用来存放节点，并用临时指针p指向这个节点
        p = (struct node *) malloc(sizeof(struct node));
//      将数据存储到当前节点的data域中
        p->data = a;
//        将当前节点的后继指针指向空
        p->next = NULL;
        if (head == NULL) {
//          如果这是第一个创建的节点就把头指针指向这个节点
            head = p;
        } else {
//            如果不是就将上一个节点的next指向当前节点
            q->next = p;
        }
        q = p;

    }
    printf("Please insert a Num\n");
    scanf("%d",&a);//读入带插入的数
//        从链表头部开始遍历
    temp = head;
    while (temp!=NULL){
        printf("%d\n\n",temp->data);
//            如果当前节点是最后一个节点或者下一个节点的值大于待插入数的时候把数插入到链表里
        if(temp->next == NULL|| temp->next->data > a){
            p = (struct node *)malloc(sizeof (struct node));
            p->data=a;
//                新增节点的后继指针指向当前节点的后继指针指向的点
            p->next=temp->next;
//                当前节点的后继指针指向新增节点
            temp->next = p;
            break;
        }
//            继续下一个节点
        temp = temp->next;
    }
//        打印输出结果
    temp = head;
    while (temp!=NULL){
        printf("%d-",temp->data);
        temp = temp->next;
    }
    getchar();
    return 0;

}
