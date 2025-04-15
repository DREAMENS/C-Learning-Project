#include "calculator.h"// 包含我们自己的头文件
#include <iostream>// 用于输入输出
#include <cmath>// 用于数学运算
#include <cstdlib>// 用于操作系统相关功能
#include <regex>// 用于正则表达式

// 实现加法运算
double Calculator::add(double a, double b) {
    return a + b;
}

// 实现减法运算
double Calculator::subtract(double a, double b) {
    return a - b;
}

// 实现乘法运算
double Calculator::multiply(double a, double b) {
    return a * b;
}

// 实现除法运算，包含除数为零的检查
double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("错误：除数不能为零！");
    }
    return a / b;
}

// 实现幂运算，使用标准库的pow函数
double Calculator::power(double base, double exponent) {
    return std::pow(base, exponent);
}

// 实现平方根计算，包含负数检查
double Calculator::squareRoot(double number) {
    if (number < 0) {
        throw std::runtime_error("错误：不能计算负数的平方根！");
    }//负数检查
    return std::sqrt(number);
}

// 使用正则表达式验证输入是否为有效数字
bool Calculator::isNumber(const std::string& str) {
    // 匹配整数和小数（包括负数）
    std::regex numberPattern("^-?\\d*\\.?\\d+$");//创建numberPattern正则表达式
    // ^  ：表示匹配字符串的开头。
    // -?  ：表示匹配一个可选的负号。
    // \\d* ：表示匹配零个或多个数字。
    // \\.? ：表示匹配一个可选的小数点。
    // \\d+ ：表示匹配一个或多个数字。
    // $  ：表示匹配字符串的结尾。
    return std::regex_match(str, numberPattern);//使用regex_match函数检查str是否匹配numberPattern
}

// 根据操作系统类型清除控制台屏幕
void Calculator::clearScreen() {
    #ifdef _WIN32
        system("cls");    // Windows系统使用cls命令
    #else
        system("clear");  // Unix/Linux系统使用clear命令
    #endif
}

// 显示计算器的主菜单
void Calculator::showMenu() {
    std::cout << "\n=== 简单计算器 ===\n";
    std::cout << "1. 加法\n";
    std::cout << "2. 减法\n";
    std::cout << "3. 乘法\n";
    std::cout << "4. 除法\n";
    std::cout << "5. 幂运算\n";
    std::cout << "6. 平方根\n";
    std::cout << "0. 退出\n";
    std::cout << "请选择操作 (0-6): ";
} 