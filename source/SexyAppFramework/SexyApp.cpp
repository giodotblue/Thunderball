#include "SexyApp.h"

using namespace Sexy;


SexyApp* Sexy::gSexyApp = NULL;

// STUB: POPCAPGAME1 0x00524db0
SexyApp::SexyApp()
{
	gSexyApp = this;
	OutputDebugStringA("Sexy::SexyApp::SexyApp()\n");
}

// STUB: POPCAPGAME1 0x00524ae0
SexyApp::~SexyApp()
{
	OutputDebugStringA("Sexy::SexyApp::~SexyApp()\n");
}

// STUB: POPCAPGAME1 0x00524ff0
bool SexyApp::Validate(const std::string& theUserName, const std::string& theRegCode)
{
	OutputDebugStringA("Sexy::SexyApp::Validate()\n");
	return true;
}

// STUB: POPCAPGAME1 0x00525960
void SexyApp::ReadFromRegistry()
{
	OutputDebugStringA("Sexy::SexyApp::ReadFromRegistry()\n");
	SexyAppBase::ReadFromRegistry();
}

// STUB: POPCAPGAME1 0x00526580
void SexyApp::WriteToRegistry()
{
	OutputDebugStringA("Sexy::SexyApp::WriteToRegistry()\n");
	SexyAppBase::WriteToRegistry();
}

// STUB: POPCAPGAME1 0x00527c70
bool SexyApp::OpenHTMLTemplate(const std::string& theTemplateFile, const DefinesMap& theDefinesMap)
{
	OutputDebugStringA("Sexy::SexyApp::OpenHTMLTemplate()\n");
	return false;
}

// STUB: POPCAPGAME1 0x005281f0
bool SexyApp::OpenRegisterPage(DefinesMap theStatsMap)
{
	OutputDebugStringA("Sexy::SexyApp::OpenRegisterPage()\n");
	return true;
}

// STUB: POPCAPGAME1 0x00524960
bool SexyApp::ShouldCheckForUpdate()
{
	OutputDebugStringA("Sexy::SexyApp::ShouldCheckForUpdate()\n");
	return false;
}

// STUB: POPCAPGAME1 0x005249d0
void SexyApp::UpdateCheckQueried()
{
	OutputDebugStringA("Sexy::SexyApp::UpdateCheckQueried()\n");
}

// STUB: POPCAPGAME1 0x00524a00
void SexyApp::URLOpenSucceeded(const std::string& theURL)
{
	OutputDebugStringA("Sexy::SexyApp::URLOpenSucceeded()\n");
	SexyAppBase::URLOpenSucceeded(theURL);
}

// STUB: POPCAPGAME1 0x005281f0
bool SexyApp::OpenRegisterPage()
{
	OutputDebugStringA("Sexy::SexyApp::OpenRegisterPage()\n");
	return true;
}

// STUB: POPCAPGAME1 0x005266b0
bool SexyApp::CheckSignature(const Buffer& theBuffer, const std::string& theFileName)
{
	OutputDebugStringA("Sexy::SexyApp::CheckSignature()\n");
	return true;
}

void SexyApp::PreTerminate()
{
}

void SexyApp::OpenUpdateURL()
{
	OutputDebugStringA("Sexy::SexyApp::OpenUpdateURL()\n");
}

// STUB: POPCAPGAME1 0x005269f0
void SexyApp::HandleCmdLineParam(const std::string& theParamName, const std::string& theParamValue)
{
	OutputDebugStringA("Sexy::SexyApp::HandleCmdLineParam()\n");
	SexyAppBase::HandleCmdLineParam(theParamName, theParamValue);
}

// STUB: POPCAPGAME1 0x00526d80
std::string SexyApp::GetGameSEHInfo()
{
	OutputDebugStringA("Sexy::SexyApp::GetGameSEHInfo()\n");
	return SexyAppBase::GetGameSEHInfo();
}

// STUB: POPCAPGAME1 0x00527950
void SexyApp::GetSEHWebParams(DefinesMap* theDefinesMap)
{
	OutputDebugStringA("Sexy::SexyApp::GetSEHWebParams()\n");
	SexyAppBase::GetSEHWebParams(theDefinesMap);
}

void SexyApp::PreDisplayHook()
{
}

// STUB: POPCAPGAME1 0x00527180
void SexyApp::InitPropertiesHook()
{
	LoadProperties("properties\\partner.xml", false, false);
	OutputDebugStringA("Sexy::SexyApp::InitPropertiesHook()\n");
}

// STUB: POPCAPGAME1 0x00527580
void SexyApp::Init()
{
	OutputDebugStringA("Sexy::SexyApp::Init()\n");
	SexyAppBase::Init();
}

// STUB: POPCAPGAME1 0x00524ac0
void SexyApp::UpdateFrames()
{
	SexyAppBase::UpdateFrames();
}