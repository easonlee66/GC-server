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
echo GC-server Upgraded,enjoy it!

@echo off
pause