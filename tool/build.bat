@echo off

set buildDir=..\build

set exeDir=..\bin\x64\Release
set workingDir=..\working

if exist %buildDir% (
echo Remove build directory
rmdir /q /s %buildDir%
echo.
)

echo Create build directory.
mkdir %buildDir%
echo.

echo Copy data and .dll
xcopy %workingDir% %buildDir% /E
echo.

echo Remove debug .dll
del /s %buildDir%\*-d*.dll
echo.

echo Copy .exe
copy %exeDir%\*.exe %buildDir%
echo.

pause