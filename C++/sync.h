#ifndef GC_SYNC_H_
#define GC_SYNC_H_ 1

//#define _IS_WINDOWS__

#endif

#ifndef _GC_FUNCTION_H__
#define _GC_FUNCTION_H__ 1

#include <iostream>
#include <string>
#include <cstdio>

#ifdef _IS_WINDOWS__
#define get getch
#else
#define get getchar
#endif

#ifndef _IS_WINDOWS__
int Sleep(int xxx){
    return 0;
}
#define MB_OK 1
#define MB_YESNO 2
#define MB_SYSTEMMODAL 2
#define IDYES true
bool MessageBox(int* x,std::string title,std::string body,int type){
    std::cout << title << "\n" << body << "\n";
    if(type==2){
        std::cout << "确定请按1加回车，否则按2加回车";
        return std::getchar()=='1';
    }
    else{
        std::cout << "请按任意键加回车继续";
        std::getchar();
        return IDYES;
    }
}
#endif

#endif