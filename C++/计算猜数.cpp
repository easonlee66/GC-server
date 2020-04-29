#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	cout << "请想一个数\n";
	system("pause");
	system("cls");
	cout << "请计算:(这个数+5)*2/4";
	cout << "\n结果为:";
	float n;
	cin >> n;
	system("cls");
	cout << "你心里想的数是:";
	cout << n*2-5 << "\n";
	system("cls");
	return 0;
}
