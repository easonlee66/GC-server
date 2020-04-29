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
	print("猜数");
	cout << "\n                          ";
	print("by eason66");
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n                           ";
	print("1.单人猜数(你想数电脑猜)     2.多人猜数(电脑想数你们猜)",60);
	cout << "\n";
	cin >> index;
	system("cls");
	if(index==1){
		cout << "1.格子猜数       2.计算猜数";
		cin >> index;
		system("cls");
		if(index==1){
			system("格子猜数");
		}
		else{
			system("计算猜数");
		}
	}
	else{
		system("cls");
		system("多人猜数");
	}
	cout << "再来一次吗？(y/n)";
	char x=getch();
	if(x=='y'){
		system("cls");
		system("猜数");
	}
	return 0;
}
