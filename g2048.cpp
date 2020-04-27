#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

#define __STD 1
#define __ONLY2 1
#define __LITTLE3 1
#define __MS 1
#define __FEB 1
#define __LIMIT 0

/* ERROR ___*/
#define __ERROR_0 "This is developing.\n\
Please waiting for it.\nThanks for using this program."
#define __ERROR_1 ""
#define rnd(n) (int)(rand()%n+1)
#define R  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED)
#define Ob  Rb
#define Rb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY)
#define W  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN)
#define Wb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY)
#define Wb2  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN)
#define B  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE)
#define Bb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE)
#define G  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN)
#define Gb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY)
#define YX  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN)
#define Yb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY)
#define S  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE)
#define Sb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY)
#define P  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED)
#define Pb  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY)

int ax[30][30]={0};
bool kkk;
int nx,kl;
int scx=0;
int lg = rnd(2);//LTL used
void outp();
void r();
void dx();
int n,sc;
bool check_fi(int lol,int olo)  //  check Fibonacci Number
{
    if(lol > olo)   swap(lol,olo);
    if(lol == olo && lol == 1)  return 1;
    if(lol == 1 && olo == 2)    return 1;
    if(olo < (lol * 2) && olo > lol)    return 1;
    return 0;
}
void outp()
{
    system("cls");
    cout<<"score:"<<sc<<endl;
    for (int i=1;i<=n;i++)
    {
        Yb,cout<<'|';for (int j=1;j<=n;j++) Yb,printf("------|");cout<<endl;
        Yb,cout<<'|';for (int j=1;j<=n;j++) if (ax[i][j]==0) Wb2,printf("      ",ax[i][j]),Yb,cout<<'|';
                                else if (ax[i][j]>8) Rb,printf("%4d  ",ax[i][j]),Yb,cout<<'|';
                                    else if(ax[i][j] > 4) Ob,printf("%4d  ",ax[i][j]),Yb,cout<<'|';
                                        else if (ax[i][j]>2) Yb,printf("%4d  ",ax[i][j]),Yb,cout<<'|';
                                            else Wb,printf("%4d  ",ax[i][j]),Yb,cout<<'|';cout<<endl;
        Yb,cout<<'|';for (int j=1;j<=n;j++) if (ax[i][j]==0) Wb2,printf("      "),Yb,cout<<'|';
                                else if (ax[i][j]>8) Rb,printf("      "),Yb,cout<<'|';
                                    else if(ax[i][j] > 4) Ob,printf("      "),Yb,cout<<'|';
                                         else if (ax[i][j]>2) Yb,printf("      "),Yb,cout<<'|';
                                            else Wb,printf("      "),Yb,cout<<'|';cout<<endl;
    }
    Yb,cout<<'|';for (int j=1;j<=n;j++) Yb,printf("------|");cout<<endl;
}
void r()
{
    //if (kl==0) cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    int g=rnd(kl--);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (ax[i][j]==16) {}//cout<<"You are win!";//,Sleep(2000),exit(0);
            if (ax[i][j]==0){
                g--;
                if (!g) if (rnd(8)==5) ax[i][j]=4; else ax[i][j]=2;
            }
        }
}
void ltl_output()       //output of LITTLE THREE LEGEND
{
    //if (kl==0) cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    int g=rnd(kl--);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (ax[i][j]==16) cout<<"You are win!";//,Sleep(2000),exit(0);
            if (ax[i][j]==0){
                g--;
                if (!g) if (rnd(8)==7) ax[i][j]=3; else{ ax[i][j]=(lg*2)%3; lg = (lg*2)%3;}
            }
        }
}
void addd()
{
    int xxx = rnd(n),yyy = rnd(n);
    while(ax[xxx][yyy])
    {
        xxx = rnd(n);
        yyy = rnd(n);
    }
    ax[xxx][yyy] = 2 * rnd(2);
}
void fi_r() //fibonacci add program that is debugged
{
    int xxx = rnd(n),yyy = rnd(n);
    while(ax[xxx][yyy])
    {
        xxx = rnd(n);
        yyy = rnd(n);
    }
    ax[xxx][yyy] = 1;
}
bool  LTL_check()
{
    for(int i = 1; i<= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(ax[i][j] == 0)    return false;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if((ax[j][i] == ax[j+1][i] && ax[j][i]!=0 && ax[j][i] != 1 && ax[j][i] != 2) ||(ax[j][i] == 1 && ax[j + 1][i] == 2) || (ax[j][i] == 2 & ax[j + 1][i] == 1))  return false;
            if((ax[j][i] == ax[j][i+1] && ax[j][i]!=0 && ax[j][i] != 1 && ax[j][i] != 2) ||(ax[j][i] == 1 && ax[j][i + 1] == 2) || (ax[j][i] == 2 & ax[j][i + 1] == 1))  return false;

        }
        return true;
}
void only_two()
{
    //if (kl==0) cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    int g=rnd(kl--);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (ax[i][j]==16) cout<<"You are win!";//,Sleep(2000),exit(0);
            if (ax[i][j]==0){
                g--;
                if (!g) if (rnd(8)==10) ax[i][j]=4; else ax[i][j]=2;
            }
        }
}
bool checkx()
{
    for(int i = 1; i<= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(ax[i][j] == 0)    return false;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(ax[i][j] == ax[i][j+1] || ax[i][j] == ax[i+1][j])    return false;
        return true;
}
bool check_fi_out()
{
    for(int i = 1; i<= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(ax[i][j] == 0)    return false;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(check_fi(ax[i][j],ax[i][j+1]) || check_fi(ax[i][j],ax[i+1][j]))  return false;
        return true;
}
void dx()
{
    kkk= 1;
    char w;
    w=getch();
    if (w=='w'||w =='W'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[k][i] = ax[k+1][i];
                ax[n][i]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(ax[j][i] == ax[j+1][i] && ax[j][i]!=0)
            {
                kl++;
                ax[j][i] *=2;
                sc+=ax[j][i];
                for(int k = j + 1; k < n; k ++)
                ax[k][i] = ax[k+1][i];
                ax[n][i] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='a'|| w == 'A'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(ax[i][j] == ax[i][j+1] && ax[i][j]!=0)
            {
                kl++;
                ax[i][j] *=2;
                sc+=ax[i][j];
                for(int k = j + 1; k < n; k ++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='s' || w == 'S'){
    for(int i = n; i >=1; i --)
        for(int k = 1,j = n; j >= 1; j --,k ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k >1; k--)
                ax[k][i] = ax[k-1][i];
                ax[1][i]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i --)
        for(int j = n; j >=1; j --)
        {
            if(ax[j][i] == ax[j-1][i] && ax[j][i]!=0)
            {
                kl++;
                ax[j][i] *=2;
                sc+=ax[j][i];
                for(int k = j - 1; k >1; k --)
                ax[k][i] = ax[k-1][i];
                ax[1][i] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='d'|| w == 'D'){
    for(int i = n;i >= 1; i --)
        for(int j = n,k = 1; j >=1; j --,k ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k > 1; k--)
                ax[i][k] = ax[i][k - 1];
                ax[i][1]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i--)
        for(int j = n; j >=1; j --)
        {
            if(ax[i][j] == ax[i][j-1] && ax[i][j]!=0)
            {
                kl++;
                ax[i][j] *=2;
                sc+=ax[i][j];
                for(int k = j - 1; k > 1; k --)
                ax[i][k] = ax[i][k - 1];
                ax[i][1] = 0;
                kkk = 0;
            }
        }
    }
    if(checkx()) cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    if(kkk)
    {
        //cout<<"No";
        dx();
    }
}
void fi_d()
{
    kkk= 1;
    char w;
    w=getch();
    if (w=='w'||w =='W'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[k][i] = ax[k+1][i];
                ax[n][i]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(check_fi(ax[j][i],ax[j+1][i]))
            {
                kl++;
                ax[j][i] +=ax[j+1][i];
                sc+=ax[j][i];
                for(int k = j + 1; k < n; k ++)
                ax[k][i] = ax[k+1][i];
                ax[n][i] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='a'|| w == 'A'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(check_fi(ax[i][j],ax[i][j+1]))
            {
                kl++;
                ax[i][j] += ax[i][j+1];
                sc+=ax[i][j];
                for(int k = j + 1; k < n; k ++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='s' || w == 'S'){
    for(int i = n; i >=1; i --)
        for(int k = 1,j = n; j >= 1; j --,k ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k >1; k--)
                ax[k][i] = ax[k-1][i];
                ax[1][i]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i --)
        for(int j = n; j >=1; j --)
        {
            if(check_fi(ax[j][i],ax[j-1][i]))
            {
                kl++;
                ax[j][i] +=ax[j-1][i];
                sc+=ax[j][i];
                for(int k = j - 1; k >1; k --)
                ax[k][i] = ax[k-1][i];
                ax[1][i] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='d'|| w == 'D'){
    for(int i = n;i >= 1; i --)
        for(int j = n,k = 1; j >=1; j --,k ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k > 1; k--)
                ax[i][k] = ax[i][k - 1];
                ax[i][1]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i--)
        for(int j = n; j >=1; j --)
        {
            if(check_fi(ax[i][j] ,ax[i][j-1]))
            {
                kl++;
                ax[i][j] += ax[i][j-1];
                sc+=ax[i][j];
                for(int k = j - 1; k > 1; k --)
                ax[i][k] = ax[i][k - 1];
                ax[i][1] = 0;
                kkk = 0;
            }
        }
    }
    if(check_fi_out())  cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    if(kkk)
    {
        //cout<<"No";
        fi_d();
    }
}
void LTL()      //LITTLE THREE LEGEND
{
    kkk= 1;
    char w;
    w=getch();
    if (w=='w'||w =='W'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[k][i] = ax[k+1][i];
                ax[n][i]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if((ax[j][i] == ax[j+1][i] && ax[j][i]!=0 && ax[j][i] != 1 && ax[j][i] != 2) ||(ax[j][i] == 1 && ax[j + 1][i] == 2) || (ax[j][i] == 2 & ax[j + 1][i] == 1))
            {
                kl++;
                ax[j][i] +=ax[j+1][i];
                sc+=ax[j][i];
                for(int k = j + 1; k < n; k ++)
                ax[k][i] = ax[k+1][i];
                ax[n][i] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='a'|| w == 'A'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if((ax[i][j] == ax[i][j+1] && ax[i][j]!=0 && ax[i][j+1] != 1 && ax[i][j+1] != 2) ||(ax[i][j] == 1 && ax[i][j+1] == 2) || (ax[i][j] == 2 & ax[i][j+1] == 1))
            {
                kl++;
                ax[i][j] +=ax[i][j+1];
                sc+=ax[i][j];
                for(int k = j + 1; k < n; k ++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='s' || w == 'S'){
    for(int i = n; i >=1; i --)
        for(int k = 1,j = n; j >= 1; j --,k ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k >1; k--)
                ax[k][i] = ax[k-1][i];
                ax[1][i]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i --)
        for(int j = n; j >=1; j --)
        {
            if(((ax[j][i] == ax[j-1][i] && ax[j][i]!=0 && ax[j][i] != 1 && ax[j][i] != 2) ||(ax[j][i] == 1 && ax[j - 1][i] == 2) || (ax[j][i] == 2 & ax[j-1][i] == 1)))
            {
                kl++;
                ax[j][i] +=ax[j-1][i];
                sc+=ax[j][i];
                for(int k = j - 1; k >1; k --)
                ax[k][i] = ax[k-1][i];
                ax[1][i] = 0;
                kkk = 0;
            }
        }
    }
    else if (w=='d'|| w == 'D'){
    for(int i = n;i >= 1; i --)
        for(int j = n,k = 1; j >=1; j --,k ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k > 1; k--)
                ax[i][k] = ax[i][k - 1];
                ax[i][1]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i--)
        for(int j = n; j >=1; j --)
        {
            if((ax[i][j] == ax[i][j-1] && ax[i][j]!=0 && ax[i][j-1] != 1 && ax[i][j-1] != 2) ||(ax[i][j] == 1 && ax[i][j-1] == 2) || (ax[i][j] == 2 & ax[i][j-1] == 1))
            {
                kl++;
                ax[i][j] +=ax[i][j-1];
                sc+=ax[i][j];
                for(int k = j - 1; k > 1; k --)
                ax[i][k] = ax[i][k - 1];
                ax[i][1] = 0;
                kkk = 0;
            }
        }
    }
    if(LTL_check()) cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    if(kkk)
    {
        //cout<<"No";
        LTL();
    }
}

void merg()
{
    kkk= 1;
    char w;
    w=getch();
    if (w=='w'||w =='W'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[k][i] = ax[k+1][i];
                ax[n][i]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
                kl++;
                ax[j][i] +=ax[j+1][i];
                sc+=ax[j][i];
                for(int k = j + 1; k < n; k ++)
                ax[k][i] = ax[k+1][i];
                ax[n][i] = 0;
                kkk = 0;
        }
    }
    else if (w=='a'|| w == 'A'){
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k < n; k++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n]= 0;
                tmp++;
            }
            if(tmp < (n-j+1) && tmp > 0)    kkk = 0;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
                kl++;
                ax[i][j] +=ax[i][j+1];
                sc+=ax[i][j];
                for(int k = j + 1; k < n; k ++)
                ax[i][k] = ax[i][k + 1];
                ax[i][n] = 0;
                kkk = 0;
        }
    }
    else if (w=='s' || w == 'S'){
    for(int i = n; i >=1; i --)
        for(int k = 1,j = n; j >= 1; j --,k ++)
        {
            int tmp = 0;
            while(ax[j][i] == 0 && tmp <=n)
            {
                for(int k = j;k >1; k--)
                ax[k][i] = ax[k-1][i];
                ax[1][i]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i --)
        for(int j = n; j >=1; j --)
        {
                kl++;
                ax[j][i] +=ax[j-1][i];
                sc+=ax[j][i];
                for(int k = j - 1; k >1; k --)
                ax[k][i] = ax[k-1][i];
                ax[1][i] = 0;
                kkk = 0;
        }
    }
    else if (w=='d'|| w == 'D'){
    for(int i = n;i >= 1; i --)
        for(int j = n,k = 1; j >=1; j --,k ++)
        {
            int tmp = 0;
            while(ax[i][j] == 0 && tmp <=n)
            {
                for(int k = j;k > 1; k--)
                ax[i][k] = ax[i][k - 1];
                ax[i][1]= 0;
                tmp++;
            }
            if(tmp < (n-k+1) && tmp > 0)    kkk = 0;
        }
    for(int i = n; i >=1; i--)
        for(int j = n; j >=1; j --)
        {
                kl++;
                ax[i][j] +=ax[i][j-1];
                sc+=ax[i][j];
                for(int k = j - 1; k > 1; k --)
                ax[i][k] = ax[i][k - 1];
                ax[i][1] = 0;
                kkk = 0;
        }
    }
    //if(check())   cout<<"You out! score:"<<sc,Sleep(2000),exit(0);
    if(kkk)
    {
        //cout<<"No";
        dx();
    }
}
void stnd()     //std
{
    r();
    while(1)
    {
        r();
        outp();
        dx();
    }
}
void ot()       //only_two
{
    only_two();
    while(1)
    {
        only_two();
        outp();
        dx();
    }
}
void ltl()          //LITTLE THREE LEGEND
{
    ltl_output();
    while(1)
    {
        ltl_output();
        outp();
        LTL();
    }
}
void first()
{
    int ty;
    scanf("%d",&ty);
    switch(ty)
    {
        case 0:{
#if __STD
            SMALL_RECT winPon={0,0,n*7+1,3*n+2};
            HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleWindowInfo(con,true,&winPon);
            stnd();
#else
            cout<<__ERROR_0;
            Sleep(2000);
#endif
        }
            break;
        case 2:{
#if __ONLY2
            SMALL_RECT winPon={0,0,n*7+1,3*n+2};
            HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleWindowInfo(con,true,&winPon);
            ot();
#else
            cout<<__ERROR_0;
            Sleep(2000);
#endif
            break;
        }
        case 4:{
#if __MS
            SMALL_RECT winPon={0,0,n*7+1,3*n+2};
            HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleWindowInfo(con,true,&winPon);
            addd();
            while(1)
            {
                addd();
                outp();
                merg();
            }
#else
            cout<<__ERROR_0;
            Sleep(2000);
#endif
            break;
        }
        case 1:{
#if __LITTLE3
            SMALL_RECT winPon={0,0,n*7+1,3*n+2};
            HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleWindowInfo(con,true,&winPon);
            ltl();
#else
            cout<<__ERROR_0;
            Sleep(2000);
#endif
            break;

        }
        case 3:{
#if __FEB
            SMALL_RECT winPon={0,0,n*7+1,3*n+2};
            HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleWindowInfo(con,true,&winPon);
            while(1)
            {
                fi_r();
                outp();
                fi_d();
            }
#else
            cout<<__ERROR_0;
            Sleep(2000);
#endif
            break;

        }
        case 5:{
#if __LIMIT
            SMALL_RECT winPon={0,0,n*7+1,3*n+2};
            HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleWindowInfo(con,true,&winPon);
            lim();
#else
            cout<<__ERROR_0;
            Sleep(2000);
#endif
            break;
        }
    }

}
int g2048() {
    srand((unsigned)time(NULL));
    cout<<" 2048 2.0\n  Name: 2048 Game\n   Copyright: W.Guo & X.Y.Zhang All Rights Reserved.\n Author: 4096 Team from 192.168.45.99 LJOJ\n Date: 14/07/17 14:29\n  Description: Join the numbers and get to the 2048 tile! \n  The Specialty of the Refreshment 2.0: added more types of the games."<<endl;
    cout<<" Now,please input the number of the size of the game(<=10)"<<endl;
    cin>>nx;
    kl=nx*nx;
    cout<<" Now,please give a number of your game type"<<endl;
    cout<<" 0: standard\n 1: Little Three Legend\n 2: Only two\n 3: Fibonacci\n 4: Merge Any(entertainment)\n 5: Time Limitation Mode(debugging)\n";
    first();
}
int main(){
	g2048();
}
