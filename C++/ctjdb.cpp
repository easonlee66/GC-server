#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
    int a,b,s=0,t;
    cout<<"请选择计算机的速度，一个整数，越大越慢。";
    cin >> t;
    for(;;)
    {
        cout<<"请选择出什么:\n1.石头\n2.剪刀\n3.布\n4.不玩了\n";
        for(int i=1;i<=t;i++)
          b=rand()%3;
        b+=1;
        cin >> a;
        if(a==4)
          break;
        if(b==1)
          cout<<"计算机出石头，";
        if(b==2)
          cout<<"计算机出剪刀，";
        if(b==3)
          cout<<"计算机出布，";
        if(a+1==b||a-2==b)
          cout<<"你赢了！！\n";
        if(a-1==b||a+2==b)
          cout<<"你输了！！\n";
        if(a==b)
          cout<<"平局。。\n";
        s++;
    }
    cout<<"下次再来哟~~";
    return 0;
}
