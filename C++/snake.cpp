#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>
int f[111][111];
int i,d[10],a,n=15,m=15,j,ett=0,headx[10],t1,d8=1,dev_c,heady[10],k=7,rm[10],d2[10],k1,l,t=250,i3;
int fdx[1111],fdy[1111],v=10,hd[10],tl[10],djx,djy,typ,dj[111],x4[10][10000],y4[10][10000],i1,vt;
pthread_t tid,sna,tim;
double sc,hsc;
FILE* f3;
char ch; 
/******************************
*0 up ;1 down ;2 left; 3 right*
*i��ѭ������ t��sleepʱ�䣬n��*
*����m�ǿ�k1�Ƿ�����ʱ����  * 
*f�ǵ�ͼ��fdx��fdy��ʳ��λ��  *
*hdͷ��tlβ ��x4��y4 �Ƕ��У� *
*i1��ѭ��������sc�Ƿ�����tid��*
*�߳� f3���ļ�ָ�룬ch��y/n�� *
******************************/
void co1()
{
    COORD c;
    c.X=0;
    c.Y=0; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);      
}
void co(int color1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);  
}
void* f1(void* args)//��һ���̣߳�������� 
{
    for(;;)
    {
        if(ett==1)//�߳̽����ڱ� 
        return 0;
        a=getch();    
        if(a==224)
        {
            a=getch();  //�������ҷ���� 
            if(a==72&&d2[7]!=1)//��ֹ��ͷ 
            d[7]=0;
            if(a==80&&d2[7]!=0)
            d[7]=1;
            if(a==75&&d2[7]!=3)
            d[7]=2;
            if(a==77&&d2[7]!=2)
            d[7]=3;         
        }
        else 
        {   
            if(a==119&&d2[6]!=1)   //WASD 
            d[6]=0;
            if(a==115&&d2[6]!=0)
            d[6]=1;
            if(a==97&&d2[6]!=3)
            d[6]=2;
            if(a==100&&d2[6]!=2)
            d[6]=3; 
        }
    }
}
void* f2(void* args)
{
    for(;;)
    {
        Sleep(1000);
        d8++;
    }
}
void print()
{
    printf("score=%.2lf\n",sc);
    printf(" ");
    for(i=0;i<m*2;i++)
    printf("-");//�߿� 
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("|");
        for(j=1;j<=m;j++)
        {
            if(f[j][i]==0)
            printf("��");//�ռ�
            else if(f[j][i]==8)
            printf("��");//ʳ�� 
            else if(f[j][i]>=257)
            printf("��");
            else
            {
                co(f[j][i]+8);
                for(i1=1;i1<=7;i1++)
                {
                    if(j==x4[i1][hd[i1]]&&i==y4[i1][hd[i1]])
                    {
                        co(f[j][i]+4);
                    }
                }
                printf("��");//���� 
                co(7);
            }       
        }
        printf("|");
        printf("\n");
    }
    printf(" ");
    for(i=0;i<m*2;i++)
    printf("-");
    printf("\n");
    printf("\nscore=%.2lf\n\nhighest score is%.2lf\n",sc,hsc);
}
int check(int b1)
{
    int er=1;
    for(i=1;i<=v;i++)
        {
            if(x4[b1][hd[b1]]==fdx[i]&&y4[b1][hd[b1]]==fdy[i])
            {
                sc+=sqrt((hd[b1]-tl[b1])*1.0/v/sqrt(m*n*d8))*40;
                i3=0;
                do
                {
                    i3++;
                    fdx[i]=rand()%m+1;//�������ʳ�� 
                    fdy[i]=rand()%n+1;
                }while(f[fdx[i]][fdy[i]]!=0&&i3<10000);
                f[fdx[i]][fdy[i]]=8;
                if(i3>9998)
                {
                    er=2;
                    goto re;
                }
                if(rand()%3==0&&djx==0&&djy==0)
                {
                    do
                    {
                        djx=rand()%m+1;
                        djy=rand()%n+1;         //���ɵ���              
                    }while(f[djx][djy]!=0);
                    typ=1;
                    f[djx][djy]=typ+256;
                }
                er=0;
            }
        }
        if(x4[b1][hd[b1]]==djx&&y4[b1][hd[b1]]==djy)
        {
            f[djx][djy]=b1;
            djx=0;
            djy=0;
            if(rand()%7==0)
            sc*=1.5;
            else if(rand()%6==1)
            sc/=1.5;
            else if(rand()%5==2)
            {
                t*=1.5;
                sc*=0.9;
            }
            else if(rand()%4==3)
            {
                t/=1.5; 
                sc*=1.1;
            }
            else        
            {
                rm[b1]=rand()%3+2;
                sc=sc+rand()%10-4;
            }
        }
    re:return er;
}
void do1(int b1)
{
    int d1=d[b1];
        hd[b1]++;
        x4[b1][hd[b1]]=x4[b1][hd[b1]-1];
        y4[b1][hd[b1]]=y4[b1][hd[b1]-1];    
        if(d1==0)
        {
            y4[b1][hd[b1]]--;
        }
        if(d1==1)
        {
            y4[b1][hd[b1]]++;
        }
        if(d1==2)
        {
            x4[b1][hd[b1]]--;//�ƶ� 
        }
        if(d1==3)
        {
            x4[b1][hd[b1]]++;
        }
        if(x4[b1][hd[b1]]<1)
        x4[b1][hd[b1]]=m;
        else if(y4[b1][hd[b1]]<1)
        y4[b1][hd[b1]]=n;
        else if(x4[b1][hd[b1]]>m)//��ǽ 
        x4[b1][hd[b1]]=1;
        else if(y4[b1][hd[b1]]>n)
        y4[b1][hd[b1]]=1;
        if(!vt) 
        i3=check(b1);
        if(i3==2)
        {
            vt=1;//ֹͣ��� 
            sc+=(rand()%10)/10.0;
        }
        else if(i3==1)//����Ƿ�Ե����� 
        {
            f[x4[b1][tl[b1]]][y4[b1][tl[b1]]]=0;//β�� 
            tl[b1]++;
        }
        for(i=tl[b1];i<hd[b1]-1;i++)
        if((x4[b1][hd[b1]]==x4[b1][i]&&y4[b1][hd[b1]]==y4[b1][i]))
        {
            f3=fopen("snake.ini","w");
            hsc=hsc>sc?hsc:sc;
            fprintf(f3,"%lf\n",hsc);
            fprintf(f3,"%d %d %d %d %d\n",n,m,v,t1,k1);
            fclose(f3);
            f3=fopen("snake.log","a");
            fprintf(f3,"%lf\n",sc);
            fprintf(f3,"%d %d %d %d %d\n\n",n,m,v,t1,k1);
            fclose(f3);
            if(MessageBoxA(NULL,TEXT("������һ����"),TEXT("snake"),MB_YESNO|MB_SYSTEMMODAL)==IDYES)//��������һ�� 
            {
                ett=1;//�����߳� 
                Sleep(1);
                system("snake");//��Ҫ�������¿�ʼ 
            }
            exit(0);
        }
        f[x4[b1][hd[b1]]][y4[b1][hd[b1]]]=b1;//ͷ��   
    return;
}
void init()
{
    system("mode con cols=180 lines=180");
    system("title SnakeBata0.6.3");
    printf("�Զ���(Y)/Ĭ��(N)/��һ��(L)��Y/N/L\n");
    ch=getch();
    f3=fopen("snake.ini","a");
    fclose(f3);
    f3=fopen("snake.ini","r");
    fscanf(f3,"%lf",&hsc);
    if(ch=='L'||ch=='l')
    fscanf(f3,"%d %d %d %d %d",&n,&m,&v,&t,&k1);
    fclose(f3);
    if(ch=='y'||ch=='Y')
    {
        printf("�������� ���� ʳ���� �ٶ� ����\n");
        scanf("%d %d %d %d %d",&n,&m,&v,&t,&k1);
        k=8-k1;
        if(k<0)
        k=1;
    }
    f3=fopen("snake.ini","w");
    fprintf(f3,"%lf\n",hsc);
    fprintf(f3,"%d %d %d %d %d",n,m,v,t,k1);
    fclose(f3);
    t1=t;
    srand(time(NULL));
    pthread_create (&tid,NULL,f1,NULL);
    pthread_create (&tim,NULL,f2,NULL);
    for(i=7;i>=k;i--)
    {
        hd[i]=1; 
        tl[i]=1;
        x4[i][1]=rand()%m+1;//��������ߵĳ�ʼλ�� 
        y4[i][1]=rand()%n+1;
        f[x4[i][1]][y4[i][1]]=i;
    }
    for(i=1;i<=v;i++)
    {
        do
        {
            fdx[i]=rand()%m+1;//�������ʳ�� 
            fdy[i]=rand()%n+1;
        }while(f[fdx[i]][fdy[i]]!=0);
        f[fdx[i]][fdy[i]]=8;
    }
}   
int main()
{
    init();
    system("cls");
    for(;;)//��ѭ�� 
    {
        d2[6]=d[6];
        d2[7]=d[7];
        Sleep(t);
        for(i1=7;i1>=k;i1--)
        {
            if(rm[i1]==0)
            do1(i1);
            else
            {
                if(hd[i1]-tl[i1]>5)
                {
                    f[x4[i1][tl[i1]]][y4[i1][tl[i1]]]=0;
                    tl[i1]++;
                    rm[i1]--;
                }
                else
                {
                    rm[i1]=0;
                    do1(i1);
                }
            }
            for(i=tl[i1];i<=hd[i1];i++)
            f[x4[i1][tl[i1]]][y4[i1][tl[i1]]]=i1;
        }
        if(t>t1)
        t--;
        else if(t<t1)
        t++;
        co1();
        //system("cls");
        print();
    }
}

