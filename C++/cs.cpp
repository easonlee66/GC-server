#include <iostream>
#include <cstdlib>
#include "sync.h"
#ifdef _IS_WINDOWS__
#include <windows.h>
#include <conio.h>
#endif
using namespace std;
void print(string index,int speed=100){
	for(int i=0;i<(int)index.length();i++){
		cout << index[i];
		Sleep(speed);
	}
}
int main(){
	int index;
	cout << "\n\n\n\n\n\n\n\n\n\n                        ";
	print("����");
	cout << "\n                          ";
	print("by eason66");
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n                           ";
	print("1.���˲���(���������Բ�)     2.���˲���(�����������ǲ�)",60);
	cout << "\n";
	cin >> index;
	system("cls");
	if(index==1){
		cout << "1.���Ӳ���       2.�������";
		cin >> index;
		system("cls");
		if(index==1){
			system("gzcs");
		}
		else{
			system("jscs");
		}
	}
	else{
		system("cls");
		system("drcs");
	}
	cout << "����һ����(y/n)";
	char x=getch();
	if(x=='y'){
		system("cls");
		system("����");
	}
	return 0;
}
