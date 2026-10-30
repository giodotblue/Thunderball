#ifndef __SEXYAPP_H__
#define __SEXYAPP_H__

#include "SexyAppBase.h"

namespace Sexy
{

class InternetManager;
class BetaSupport;

// VTABLE: POPCAPGAME1 0x00612054
class SexyApp : public SexyAppBase
{
public: 
        char padding[0x118];        

public:
        virtual void                    UpdateFrames();

        virtual void                    WriteToRegistry();
        virtual void                    ReadFromRegistry();     

        virtual bool                    CheckSignature(const Buffer& theBuffer, const std::string& theFileName);
        
        virtual bool                    ShouldCheckForUpdate();
        virtual void                    UpdateCheckQueried();

        virtual void                    URLOpenSucceeded(const std::string& theURL);

public:
        SexyApp();
        virtual ~SexyApp();

        bool                            Validate(const std::string& theUserName, const std::string& theRegCode);

        virtual bool                    OpenRegisterPage(DefinesMap theDefinesMap);
        virtual bool                    OpenRegisterPage();

        virtual void                    PreDisplayHook();
        virtual void                    InitPropertiesHook();
        virtual void                    Init();
        virtual void                    PreTerminate();

        virtual bool                    OpenHTMLTemplate(const std::string& theTemplateFile, const DefinesMap& theDefinesMap);
        virtual void                    OpenUpdateURL();

        virtual void                    HandleCmdLineParam(const std::string& theParamName, const std::string& theParamValue);
        virtual std::string             GetGameSEHInfo();
        virtual void                    GetSEHWebParams(DefinesMap* theDefinesMap);

};

// GLOBAL: POPCAPGAME1 0x00687394
extern SexyApp* gSexyApp;

};

#endif //__SEXYAPP_H__