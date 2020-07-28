#include <string>
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
#define n 20
int ny;
//函数定义
void sch(int color);
void fileout();
void print(const char a[],int b);
void Initialize();
void gotoxy(int x,int y);
void cursor(bool a);
void shop(int c);
void warout(int xx,int yy);
void war(int c);
void game();
bool issame(string x);
bool charsame(char a[105],char b[105],int blen);
int canfind(int len);
bool login_register();
void enter();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//存档系统
struct users{
    char name[105];int namelen;
    char password[105];int passwordlen;
    int gold,h,u;
}user[100005];
int usertot,nowuser;
void fileout(bool x){
    freopen("game.ini","w",stdout);
    cout<<usertot<<endl;
    for (int i=1;i<=usertot;i++)cout<<user[i].name<<' '<<user[i].namelen<<' '<<user[i].password<<' '<<user[i].passwordlen<<' '<<user[i].gold<<' '<<user[i].h<<' '<<user[i].u<<endl;
}
//存档系统
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//工具程序
void sch(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}
void print(const char a[],int b){
    int s=strlen(a);
    for(int i=0;i<s;i++){
        printf("%c",a[i]);
        Sleep(b);
    }
}
void Initialize(){
    system("color f0");
    RECT rect;
    HWND hwnd=GetForegroundWindow();
    GetWindowRect(hwnd,&rect);
    MoveWindow(hwnd,0,0,rect.right-rect.left,rect.bottom-rect.top,TRUE);
    system("mode con cols=90 lines=30");
}
void gotoxy2(int x,int y){
    COORD pos;
    pos.X=2*x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void cursor(bool a){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = a;
    SetConsoleCursorInfo(handle, &CursorInfo);
}
//工具程序
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//神之商城
void shop(int c){
    system("cls");
    cout<<"剩余金币："<<user[c].gold<<endl;
    cout<<"按H购买武器"<<endl;
    cout<<"按U购买技能"<<endl;
    char x;
    x=getch();
    if(x>='a'){
    	x-='a'-'A';
	}
    if (x!='H'&&x!='U'){cout<<"操作失败！"<<endl;Sleep(500);return;}
    if (x=='H'){
        cout<<endl<<"请输入武器编号购买武器"<<endl;
        cout<<"1 神之剑 花费0金币"<<endl;
        cout<<"2 激光枪 花费200金币" <<endl;
        cout<<"3 激光炮 花费400金币"<<endl;
        cout<<"4 概率枪 花费1500金币"<<endl;
        cout<<"5 电之弓 花费1000金币"<<endl;
        int cost[105]={0,0,200,400,1500,1000};
        char s=getch();
        if (s<'1'||s>'5'){cout<<"操作失败"<<endl;Sleep(500);return;}
        if ((user[c].h&(1<<s-1-48))||(user[c].gold<cost[s-48])){cout<<"操作失败！"<<endl;Sleep(500);return;}
        user[c].h|=(1<<s-1-48),user[c].gold-=cost[s-48];
        cout<<"购买成功！"<<endl;
        Sleep(500);
    }
    if (x=='U'){
        cout<<endl<<"请输入技能编号购买技能"<<endl;
        cout<<"1 箭雨 花费0金币"<<endl;
        cout<<"2 生命法阵 花费600金币" <<endl;
        cout<<"3 法术传送 花费800金币"<<endl;
        cout<<"4 突刺 花费600金币"<<endl;
        cout<<"5 时空跃迁 花费1000金币"<<endl;
        int cost[105]={0,0,600,800,600,1000};
        char s=getch();
        if (s<'1'||s>'5'){cout<<"操作失败！"<<endl;Sleep(500);return;}
        if ((user[c].u&(1<<s-1-48))||(user[c].gold<cost[s-48])){cout<<"操作失败！"<<endl;Sleep(500);return;}
        user[c].u|=1<<(s-1-48),user[c].gold-=cost[s-48];
        cout<<"购买成功！"<<endl;
        Sleep(500);
    }
    return;
}
//神之商城
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//神域战争
struct warmap{
    int a,b,hp;
}mp[30][30];
int ccc[30][30];
void warout(int xx,int yy){
    system("cls");
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ccc[i][j]){
                cout<<'@';
            }
            else{
                if (mp[i][j].b){
                    cout<<mp[i][j].hp;
                }
                else if(i!=xx||j!=yy)cout<<'.';
                else{
                    cout<<"#";
                }
            }
        }
        cout<<endl;
    }
    Sleep(700);
    return;
}
void war(int c){
    int book[30][30];
    int cd[105]={0,10,30,5,8,10};
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mp[i][j].a=mp[i][j].b=0;
    srand((unsigned)time(NULL));
    char hc,uc;
    if (user[c].h==0||user[c].u==0){
        system("cls");
        cout<<"请先购买武器和技能"<<endl;
        Sleep(500);
        return;
    }
    system("cls");
    int sss=user[c].h;
    cout<<"请输入编号选择武器"<<endl;
    if (sss&1)cout<<"1 神之剑"<<endl;
    if (sss&2)cout<<"2 激光枪"<<endl;
    if (sss&4)cout<<"3 激光炮"<<endl;
    if (sss&8)cout<<"4 概率枪"<<endl;
    if (sss&16)cout<<"5 电之弓"<<endl;
    hc=getch();
    if (hc<'1'||hc>'5'||(!(sss&(1<<(hc-48-1))))){
        system("cls");
        cout<<"操作失败！"<<hc-48-1<<endl;
        Sleep(500);
        return;
    }
    else cout<<"选择成功！"<<endl;
    Sleep(500);
    hc-=48;
    system("cls");
    sss=user[c].u;
    cout<<"请输入编号选择技能"<<endl;
    if (sss&1)cout<<"1 箭雨"<<endl;
    if (sss&2)cout<<"2 生命法阵"<<endl;
    if (sss&4)cout<<"3 法术传送"<<endl;
    if (sss&8)cout<<"4 突刺"<<endl;
    if (sss&16)cout<<"5 时空跃迁"<<endl;
    uc=getch();
    if (uc<'1'||uc>'5'||(!(sss&(1<<(uc-1-48))))){
        system("cls");
        cout<<"操作失败！"<<endl;
        Sleep(500);
        return;
    }
    else cout<<"选择成功！"<<endl;
    uc-=48;
    Sleep(500);
    int hp=5;
    int xx=1+rand()%n;
    int yy=1+rand()%n;
    int ucd=cd[uc],gold=0;
    int cnt=0,kill=0,killl;
    int lx=xx,ly=yy,last=0;
    while(1){
        if (cnt==200){
            system("cls");
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++)
                    cout<<'!';
                cout<<endl;
            }
            Sleep(1500);
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++)
                    mp[i][j].b=0;
            }
            cout<<"通关了！"<<endl;
            user[c].gold+=1000;
            cout<<"获得1000金币！"<<endl;
            Sleep(3000);
            return;
        }
        for (int i=4;i;i--)
            if (rand()%i){
                int x=1+rand()%n;
                int y=1+rand()%n;
                if (mp[x][y].b==0&&(x!=xx||y!=yy)){
                    mp[x][y].b=1;
                    mp[x][y].hp=1+rand()%9;
                }
            }
        system("cls");
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++)
                if (mp[i][j].b){
                    cout<<mp[i][j].hp;
                }
                else if(i!=xx||j!=yy)cout<<'.';
                else{
                    cout<<"#";
                }
            cout<<endl;
        }
        Sleep(500);
        if (hp<=0){
            system("cls");
            cout<<"神失败了！"<<endl;
            cout<<"共进行"<<cnt<<"回合"<<endl;
            cout<<"共获得"<<gold<<"金币"<<endl;
            cout<<"共击杀"<<killl<<"敌人"<<endl;
            user[c].gold+=gold;
            Sleep(2000);
            return;
        }
        cout<<"当前生命值："<<hp<<endl;
        cout<<"当前能量值："<<kill<<endl;
        cout<<"当前回合数："<<cnt<<endl;
        cout<<"移动请输入W或A或S或D"<<endl;
        cout<<"技能请输入U 当前CD："<<ucd<<endl;
        cout<<"攻击请输入I或J或K或L"<<endl;
        cout<<"消耗40能量值回复生命请输入H"<<endl;
        cout<<"消耗100能量值清除所有敌人请输入C"<<endl;
        cout<<"退出游戏请输入B"<<endl;
        char cc=getch();
        if (cc=='B'){
            system("cls");
            cout<<"共获得"<<gold<<"金币"<<endl;
            user[c].gold+=gold;
            Sleep(500);
            return;
        }
        if (cc=='H'&&kill>=40){
            kill-=40;
            hp=5;
            cout<<"回复成功！"<<endl;
        }
        if (cc=='C'&&kill>=100){
            kill-=100;
            system("cls");
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++)
                    if (mp[i][j].b)cout<<mp[i][j].hp;
                    else if(i!=xx||j!=yy)cout<<'.';
                    else cout<<"#";
                cout<<endl;
            }
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    mp[i][j].b=0;
            Sleep(500);
        }
        if (cc=='W'&&xx>1&&mp[xx-1][yy].b==0)xx--;
        if (cc=='A'&&yy>1&&mp[xx][yy-1].b==0)yy--;
        if (cc=='S'&&xx<n&&mp[xx+1][yy].b==0)xx++;
        if (cc=='D'&&yy<n&&mp[xx][yy+1].b==0)yy++;
        if (cc=='U'&&ucd==0&&uc==1){
            system("cls");
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++)
                    if (mp[i][j].b)cout<<mp[i][j].hp;
                    else if(i!=xx||j!=yy)cout<<'.';
                    else cout<<"#";
                cout<<endl;
            }
            Sleep(500);
            ucd=cd[uc]+1;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++){
                    if (mp[i][j].b){
                        mp[i][j].hp-=2;
                        if (mp[i][j].hp<=0)mp[i][j].b=0,gold+=rand()%3,kill++,killl++;
                    }
                }
        }
        if (cc=='U'&&ucd==0&&uc==2){
            hp=5;
            ucd=cd[uc]+1;
        }
        if (cc=='U'&&ucd==0&&uc==3){
            int nx=1+rand()%n,ny=1+rand()%n;
            while(mp[nx][ny].b)nx=1+rand()%n,ny=1+rand()%n;
            xx=nx,yy=ny;
            ucd=cd[uc]+1;
        }
        if (cc=='U'&&ucd==0&&uc==4){
            cout<<"请选择突刺方向，输入I或J或K或L"<<endl;
            char inc;
            inc=getch();
            if (inc!='I'&&inc!='J'&&inc!='K'&&inc!='L'){
                cout<<"操作失败！"<<endl;
                Sleep(500);
            }
            int nnx=xx,nny=yy;
            if (inc=='I'){
                memset(ccc,0,sizeof(ccc));
                for (int i=1;i<=3&&xx>i;i++){
                    ccc[xx-i][yy]=1;
                    if (mp[xx-i][yy].b)gold+=rand()%3,kill++,killl++;
                    mp[xx-i][yy].b=0;
                }
                xx=max(xx-3,1);
            }
            if (inc=='J'){
                memset(ccc,0,sizeof(ccc));
                for (int i=1;i<=3&&yy>i;i++){
                    ccc[xx][yy-i]=1;
                    if (mp[xx][yy-i].b)gold+=rand()%3,kill++,killl++;
                    mp[xx][yy-i].b=0;
                }
                yy=max(yy-3,1);
            }
            if (inc=='K'){
                memset(ccc,0,sizeof(ccc));
                for (int i=1;i<=3&&xx+i<=n;i++){
                    ccc[xx+i][yy]=1;
                    if (mp[xx+i][yy].b)gold+=rand()%3,kill++,killl++;
                    mp[xx+i][yy].b=0;
                }
                xx=min(xx+3,n);
            }
            if (inc=='L'){
                memset(ccc,0,sizeof(ccc));
                for (int i=1;i<=3&&yy+i<=n;i++){
                    ccc[xx][yy+i]=1;
                    if (mp[xx][yy+i].b)gold+=rand()%3,kill++,killl++;
                    mp[xx][yy+i].b=0;
                }
                yy=min(yy+3,n);
            }
            ccc[nnx][nny]=1;
            warout(nnx,nny);
            ucd=cd[uc]+1;
        }
        if (cc=='U'&&ucd==0&&uc==5){
            cout<<"请选择移动方向，输入I或J或K或L"<<endl;
            char inc;
            inc=getch();
            if (inc=='I')xx=1;
            if (inc=='J')yy=1;
            if (inc=='K')xx=n;
            if (inc=='L')yy=n;
            ucd=cd[uc]+1;
            mp[xx][yy].b=0;
        }
        if (cc=='I'||cc=='J'||cc=='K'||cc=='L'){
            memset(ccc,0,sizeof(ccc));
            if (hc==1&&cc=='I'){
                if (xx>1)ccc[xx-1][yy]=1;
                if (xx>2)ccc[xx-2][yy]=1;
                warout(xx,yy);
                if (xx>1&&mp[xx-1][yy].b){
                    if (!mp[xx-1][yy].b)continue;
                    mp[xx-1][yy].hp-=8;
                    if (mp[xx-1][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx-1][yy].b=0;
                }
                if (xx>2&&mp[xx-2][yy].b){
                    if (!mp[xx-2][yy].b)continue;
                    mp[xx-2][yy].hp-=8;
                    if (mp[xx-2][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx-2][yy].b=0;
                }
            }
            if (hc==1&&cc=='J'){
                if (yy>1)ccc[xx][yy-1]=1;
                if (yy>2)ccc[xx][yy-2]=1;
                warout(xx,yy);
                if (yy>1&&mp[xx][yy-1].b){
                    if (mp[xx][yy-1].b)mp[xx][yy-1].hp-=8;
                    if (mp[xx][yy-1].b&&mp[xx][yy-1].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][yy-1].b=0;
                }
                if (yy>2&&mp[xx][yy-2].b){
                    if (mp[xx][yy-2].b)mp[xx][yy-2].hp-=8;
                    if (mp[xx][yy-2].hp<=0&&mp[xx][yy-2].b)gold+=rand()%3,kill++,killl++,mp[xx][yy-2].b=0;
                }
            }
            if (hc==1&&cc=='K'){
                if (xx+1<=n)ccc[xx+1][yy]=1;
                if (xx+2<=n)ccc[xx+2][yy]=1;
                warout(xx,yy);
                if (xx+1<=n&&mp[xx+1][yy].b){
                    if (mp[xx+1][yy].b)mp[xx+1][yy].hp-=8;
                    if (mp[xx+1][yy].hp<=0&&mp[xx+1][yy].b)gold+=rand()%3,kill++,killl++,mp[xx+1][yy].b=0;
                }
                if (xx+2<=n&&mp[xx+2][yy].b){
                    if (mp[xx+2][yy].b)mp[xx+2][yy].hp-=8;
                    if (mp[xx+2][yy].hp<=0&&mp[xx+2][yy].b)gold+=rand()%3,kill++,killl++,mp[xx+2][yy].b=0;
                }
            }
            if (hc==1&&cc=='L'){
                if (yy+1<=n)ccc[xx][yy+1]=1;
                if (yy+2<=n)ccc[xx][yy+2]=1;
                warout(xx,yy);
                if (yy+1<=n&&mp[xx][yy+1].b){
                    if (mp[xx][yy+1].b)mp[xx][yy+1].hp-=8;
                    if (mp[xx][yy+1].hp<=0&&mp[xx][yy+1].b)gold+=rand()%3,kill++,killl++,mp[xx][yy+1].b=0;
                }
                if (yy+2<=n&&mp[xx][yy+2].b){
                    if (mp[xx][yy+2].b)mp[xx][yy+2].hp-=8;
                    if (mp[xx][yy+2].hp<=0&&mp[xx][yy+2].b)gold+=rand()%3,kill++,killl++,mp[xx][yy+2].b=0;
                }
            }
            if (hc==2&&cc=='I'){
                for (int i=xx-1;i;i--)ccc[i][yy]=1;
                warout(xx,yy);
                for (int i=xx-1;i;i--){
                    if (!mp[i][yy].b)continue;
                    mp[i][yy].hp-=3+rand()%3;
                    if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                }
            }
            if (hc==2&&cc=='J'){
                for (int i=yy-1;i;i--)ccc[xx][i]=1;
                warout(xx,yy);
                for (int i=yy-1;i;i--){
                    if (!mp[xx][i].b)continue;
                    mp[xx][i].hp-=3+rand()%3;
                    if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                }
            }
            if (hc==2&&cc=='K'){
                for (int i=xx+1;i<=n;i++)ccc[i][yy]=1;
                warout(xx,yy);
                for (int i=xx+1;i<=n;i++){
                    if (!mp[i][yy].b)continue;
                    mp[i][yy].hp-=3+rand()%3;
                    if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                }
            }
            if (hc==2&&cc=='L'){
                for (int i=yy+1;i<=n;i++)ccc[xx][i]=1;
                warout(xx,yy);
                for (int i=yy+1;i<=n;i++){
                    if (!mp[xx][i].b)continue;
                    mp[xx][i].hp-=3+rand()%3;
                    if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                }
            }
            if (hc==3&&cc=='I'){
                for (int i=xx-1;i;i--){
                    ccc[i][yy-1]=1;
                    ccc[i][yy]=1;
                    ccc[i][yy+1]=1;
                }
                warout(xx,yy);
                for (int i=xx-1;i;i--){
                    if (mp[i][yy].b){
                        mp[i][yy].hp-=2+rand()%2;
                        if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                    }
                    if (mp[i][yy-1].b){
                        mp[i][yy-1].hp-=2+rand()%2;
                        if (mp[i][yy-1].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy-1].b=0;
                    }
                    if (mp[i][yy+1].b){
                        mp[i][yy+1].hp-=2+rand()%2;
                        if (mp[i][yy+1].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy+1].b=0;
                    }
                }
            }
            if (hc==3&&cc=='J'){
                for (int i=yy-1;i;i--){
                    ccc[xx][i]=1;
                    ccc[xx-1][i]=1;
                    ccc[xx+1][i]=1;
                }
                warout(xx,yy);
                for (int i=yy-1;i;i--){
                    if (mp[xx][i].b){
                        mp[xx][i].hp-=2+rand()%2;
                        if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                    }
                    if (mp[xx-1][i].b){
                        mp[xx-1][i].hp-=2+rand()%2;
                        if (mp[xx-1][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx-1][i].b=0;
                    }
                    if (mp[xx+1][i].b){
                        mp[xx+1][i].hp-=2+rand()%2;
                        if (mp[xx+1][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx+1][i].b=0;
                    }
                }
            }
            if (hc==3&&cc=='K'){
                for (int i=xx+1;i<=n;i++){
                    ccc[i][yy-1]=1;
                    ccc[i][yy]=1;
                    ccc[i][yy+1]=1;
                }
                warout(xx,yy);
                for (int i=xx+1;i<=n;i++){
                    if (mp[i][yy].b){
                        mp[i][yy].hp-=2+rand()%2;
                        if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                    }
                    if (mp[i][yy-1].b){
                        mp[i][yy-1].hp-=2+rand()%2;
                        if (mp[i][yy-1].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy-1].b=0;
                    }
                    if (mp[i][yy+1].b){
                        mp[i][yy+1].hp-=2+rand()%2;
                        if (mp[i][yy+1].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy+1].b=0;
                    }
                }
            }
            if (hc==3&&cc=='L'){
                for (int i=yy+1;i<=n;i++){
                    ccc[xx-1][i]=1;
                    ccc[xx][i]=1;
                    ccc[xx+1][i]=1;
                }
                warout(xx,yy);
                for (int i=yy+1;i<=n;i++){
                    if (mp[xx][i].b){
                        mp[xx][i].hp-=2+rand()%2;
                        if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                    }
                    if (mp[xx-1][i].b){
                        mp[xx-1][i].hp-=2+rand()%2;
                        if (mp[xx-1][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx-1][i].b=0;
                    }
                    if (mp[xx+1][i].b){
                        mp[xx+1][i].hp-=2+rand()%2;
                        if (mp[xx+1][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx+1][i].b=0;
                    }
                }
            }
            if (hc==4&&cc=='I'){
                for (int i=xx-1;i;i--)ccc[i][yy]=1;
                warout(xx,yy);
                for (int i=xx-1;i;i--){
                    if (!mp[i][yy].b)continue;
                    int r=rand()%3;
                    mp[i][yy].hp-=mp[i][yy].hp*r;
                    if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                }
            }
            if (hc==4&&cc=='J'){
                for (int i=yy-1;i;i--)ccc[xx][i]=1;
                warout(xx,yy);
                for (int i=yy-1;i;i--){
                    if (!mp[xx][i].b)continue;
                    int r=rand()%3;
                    mp[xx][i].hp-=mp[xx][i].hp*r;
                    if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                }
            }
            if (hc==4&&cc=='K'){
                for (int i=xx+1;i<=n;i++)ccc[i][yy]=1;
                warout(xx,yy);
                for (int i=xx+1;i<=n;i++){
                    if (!mp[i][yy].b)continue;
                    int r=rand()%3;
                    mp[i][yy].hp-=mp[i][yy].hp*r;
                    if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                }
            }
            if (hc==4&&cc=='L'){
                for (int i=yy+1;i<=n;i++)ccc[xx][i]=1;
                warout(xx,yy);
                for (int i=yy+1;i<=n;i++){
                    if (!mp[xx][i].b)continue;
                    int r=rand()%3;
                    mp[xx][i].hp-=mp[xx][i].hp*r;
                    if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                }
            }
            if (hc==5&&cc=='I'){
                int i;
                for (i=xx;i;i--)
                    if (mp[i][yy].b)break;
                mp[i][yy].hp-=5;
                if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                if (i){
                    memset(ccc,0,sizeof(ccc));
                    ccc[i][yy]=1;
                    warout(xx,yy);
                    if (rand()%10==0){
                        memset(ccc,0,sizeof(ccc));
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                if (mp[i][j].b){
                                    mp[i][j].hp--;
                                    if (mp[i][j].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][j].b=0;
                                }
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                ccc[i][j]=1;
                        warout(xx,yy);
                    }
                }
            }
            if (hc==5&&cc=='J'){
                int i;
                for (i=yy;i;i--)
                    if (mp[xx][i].b)break;
                mp[xx][i].hp-=5;
                if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                if (i){
                    memset(ccc,0,sizeof(ccc));
                    ccc[xx][i]=1;
                    warout(xx,yy);
                    if (rand()%10==0){
                        memset(ccc,0,sizeof(ccc));
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                if (mp[i][j].b){
                                    mp[i][j].hp--;
                                    if (mp[i][j].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][j].b=0;
                                }
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                ccc[i][j]=1;
                        warout(xx,yy);
                    }
                }
            }
            if (hc==5&&cc=='K'){
                int i;
                for (i=xx;i<=n;i++)
                    if (mp[i][yy].b)break;
                mp[i][yy].hp-=5;
                if (mp[i][yy].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][yy].b=0;
                if (i<=n){
                    memset(ccc,0,sizeof(ccc));
                    ccc[i][yy]=1;
                    warout(xx,yy);
                    if (rand()%10==0){
                        memset(ccc,0,sizeof(ccc));
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                if (mp[i][j].b){
                                    mp[i][j].hp--;
                                    if (mp[i][j].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][j].b=0;
                                }
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                ccc[i][j]=1;
                        warout(xx,yy);
                    }
                }
            }
            if (hc==5&&cc=='L'){
                int i;
                for (i=yy;i<=n;i++)
                    if (mp[xx][i].b)break;
                mp[xx][i].hp-=5;
                if (mp[xx][i].hp<=0)gold+=rand()%3,kill++,killl++,mp[xx][i].b=0;
                if (i<=n){
                    memset(ccc,0,sizeof(ccc));
                    ccc[xx][i]=1;
                    warout(xx,yy);
                    if (rand()%10==0){
                        memset(ccc,0,sizeof(ccc));
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                if (mp[i][j].b){
                                    mp[i][j].hp--;
                                    if (mp[i][j].hp<=0)gold+=rand()%3,kill++,killl++,mp[i][j].b=0;
                                }
                        for (int i=1;i<=n;i++)
                            for (int j=1;j<=n;j++)
                                ccc[i][j]=1;
                        warout(xx,yy);
                    }
                }
            }
        }
        memset(book,0,sizeof(book));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                if (book[i][j])continue;
                if (!mp[i][j].b)continue;
                int movex[4]={1,0,0,-1};
                int movey[4]={0,1,-1,0};
                int s=rand()%4;
                int mmm=rand()%4;
                int nx,ny;
                if (!mmm)nx=i+movex[s],ny=j+movey[s];
                else{
                    nx=i,ny=j;
                    int mmmm=rand()%2;
                    if (nx==xx)mmmm=1;
                    if (nx==yy)mmmm=0;
                    if (mmmm==0){
                        if (nx<xx)nx++;
                        if (nx>xx)nx--;
                    }
                    if (mmmm==1){
                        if (ny<yy)ny++;
                        if (ny>yy)ny--;
                    }
                }
                if (nx<1||ny<1||nx>n||ny>n)continue;
                book[nx][ny]=1;
                if (nx==xx&&ny==yy){
                    hp-=2;
                    mp[i][j].b=0;
                    system("cls");
                    for (int i=1;i<=n;i++){
                        for (int j=1;j<=n;j++)
                            if (mp[i][j].b)cout<<mp[i][j].hp;
                            else if(i!=xx||j!=yy)cout<<'.';
                            else cout<<"!";
                        cout<<endl;
                    }
                    Sleep(500);
                    continue;
                }
                if (!mp[nx][ny].b){
                    mp[i][j].b=0;
                    mp[nx][ny].b=1;
                    mp[nx][ny].hp=mp[i][j].hp;
                }
            }
        if (xx==lx&&yy==ly)last++;
        else last=0,lx=xx,ly=yy;
        if (last>=5){
            system("cls");
                for (int i=1;i<=n;i++){
                    for (int j=1;j<=n;j++)
                        if (mp[i][j].b)cout<<mp[i][j].hp;
                        else if(i!=xx||j!=yy)cout<<'.';
                        else cout<<"!";
                    cout<<endl;
                }
            Sleep(500);
            hp--;
        }
        ucd--;
        ucd=max(ucd,0);
        cnt++;
    }
    return;
}
//神域战争
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void game2(){
    char x;
    while(x!='B'&&x!='b'){
        cout<<"退出并保存游戏请输入：B"<<endl;
        cout<<"打开神之商城请输入：S"<<endl;
        cout<<"进入神域战争请输入：W"<<endl;
        x=getch();
        if (x=='S'||x=='s')shop(nowuser);
        if (x=='W'||x=='w')war(nowuser);
        system("cls");
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//注册 登录
char rere[105];
bool issame(string x){
    for (int i=1;i<x.size();i++)
        if (rere[i]!=x[i])return 0;
    return 1;
}
bool charsame(char a[105],char b[105],int blen){
    for (int i=0;i<blen;i++)if (a[i]!=b[i])return 0;
    return 1;
}
int canfind(int len){
    int ansi=0;
    for (int i=1;i<=usertot;i++)
        if (charsame(rere,user[i].name,user[i].namelen)&&len==user[i].namelen)ansi=i;
    return ansi;
}
bool login_register(){
    char k=getch();
    while(k!='1'&&k!='2'){
        system("cls");
        cout<<"抱歉，请您再试一次"<<endl;
        cout<<"登陆请按1"<<' '<<"用户名"<<' '<<"密码"<<endl;
        cout<<"注册请按2"<<' '<<"用户名"<<' '<<"密码"<<endl;
        k=getch();
    }
    system("cls");
    if (k=='1'){
        if (usertot==0){cout<<"ERROR"<<endl;return 0;}
        cout<<"请输入用户名："<<endl;
        int len;
        scanf("%s",rere);
        len=strlen(rere);
        system("cls");
        while(!canfind(len)){
            cout<<"抱歉，未找到用户名"<<endl;
            cout<<"请重新输入"<<endl;
            scanf("%s",rere);
            len=strlen(rere);
            system("cls");
        }
        nowuser=canfind(len);
        cout<<"请输入密码："<<endl;
        scanf("%s",rere);
        len=strlen(rere);
        system("cls");
        while(!charsame(rere,user[nowuser].password,user[nowuser].passwordlen)||(len!=user[nowuser].passwordlen)){
            cout<<"抱歉，密码错误"<<endl;
            cout<<"请重新输入"<<endl;
            scanf("%s",rere);
            len=strlen(rere);
            system("cls");
        }
    }
    if (k=='2'){
        usertot++;
        nowuser=usertot;
        cout<<"请输入用户名："<<endl;
        scanf("%s",rere);
        while(canfind(strlen(rere))){
            system("cls");
            cout<<"抱歉，用户名重复，请重新输入"<<endl;
            scanf("%s",rere);
        }
        for (int i=0;i<strlen(rere);i++)user[usertot].name[i]=rere[i];
        user[usertot].namelen=strlen(rere);
        cout<<"请输入密码："<<endl;
        scanf("%s",user[usertot].password);
        user[usertot].passwordlen=strlen(user[usertot].password);
        user[usertot].gold=user[usertot].h=user[usertot].u=0;
    }
    return 1;
}
//注册 登录
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int sy(){
	freopen("game.ini","a",stdin);
	fclose(stdin);
    freopen("game.ini","r",stdin);
    cin>>usertot;
    for (int i=1;i<=usertot;i++)cin>>user[i].name>>user[i].namelen>>user[i].password>>user[i].passwordlen>>user[i].gold>>user[i].h>>user[i].u;
   // enter();
    freopen("CON", "r", stdin);
    cout<<"登陆请按1"<<endl;
    cout<<"注册请按2"<<endl;
    string name,password;
    if (!login_register())return 0;
    cout<<"欢迎，"<<user[nowuser].name<<"！"<<endl;
    Sleep(1500);
    game2();
    system("cls");
    cout<<"保存中，请稍等..."<<endl;
    fileout();
    system("cls");
    return 0;
}
int main(){
	sy();
	return 0;
}
