@echo off
echo 正在编译程序...
g++ main.cpp calculator.cpp -o calculator
if errorlevel 1 (
    echo 编译失败！
    pause
    exit /b 1
)
echo 编译成功！
echo 正在运行程序...
calculator
pause 