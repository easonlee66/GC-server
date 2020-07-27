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
strongman={"森林巨人","",350,350,500,100,1500,0},big_strongman={"巨人之王","巨人之臂",350*5,350*5,500*5,100*5,1500*5,1},xiyi={"森林蜥蜴","铁甲",100,100,200,30,500,2},whitch={"森林女巫","防弹衣",180,180,350,50,1000,3},bee={"草原黄蜂","剑",100,100,200,30,500,4},horse={"草原野马","碧血剑",180,180,350,50,1000,5},lion={"草原雄狮","绝世好剑",350,350,500,100,1500,6},shitu={"使徒","",350*7,350*7,500*7,0,0,0},guai;
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
	sprintf(data,"===================\n1.止血草%d个   2.急救包%d个    3.云南白药%d个   4.超级云南白药%d个     5.手雷%d个   6.毒标%d个    7.手抛式原子弹%d个    0.退出\n",grass,bag,medicine,super_medicine,boom,dead,hoom);
	printf(data);
	cin >> number;
	switch(number){
		case 1:if(grass==0){
			print("没有止血草了\n");
			break;
		}
		if(play.hp+50>play.max_hp){
			print("hp过多，不需要止血草\n");
			break;
		}
		play.hp+=50;
		grass--;
		break;
		case 2:if(bag==0){
			print("没有急救包了\n");
			break;
		}
		if(play.hp+80>play.max_hp){
			print("hp过多，不需要急救包\n");
			break;
		}
		play.hp+=80;
		bag--;
		break;
		case 3:if(medicine==0){
			print("没有云南白药了\n");
			break;
		}
		if(play.hp+100>play.max_hp){
			print("hp过多，不需要云南白药\n");
			break;
		}
		play.hp+=100;
		medicine--;
		break;
		case 4:if(super_medicine==0){
			print("没有超级云南白药了\n");
			break;
		}
		if(play.hp+200>play.max_hp){
			print("hp过多，不需要超级云南白药了\n");
			break;
		}
		play.hp+=200;
		super_medicine--;
		break;
		case 5:if(!vs_now){
			print("非战斗状态，不能使用手雷\n");
			break;
		}
		if(boom==0){
			print("没有手雷了\n");
			break;
		}
		print("使用手雷，敌人hp减少100");
		guai.hp-=100;
		boom--;
		print("\n\n");
		cout << guai.name;
		print("反击！！你的hp减少");
		cout << guai.gongji/3-play.fangyu;
		play.hp-=guai.gongji/3-play.fangyu;
		cout << "\n";
		break;
		case 6:if(!vs_now){
			print("非战斗状态，不能使用毒标\n");
			break;
		}if(dead==0){
			print("没有毒标了\n");
			break;
		}
		print("使用毒标，敌人hp减少200\n\n");
		guai.hp-=200;
		cout << guai.name;
		dead--;
		print("反击！！你的hp减少");
		cout << guai.gongji/3-play.fangyu;
		play.hp-=guai.gongji/3-play.fangyu;
		cout << "\n";
		break;
		case 7:if(!vs_now){
			print("非战斗状态，不能使用手抛式原子弹\n");
			break;
		}
		if(hoom==0){
			print("没有手抛式原子弹了\n");
			break;
		}
		hoom--;
		print("使用手抛式原子弹，敌人hp减少500\n\n");
		char data[100];
		guai.hp-=500;
		cout << guai.name;
		sprintf(data,"反击！！你的hp减少了%d",guai.gongji/3-play.fangyu);
		play.hp-=guai.gongji/3-play.fangyu;
		printf(data);
	}
}
void check(){
	char data[200];
	sprintf(data,"\n\n\n\n====================\n攻击力%d+%d   防御力%d+%d     hp:%d/%d\n\n等级%d   还需要%d经验升级    金币%d\n",play.gongji,play.thing_gong,play.fangyu,play.thing_fang,play.hp,play.max_hp,play.level,play.max_exp-play.exp,play.gold);
	printf(data);
}
void vs(){
	srand(rand());
	vs_now=true;
	while(play.hp>0&&guai.hp>0){
		print("\n\n\n\n\n\n\n=====================================\n\n\n要怎么办？\n1.攻击   2.物品    3.查看状态   4.逃跑\n");
		cin >> number;
		switch(number){
			case 1:cout << play.name;
			print("攻击！！敌人hp减少");
			cout << play.gongji+play.thing_gong-guai.fangyu/3;
			guai.hp-=play.gongji+play.thing_gong-guai.fangyu/3;
			print("\n\n");
			cout << guai.name;
			print("反击！你的hp减少");
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
				print("逃跑了~\n");
				return ;
			}
			else{
				print(play.name);
				print("逃跑失败！\n");
			}
			break;
		}
		print("\n\n\n\n\n");
	}
	if(play.hp==0){
		print(play.name);
		print("战死！！金币掉落");
		cout << guai.gold_koi;
		play.gold-=guai.gold_koi;
		if(play.gold<0){
			play.gold=0;
		}
		play.hp=play.max_hp;
	}
	else{
		if(guai.name=="使徒"){
			print("战斗胜利，救出公主！！");
			frees=true;
			return ;
		}
		else{
			print("战斗胜利！！！获得经验100，金币");
			cout << guai.gold_ko;
			play.exp+=100;
			play.gold+=guai.gold_ko;
			int s=rand()%10;
			print("\n\n\n");
			if(s<4){
				print("从敌人尸体中发现");
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
				print("升级！！攻击力+3，防御力+2，hp上限+100\n");
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
		print("没有");
		print(name);
		print("了\n");
		return 0;
	}
	print("拿起了");
	print(name);
	play.thing_gong=power;
	return 0;
	
}
int zbf(int number,int power,string name){
	if(number==0){
		print("没有");
		print(name);
		print("了\n");
		return 0;
	}
	print("穿上了");
	print(name);
	play.thing_fang=power;
	return 0;

}
int drink(int x){
	if(play.gold<x){
		print("钱不够！！！\n");
		return 0;
	}
	if(play.hp+x>play.max_hp){
		print("hp太多，不用喝酒\n");
		return 0;
	}
	play.hp+=x;
	play.gold-=x;
	return 0;
}
int main(int argv,char *argc[]){
	srand(time(0));
	int bar=rand(),hotel=rand(),forest_1=rand(),forest_2=rand(),forest_3=rand(),grass_1=rand(),grass_2=rand(),grass_3=rand();
	print("这是一个勇者的世界！！雅丽萨斯国的罗茜公主被陌生人绑架了！！\n\n\n伟大的勇者啊，拿起武器，营救公主！！！\n\n\n输入你的名字（100个字符以内）\n");
	cin >> play.name;
	if(play.name=="EVA初号机"){
		print("封印多年的EVA初号机啊，你终于可以重见天日了！！！\n\n\nEVA初号机，重新启动...随即,暴走！！！\n");
		play.fangyu+=10000;
		play.gongji+=10000;
		play.max_hp+=10000;
		play.hp+=10000;
	}
	if(play.name=="seven"||play.name=="eason"||play.name=="carolyn"){
		print("曾救出公主的勇士啊，你终于回来了！！！随即，暴走！！！！！\n");
		play.fangyu+=10000;
		play.gongji+=10000;
		play.max_hp+=10000;
		play.hp+=10000;
	}
	bool say=false;
	while(!frees){
		print("\n\n\n\n===========================================\n\n\n\n\n要做什么？\n1.移动  2.物品   3.对话   4.查看状态  5.装备  0.退出\n");
		cin >> number;
		switch(number){
			case 1:print("\n\n\n\n\n\n================================================\n\n\n要去哪里？\n1.酒吧   2.旅店    3.森林一层   4.森林二层   5.森林三层   6.草原一层   7.草原二层   8.草原三层\n");
			cin >> number;
			switch(number){
				case 1:plase=bar;break;
				case 2:plase=hotel;
				print("要住店吗？200个金币，可以让你hp变满哦\n1.是  0.否");
				cin >> number;
				if(number){
					if(play.gold<200){
						print("金币不够！！！");
						break;
					}
					play.gold-=200;
					print("第二天了\n\thp满了\n\t\t下次再来！");
					int s=rand()%10;
					if(s<4){
						print("临走时发现其他客人遗留的");
						s=rand()%8+1;
						if(s<=3){
							print("止血草");
							grass++;
						}else if(s<=5){
							print("急救包");
							bag++;
						}
						else if(s<=7){
							print("云南白药");
							medicine++;
						}
						else{
							print("超级云南白药");
							super_medicine++;
						}
						print("一个和");
						s=rand()%6+1;
						if(s<=3){
							print("手雷");
							boom++;
						}else if(s<=5){
							print("毒标");
							dead++;
						}
						else{
							print("手抛式原子弹");
							hoom++;
						}
						print("一个\n");
					}
					play.hp=play.max_hp;
					break;
				}
				else{
					print("下次再来！\n");
					break;
				}
				case 3:plase=forest_1;
				int s;
				s=rand()%10;
				if(s<7){
					guai=xiyi;
					print("森林蜥蜴扑了过来！\n");
					vs();
				}
				else if(s<9){
					guai=whitch;
					print("森林女巫扑了过来！！\n");
					vs();
				}
				else{
					print("这里安全\n");
				}
				break;
				case 4:plase=forest_2;
				s=rand()%10;
				if(s<7){
					guai=whitch;
					print("森林女巫扑了过来！！\n");
					vs();
				}
				else if(s<9){
					guai=strongman;
					print("森林巨人扑了过来！！！\n");
					s=rand()%10;
					if(s<8){
						guai.thing="黄金圣衣";
						guai.thing_number=0;
					}
					else{
						guai.thing="巨人之臂";
						guai.thing_number=1;
					}
					vs();
				}
				else{
					print("这里安全\n");
				}
				break;
				case 5:plase=forest_3;
				s=rand()%10;
				if(s<7){
					guai=strongman;
					print("森林巨人扑了过来！！！\n");
					s=rand()%10;
					if(s<8){
						guai.thing="黄金圣衣";
						guai.thing_number=0;
					}
					else{
						guai.thing="巨人之臂";
						guai.thing_number=1;
					}
					vs();
				}
				else if(s<9){
					guai=big_strongman;
					print(guai.name);
					print("扑了过来！！！！\n");
					vs();
				}
				else{
					print("这里安全\n");
				}
				break;
				case 6:plase=grass_1;
				s=rand()%10;
				if(s<7){
					guai=bee;
					print("草原黄蜂扑了过来！\n");
					vs();
				}else if(s<9){
					guai=horse;
					print("草原野马扑了过来！！\n");
					vs();
				}
				else{
					print("这里安全\n");
				}
				break;
				case 7:plase=grass_2;
				s=rand()%10;
				if(s<7){
					guai=horse;
					print("草原野马扑了过来！！\n");
					vs();
				}else if(s<9){
					guai=lion;
					print("草原雄狮扑了过来！！！\n");
					vs();
				}
				else{
					print("这里安全\n");
					vs();
				}
				break;
				case 8:plase=grass_3;
				s=rand()%10;
				if(s<7){
					guai=lion;
					print("草原雄狮扑了过来！！！\n");
					vs();
				}else if(s<9){
					if(arm==0){
						if(say){
							print("神秘老人：加油吧，年轻人，争取获得巨人之臂！^_^\n");
						}
						else{
							print("神秘老人：如果你有巨人之臂，我就告诉你公主的下落哦！^_^\n");
						}
					}
					else{
						print("神秘老人：年轻人，做的不错。不过……嘿嘿，你上当了。巨人之臂我要了，公主你也别想带走！！！\n\n\n");
						guai=shitu;
						print("使徒扑了过来！！！！\n");
						vs();
					}
				}
				else{
					print("这里安全\n");
				}
			}
			break;
			case 2:choose_things();break;
			case 3:if(plase==bar){
				print("要和谁说话？\n1.红发女郎    2.赏金猎人    3.酒吧老板\n");
				cin >> number;
				switch(number){
					case 1:print("红发女郎：吧台那边的猎人好帅啊！！^_^\n");break;
					case 2:if(clothes==0){
						print("赏金猎人：你要救公主啊，好胆量！不过外面的草原和丛林很险恶，而且越深越危险。这是匕首和布衣，对你会有帮助的。\n\n");
						print(play.name);
						print("心想：这位大叔人真好啊！\n");
						clothes++;
						very_small++;
						break;
					}
					else{
						print("赏金猎人：加油吧，年轻人，不要被外面的丛林和草原所吓倒！^_^");
						break;
					}
					case 3:print("酒吧老板：要喝点什么？1.二锅头25金币，hp+25    2.xo酒50金币，hp+50      3.人头马面100金币，hp+100    4.青花郎200金币，hp+200     5.茅台酒500金币，hp+500\n");
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
				print("这里好像没人可以聊天");
				break;
			}
			break;
			case 4:check();break;
			case 5:print("选择要更换的装备：\n\n");
			#undef data
			char data[100];
			sprintf(data,"1.匕首%d个    2.剑%d个     3.碧血剑%d个     4.绝世好剑%d个      \n5.布衣%d个     6.铁甲%d个     7.防弹衣%d个         8.黄金圣衣%d个\n",very_small,small,big,good,clothes,tie,fang,gold_clothes);
			printf(data);
			cin >> number;
			switch(number){
				case 1: zbg(very_small,30,"匕首");break;
				case 2: zbg(small,50,"剑");break;
				case 3: zbg(big,100,"碧血剑");break;
				case 4: zbg(good,200,"绝世好剑");break;
				case 5: zbf(clothes,30,"布衣");break;
				case 6: zbf(tie,50,"铁甲");break;
				case 7: zbf(fang,100,"防弹衣");break;
				case 8: zbf(gold_clothes,200,"黄金圣衣");break;
			}
			break;
			case 0: print("确定退出游戏？\n1.是    0.否");
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

