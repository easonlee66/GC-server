#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	cout << "几人猜数？";
	int n;
	cin >> n;
	int r,l=0;
	cout << "0~几？";
	cin >> r;
	system("cls");
	int p=rand()%(r+1);
	cout << "开始！\n";
	int now_player=1;
	while(1){
		cout << "===================================\n";
		cout << l << "~" << r << " " << now_player << "号猜（-1 电脑帮猜）";
		int index;
		cin >> index;
		if(index==-1){
			index=rand()%(r-l+1)+l;
			cout << "帮" << now_player << "号猜成" << index << "\n";
		}
		if(index>r||index<l){
			cout << "浪费机会！\n";
			continue;
		}
		if(index>p){
			cout << "大了\n";
			r=index;
			continue;
		}
		if(index<p){
			cout << "小了\n";
			l=index;
			continue;
		}
		cout << now_player << "号赢了！\n";
		break;
	}
	system("pause");
	return 0;
}
