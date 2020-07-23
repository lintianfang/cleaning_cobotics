@echo off
setlocal EnableDelayedExpansion
%~d0
cd %~p0
set my_path=%~dp0
set cgvdir=%my_path:~0,-1%
set cgvprjdir=%cgvdir%\project
if [%1] == [] (
   set param=""
) else (
   set param=%1
)
set param=%param:"=%
if NOT [%1] == [] (
   if EXIST "%param%\..\%~n1" (
      call set cgvprjdir=%param%
   ) else ( 
      echo only directories valid as project path argument
      echo "%param%\..\%~n1" does not exist
      pause
      goto:eof
   )
) else (
   echo no cgv project directory dragged onto batch script
   pause
   goto:eof
)
call reg ADD HKEY_CURRENT_USER\Environment /v CGV_PROJECT_DIR /t REG_SZ /d "%cgvprjdir%" /f > nul 2> nul
bin\setx CGV_DUMMY ""
call reg DELETE HKEY_CURRENT_USER\Environment /v CGV_DUMMY /f  >nul 2> nul
echo set CGV_PROJECT_DIR to %cgvprjdir%
pause
