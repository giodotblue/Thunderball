#include "FileDialog.h"

#include <string>
#include <SexyAppFramework/SexyAppBase.h>
#include <windows.h>
#include <winnt.h>
#include <winreg.h>
#include <winuser.h>

using namespace Sexy;

std::string FileDialog::mDefInitialDir = "";
std::string FileDialog::mDefRegKeyName = "";
std::string FileDialog::mDefRegKeyPath = "";

// TEMPLATE: POPCAPGAME1 0x004bcd90
// std::list<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >::_Buynode(void)

// FUNCTION: POPCAPGAME1 0x004bd7e0
FileDialog::FileDialog(bool param_1)
{
    mUnk0x4 = param_1;
    mUnk0x6 = false;
    mUnk0x7 = false;
    mUnk0x5 = false;
    mUnk0x9 = false;
    mUnk0xcc = false;
    mUnk0x8 = !param_1;

    if (!mDefRegKeyPath.empty()) {
        SetRegKey(mDefRegKeyPath, mDefRegKeyName, false);
        SetInitialDir(mDefInitialDir, false);
    }   
}

// FUNCTION: POPCAPGAME1 0x00423790
FileDialog::~FileDialog() {}
 
// FUNCTION: POPCAPGAME1 0x004bd1e0
void FileDialog::SetRegKey(const std::string& theRegKeyPath, const std::string& theRegKeyName, bool param_3) {
    mUnk0x94 = theRegKeyPath;
    mUnk0xb0 = theRegKeyName;
    mUnk0xcc = param_3;
}

// FUNCTION: POPCAPGAME1 0x004bd790
void FileDialog::SetInitialDir(const std::string& param_1, bool param_2) {
    if (!param_2) {
        if (!GetRegKeyDir().empty()) {
            return;
        }
    }

    mUnk0x78 = param_1;
}

// FUNCTION: POPCAPGAME1 0x004bd290
std::string FileDialog::GetRegKeyDir() {
    if (!mUnk0x94.empty()) {
        HKEY aKey;
        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, mUnk0x94.c_str(), NULL, KEY_ALL_ACCESS,  &aKey) == ERROR_SUCCESS) {
            DWORD dataType;
            DWORD dataSize = 4096;
            BYTE buffer[4096];

            LONG aResult = RegQueryValueExA(aKey, (mUnk0xb0 + "_dir").c_str(), NULL, &dataType, buffer, &dataSize);
            RegCloseKey(aKey);

            if (aResult == ERROR_SUCCESS && dataType == REG_SZ) {
                return std::string((char*)buffer);
            }
        }
    }

    return "";
}

// FUNCTION: POPCAPGAME1 0x004bd4c0
std::string FileDialog::GetRegKeyFileName() {
    if (!mUnk0x94.empty()) {
        HKEY aKey;
        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, mUnk0x94.c_str(), NULL, KEY_ALL_ACCESS,  &aKey) == ERROR_SUCCESS) {
            DWORD dataType;
            DWORD dataSize = 4096;
            BYTE buffer[4096];

            LONG aResult = RegQueryValueExA(aKey, (mUnk0xb0 + "_file").c_str(), NULL, &dataType, buffer, &dataSize);
            RegCloseKey(aKey);

            if (aResult == ERROR_SUCCESS && dataType == REG_SZ) {
                return std::string((char*)buffer);
            }
        }
    }

    return "";
}

// FUNCTION: POPCAPGAME1 0x004bd3f0
void FileDialog::SetRegKeyDir(const std::string& theDir) {
    if (!mUnk0x94.empty()) {
        HKEY aKey;
        if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, mUnk0x94.c_str(), NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &aKey, NULL) == ERROR_SUCCESS) {
            RegSetValueExA(aKey, (mUnk0xb0 + "_dir").c_str(), NULL, REG_SZ, (const BYTE*)theDir.c_str(), theDir.length() + 1);
            RegCloseKey(aKey);
        }
    }
}

// FUNCTION: POPCAPGAME1 0x004bd620
void FileDialog::SetRegKeyFileName(const std::string &theFileName) {
    if (!mUnk0x94.empty()) {
        HKEY aKey;
        if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, mUnk0x94.c_str(), NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &aKey, NULL) == ERROR_SUCCESS) {
            RegSetValueExA(aKey, (mUnk0xb0 + "_file").c_str(), NULL, REG_SZ, (const BYTE*)theFileName.c_str(), theFileName.length() + 1);
            RegCloseKey(aKey);
        }
    }
}

