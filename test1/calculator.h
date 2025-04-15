//计算器类
//定义了计算器类的接口
//声明了所有可用的数学运算函数
//提供了输入验证和错误处理
//定义了清除屏幕和显示菜单的辅助功能

//接口定义：头文件定义了类的"契约"
//告诉使用者这个类能做什么
//分离声明和实现：声明在 .h 文件中，实现在 .cpp 文件中，这是C++的标准做法。
//代码组织：使代码结构清晰便于维护和修改
//这种设计方式符合C++的模块化编程思想，使代码更加清晰和易于维护。

#ifndef CALCULATOR_H
#define CALCULATOR_H
//这是C++中的头文件保护机制，也称为"include guard"
//用于防止头文件被多次包含
//确保每个头文件只被编译一次
//避免重复定义错误

#include <string>
#include <stdexcept>
//<string>：字符串处理库
//提供std::string类
//用于处理文本输入和输出
//在我们的计算器中用于处理用户输入的数字字符串

//<stdexcept>：标准异常库
//提供std::runtime_error类
//用于处理运行时错误
//在我们的计算器中用于抛出错误消息


/**
 * @class Calculator
 * @brief 简单计算器类，提供基本的数学运算功能
 * 
 * 该类提供了基本的数学运算功能，包括：
 * - 基本运算：加、减、乘、除
 * - 高级运算：幂运算、平方根
 * - 辅助功能：输入验证、界面显示
 */
class Calculator {
public:
    /**
     * @brief 执行加法运算
     * @param a 第一个操作数
     * @param b 第二个操作数
     * @return 两数之和
     */
    double add(double a, double b);

    /**
     * @brief 执行减法运算
     * @param a 第一个操作数
     * @param b 第二个操作数
     * @return 两数之差
     */
    double subtract(double a, double b);

    /**
     * @brief 执行乘法运算
     * @param a 第一个操作数
     * @param b 第二个操作数
     * @return 两数之积
     */
    double multiply(double a, double b);

    /**
     * @brief 执行除法运算
     * @param a 第一个操作数（被除数）
     * @param b 第二个操作数（除数）
     * @return 除法结果
     * @throw std::runtime_error 当除数为零时抛出异常
     */
    double divide(double a, double b);
    
    /**
     * @brief 执行幂运算
     * @param base 底数
     * @param exponent 指数
     * @return 幂运算结果
     */
    double power(double base, double exponent);

    /**
     * @brief 计算平方根
     * @param number 要计算平方根的数
     * @return 平方根结果
     * @throw std::runtime_error 当输入负数时抛出异常
     */
    double squareRoot(double number);
    
    /**
     * @brief 验证字符串是否为有效数字
     * @param str 要验证的字符串
     * @return 如果是有效数字返回true，否则返回false
     */
    bool isNumber(const std::string& str);

    /**
     * @brief 清除控制台屏幕
     */
    void clearScreen();

    /**
     * @brief 显示计算器菜单
     */
    void showMenu();
};

#endif // CALCULATOR_H 