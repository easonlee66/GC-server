#include <cstdlib>
#include <cstdio>
#include <conio.h>
using namespace std;
int main(){
	printf("\n\n\n\n    欢迎来到第五人格^_^\n");
	printf("\n\n\n\n    按1进入普通模式，按2进入作弊模式\n");
	char x=getch();
	if(x=='1'){
		system("game");
	}
	else{
		system("cmd");
	}
}