// TEMPLATE: POPCAPGAME1 0x004bd6f0
// std::list<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >::_Buynode(struct std::_List_nod<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>>::_Node *, struct std::_List_nod<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>, class std::allocator<struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>>::_Node *, struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>> const &)

// TEMPLATE: POPCAPGAME1 0x004bcdb0
// std::list<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >::_Incsize

// FUNCTION: POPCAPGAME1 0x004be320
void FileDialog::AddFilter(const std::string& theName, const std::string& theExtension) {
    mFilters.push_back(std::list<std::pair<std::string, std::string>>::value_type(theName, theExtension));
}

// FUNCTION: POPCAPGAME1 0x004bd1a0
void FileDialog::SetTitle(const std::string& theTitle) {
    mUnk0x24 = theTitle;
}

// FUNCTION: POPCAPGAME1 0x004bcd80
void FileDialog::SetNoChangeDir(bool param_1) {
    mUnk0x9 = param_1;
}

// FUNCTION: POPCAPGAME1 0x004bcd60
void FileDialog::SetWarnIfExists(bool param_1) {
    if (mUnk0x4) {
        mUnk0x7 = param_1;
    }
}

// FUNCTION: POPCAPGAME1 0x004bd1c0
void FileDialog::SetInitialFileName(const std::string& theFileName) {
    mUnk0x5c = theFileName;
}

// STUB: POPCAPGAME1 0x004bd220
std::string FileDialog::GetFile() {
    if (mUnk0x18.empty()) {
        return "";
    }

    return mUnk0x18.front();
}

// FUNCTION: POPCAPGAME1 0x004bcea0
std::string GetFilePath(const std::string& thePath) {
    size_t aForwardIdx = thePath.rfind('/');
    size_t aBackwardIdx = thePath.rfind('\\');
    
    char aSeparator = (aForwardIdx < aBackwardIdx) ? '\\' : '/';
    
    size_t aLastSlash = thePath.rfind(aSeparator);
    
    if (aLastSlash == std::string::npos) {
        return "";
    }
    
    return thePath.substr(0, aLastSlash);
}

// GLOBAL: POPCAPGAME1 0x00650a88
static bool BOOL_00650a88 = false;
// GLOBAL: POPCAPGAME1 0x00650a8c
static FileDialog* DAT_00650a8c = NULL;
// GLOBAL: POPCAPGAME1 0x0064a508
static std::string DAT_0064a508 = "";

// STUB: POPCAPGAME1 0x004bd000
UINT_PTR CALLBACK FileDialog::HookProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam) {
    if (!DAT_00650a8c) {
        return 0;
    }

    if (uiMsg == WM_NOTIFY) {
        NMHDR* nmhdr = reinterpret_cast<NMHDR*>(lParam);
        
        if (DAT_00650a8c->mUnk0x5 == 0 || nmhdr->code != CDN_SELCHANGE) {
            return 0;
        }

        char pathBuffer[MAX_PATH];
        SendMessageA(GetParent(hdlg), CDM_GETFOLDERPATH, sizeof(pathBuffer), (LPARAM)pathBuffer);
        
        std::string aPath(pathBuffer);

        if (aPath == DAT_0064a508) {
            PostMessageA(GetParent(hdlg), WM_COMMAND, IDCANCEL, 0);
            BOOL_00650a88 = true;
            return 0;
        }

        DAT_0064a508 = aPath;
    }
    else if (uiMsg == WM_INITDIALOG) {
        if (!DAT_00650a8c->mUnk0x40.empty()) {
            SendMessageA(GetParent(hdlg), CDM_SETCONTROLTEXT, 1, (LPARAM)DAT_00650a8c->mUnk0x40.c_str());
        }
    }

    return 0;
}



