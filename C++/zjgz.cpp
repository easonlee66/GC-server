#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
/*extern
  __attribute__((__format__ (gnu_printf, 2, 0))) __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_svsprintf (string __restrict__ , const char * __restrict__ , va_list) __MINGW_NOTHROW;
int ssprintf(string __stream, const char *__format, ...){
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_svsprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}*/
void print(string a){
	for(int i=0;i<a.length();i++){
		printf("%c",a[i]);
		Sleep(100);
	}
}
struct monster{
	string name,thing;
	int gongji,fangyu,hp,gold_ko,gold_koi,thing_number;
}
strongman={"ɭ�־���","",350,350,500,100,1500,0},big_strongman={"����֮��","����֮��",350*5,350*5,500*5,100*5,1500*5,1},xiyi={"ɭ������","����",100,100,200,30,500,2},whitch={"ɭ��Ů��","������",180,180,350,50,1000,3},bee={"��ԭ�Ʒ�","��",100,100,200,30,500,4},horse={"��ԭҰ��","��Ѫ��",180,180,350,50,1000,5},lion={"��ԭ��ʨ","�����ý�",350,350,500,100,1500,6},shitu={"ʹͽ","",350*7,350*7,500*7,0,0,0},guai;
struct player{
	string name;
	int hp,gongji,fangyu,gold,thing_fang,thing_gong,max_hp,level,exp,max_exp;
}
play={"",100,50,40,500,0,0,100,1,0,100};
bool frees=false;
int plase=0;
int grass=3,bag=2,medicine=2,super_medicine=1,boom=3,dead=2,hoom=1;
int clothes,tie,fang,gold_clothes,arm,very_small,small,big,good;
bool vs_now;
int number;
void choose_things(){
	char data[100];
	sprintf(data,"===================\n1.ֹѪ��%d��   2.���Ȱ�%d��    3.���ϰ�ҩ%d��   4.�������ϰ�ҩ%d��     5.����%d��   6.����%d��    7.����ʽԭ�ӵ�%d��    0.�˳�\n",grass,bag,medicine,super_medicine,boom,dead,hoom);
	printf(data);
	cin >> number;
	switch(number){
		case 1:if(grass==0){
			print("û��ֹѪ����\n");
			break;
		}
		if(play.hp+50>play.max_hp){
			print("hp���࣬����ҪֹѪ��\n");
			break;
		}
		play.hp+=50;
		grass--;
		break;
		case 2:if(bag==0){
			print("û�м��Ȱ���\n");
			break;
		}
		if(play.hp+80>play.max_hp){
			print("hp���࣬����Ҫ���Ȱ�\n");
			break;
		}
		play.hp+=80;
		bag--;
		break;
		case 3:if(medicine==0){
			print("û�����ϰ�ҩ��\n");
			break;
		}
		if(play.hp+100>play.max_hp){
			print("hp���࣬����Ҫ���ϰ�ҩ\n");
			break;
		}
		play.hp+=100;
		medicine--;
		break;
		case 4:if(super_medicine==0){
			print("û�г������ϰ�ҩ��\n");
			break;
		}
		if(play.hp+200>play.max_hp){
			print("hp���࣬����Ҫ�������ϰ�ҩ��\n");
			break;
		}
		play.hp+=200;
		super_medicine--;
		break;
		case 5:if(!vs_now){
			print("��ս��״̬������ʹ������\n");
			break;
		}
		if(boom==0){
			print("û��������\n");
			break;
		}
		print("ʹ�����ף�����hp����100");
		guai.hp-=100;
		boom--;
		print("\n\n");
		cout << guai.name;
		print("�����������hp����");
		cout << guai.gongji/3-play.fangyu;
		play.hp-=guai.gongji/3-play.fangyu;
		cout << "\n";
		break;
		case 6:if(!vs_now){
			print("��ս��״̬������ʹ�ö���\n");
			break;
		}if(dead==0){
			print("û�ж�����\n");
			break;
		}
		print("ʹ�ö��꣬����hp����200\n\n");
		guai.hp-=200;
		cout << guai.name;
		dead--;
		print("�����������hp����");
		cout << guai.gongji/3-play.fangyu;
		play.hp-=guai.gongji/3-play.fangyu;
		cout << "\n";
		break;
		case 7:if(!vs_now){
			print("��ս��״̬������ʹ������ʽԭ�ӵ�\n");
			break;
		}
		if(hoom==0){
			print("û������ʽԭ�ӵ���\n");
			break;
		}
		hoom--;
		print("ʹ������ʽԭ�ӵ�������hp����500\n\n");
		char data[100];
		guai.hp-=500;
		cout << guai.name;
		sprintf(data,"�����������hp������%d",guai.gongji/3-play.fangyu);
		play.hp-=guai.gongji/3-play.fangyu;
		printf(data);
	}
}
void check(){
	char data[200];
	sprintf(data,"\n\n\n\n====================\n������%d+%d   ������%d+%d     hp:%d/%d\n\n�ȼ�%d   ����Ҫ%d��������    ���%d\n",play.gongji,play.thing_gong,play.fangyu,play.thing_fang,play.hp,play.max_hp,play.level,play.max_exp-play.exp,play.gold);
	printf(data);
}
void vs(){
	srand(rand());
	vs_now=true;
	while(play.hp>0&&guai.hp>0){
		print("\n\n\n\n\n\n\n=====================================\n\n\nҪ��ô�죿\n1.����   2.��Ʒ    3.�鿴״̬   4.����\n");
		cin >> number;
		switch(number){
			case 1:cout << play.name;
			print("������������hp����");
			cout << play.gongji+play.thing_gong-guai.fangyu/3;
			guai.hp-=play.gongji+play.thing_gong-guai.fangyu/3;
			print("\n\n");
			cout << guai.name;
			print("���������hp����");
			cout << guai.gongji/3-play.fangyu-play.thing_fang;
			play.hp-=guai.gongji/3-play.fangyu-play.thing_fang;
			cout << "\n";
			break;
			case 2:choose_things();break;
			case 3:check();break;
			case 4:int s=rand()%10;
			srand(rand());
			if(s<4){
				print(play.name);
				print("������~\n");
				return ;
			}
			else{
				print(play.name);
				print("����ʧ�ܣ�\n");
			}
			break;
		}
		print("\n\n\n\n\n");
	}
	if(play.hp==0){
		print(play.name);
		print("ս��������ҵ���");
		cout << guai.gold_koi;
		play.gold-=guai.gold_koi;
		if(play.gold<0){
			play.gold=0;
		}
		play.hp=play.max_hp;
	}
	else{
		if(guai.name=="ʹͽ"){
			print("ս��ʤ�����ȳ���������");
			frees=true;
			return ;
		}
		else{
			print("ս��ʤ����������þ���100�����");
			cout << guai.gold_ko;
			play.exp+=100;
			play.gold+=guai.gold_ko;
			int s=rand()%10;
			print("\n\n\n");
			if(s<4){
				print("�ӵ���ʬ���з���");
				cout << guai.thing;
				switch(guai.thing_number){
					case 0:gold_clothes++;break;
					case 1:arm++;break;
					case 2:tie++;break;
					case 3:fang++;break;
					case 4:small++;break;
					case 5:big++;break;
					case 6:good++;break;
				}
				print("\n\n\n\n");
			}
			while(play.exp>=play.max_exp){
				print(play.name);
				print("��������������+3��������+2��hp����+100\n");
				play.gongji+=3;
				play.fangyu+=2;
				play.max_hp+=100;
				play.exp-=play.max_exp;
				play.max_exp+=100;
				print("\n\n");
			}
			play.hp=play.max_hp;
		}
	}
}
int zbg(int number,int power,string name){
	if(number==0){
		print("û��");
		print(name);
		print("��\n");
		return 0;
	}
	print("������");
	print(name);
	play.thing_gong=power;
	return 0;
	
}
int zbf(int number,int power,string name){
	if(number==0){
		print("û��");
		print(name);
		print("��\n");
		return 0;
	}
	print("������");
	print(name);
	play.thing_fang=power;
	return 0;

}
int drink(int x){
	if(play.gold<x){
		print("Ǯ����������\n");
		return 0;
	}
	if(play.hp+x>play.max_hp){
		print("hp̫�࣬���úȾ�\n");
		return 0;
	}
	play.hp+=x;
	play.gold-=x;
	return 0;
}
int main(int argv,char *argc[]){
	srand(time(0));
	int bar=rand(),hotel=rand(),forest_1=rand(),forest_2=rand(),forest_3=rand(),grass_1=rand(),grass_2=rand(),grass_3=rand();
	print("����һ�����ߵ����磡��������˹�������繫����İ���˰���ˣ���\n\n\nΰ������߰�������������Ӫ�ȹ���������\n\n\n����������֣�100���ַ����ڣ�\n");
	cin >> play.name;
	if(play.name=="EVA���Ż�"){
		print("��ӡ�����EVA���Ż����������ڿ����ؼ������ˣ�����\n\n\nEVA���Ż�����������...�漴,���ߣ�����\n");
		play.fangyu+=10000;
		play.gongji+=10000;
		play.max_hp+=10000;
		play.hp+=10000;
	}
	if(play.name=="seven"||play.name=="eason"||play.name=="carolyn"){
		print("���ȳ���������ʿ���������ڻ����ˣ������漴�����ߣ���������\n");
		play.fangyu+=10000;
		play.gongji+=10000;
		play.max_hp+=10000;
		play.hp+=10000;
	}
	bool say=false;
	while(!frees){
		print("\n\n\n\n===========================================\n\n\n\n\nҪ��ʲô��\n1.�ƶ�  2.��Ʒ   3.�Ի�   4.�鿴״̬  5.װ��  0.�˳�\n");
		cin >> number;
		switch(number){
			case 1:print("\n\n\n\n\n\n================================================\n\n\nҪȥ���\n1.�ư�   2.�õ�    3.ɭ��һ��   4.ɭ�ֶ���   5.ɭ������   6.��ԭһ��   7.��ԭ����   8.��ԭ����\n");
			cin >> number;
			switch(number){
				case 1:plase=bar;break;
				case 2:plase=hotel;
				print("Ҫס����200����ң���������hp����Ŷ\n1.��  0.��");
				cin >> number;
				if(number){
					if(play.gold<200){
						print("��Ҳ���������");
						break;
					}
					play.gold-=200;
					print("�ڶ�����\n\thp����\n\t\t�´�������");
					int s=rand()%10;
					if(s<4){
						print("����ʱ������������������");
						s=rand()%8+1;
						if(s<=3){
							print("ֹѪ��");
							grass++;
						}else if(s<=5){
							print("���Ȱ�");
							bag++;
						}
						else if(s<=7){
							print("���ϰ�ҩ");
							medicine++;
						}
						else{
							print("�������ϰ�ҩ");
							super_medicine++;
						}
						print("һ����");
						s=rand()%6+1;
						if(s<=3){
							print("����");
							boom++;
						}else if(s<=5){
							print("����");
							dead++;
						}
						else{
							print("����ʽԭ�ӵ�");
							hoom++;
						}
						print("һ��\n");
					}
					play.hp=play.max_hp;
					break;
				}
				else{
					print("�´�������\n");
					break;
				}
				case 3:plase=forest_1;
				int s;
				s=rand()%10;
				if(s<7){
					guai=xiyi;
					print("ɭ���������˹�����\n");
					vs();
				}
				else if(s<9){
					guai=whitch;
					print("ɭ��Ů�����˹�������\n");
					vs();
				}
				else{
					print("���ﰲȫ\n");
				}
				break;
				case 4:plase=forest_2;
				s=rand()%10;
				if(s<7){
					guai=whitch;
					print("ɭ��Ů�����˹�������\n");
					vs();
				}
				else if(s<9){
					guai=strongman;
					print("ɭ�־������˹���������\n");
					s=rand()%10;
					if(s<8){
						guai.thing="�ƽ�ʥ��";
						guai.thing_number=0;
					}
					else{
						guai.thing="����֮��";
						guai.thing_number=1;
					}
					vs();
				}
				else{
					print("���ﰲȫ\n");
				}
				break;
				case 5:plase=forest_3;
				s=rand()%10;
				if(s<7){
					guai=strongman;
					print("ɭ�־������˹���������\n");
					s=rand()%10;
					if(s<8){
						guai.thing="�ƽ�ʥ��";
						guai.thing_number=0;
					}
					else{
						guai.thing="����֮��";
						guai.thing_number=1;
					}
					vs();
				}
				else if(s<9){
					guai=big_strongman;
					print(guai.name);
					print("���˹�����������\n");
					vs();
				}
				else{
					print("���ﰲȫ\n");
				}
				break;
				case 6:plase=grass_1;
				s=rand()%10;
				if(s<7){
					guai=bee;
					print("��ԭ�Ʒ����˹�����\n");
					vs();
				}else if(s<9){
					guai=horse;
					print("��ԭҰ�����˹�������\n");
					vs();
				}
				else{
					print("���ﰲȫ\n");
				}
				break;
				case 7:plase=grass_2;
				s=rand()%10;
				if(s<7){
					guai=horse;
					print("��ԭҰ�����˹�������\n");
					vs();
				}else if(s<9){
					guai=lion;
					print("��ԭ��ʨ���˹���������\n");
					vs();
				}
				else{
					print("���ﰲȫ\n");
					vs();
				}
				break;
				case 8:plase=grass_3;
				s=rand()%10;
				if(s<7){
					guai=lion;
					print("��ԭ��ʨ���˹���������\n");
					vs();
				}else if(s<9){
					if(arm==0){
						if(say){
							print("�������ˣ����Ͱɣ������ˣ���ȡ��þ���֮�ۣ�^_^\n");
						}
						else{
							print("�������ˣ�������о���֮�ۣ��Ҿ͸����㹫��������Ŷ��^_^\n");
						}
					}
					else{
						print("�������ˣ������ˣ����Ĳ������������ٺ٣����ϵ��ˡ�����֮����Ҫ�ˣ�������Ҳ������ߣ�����\n\n\n");
						guai=shitu;
						print("ʹͽ���˹�����������\n");
						vs();
					}
				}
				else{
					print("���ﰲȫ\n");
				}
			}
			break;
			case 2:choose_things();break;
			case 3:if(plase==bar){
				print("Ҫ��˭˵����\n1.�췢Ů��    2.�ͽ�����    3.�ư��ϰ�\n");
				cin >> number;
				switch(number){
					case 1:print("�췢Ů�ɣ���̨�Ǳߵ����˺�˧������^_^\n");break;
					case 2:if(clothes==0){
						print("�ͽ����ˣ���Ҫ�ȹ��������õ�������������Ĳ�ԭ�ʹ��ֺ��ն񣬶���Խ��ԽΣ�ա�����ذ�׺Ͳ��£�������а����ġ�\n\n");
						print(play.name);
						print("���룺��λ��������ð���\n");
						clothes++;
						very_small++;
						break;
					}
					else{
						print("�ͽ����ˣ����Ͱɣ������ˣ���Ҫ������Ĵ��ֺͲ�ԭ���ŵ���^_^");
						break;
					}
					case 3:print("�ư��ϰ壺Ҫ�ȵ�ʲô��1.����ͷ25��ң�hp+25    2.xo��50��ң�hp+50      3.��ͷ����100��ң�hp+100    4.�໨��200��ң�hp+200     5.ę́��500��ң�hp+500\n");
					cin >> number;
					switch(number){
						case 1:drink(25);break;
						case 2:drink(50);break;
						case 3:drink(100);break;
						case 4:drink(200);break;
						case 5:drink(500);break;
					}
					break;
				}
				break;
			}
			else{
				print("�������û�˿�������");
				break;
			}
			break;
			case 4:check();break;
			case 5:print("ѡ��Ҫ������װ����\n\n");
			#undef data
			char data[100];
			sprintf(data,"1.ذ��%d��    2.��%d��     3.��Ѫ��%d��     4.�����ý�%d��      \n5.����%d��     6.����%d��     7.������%d��         8.�ƽ�ʥ��%d��\n",very_small,small,big,good,clothes,tie,fang,gold_clothes);
			printf(data);
			cin >> number;
			switch(number){
				case 1: zbg(very_small,30,"ذ��");break;
				case 2: zbg(small,50,"��");break;
				case 3: zbg(big,100,"��Ѫ��");break;
				case 4: zbg(good,200,"�����ý�");break;
				case 5: zbf(clothes,30,"����");break;
				case 6: zbf(tie,50,"����");break;
				case 7: zbf(fang,100,"������");break;
				case 8: zbf(gold_clothes,200,"�ƽ�ʥ��");break;
			}
			break;
			case 0: print("ȷ���˳���Ϸ��\n1.��    0.��");
			cin >> number;
			if(number){
				return 0;
			}
			break;
		}
	}
	system("pause");
	return 0;
}

