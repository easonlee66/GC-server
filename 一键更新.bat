@echo off
title GC-server Upgrader

@echo on
echo GC-server Upgrading,please wait……

@echo off

IF EXIST "%~dp0"\.git\index.lock ( 
	del /f /s /q "%~dp0"\.git\index.lock > nul
	rd /q /s "%~dp0"\.git\index.lock > nul
)

echo.
echo.
cd "%~dp0"\git\cmd\
rem 更新GC-server
git reset --hard origin/master
git pull origin master

git gc
git prune

rem rd/s/q "%~dp0"\.git\refs\original > nul
rem rd/s/q "%~dp0"\.git\logs\ > nul

@echo on 
echo GC-server Upgraded,but it can't use.compiling……

@echo on
cd "%~dp0"\MinGW\bin
rem 编译文件
g++ "%~dp0C++\GC_server.cpp" -o "%~dp0C++\GC_server.exe"
g++ "%~dp0C++\cs.cpp" -o "%~dp0C++\cs.exe"
g++ "%~dp0C++\ctjdb.cpp" -o "%~dp0C++\ctjdb.exe"
g++ "%~dp0C++\drcs.cpp" -o "%~dp0C++\drcs.exe"
g++ "%~dp0C++\g2048.cpp" -o "%~dp0C++\g2048.exe"
g++ "%~dp0C++\gzcs.cpp" -o "%~dp0C++\gzcs.exe"
g++ "%~dp0C++\jscs.cpp" -o "%~dp0C++\jscs.exe"
g++ "%~dp0C++\mg.cpp" -o "%~dp0C++\mg.exe"
g++ "%~dp0C++\snake.cpp" -o "%~dp0C++\snake.exe"
g++ "%~dp0C++\sy.cpp" -o "%~dp0C++\sy.exe"

@echo on
echo GC-server complied,enjoy it !

@echo off
pause