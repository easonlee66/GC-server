@echo off
title GC-server Upgrader

@echo on
echo GC-server Upgrading,please wait……

@echo off

echo .
cd "%~dp0"\git\cmd\
git pull origin master

@echo on 
echo GC-server Upgraded,enjoy it!

@echo off
pause