// FUNCTION: POPCAPGAME1 0x004bd8f0
bool FileDialog::DoDialog(HWND theParentWnd) {

    if (theParentWnd == NULL)
    {
        theParentWnd = GetDefWindow();
    }

    mUnk0x18.clear();
    
    tagOFNA aOFNA;
    memset(&aOFNA, 0, sizeof(aOFNA));
    aOFNA.lStructSize = sizeof(aOFNA);
    aOFNA.hwndOwner = theParentWnd;
    std::string aTitle = mUnk0x24;
    aOFNA.lpstrTitle = aTitle.c_str();
    aOFNA.lpfnHook = (LPOFNHOOKPROC)FileDialog::HookProc;

    DAT_00650a8c = this;
    BOOL_00650a88 = false;
    DAT_0064a508.erase(std::string::npos);

    std::string aFilterStr;
    for (std::list<std::pair<std::string, std::string>>::iterator it = mFilters.begin(); it != mFilters.end(); ++it) {
        aFilterStr += it->first;
        aFilterStr += '\0';
        aFilterStr += it->second;
        aFilterStr += '\0';
    }
    aFilterStr += '\0';
    aOFNA.lpstrFilter = aFilterStr.c_str();

    std::string anInitialFileName = mUnk0x5c;
    if (anInitialFileName.empty()) {
        anInitialFileName = GetRegKeyFileName();
    }

    char aFileNameBuffer[0x1fff];
    strcpy(aFileNameBuffer, anInitialFileName.c_str());
    aOFNA.lpstrFile = aFileNameBuffer;
    aOFNA.nMaxFile = sizeof(aFileNameBuffer);

    std::string anInitialDir = mUnk0x78;
    if (anInitialDir.empty()) {
        anInitialDir = GetRegKeyDir();
    }

    char aDirBuffer[0x2000];
    strcpy(aDirBuffer, anInitialDir.c_str());
    aOFNA.lpstrInitialDir = aDirBuffer;

    aOFNA.Flags = OFN_EXPLORER;
    if (mUnk0x6) aOFNA.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;
    if (mUnk0x7) aOFNA.Flags |= OFN_OVERWRITEPROMPT;
    if (mUnk0x8) aOFNA.Flags |= OFN_FILEMUSTEXIST;
    if (mUnk0x9) aOFNA.Flags |= OFN_NOCHANGEDIR;
    if (mUnk0x5 || !mUnk0x40.empty()) aOFNA.Flags |= OFN_ENABLEHOOK;

    BOOL aOpenSuccess = FALSE;
    if (mUnk0x4) {
        aOpenSuccess = GetSaveFileNameA(&aOFNA);
    } else {
        aOpenSuccess = GetOpenFileNameA(&aOFNA);
    }

    DAT_00650a8c = NULL;
    std::string aDir;
    if (BOOL_00650a88) {
        if (aOpenSuccess == FALSE) {
            return true;
        }
        
        if (mUnk0x5) {
            std::string aFileName = aFileNameBuffer;
            aDir = GetFilePath(aFileName);
            strcpy(aFileNameBuffer, aDir.c_str());
        }
    } else {
        aDir = DAT_0064a508;
        strcpy(aFileNameBuffer, aDir.c_str());
    }

    std::string aFileName = aFileNameBuffer;
    aDir = GetFilePath(aFileName);

    std::string aStr;
    if (mUnk0x6) {
        mUnk0x18.push_back(aFileName);
        aFileName = aFileNameBuffer;
        SetRegKeyFileName(GetFileName(aFileName));
    } else {
        aFileName = aFileNameBuffer;
        const char* p = &aFileNameBuffer[aFileName.size()];

        while (true) {
            const char* start = p;
            while (*p != '\0') {
                p++;
            }

            if (start == p) {
                break;
            }

            std::string aFile(start);
            p++;

            std::string fullPath = aDir + "/" + aFile;
            mUnk0x18.push_back(fullPath);
        }

        if (mUnk0x18.empty()) {
            mUnk0x18.push_back(aFileName);
        }
    }

    SetRegKeyDir(aDir);

    return false;
}

// FUNCTION: POPCAPGAME1 0x00427d50
HWND FileDialog::GetDefWindow() {
    return NULL;
}

bool FileDialog::DialogHook() {
    return false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// FUNCTION: POPCAPGAME1 0x004be3e0
bool SexyFileDialog::DoDialog(HWND theParentWnd) {
    bool local_31 = false;
    int local_38 = 0;
    if (!gSexyAppBase->mPlayingDemoBuffer) {
        gSexyAppBase->BeginPopup();
        local_31 = FileDialog::DoDialog(theParentWnd);
        gSexyAppBase->EndPopup();
        local_38 = mUnk0x18.size();
    } else {
        mUnk0x18.clear();
    }

    gSexyAppBase->DemoSyncBool(&local_31);
    if (local_31) {
        gSexyAppBase->DemoSyncInt(&local_38);
        if (!gSexyAppBase->mPlayingDemoBuffer) {
            for (std::list<std::string>::iterator it = mUnk0x18.begin(); it != mUnk0x18.end(); ++it) {
                gSexyAppBase->DemoSyncString(&*it);
            }
        } else {
            for (int i = 0; i < local_38; i++) {
                std::string aString;
                gSexyAppBase->DemoSyncString(&aString);
                mUnk0x18.push_back(aString);
            }
        }
    }

    return local_31;
}