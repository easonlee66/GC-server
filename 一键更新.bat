@echo off
title GC-server Upgrader

@echo on
echo GC-server Upgrading,please wait……

@echo off

echo .
rem 更新GC-server
cd "%~dp0"\git\cmd\
git reset --hard origin/master
git pull origin master

git gc
git prune

@echo on 
echo GC-server Upgraded,enjoy it!

@echo off
pause