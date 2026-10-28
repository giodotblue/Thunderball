#ifndef __FILE_DIALOG_H__
#define __FILE_DIALOG_H__


#include <windows.h>
#include <string>
#include <list>

namespace Sexy
{

class FileDialog {
public:
	static std::string mDefRegKeyPath;
	static std::string mDefRegKeyName;
	static std::string mDefInitialDir;

	bool mUnk0x4;
	bool mUnk0x5;
	bool mUnk0x6;
	bool mUnk0x7;
	bool mUnk0x8;
	bool mUnk0x9;
	std::list<std::pair<std::string, std::string>> mFilters; // +0x10
	std::list<std::string> mUnk0x18;
	std::string mUnk0x24;
	std::string mUnk0x40;
	std::string mUnk0x5c;
	std::string mUnk0x78;
	std::string mUnk0x94;
	std::string mUnk0xb0;
	bool mUnk0xcc;

	FileDialog(bool param_1);
	~FileDialog();

	void SetRegKey(const std::string& theRegKeyPath, const std::string& theRegKeyName, bool param_3);
    void SetInitialDir(const std::string& theDir, bool param_2);
	std::string GetRegKeyDir();
	std::string GetRegKeyFileName();
	void SetRegKeyDir(const std::string& theDir);
	void SetRegKeyFileName(const std::string &theFileName);
    void AddFilter(const std::string& theName, const std::string& theExtension);
    void SetTitle(const std::string& theTitle);
	void SetNoChangeDir(bool param_1);
	void SetWarnIfExists(bool param_1);
	void SetInitialFileName(const std::string& theFileName);
	std::string GetFile();

	static UINT_PTR CALLBACK HookProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam);

	virtual bool DoDialog(HWND theParentWnd);
	virtual HWND GetDefWindow();
	virtual bool DialogHook();
};

class SexyFileDialog : public FileDialog {
public:
	SexyFileDialog() : FileDialog(true) {}

	virtual bool DoDialog(HWND theParentWnd);
};

} // namespace Sexy

#endif
