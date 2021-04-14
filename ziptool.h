#ifndef ZIPTOOL_H
#define ZIPTOOL_H
#include <string>
class ZipTool
{
public:
	ZipTool();
	// ��ѹ�ļ����ļ���
	static bool extractDir(std::string fileCompressed, std::string dir);
	// ѹ��Ŀ¼
	static bool compressDir(std::string fileCompressed,
		std::string dir, bool deleteDir = false);
	// ɾ��Ŀ¼
	static void deleteFolder(const std::string& folderFullPath);
	// ���ļ�������һ������ת�����ļ�����
	std::string FilePathToFolderPath(const std::string& filePath);
};

#endif // ZIPTOOL_H
