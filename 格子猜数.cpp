#include <iostream>
#include <cstdlib>
using namespace std;
const int x1[4]={1,3,5,7},x10[4]={2,3,6,7},x100[4]={4,5,6,7};
int main(){
	cout << "����һ��<=7����\n";
	system("pause");
	system("cls");
	cout << x1[0] << "   " << x1[1] << "  " << x1[2] << "   " << x1[3];
	cout << "\n�����������Щ������ֹ���1.�� 0.��";
	bool x;
	cin >> x;
	int index=0;
	if(x){
		index++;
	}
	system("cls");
	cout << x10[0] << "   " << x10[1] << "  " << x10[2] << "   " << x10[3];
	cout << "\n�����������Щ������ֹ���1.�� 0.��";
	cin >> x;
	if(x){
		index+=2;
	}
	system("cls");
	cout << x100[0] << "   " << x100[1] << "   " << x100[2] << "   " << x100[3];
	cout << "\n�����������Щ������ֹ���1.�� 0.��";
	cin >> x;
	if(x){
		index+=4;
	}
	system("cls");
	cout << "�������������:" << index << "\n";
	system("pause");
	return 0;
}
