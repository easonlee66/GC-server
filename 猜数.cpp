#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
void print(string index,int speed=100){
	for(int i=0;i<index.length();i++){
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
			system("���Ӳ���");
		}
		else{
			system("�������");
		}
	}
	else{
		system("cls");
		system("���˲���");
	}
	cout << "����һ����(y/n)";
	char x=getch();
	if(x=='y'){
		system("cls");
		system("����");
	}
	return 0;
}
