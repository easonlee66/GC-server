#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
    int a,b,s=0,t;
    cout<<"��ѡ���������ٶȣ�һ��������Խ��Խ����";
    cin >> t;
    for(;;)
    {
        cout<<"��ѡ���ʲô:\n1.ʯͷ\n2.����\n3.��\n4.������\n";
        for(int i=1;i<=t;i++)
          b=rand()%3;
        b+=1;
        cin >> a;
        if(a==4)
          break;
        if(b==1)
          cout<<"�������ʯͷ��";
        if(b==2)
          cout<<"�������������";
        if(b==3)
          cout<<"�����������";
        if(a+1==b||a-2==b)
          cout<<"��Ӯ�ˣ���\n";
        if(a-1==b||a+2==b)
          cout<<"�����ˣ���\n";
        if(a==b)
          cout<<"ƽ�֡���\n";
        s++;
    }
    cout<<"�´�����Ӵ~~";
    return 0;
}
