#include<stdio.h>
#include "sync.h"
#ifdef _IS_WINDOWS__
#include<windows.h>
#include<conio.h>
#endif
#include<iostream>
#include <stdlib.h>
#include <queue>
#include <string>
//һ���ͷ�ļ�
//#define DEBUG//�Ƿ�Ϊ�ڲ�����ģʽ 
using namespace std;
char UsersName[100];
int getint(int *index=NULL){
	char c;
	int a;
	while((c=get())!=13){
		cout << c-'0';
		a*=10;
		a+=c-'0';
	}
	cout << "\n";
	return a;
}
void print(string a,int speed=100){
	for(int i=0;i<a.length();i++){
		printf("%c",a[i]);
		#ifdef _IS_WINDOWS__
		Sleep(speed);
		#endif
	}
}
struct Users{
	string key;
	string name;
	int level; 
	Users(string key="\0",string name="\0",int level=-1):key(key),name(name),level(level) {}
};
queue <Users> name;
bool C_WINDOWS_=false;
char enter;
void wol(){
    #ifdef _IS_WINDOWS__
	enter='\r';
    #else
    enter='\n';
    #endif
}
string getint2(){
	char c;
	string a;
	while((c=getch())!=enter){
		cout << "*";
		a.push_back(c);
	}
	return a;
}
int dl();
string UserLevel;
int zc(){
	freopen("CON","r",stdin);
	system("cls");
	cout << "�û���(��಻����20���ַ���������ʹ�����ģ�����Ϊzjn)��";
	//system("pause");
	string name2;
	cin >> name2;
	if(name2=="zjn"){
		MessageBox(NULL,"�û�������Ϊzjn","error",MB_OK);
		zc();
		return 0;
	}
	cout << "����(��಻����20���ַ��������������֡���д��ĸ��Сд��ĸ�������ַ�(%��$��#��)��������ʹ�����ġ���֧��backspace��delate)��";
//	system("pause");
	string key;
	key=getint2();
	cout << "\nȷ������:";
	string key2;
//	system("pause");
	key2=getint2();
	if(key==key2){
		cout << "\n�����¼��Ϣ��......\n";
		fclose(stdin);
		freopen("GC_servy.ini","a",stdin);
		fclose(stdin);
		freopen("GC_servy.ini","r",stdin);
		int n2;
		cin >> n2;
		for(int i=0;i<n2;i++){
			Users a;
			//fscanf(messagein,"%s %s",a.name.c_str(),a.key.c_str());
			/**/cin >> a.name >> a.key >> a.level;
			if(a.name==name2){
				MessageBox(NULL,"�û����Ѵ��ڣ����¼","Error",MB_OK);
				return dl();
			}
			name.push(a);
		}
		name.push(Users(key,name2,-1));
		n2++;
		if(n2==51){
			name.pop();
			n2--;
		}
		fclose(stdin);
		freopen("GC_servy.ini","w",stdout);
		cout << n2;
		char namechar[100],keychar[100];
		for(int i=0;i<name.size();i++){
		/**/	cout << name.front().name << " " << name.front().key << "\n";
		//	fprintf(messagein,"%s %s",name.front().name.c_str(),name.front().key.c_str());
			name.pop();
		}
		fclose(stdout);
		freopen("CON","w",stdout);
		cout << "ע��ɹ������¼\n";
		Sleep(900);
		dl();
		return 0;
	}
	else{
		cout << "\n���벻ƥ�� :(  ������ע��\n";
	//	cout << "\n密码1:" << key << " 密码2�? << key2;
		Sleep(900);
		zc();
		return 0;
	}
}
int dl(){
	freopen("CON","r",stdin);
	system("cls");
	cout << "�������û���\n";
//	system("pause");
	string name2;
	cin >> name2;
	string key2;
	cout << "����:\n";
//	system("pause");
	key2=getint2();
	cout << "\n";
	fclose(stdin);
	freopen("GC_servy.ini","a",stdin);
	fclose(stdin);
	freopen("GC_servy.ini","r",stdin);
	int n2;
	cin >> n2;
	string key;
	char name3[20];
	int i;
	for(i=0;i<n2;i++){
		//cin >> name3 >> key;
		int level;
		cin >> name3 >> key >> level;
		if(name3==name2){
			if(key2==key){
				cout << "��¼�ɹ�~";
				Sleep(900);
				switch(level){
					case -1:UserLevel="����ʽ�û�";break;
					case 0:UserLevel="��ѻ�Ա";break;
					case 1:UserLevel="1����Ա";break;
				}
				UsersName=name3;
				fclose(stdin);
				return 0;
			}
			else{
				cout << "������� :( ���µ�¼";
				#ifdef DEBUG
				cout << "Ӧ���룺" << key << "ʵ���룺" << key2;
				#endif
				Sleep(900);
				dl();
				fclose(stdin);
				return 0;
			}
		}
	}
	fclose(stdin);
	freopen("CON","r",stdin);
	if(i==n2-1){
		cout << "�û��������ڣ���ע����ٵ�¼";
		zc();
		fclose(stdin);
		return 0;
	}
}
#ifdef _IS_WINDOWS__
#define FOREGROUND_WHITE FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN
#define RETURN_INIT SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE)
#endif
void message(){
	system("cls");
	print("\n\n\n\n\n\n\n\n\n\n\n                                                                         ",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	print("version:1.0.2 IN ������");
}
void enterX(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                           ";
	print("��ӭ��ʹ��GC_server ^_^",100);
	RETURN_INIT;
	cout << "\n                                                            ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("1.����ע��");
	RETURN_INIT;
	print("   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("2.������¼");
	RETURN_INIT;
	print("     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("3.�汾��Ϣ");
	RETURN_INIT;
	print("     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("4.����/��������");
	RETURN_INIT;
}
#undef n
#ifdef _IS_WINDOWS__
#define STDHANDLE GetStdHandle(STD_OUTPUT_HANDLE)
#endif
bool Ause(string gamename){
	system("cls");
	cout << "�Ƿ�����ע����Ϣ��Ȩ��" << gamename << "��\n1. �� 2.��\nע���������ʹ�����ף�������2";
	return (get()-'0')==1;
}
int main(){
	system("title GC_server1.1�汾������");
	system("mode con cols=180 lines=45");
	system("color fc");
	wol();
	system("cls");
	enterX();
/*	if(MessageBox(NULL,"�������룿","�޸����� fix randomword",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL)==IDYES){
		MessageBox(NULL,"fix:\npress OK and copy no_randomword program","fix randomword",MB_OK|MB_ICONINFORMATION);
		system("start https://gitee.com/easonlee66/GC-server/blob/master/C++/GC_server.cpp");
	}*/
	int number;
	in:
	number=getch()-'0';
	while(number>4||number<0){
		SetConsoleTextAttribute(STDHANDLE,BACKGROUND_RED|FOREGROUND_INTENSITY);
		cout << "Error �������";
		RETURN_INIT;
		cout << "\n";
	}
	RETURN_INIT;
	if(number==4){
		system("cls");
		MessageBox(NULL,"���ܿ����С���","GC-server",MB_OK);
		goto in;
	}
	if(number==3){
		message();
		cout << "\n                                                                    ";
		SetConsoleTextAttribute(STDHANDLE,FOREGROUND_WHITE|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY);
		cout << "1.ע�� 2.��¼";
		RETURN_INIT;
		cin >> number;
	}
	if(number==1){
		zc();
	}
	else{
		dl();
	}
	freopen("CON","r",stdin);
#ifdef _IS_WINDOWS__
	system("cls");
#endif
	cout<< "�𾴵�" << UserLevel << " " << UsersName << "���^_^\n";
	while(number!=0){
		cout << "ѡ����һ����Ϸ��\n  1.������ԭ����  2.ʯͷ��������ת�أ�  3.���ȹ�����ԭ����     4.̰���ߣ�ת�أ�  5.�Թ���ת�أ���  6.����ת�أ�   7.2048��ת�أ�   8.��������ת�أ�   " << ((UsersLevel=="����ʽ�û�")?"9.�����������Գ�Ϊ��ʽ�û�   10.�������ʹ����Գ�Ϊ��ʽ�û�  11.���븨�����Գ�Ϊ֤���û�":"") << "  0.�˳�";
		number=getint();
		while(number>8&&UserLevel!="����ʽ�û�"||number>11&&UserLevel=="����ʽ�û�"){
			cout << "������� :( ����������\n";
			number=getint();
		}
		switch(number){
			case 0:goto out;
			case 2:system("cls");system("ctjdb");break;
			case 1:system("cls");
			if(Ause("���ȹ�����Ϸ")){
				char x[200];
				sprintf(x,"zjgz %s",UsersName);
				system(x);
			}
			else{
				system("zjgz zjn");
			}
			system("cs");
			break;
			case 7:system("cls");system("g2048");break;
			case 8:system("cls");system("ddz");break;
			case 3:system("cls");system("zjgz");break;
			case 4:system("cls");system("snake");break;
			case 6:if(MessageBox(NULL,"����ϷҲ�е�½ϵͳ����ʱ�޷��뱾��Ϸ���ݣ�ȷ�������𣿣�","ȷ�Ͻ�����Ϸ",MB_YESNO|MB_SYSTEMMODAL)==IDYES){
				system("cls");
				system("sy");
				break;
			}system("cls");break;
			case 5:system("cls");system("mg");break;
		}
		system("cls");
	}
	out:
	cout << "�´�����Ŷ ^_^";
	Sleep(1000);
	fclose(stdin);
	return 0;
}
