#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	cout << "���˲�����";
	int n;
	cin >> n;
	int r,l=0;
	cout << "0~����";
	cin >> r;
	system("cls");
	int p=rand()%(r+1);
	cout << "��ʼ��\n";
	int now_player=1;
	while(1){
		cout << "===================================\n";
		cout << l << "~" << r << " " << now_player << "�Ų£�-1 ���԰�£�";
		int index;
		cin >> index;
		if(index==-1){
			index=rand()%(r-l+1)+l;
			cout << "��" << now_player << "�Ų³�" << index << "\n";
		}
		if(index>r||index<l){
			cout << "�˷ѻ��ᣡ\n";
			continue;
		}
		if(index>p){
			cout << "����\n";
			r=index;
			continue;
		}
		if(index<p){
			cout << "С��\n";
			l=index;
			continue;
		}
		cout << now_player << "��Ӯ�ˣ�\n";
		break;
	}
	system("pause");
	return 0;
}
