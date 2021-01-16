@echo off

set deleteDir=..\vsproj\x64
set removeDir=..\bin

if exist %deleteDir% (

echo Delete the directory %deleteDir%
rd /s /q %deleteDir%
echo.

)

echo Delete all tmp file in %removeDir%
del /s /q %removeDir%\*.ilk
del /s /q %removeDir%\*.pdb
del /s /q %removeDir%\*.iobj
del /s /q %removeDir%\*.ipdb
echo.
