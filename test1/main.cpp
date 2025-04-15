#include "calculator.h"// 包含我们自己的头文件
#include <iostream>// 用于输入输出
#include <string>// 用于字符串处理
#include <windows.h>// 用于设置控制台编码

/**
 * @brief 获取用户输入的数字
 * @param num 用于存储输入的数字
 * 
 * 该函数会循环读取用户输入，直到获得有效的数字。
 * 使用Calculator类的isNumber方法验证输入。
 */
void getInput(double& num) {
    std::string input;
    while (true) {
        std::cin >> input;
        if (Calculator().isNumber(input)) {
            num = std::stod(input);
            break;
        }
        std::cout << "请输入有效的数字: ";
    }
}

int main() {
    // 设置控制台编码为 UTF-8
    SetConsoleOutputCP(65001);
    
    // 创建计算器对象
    Calculator calc;
    int choice;
    double num1, num2, result;

    // 主程序循环
    while (true) {
        // 清屏并显示菜单
        calc.clearScreen();
        calc.showMenu();
        
        // 获取用户选择
        std::string input;// 声明了string型变量用于存储用户输入
        std::cin >> input;// 从标准输入读取用户输入
        
        // 验证输入是否为有效数字
        if (!Calculator().isNumber(input)) {
            std::cout << "无效的选择，请重试\n";
            continue;
        }
        
        choice = std::stoi(input);//将input转换为整数

        // 检查是否退出
        if (choice == 0) {
            std::cout << "感谢使用，再见！\n";
            break;
        }

        // 使用try-catch处理可能的异常
        try {
            switch (choice) {
                case 1: // 加法
                    std::cout << "请输入第一个数字: ";
                    getInput(num1);
                    std::cout << "请输入第二个数字: ";
                    getInput(num2);
                    result = calc.add(num1, num2);
                    std::cout << "结果: " << result << "\n";
                    break;

                case 2: // 减法
                    std::cout << "请输入第一个数字: ";
                    getInput(num1);
                    std::cout << "请输入第二个数字: ";
                    getInput(num2);
                    result = calc.subtract(num1, num2);
                    std::cout << "结果: " << result << "\n";
                    break;

                case 3: // 乘法
                    std::cout << "请输入第一个数字: ";
                    getInput(num1);
                    std::cout << "请输入第二个数字: ";
                    getInput(num2);
                    result = calc.multiply(num1, num2);
                    std::cout << "结果: " << result << "\n";
                    break;

                case 4: // 除法
                    std::cout << "请输入第一个数字: ";
                    getInput(num1);
                    std::cout << "请输入第二个数字: ";
                    getInput(num2);
                    result = calc.divide(num1, num2);
                    std::cout << "结果: " << result << "\n";
                    break;

                case 5: // 幂运算
                    std::cout << "请输入底数: ";
                    getInput(num1);
                    std::cout << "请输入指数: ";
                    getInput(num2);
                    result = calc.power(num1, num2);
                    std::cout << "结果: " << result << "\n";
                    break;

                case 6: // 平方根
                    std::cout << "请输入数字: ";
                    getInput(num1);
                    result = calc.squareRoot(num1);
                    std::cout << "结果: " << result << "\n";
                    break;

                default:
                    std::cout << "无效的选择，请重试\n";
                    break;
            }
        }
        catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }

        // 等待用户按回车继续
        std::cout << "\n按回车键继续...";
        std::cin.ignore();//忽略输入缓冲区中的字符
        std::cin.get();//等待用户按回车键
    }

    return 0;
} 