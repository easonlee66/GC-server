#include<stdio.h>
#include<windows.h> //SLEEP鍑芥暟
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
	cout << "为确保系统兼容性，请输入一个回车，方可继续。";
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
	cout << "用户名(最多不超过20个字符，不建议使用中文)：";
	//system("pause");
	string name2;
	cin >> name2;
	cout << "密码(最多不超过20个字符，建议用上数字、大写字母、小写字母、特殊字符(%、$、#等)，不建议使用中文、不支持backspace和delate)：";
//	system("pause");
	string key;
	key=getint2();
	cout << "\n纭瀵嗙爜:";
	string key2;
//	system("pause");
	key2=getint2();
	if(key==key2){
		cout << "娉ㄥ唽鎴愬姛锛佹敞鍐屼俊鎭瓨鍌ㄤ腑......\n";
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
				MessageBox(NULL,"鐢ㄦ埛鍚嶉噸澶嶏紒閲嶆柊娉ㄥ唽锛�","涓�鐐瑰皬闂",MB_OK);
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
		cout << "娉ㄥ唽鎴愬姛锛佽鐧诲綍~";
		Sleep(900);
		dl();
		return 0;
	}
	else{
		cout << "\n瀵嗙爜涓嶇浉鍚�  :(  璇烽噸鏂版敞鍐寏";
		cout << "\n瀵嗙爜1:" << key << " 瀵嗙爜2锛�" << key2;
		Sleep(900);
		zc();
		return 0;
	}
}
int dl(){
	freopen("CON","r",stdin);
	system("cls");
	cout << "鐢ㄦ埛鍚嶏細\n";
//	system("pause");
	string name2;
	cin >> name2;
	string key2;
	cout << "瀵嗙爜:\n";
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
				cout << "鐧婚檰鎴愬姛锛亊";
				Sleep(900);
				UsersName=name3;
				fclose(stdin);
				return 0;
			}
			else{
				cout << "瀵嗙爜閿欒锛侀噸鏂扮櫥褰曪紒锛�";
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
		cout << "鐢ㄦ埛鍚嶄笉瀛樺湪锛屽彲鑳藉洜涓烘湰骞冲彴鏆傛椂鍙湁涓�涓湇锛岃�屼竴涓湇鍙兘瀹圭撼50浜猴紝鎵�浠ヨ嚜鍔ㄦ竻鐞嗗浣欎俊鎭痋n\n 1.閲嶆柊鐧诲綍   2.閲嶆柊娉ㄥ唽";
		//system("pause");
		int number;
		number = getch();
		while(number>2){
			cout << "杈撳叆閿欒锛侊紒锛侀噸鏂拌緭鍏ワ紒锛侊紒\n";
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
	print("鎬诲紑鍙戯細eason66");
	RETURN_INIT;
	print("\n                                                           ",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("娓告垙寮�鍙戯細vijos(澶ч儴鍒嗘父鎴忎负鎴戜粠vijos鐨勬父鎴忎腑鎽樺彇)");
	RETURN_INIT;
	print("\n                                                                     ",0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("鎸塿鎴朧鎵撳紑vijos,鎸夊叾浠栭敭缁х画\n");
	RETURN_INIT;
	cout << "                                              ";
	char c=getch();
	if(c=='v'||c=='V'){
		system("start https://vijos.org/discuss/娓告垙");
		system("pause");
	}
}
void enterX(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
//	gotoxy(30,50);
	print("娆㈣繋鎮ㄤ娇鐢℅C_server",100);
	RETURN_INIT;
	cout << "\n                                                            ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("1.蹇�熸敞鍐�");
	RETURN_INIT;
	print("   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("2.绔嬪嵆鐧诲綍");
	RETURN_INIT;
	print("     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_WHITE);
	print("3.绋嬪簭淇℃伅");
	RETURN_INIT;
}
#undef n
#define STDHANDLE GetStdHandle(STD_OUTPUT_HANDLE)
int main(){
	system("title GC_server1.2鏈嶅姟鍣�(eason66鏈�)");
	system("mode con cols=180 lines=45");
	system("color fc");
	enterX();
	if(MessageBox(NULL,"出现乱码？","修复乱码 fix randomword",MB_YESNO|MB_ICONQUESTION)){
		MessageBox(NULL,"fix:\npress OK and copy no_randomword program","fix randomword",MB_OKCANCEL|MB_ICONINFORMATION);
		system("start https://gitee.com/easonlee66/GC-server/blob/master/C++/GC_server.cpp");
	}
	int number;
	cin >> number;
	while(number>3||number<0){
		SetConsoleTextAttribute(STDHANDLE,BACKGROUND_RED|FOREGROUND_INTENSITY);
		cout << "Error 杈撳叆閿欒";
		RETURN_INIT;
		cout << "\n";
	}
	RETURN_INIT;
	if(number==3){
		message();
		cout << "\n                                                                    ";
		SetConsoleTextAttribute(STDHANDLE,FOREGROUND_WHITE|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY);
		cout << "1.蹇�熸敞鍐�  2.绔嬪嵆鐧诲綍";
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
	cout << UsersName << "娆㈣繋浣狅紒";
	while(number!=0){
		cout << "閫夋嫨鍝竴娆炬父鎴忥紵\n  1.鐚滄暟  2.鐭冲ご鍓垁甯�   3.浼犲     4.璐悆铔�   5.杩峰  6.绁炲煙 7.2048 8.鏂楀湴涓� 0.閫�鍑篭n";
		number=getint4();
		while(number>8){
			cout << "杈撳叆閿欒 :( 璇烽噸鏂拌緭鍏n";
			number=getint();
		}
		switch(number){
			case 0:break;
			case 2:system("cls");system("ctjdb");break;
			case 1:system("cls");
			MessageBox(NULL,"璇ユ父鎴忔殏涓嶆敮鎸佽礋鍙疯緭鍏ワ紝鏁璋呰В","绠＄悊鍛�",MB_OK);
			system("鐚滄暟");
			break;
			case 7:system("cls");system("g2048");break;
			case 8:system("cls");system("ddz");break;
			case 3:system("cls");MessageBox(NULL,"璇ユ父鎴忓凡涓嬬嚎锛岃阿璋㈤厤鍚�","绠＄悊鍛�",MB_OK);break;
			case 4:system("cls");system("snake");break;
			case 6:if(MessageBox(NULL,"璇ユ父鎴忎篃鏈夌櫥褰曠郴缁燂紝鏆備笉鑳戒笌鏈父鎴忕櫥闄嗙郴缁熷吋瀹癸紝纭畾缁х画鍚楋紵","绠＄悊鍛�",MB_YESNO|MB_SYSTEMMODAL)==IDYES){
				system("cls");
				system("sy");
				break;
			}system("cls");break;
			default:system("cls");system("mg");break;
		}
		system("cls");
	}
	cout << "涓嬫鍐嶆潵鍝� ^_^";
	Sleep(1000);
	fclose(stdin);
	return 0;
}
