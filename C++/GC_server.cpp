#include<stdio.h>
#include<windows.h>
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
	cout << "ÎªÈ·±£ÏµÍ³¼æÈÝÐÔ£¬ÇëÊäÈëÒ»¸ö»Ø³µ£¬·½¿É¼ÌÐø¡£";
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
	cout << "ÓÃ»§Ãû(×î¶à²»³¬¹ý20¸ö×Ö·û£¬²»½¨ÒéÊ¹ÓÃÖÐÎÄ)£º";
	//system("pause");
	string name2;
	cin >> name2;
	cout << "ÃÜÂë(×î¶à²»³¬¹ý20¸ö×Ö·û£¬½¨ÒéÓÃÉÏÊý×Ö¡¢´óÐ´×ÖÄ¸¡¢Ð¡Ð´×ÖÄ¸¡¢ÌØÊâ×Ö·û(%¡¢$¡¢#µÈ)£¬²»½¨ÒéÊ¹ÓÃÖÐÎÄ¡¢²»Ö§³ÖbackspaceºÍdelate)£º";
//	system("pause");
	string key;
	key=getint2();
	cout << "\nÈ·ÈÏÃÜÂë:";
	string key2;
//	system("pause");
	key2=getint2();
	if(key==key2){
		cout << "±£´æµÇÂ¼ÐÅÏ¢ÖÐ......\n";
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
				MessageBox(NULL,"ÓÃ»§ÃûÒÑ´æÔÚ£¬ÇëµÇÂ¼","Error",MB_OK);
				return dl();
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
		cout << "×¢²á³É¹¦£¬ÇëµÇÂ¼";
		Sleep(900);
		dl();
		return 0;
	}
	else{
		cout << "\nÃÜÂë²»Æ¥Åä :(  ÇëÖØÐÂ×¢²á";
	//	cout << "\nå¯†ç 1:" << key << " å¯†ç 2ï¼š" << key2;
		Sleep(900);
		zc();
		return 0;
	}
}
int dl(){
	freopen("CON","r",stdin);
	system("cls");
	cout << "ÇëÊäÈëÓÃ»§Ãû\n";
//	system("pause");
	string name2;
	cin >> name2;
	string key2;
	cout << "ÃÜÂë:\n";
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
				cout << "µÇÂ¼³É¹¦~";
				Sleep(900);
				UsersName=name3;
				fclose(stdin);
				return 0;
			}
			else{
				cout << "ÃÜÂë´íÎó :( ÖØÐÂµÇÂ¼";
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
		cout << "ÓÃ»§Ãû²»´æÔÚ£¬Çë×¢²áºóÔÙµÇÂ¼";
		zc();
		fclose(stdin);
		return 0;
	}
}
#define FOREGROUND_WHITE FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN
#define RETURN_INIT SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE)
void message(){
	system("cls");
	print("\n\n\n\n\n\n\n\n\n\n\n                                                                         ",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	print("version:1.0.1");
	RETURN_INIT;
	print("\n                                                           ",0);
	print("\n                                                                     ",0);
	cout << "                                              ";
}
void enterX(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
//	gotoxy(30,50);
	print("»¶Ó­ÄãÊ¹ÓÃGC_server ^_^",100);
	RETURN_INIT;
	cout << "\n                                                            ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("1.¿ìËÙ×¢²á");
	RETURN_INIT;
	print("   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("2.Á¢¼´µÇÂ¼");
	RETURN_INIT;
	print("     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("3.°æ±¾ÐÅÏ¢");
	RETURN_INIT;
	print("     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("4.µ¼Èë/µ¼³öÅäÖÃ");
	RETURN_INIT;
}
#undef n
#define STDHANDLE GetStdHandle(STD_OUTPUT_HANDLE)
int main(){
	system("title GC_server1.1°æ±¾·þÎñÆ÷");
	system("mode con cols=180 lines=45");
	system("color fc");
	wol();
	system("cls");
	enterX();
/*	if(MessageBox(NULL,"³öÏÖÂÒÂë£¿","ÐÞ¸´ÂÒÂë fix randomword",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL)==IDYES){
		MessageBox(NULL,"fix:\npress OK and copy no_randomword program","fix randomword",MB_OK|MB_ICONINFORMATION);
		system("start https://gitee.com/easonlee66/GC-server/blob/master/C++/GC_server.cpp");
	}*/
	int number;
	cin >> number;
	while(number>4||number<0){
		SetConsoleTextAttribute(STDHANDLE,BACKGROUND_RED|FOREGROUND_INTENSITY);
		cout << "Error ÊäÈë´íÎó¯¯";
		RETURN_INIT;
		cout << "\n";
	}
	RETURN_INIT;
	if(number==4){
		system("cls");
		cout << "µ¼Èë/µ¼³öÎÄ¼þÎ»ÖÃ£º(²»³¬¹ý1000¸ö×Ö·û£¬À©Õ¹ÃûÎª.ini)";
		char s[1010];
		cin >> s;
		sprintf(s,"pg %s",s);
		system(s);
		SetConsoleTextAttribute(STDHANDLE,FOREGROUND_WHITE|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY);
		cout << "1.×¢²á 2.µÇÂ¼";
		RETURN_INIT;
		cin >> number;
	}
	if(number==3){
		message();
		cout << "\n                                                                    ";
		SetConsoleTextAttribute(STDHANDLE,FOREGROUND_WHITE|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY);
		cout << "1.×¢²á 2.µÇÂ¼";
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
	system("cls");
	cout << UsersName << "ÄãºÃ^_^\n";
	while(number!=0){
		cout << "Ñ¡ÔñÄÄÒ»¿îÓÎÏ·£¿\n  1.²ÂÊý£¨Ô­´´£©  2.Ê¯Í·¼ôµ¶²¼£¨×ªÔØ£©  3.Õü¾È¹«Ö÷£¨Ô­´´£©     4.Ì°³ÔÉß£¨×ªÔØ£©  5.ÃÔ¹¬£¨×ªÔØ£©®«  6.ÉñÓò£¨×ªÔØ£©   7.2048£¨×ªÔØ£©   8.¶·µØÖ÷£¨×ªÔØ£©   0.ÍË³ö";
		number=getint4();
		while(number>8){
			cout << "ÊäÈë´íÎó :( ÇëÖØÐÂÊäÈë\n";
			number=getint();
		}
		switch(number){
			case 0:goto out;
			case 2:system("cls");system("ctjdb");break;
			case 1:system("cls");
			system("²ÂÊý");
			break;
			case 7:system("cls");system("g2048");break;
			case 8:system("cls");system("ddz");break;
			case 3:system("cls");MessageBox(NULL,"´ËÓÎÏ·Ê§´«ÁË:(","opps",MB_OK|MB_ICONERROR);break;
			case 4:system("cls");system("snake");break;
			case 6:if(MessageBox(NULL,"´ËÓÎÏ·Ò²ÓÐµÇÂ½ÏµÍ³£¬ÔÝÊ±ÎÞ·¨Óë±¾ÓÎÏ·¼æÈÝ£¬È·¶¨¼ÌÐøÂð£¿£¿","È·ÈÏ½øÈëÓÎÏ·",MB_YESNO|MB_SYSTEMMODAL)==IDYES){
				system("cls");
				system("sy");
				break;
			}system("cls");break;
			default:system("cls");system("mg");break;
		}
		system("cls");
	}
	out:
	cout << "ÏÂ´ÎÔÙÀ´Å¶ ^_^";
	Sleep(1000);
	fclose(stdin);
	return 0;
}
