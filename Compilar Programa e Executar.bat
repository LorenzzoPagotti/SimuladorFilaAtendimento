@echo off
cls

echo =======================================
echo     COMPILANDO O SIMULADOR...
echo =======================================
echo.

gcc main.c fila.c simulador.c -o simulador

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [X] ERRO NA COMPILACAO! O programa nao foi executado.
    echo.
    pause
    exit /b
)

echo.
echo =======================================
echo          INICIANDO PROGRAMA...
echo =======================================
echo.

simulador.exe

echo.
echo =======================================
echo Programa finalizado.
pause