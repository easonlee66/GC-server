#include<stdio.h>
#include<windows.h> //SLEEP函数
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include <queue>
#include <string>
using namespace std;
#define next 32
string UsersName;
int getint4(int *index=NULL){
	char c;
	int a;
	while((c=getch())!=13){
		cout << c-'0';
		a*=10;
		a+=c-'0';
	}
	cout << "\n";
	return a;
}
#define getint getint4
void print(string a,int speed=100){
	for(int i=0;i<a.length();i++){
		printf("%c",a[i]);
		Sleep(speed);
	}
}
struct Users{
	string key;
	string name;
	Users(string key="\0",string name="\0"):key(key),name(name) {}
};
queue <Users> name;
bool C_WINDOWS_=false;
char enter;
void wol(){
	cout << "Ϊȷ��ϵͳ�����ԣ�������һ���س������ɼ�����";
	char c=getch();
	if(c=='\n'){
		enter='\n';
	}
	else{
		enter='\r';
	}
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
int zc(){
	freopen("CON","r",stdin);
	system("cls");
	cout << "�û���(��಻����20���ַ���������ʹ������)��";
	//system("pause");
	string name2;
	cin >> name2;
	cout << "����(��಻����20���ַ��������������֡���д��ĸ��Сд��ĸ�������ַ�(%��$��#��)��������ʹ�����ġ���֧��backspace��delate)��";
//	system("pause");
	string key;
	key=getint2();
	cout << "\nȷ������:";
	string key2;
//	system("pause");
	key2=getint2();
	if(key==key2){
		cout << "�����¼��Ϣ��......\n";
		fclose(stdin);
		freopen("GC_servy.ini","a",stdin);
		fclose(stdin);
		freopen("GC_servy.ini","r",stdin);
		int n2;
		cin >> n2;
		for(int i=0;i<n2;i++){
			Users a;
			//fscanf(messagein,"%s %s",a.name.c_str(),a.key.c_str());
			/**/cin >> a.name >> a.key;
			if(a.name==name2){
				MessageBox(NULL,"�û����Ѵ��ڣ����¼","Error",MB_OK);
				return zc();
			}
			name.push(a);
		}
		name.push(Users(key,name2));
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
		cout << "ע��ɹ������¼";
		Sleep(900);
		dl();
		return 0;
	}
	else{
		cout << "\n���벻ƥ�� :(  ������ע��";
	//	cout << "\n密码1:" << key << " 密码2：" << key2;
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
		cin >> name3 >> key;
		if(name3==name2){
			if(key2==key){
				cout << "登陆成功！~";
				Sleep(900);
				UsersName=name3;
				fclose(stdin);
				return 0;
			}
			else{
				cout << "密码错误！重新登录！！";
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
		cout << "用户名不存在，可能因为本平台暂时只有一个服，而一个服只能容纳50人，所以自动清理多余信息\n\n 1.重新登录   2.重新注册";
		//system("pause");
		int number;
		number = getch();
		while(number>2){
			cout << "输入错误！！！重新输入！！！\n";
		//	system("pause");
			number=getch();
		}
		if(number==1){
			dl();
			fclose(stdin);
			return 0;
		}
		else{
			zc();
			fclose(stdin);
			return 0;
		}
	}
}
#define FOREGROUND_WHITE FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN
#define RETURN_INIT SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE)
void message(){
	system("cls");
	print("\n\n\n\n\n\n\n\n\n\n\n                                                                         ",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	print("version:1.1");
	RETURN_INIT;
	print("\n                                                           ",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("ע������һ�������");
	RETURN_INIT;
	print("\n                                                                     ",0);
	cout << "                                              ";
}
void enterX(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
//	gotoxy(30,50);
	print("欢迎您使用GC_server",100);
	RETURN_INIT;
	cout << "\n                                                            ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("1.快速注册");
	RETURN_INIT;
	print("   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("2.立即登录");
	RETURN_INIT;
	print("     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("3.程序信息");
	RETURN_INIT;
}
#undef n
#define STDHANDLE GetStdHandle(STD_OUTPUT_HANDLE)
int main(){
	system("title GC_server1.1�汾������");
	system("mode con cols=180 lines=45");
	system("color fc");
	enterX();
	wol();
	if(MessageBox(NULL,"�������룿","�޸����� fix randomword",MB_YESNO|MB_ICONQUESTION)){
		MessageBox(NULL,"fix:\npress OK and copy no_randomword program","fix randomword",MB_OKCANCEL|MB_ICONINFORMATION);
		system("start https://gitee.com/easonlee66/GC-server/blob/master/C++/GC_server.cpp");
	}
	int number;
	cin >> number;
	while(number>3||number<0){
		SetConsoleTextAttribute(STDHANDLE,BACKGROUND_RED|FOREGROUND_INTENSITY);
		cout << "Error �������";
		RETURN_INIT;
		cout << "\n";
	}
	RETURN_INIT;
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
		return 0;
	}
	freopen("CON","r",stdin);
	system("cls");
	cout << UsersName << "���^_^";
	while(number!=0){
		cout << "ѡ����һ����Ϸ��\n  1.������ԭ����  2.ʯͷ��������ת�أ�  3.���ȹ�����ԭ����     4.̰���ߣ�ת�أ�  5.�Թ���ת�أ���  6.����ת�أ�   7.2048��ת�أ�   8.斗地主 0.退出\n";
		number=getint4();
		while(number>8){
			cout << "������� :( ����������\n";
			number=getint();
		}
		switch(number){
			case 0:goto out;
			case 2:system("cls");system("ctjdb");break;
			case 1:system("cls");
			system("����");
			break;
			case 7:system("cls");system("g2048");break;
			case 8:system("cls");system("ddz");break;
			case 3:system("cls");MessageBox(NULL,"����Ϸʧ����:(","opps",MB_OK|MB_ICONERROR);break;
			case 4:system("cls");system("snake");break;
			case 6:if(MessageBox(NULL,"����ϷҲ�е�½ϵͳ����ʱ�޷��뱾��Ϸ���ݣ�ȷ�������𣿣�","ȷ�Ͻ�����Ϸ",MB_YESNO|MB_SYSTEMMODAL)==IDYES){
				system("cls");
				system("sy");
				break;
			}system("cls");break;
			default:system("cls");system("mg");break;
		}
		system("cls");
	}
	out:
	cout << "�´�����Ŷ ^_^";
	Sleep(1000);
	fclose(stdin);
	return 0;
}
