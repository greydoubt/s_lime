@echo on
rem format b:

@echo This will creat bootdisk for BeOS 4.5.2
@echo Insert empty formated floppy disk to you floppy drive.
@echo off
pause

Rawrite.exe boot452.img b:
rem Rawrite.exe boot452.img a: