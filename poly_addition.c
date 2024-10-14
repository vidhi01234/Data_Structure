#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
    int constt;
    int expo;
    struct poly *next;
}poly;

poly* create();
poly* addpoly(poly*,poly*);
void disp (poly*);

int main()
{
    poly *p1=NULL,*p2,*p3=NULL;
    printf("Enter 1 poly\n");
    p1=create();
    printf("Enter 2 poly\n");
    p2=create();
    p3=addpoly(p1,p2);
    printf("1 poly\n");
    disp(p1);
    printf("\n2 poly\n");
    disp(p2);
    printf("\nsum of both poly\n");
    disp(p3);
    return 0;
}

poly* create()
{
    poly *p=NULL,*l=NULL,*r=NULL;
    int ch,c,e;
    while(1)
    {
        p=(poly*) malloc (sizeof(poly));
        printf("Enter exponent");
        scanf("%d",&e);
        printf("Enter constant");
        scanf("%d",&c);
        p->expo=e;
        p->constt=c;
        if(l==NULL && r==NULL)
        {
            l=r=p;
        }
        else
        {
            r->next=p;
            r=p;
        }
        r->next=NULL;
        printf("Do you Wish to continue");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    return l;
}

poly* addpoly(poly* p1, poly* p2)
{
    poly *p=NULL,*l=NULL,*r=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        p=(poly*) malloc (sizeof(poly));
        if (p1!=NULL && p2!=NULL)
        {
            if(p1->expo==p2->expo)
            {
                p->expo=p1->expo;
                p->constt=(p1->constt) +(p2->constt);
                p1=p1->next;
                p2=p2->next;
            }
            else if((p1->expo) > (p2->expo))
            {
                p->constt=p1->constt;
                p->expo=p1->expo;
                p1=p1->next;
            }
            else
            {
                p->constt=p2->constt;
                p->expo=p2->expo;
                p2=p2->next;
            }
        }
        else if(p1!=NULL)
        {
            printf("hii loop3");
            p->constt=p1->constt;
            p->expo=p1->expo;
            p1=p1->next;
        }
        else if(p2!=NULL)
        {
            printf("hii loop4");
            p->constt=p2->constt;
            p->expo=p2->expo;
            p2=p2->next;
        }
        if(l==NULL && r==NULL)
        {
            l=r=p;
        }
        else
        {
            r->next=p;
            r=p;
        }
        r->next=NULL;
    }
    return l;
}

void disp(poly *l)
{
    if(l==NULL)
        printf("Empty");
    else
    {
        while(l!=NULL)
        {
            printf("%dx^%d",l->constt,l->expo);
            if(l->next != NULL)
                printf(" + ");
            l=l->next;
        }
    }
}

/*poly* addpoly(poly* p1, poly* p2) {
    poly *p = NULL, *l = NULL, *r = NULL;

    // Continue while either polynomial has terms left
    while (p1 != NULL || p2 != NULL) {
        p = (poly*) malloc(sizeof(poly));

        if (p1 != NULL && p2 != NULL) {
            if (p1->expo == p2->expo) {
                p->constt = p1->constt + p2->constt;
                p->expo = p1->expo;
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->expo > p2->expo) {
                p->constt = p1->constt;
                p->expo = p1->expo;
                p1 = p1->next;
            } else {
                p->constt = p2->constt;
                p->expo = p2->expo;
                p2 = p2->next;
            }
        } else if (p1 != NULL) {  // If only p1 has terms left
            p->constt = p1->constt;
            p->expo = p1->expo;
            p1 = p1->next;
        } else {  // If only p2 has terms left
            p->constt = p2->constt;
            p->expo = p2->expo;
            p2 = p2->next;
        }

        if (l == NULL) {
            l = r = p;
        } else {
            r->next = p;
            r = p;
        }
        r->next = NULL;
    }
    return l;
}
poly* addpoly(poly*p1,poly*p2)
{
    poly *p=NULL ,*l=NULL, *r=NULL;
        while(p1!=NULL || p2!=NULL)
        {
            p=(poly*) malloc (sizeof(poly));
            if(p1!=NULL && p2!=NULL)
            {
                if((p1->expo)==(p2->expo))
               {
                    p->constt=p1->constt+p2->constt;
                    p->expo=p1->expo;
                    p1=p1->next;
                    p2=p2->next;
               }
                else if((p1->expo)>(p2->expo))
               {
                    p->constt=p1->constt;
                    p->expo=p1->expo;
                    p1=p1->next;
               }
              else
              {
                p->constt=p2->constt;
                p->expo=p2->expo;
                p2=p2->next;
              }
            }
            if(p1!=NULL)
            {
                p->expo=p1->expo;
                p->constt=p1->expo;
                p1->next;
            }
            else
            {
                p->expo=p2->expo;
                p->constt=p2->expo;
                p2->next;
            }
            if(l==NULL && r==NULL)
            {
                l=p;
                r=p;
            }
            else
            {
               r->next=p;
               r=p;
            }
            r->next=NULL;
        }
    return l;
}*/
