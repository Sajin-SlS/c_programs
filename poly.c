#include<stdio.h>
#include<malloc.h>
struct poly
{
    int coeff;
    int powr;
    struct poly *link;
}*pptr,*qptr,*rptr,*pheader,*qheader,*rheader,*nw;


void dis(struct poly *header)
{
    struct poly *pntr;
    pntr=header->link;
    while(pntr!=NULL)
    {
        printf("%dx^%d + ",pntr->coeff,pntr->powr);
        pntr=pntr->link;
    }
}
void add(struct poly *pheader,struct poly *qheader,struct poly *rheader)
{
    pptr=pheader->link;
    qptr=qheader->link;
    rptr=rheader;
    while((pptr!=NULL)&&(qptr!=NULL))
    {
        if ((pptr->powr)==(qptr->powr))
        {
            nw=malloc(sizeof(struct poly));
            rptr->link=nw;
            nw->link=NULL;
            rptr=nw;
            rptr->coeff=pptr->coeff + qptr->coeff;
            rptr->powr=pptr->powr;
            pptr=pptr->link;
            qptr=qptr->link;
        }
        else if((pptr->powr)>(qptr->powr))
        {
            nw=malloc(sizeof(struct poly));
            rptr->link=nw;
            nw->link=NULL;
            rptr=nw;
            rptr->coeff=pptr->coeff;
            rptr->powr=pptr->powr;
            pptr=pptr->link;
        }
        else if((pptr->powr)<(qptr->powr))
        {
            nw=malloc(sizeof(struct poly));
            rptr->link=nw;
            nw->link=NULL;
            rptr=nw;
            rptr->coeff=qptr->coeff;
            rptr->powr=qptr->powr;
            qptr=qptr->link;
        }
    }
    if((pptr!=NULL)&&(qptr=NULL))
    {
        while(pptr!=NULL)
        {
            nw=malloc(sizeof(struct poly));
            rptr->link=nw;
            nw->link=NULL;
            rptr=nw;
            rptr->coeff=pptr->coeff;
            rptr->powr=pptr->powr;
            pptr=pptr->link;
        }
    }
    else if((pptr==NULL)&&(qptr!=NULL))
    {
        while(qptr!=NULL)
        {
            nw=malloc(sizeof(struct poly));
            rptr->link=nw;
            nw->link=NULL;
            rptr=nw;
            rptr->coeff=qptr->coeff;
            rptr->powr=qptr->powr;
            qptr=qptr->link;
        }
    }
    printf("\n Sum is: \n");
    dis(rheader);
}
void main()
{
    int i,te;
    pheader=malloc(sizeof(struct poly));
    qheader=malloc(sizeof(struct poly));
    rheader=malloc(sizeof(struct poly));
    pheader->coeff=NULL;pheader->link=NULL;pheader->powr=NULL;
    qheader->coeff=NULL;qheader->link=NULL;qheader->powr=NULL;
    rheader->coeff=NULL;rheader->link=NULL;rheader->powr=NULL;
    pptr=pheader;
    qptr=qheader;
    printf("Input number of terms in first expression: \n");
    scanf("%d",&te);
    for(i=0;i<te;i++)
    {
        nw= malloc(sizeof(struct poly));
        nw->coeff=NULL;nw->link=NULL;nw->powr=NULL;
        printf("Input the coefficient of %dth term:\n ",i+1);
        scanf("%d",&nw->coeff);
        printf("Input the power of %dth term:\n ",i+1);
        scanf("%d",&nw->powr);
        pptr->link=nw;
        pptr=nw;
    }
    dis(pheader);
    printf("\nInput noumber of terms in second expression: \n");
    scanf("%d",&te);
    for(i=0;i<te;i++)
    {
        nw= malloc(sizeof(struct poly));
        nw->coeff=NULL;nw->link=NULL;nw->powr=NULL;
        printf("\n Input the coefficient of %dth term:\n ",i+1);
        scanf("%d",&nw->coeff);
        printf("\n Input the power of %dth term:\n ",i+1);
        scanf("%d",&nw->powr);
        qptr->link=nw;
        qptr=nw;
    }
    dis(qheader);
    add(pheader,qheader,rheader);
}
