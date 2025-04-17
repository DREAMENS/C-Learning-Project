#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>    // 用于字符串操作
#include <vector>    // 用于存储文件列表
#include <fstream>   // 用于文件流操作
#include <stdexcept> // 用于异常处理

/**
 * @class FileManager
 * @brief 文件管理器类，提供文件和目录的基本操作功能
 * 
 * 该类封装了文件和目录的基本操作，包括：
 * 1. 文件操作：创建、读取、写入、删除、追加内容
 * 2. 目录操作：创建、删除、列出内容
 * 3. 文件信息：获取大小、扩展名等
 * 
 * 使用 Windows API 实现底层文件操作，确保跨平台兼容性
 */
class FileManager {
public:
    /**
     * @brief 构造函数
     * 初始化文件管理器，设置当前工作目录
     * 使用 Windows API 获取程序运行时的当前目录
     */
    FileManager();

    /**
     * @brief 创建新文件
     * @param filename 要创建的文件名（包含路径）
     * @return 创建成功返回true，失败返回false
     * @note 如果文件已存在，则返回false
     */
    bool createFile(const std::string& filename);

    /**
     * @brief 写入内容到文件
     * @param filename 目标文件名
     * @param content 要写入的内容
     * @return 写入成功返回true，失败返回false
     * @note 写入会覆盖原有内容，如果文件不存在则创建新文件
     */
    bool writeFile(const std::string& filename, const std::string& content);

    /**
     * @brief 读取文件内容
     * @param filename 要读取的文件名
     * @return 文件内容，如果读取失败返回空字符串
     * @note 使用二进制模式读取，支持所有类型的文件
     */
    std::string readFile(const std::string& filename);

    /**
     * @brief 删除文件
     * @param filename 要删除的文件名
     * @return 删除成功返回true，失败返回false
     * @note 如果文件不存在，返回false
     */
    bool deleteFile(const std::string& filename);

    /**
     * @brief 向文件追加内容
     * @param filename 目标文件名
     * @param content 要追加的内容
     * @return 追加成功返回true，失败返回false
     * @note 如果文件不存在则创建新文件
     */
    bool appendToFile(const std::string& filename, const std::string& content);
    
    /**
     * @brief 检查文件是否存在
     * @param filename 要检查的文件名
     * @return 文件存在返回true，不存在返回false
     * @note 使用 Windows API 的 stat 函数检查文件状态
     */
    bool fileExists(const std::string& filename);

    /**
     * @brief 获取文件大小
     * @param filename 目标文件名
     * @return 文件大小（字节），失败返回-1
     * @note 使用 Windows API 的 stat 函数获取文件信息
     */
    long long getFileSize(const std::string& filename);

    /**
     * @brief 获取文件扩展名
     * @param filename 目标文件名
     * @return 文件扩展名，如果没有扩展名返回空字符串
     * @note 返回的扩展名包含点号，如".txt"
     */
    std::string getFileExtension(const std::string& filename);
    
    /**
     * @brief 列出目录中的所有文件
     * @param directory 目标目录路径
     * @return 包含所有文件路径的向量
     * @note 使用 Windows API 的 FindFirstFile/FindNextFile 函数
     */
    std::vector<std::string> listFiles(const std::string& directory);

    /**
     * @brief 创建新目录
     * @param directory 要创建的目录名
     * @return 创建成功返回true，失败返回false
     * @note 如果目录已存在，返回false
     */
    bool createDirectory(const std::string& directory);

    /**
     * @brief 删除目录及其内容
     * @param directory 要删除的目录名
     * @return 删除成功返回true，失败返回false
     * @note 递归删除目录中的所有文件和子目录
     */
    bool deleteDirectory(const std::string& directory);

private:
    std::string currentPath;  ///< 当前工作目录路径，在构造函数中初始化
};

#endif // FILEMANAGER_H 