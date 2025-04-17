#include "filemanager.h"//包含头文件
#include <iostream>//包含输入输出流库
#include <algorithm>//包含算法库
#include <fstream>//包含文件流库
#include <sys/stat.h>//包含文件状态库
#include <direct.h>//包含目录操作库
#include <io.h>//包含输入输出库，处理二进制文件和需要高性能文件操作
#include <windows.h>//包含Windows API库——该项目主要使用其对文件和目录操作的函数

/**
 * @brief 构造函数实现
 * 初始化文件管理器，设置当前工作目录为程序运行目录
 * 使用 Windows API 的 GetCurrentDirectoryA 函数获取当前目录
 */
FileManager::FileManager() {
    char buffer[MAX_PATH];//MAX_PATH 是 Windows 系统中定义的最大路径长度常量（通常是 260 个字符）
    if (GetCurrentDirectoryA(MAX_PATH, buffer) != 0) {
        currentPath = std::string(buffer);//同一类中，任何成员函数都可以访问该类的所有成员（包括私有成员）
    }
}

/**
 * @brief 创建新文件
 * 如果文件已存在，则返回false
 * 使用 std::ofstream 创建文件
 */
bool FileManager::createFile(const std::string& filename) {
    if (fileExists(filename)) {
        return false;
    }//检测文件是否存在
    
    std::ofstream file(filename);//创建文件。
    //以默认模式（通常是只写模式）打开指定的文件。如果文件不存在，  ofstream   会尝试创建该文件。
    //ofstream   是C++标准库中的文件输出流类
    return file.is_open();//返回文件是否打开
}

/**
 * @brief 写入内容到文件
 * 如果文件不存在，则创建新文件
 * 写入会覆盖原有内容
 */
bool FileManager::writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    file << content;
    return true;
}

/**
 * @brief 读取文件内容
 * 如果文件不存在或无法打开，返回空字符串
 * 使用二进制模式读取，支持所有类型的文件
 */
std::string FileManager::readFile(const std::string& filename) {
    if (!fileExists(filename)) {
        return "";
    }
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }
    
    return std::string(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );
}

/**
 * @brief 删除文件
 * 如果文件不存在，返回false
 * 使用 Windows API 的 remove 函数删除文件
 */
bool FileManager::deleteFile(const std::string& filename) {
    if (!fileExists(filename)) {
        return false;
    }
    
    return remove(filename.c_str()) == 0;
}

/**
 * @brief 向文件追加内容
 * 如果文件不存在，则创建新文件
 * 使用追加模式打开文件
 */
bool FileManager::appendToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        return false;
    }
    
    file << content;
    return true;
}

/**
 * @brief 检查文件是否存在
 * 使用 Windows API 的 stat 函数检查文件状态
 */
bool FileManager::fileExists(const std::string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

/**
 * @brief 获取文件大小
 * 如果文件不存在或无法访问，返回-1
 * 使用 Windows API 的 stat 函数获取文件信息
 */
long long FileManager::getFileSize(const std::string& filename) {
    struct stat buffer;
    if (stat(filename.c_str(), &buffer) != 0) {
        return -1;
    }
    return buffer.st_size;
}

/**
 * @brief 获取文件扩展名
 * 返回包含点号的扩展名（如".txt"）
 * 使用字符串操作获取扩展名
 */
std::string FileManager::getFileExtension(const std::string& filename) {
    size_t pos = filename.find_last_of(".");
    if (pos == std::string::npos) {
        return "";
    }
    return filename.substr(pos);
}

/**
 * @brief 列出目录中的所有文件
 * 返回包含完整文件路径的向量
 * 使用 Windows API 的 FindFirstFile/FindNextFile 函数
 */
std::vector<std::string> FileManager::listFiles(const std::string& directory) {
    std::vector<std::string> files;
    std::string search_path = directory + "\\*.*";
    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(search_path.c_str(), &fd);
    
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                files.push_back(directory + "\\" + fd.cFileName);
            }
        } while (FindNextFileA(hFind, &fd));
        FindClose(hFind);
    }
    
    return files;
}

/**
 * @brief 创建新目录
 * 如果目录已存在，返回false
 * 使用 Windows API 的 _mkdir 函数创建目录
 */
bool FileManager::createDirectory(const std::string& directory) {
    if (fileExists(directory)) {
        return false;
    }
    
    return _mkdir(directory.c_str()) == 0;
}

/**
 * @brief 删除目录及其内容
 * 递归删除目录中的所有文件和子目录
 * 使用 Windows API 的 FindFirstFile/FindNextFile 函数遍历目录
 */
bool FileManager::deleteDirectory(const std::string& directory) {
    if (!fileExists(directory)) {
        return false;
    }
    
    std::string search_path = directory + "\\*.*";
    WIN32_FIND_DATAA fd;
    HANDLE hFind = FindFirstFileA(search_path.c_str(), &fd);
    
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::string file_name = fd.cFileName;
            if (file_name != "." && file_name != "..") {
                std::string full_path = directory + "\\" + file_name;
                if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    deleteDirectory(full_path);
                } else {
                    DeleteFileA(full_path.c_str());
                }
            }
        } while (FindNextFileA(hFind, &fd));
        FindClose(hFind);
    }
    
    return RemoveDirectoryA(directory.c_str()) != 0;
} 