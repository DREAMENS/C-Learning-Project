#include "filemanager.h"
#include <iostream>
#include <string>

/**
 * @brief 打印主菜单
 * 显示所有可用的文件操作选项
 */
void printMenu() {
    std::cout << "\n文件管理器测试程序\n";
    std::cout << "1. 创建文件\n";
    std::cout << "2. 写入文件\n";
    std::cout << "3. 读取文件\n";
    std::cout << "4. 删除文件\n";
    std::cout << "5. 创建目录\n";
    std::cout << "6. 列出目录内容\n";
    std::cout << "7. 删除目录\n";
    std::cout << "0. 退出\n";
    std::cout << "请选择操作: ";
}

int main() {
    // 设置控制台编码为 UTF-8，以正确显示中文
    system("chcp 65001");
    
    FileManager fm;  // 创建文件管理器实例
    std::string filename, content, directory;  // 用于存储用户输入
    int choice;  // 用于存储用户选择的操作

    while (true) {  // 主循环
        printMenu();  // 显示菜单
        std::cin >> choice;  // 获取用户输入

        switch (choice) {  // 根据用户选择执行相应操作
            case 0:  // 退出程序
                std::cout << "程序退出\n";
                return 0;

            case 1: {  // 创建文件
                std::cout << "请输入要创建的文件名: ";
                std::cin >> filename;
                if (fm.createFile(filename)) {
                    std::cout << "文件创建成功\n";
                } else {
                    std::cout << "文件创建失败\n";
                }
                break;
            }

            case 2: {  // 写入文件
                std::cout << "请输入文件名: ";
                std::cin >> filename;
                std::cout << "请输入要写入的内容: ";
                std::cin.ignore();  // 清除输入缓冲
                std::getline(std::cin, content);  // 读取整行内容
                if (fm.writeFile(filename, content)) {
                    std::cout << "内容写入成功\n";
                } else {
                    std::cout << "内容写入失败\n";
                }
                break;
            }

            case 3: {  // 读取文件
                std::cout << "请输入要读取的文件名: ";
                std::cin >> filename;
                content = fm.readFile(filename);
                if (!content.empty()) {
                    std::cout << "文件内容: " << content << "\n";
                } else {
                    std::cout << "文件读取失败\n";
                }
                break;
            }

            case 4: {  // 删除文件
                std::cout << "请输入要删除的文件名: ";
                std::cin >> filename;
                if (fm.deleteFile(filename)) {
                    std::cout << "文件删除成功\n";
                } else {
                    std::cout << "文件删除失败\n";
                }
                break;
            }

            case 5: {  // 创建目录
                std::cout << "请输入要创建的目录名: ";
                std::cin >> directory;
                if (fm.createDirectory(directory)) {
                    std::cout << "目录创建成功\n";
                } else {
                    std::cout << "目录创建失败\n";
                }
                break;
            }

            case 6: {  // 列出目录内容
                std::cout << "请输入要列出内容的目录名: ";
                std::cin >> directory;
                auto files = fm.listFiles(directory);
                if (!files.empty()) {
                    std::cout << "目录内容:\n";
                    for (const auto& file : files) {
                        std::cout << file << "\n";
                    }
                } else {
                    std::cout << "目录为空或不存在\n";
                }
                break;
            }

            case 7: {  // 删除目录
                std::cout << "请输入要删除的目录名: ";
                std::cin >> directory;
                if (fm.deleteDirectory(directory)) {
                    std::cout << "目录删除成功\n";
                } else {
                    std::cout << "目录删除失败\n";
                }
                break;
            }

            default:  // 处理无效输入
                std::cout << "无效的选择\n";
        }
    }

    return 0;
} 