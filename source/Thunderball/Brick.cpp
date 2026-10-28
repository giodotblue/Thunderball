#include "Brick.h"
#include "PegInfo.h"
#include "Res.h"
#include "ThunderCommon.h"

#include <SexyAppFramework/Graphics.h>
#include <SexyAppFramework/MemoryImage.h>
#include <SexyAppFramework/SexyVector.h>

using namespace Sexy;

// FUNCTION: POPCAPGAME1 0x00408db0
static __declspec(noinline) float GetDistanceSquared(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	return dx * dx + dy * dy;
}

// FUNCTION: POPCAPGAME1 0x00481bd0
Brick::Brick()
{
	mUnk0x148 = 35.0f;
	mUnk0x181 = false;
	mUnk0x14c = 30.0f;
	mUnk0x182 = false;
	mUnk0x180 = false;
	mUnk0x168 = 2;
	mUnk0x158 = 20.0f;
	mUnk0x16c = 0;
	mUnk0x15c = -90.0f;
	mUnk0x150 = 0.0f;
	mUnk0x154 = 0.0f;
	mUnk0x160 = 0.0f;
	mUnk0x164 = 0.0f;
	mUnk0x170[0] = 0;
	mUnk0x170[1] = 0;
	mUnk0x170[2] = 0;
	mUnk0x170[3] = 0;
	for (int i = 0; i < 10; i++) {
		mUnk0x4f4[i] = NULL;
	}
}

// SYNTHETIC: POPCAPGAME1 0x00483af0
// Sexy::Brick::`scalar deleting destructor'

// FUNCTION: POPCAPGAME1 0x00481d10
Brick::~Brick()
{
	for (int i = 0; i < 10; i++) {
		delete mUnk0x4f4[i];
	}
}

// STUB: POPCAPGAME1 0x00487970
bool Brick::EditGetSetValHook(std::string* param_1, bool param_2)
{
	return false;
}

// FUNCTION: POPCAPGAME1 0x00488030
void Brick::SyncState(DataSync& theSync)
{
	Poly::SyncCommon(theSync, PhysObj::mSyncType == 3);
	if (theSync.mReader != NULL) {
		mUnk0x16c = 0;
		mUnk0x158 = 20.0f;
		mUnk0x168 = 2;
		mUnk0x164 = 0;
		mUnk0x160 = 0;
	}

	bool local_24 = mUnk0x16c != 0;
	bool local_1e = (mUnk0x168 == 2 || mUnk0x16c == 5) ? false : true;
	bool local_1f = mUnk0x150 != 0.0f;
	bool local_20 = mUnk0x154 != 0.0f;
	bool local_21 = mUnk0x16c != 5;
	bool local_22 = mUnk0x158 != 20.0f;
	bool local_23 = mUnk0x160 != 0.0f;
	bool local_25 = mUnk0x164 != 0.0f;
	theSync.SyncBoolBit(mUnk0x12d);
	theSync.SyncBoolBit(mUnk0x12e);
	theSync.SyncBoolBit(local_24);
	theSync.SyncBoolBit(local_1e);
	theSync.SyncBoolBit(local_21);
	theSync.SyncBoolBit(local_1f);
	theSync.SyncBoolBit(local_20);
	theSync.SyncBoolBit(local_22);
	theSync.EndBit();

	theSync.SyncBoolBit(local_23);
	theSync.SyncBoolBit(local_25);
	theSync.SyncBoolBit(mUnk0x12c);
	theSync.EndBit();

	if (local_23) {
		theSync.SyncFloat(mUnk0x160);
	}

	if (local_25) {
		theSync.SyncFloat(mUnk0x164);
	}

	if (local_24) {
		theSync.SyncByte(mUnk0x16c);
	}

	if (local_1e) {
		theSync.SyncByte(mUnk0x168);
	}

	if (local_1f) {
		theSync.SyncFloat(mUnk0x150);
	}

	// twice LMAO
	if (local_20) {
		theSync.SyncFloat(mUnk0x154);
		theSync.SyncFloat(mUnk0x154);
	}

	if (local_21) {
		theSync.SyncFloat(mUnk0x14c);
	}

	if (local_22) {
		theSync.SyncFloat(mUnk0x158);
	}

	theSync.SyncFloat(mUnk0x148);
	theSync.SyncFloat(mUnk0x15c);

	for (int i = 0; i < 4; i++) {
		theSync.SyncByte(mUnk0x170[i]);
	}

	if (theSync.mReader != NULL && mSyncType != 3) {
		InitFromParams();
	}
}

// FUNCTION: POPCAPGAME1 0x00481d00
int Brick::GetClass()
{
	return 6;
}

// FUNCTION: POPCAPGAME1 0x0047dea0
void Brick::EditGetDragMode(float param_1, float param_2)
{
	SexyVector2 corners[4];
	if (!GetCorners(corners)) {
		return;
	}

	if (mUnk0x181 && mUnk0x182) {
		return;
	}
	if (mUnk0x181 || mUnk0x182) {
		mUnk0xd8 = -2;
	}
	else {
		mUnk0xd8 = GetDistanceSquared(param_1, param_2, mUnk0x114, mUnk0x118) <= 100.0 ? -1 : 0;
	}
}

// FUNCTION: POPCAPGAME1 0x004878c0
void Brick::EditDoPointDrag(float param_1, float param_2)
{
	if (mUnk0xd8 == -2) {
		bool stretchX = mUnk0x16c != 5;
		AnchoredStretch((int)param_1, (int)param_2, stretchX, !stretchX);
		return;
	}

	float oldX = mUnk0x114;
	float oldY = mUnk0x118;
	Poly::EditDoPointDrag(param_1, param_2);
	mUnk0x160 += mUnk0x114 - oldX;
	mUnk0x164 += mUnk0x118 - oldY;
}

// FUNCTION: POPCAPGAME1 0x00486a10
void Brick::EditReflect(float param_1, float param_2, bool param_3, bool param_4)
{
	PhysObj::EditReflect(param_1, param_2, param_3, param_4);
	if (param_4) {
		if (param_3) {
			mUnk0x15c = NormalizeAngle(180.0f - mUnk0x15c);
		}
		else {
			mUnk0x15c = 360.0f - mUnk0x15c;
		}
		InitFromParams();
	}
}

// FUNCTION: POPCAPGAME1 0x00483d70
void Brick::Draw(Graphics* g)
{
	if (mPegInfo != NULL) {
		mPegInfo->DrawBrick(this, g);
	}
	else {
		Poly::Draw(g);
	}
}

// FUNCTION: POPCAPGAME1 0x00483b30
void Brick::DrawShadow(Graphics* g)
{
	if (mOutlineMode == 2) {
		return;
	}
	if (mPegInfo == NULL || mPegInfo->mPegType == NONE) {
		Poly::DrawShadow(g);
		return;
	}

	if (g->mIs3D || (mUnk0x11c == 0.0f && !mUnk0x2e)) {
		int image = mPegInfo->mPegType - 1;
		if (g->mIs3D) {
			g->SetColorizeImages(true);
			g->SetColor(Color(
				0,
				ModVal(0, "SEXY_SEXYMODVALc:\\gamesrc\\cpp\\thunderball\\Brick.cpp14,1025", 0x90)));
		}
		else if (ModVal(0, "SEXY_SEXYMODVALc:\\gamesrc\\cpp\\thunderball\\Brick.cpp15,1027", true)) {
			g->SetColorizeImages(true);
			g->SetColor(Color(
				0,
				ModVal(0, "SEXY_SEXYMODVALc:\\gamesrc\\cpp\\thunderball\\Brick.cpp16,1030", 0x90)));
		}
		else {
			if (mUnk0x4f4[9] == NULL) {
				CreateImage(image);
				Image* source = mUnk0x4f4[image];
				MemoryImage* shadow = new MemoryImage();
				shadow->Create(source->mWidth, source->mHeight);
				shadow->SetImageMode(true, true);

				Graphics imageGraphics(shadow);
				imageGraphics.SetColor(Color(0));
				imageGraphics.SetColorizeImages(true);
				imageGraphics.DrawImage(source, 0, 0);
				g->SetColor(Color(0xffffff));

				mUnk0x4f4[9] = shadow;
				mUnk0x184[9].Create(shadow);
			}
			image = 9;
		}

		g->Translate(-3, 3);
		DrawBrick(g, image);
		g->Translate(3, -3);
		g->SetColorizeImages(false);
	}

	mPegInfo->DrawGlow(this, g);
}

// FUNCTION: POPCAPGAME1 0x00483b20
void Brick::PegChangedHook(bool param_1)
{
	CreateImage();
}

// FUNCTION: POPCAPGAME1 0x00477ba0
void Brick::DeleteImage()
{
	PhysObj::DeleteImage();
	for (int i = 0; i < 10; i++) {
		delete mUnk0x4f4[i];
		mUnk0x4f4[i] = NULL;
		mUnk0x184[i].DeleteImages();
	}
}

// FUNCTION: POPCAPGAME1 0x00482800
void Brick::EditReloadImage()
{
	CreateImage();
}

// FUNCTION: POPCAPGAME1 0x00477b80
Image* Brick::GetTextureImage()
{
	return mPegInfo != NULL ? IMAGE_BRICK : NULL;
}

// FUNCTION: POPCAPGAME1 0x0047db90
bool Brick::GetCorners(SexyVector2* param_1)
{
	EnsureLines();
	for (int i = 0; i < 4; i++) {
		if (mUnk0x170[i] >= (int)mUnk0x108.size()) {
			return false;
		}
		Line* line = mUnk0x108[mUnk0x170[i]];
		param_1[i] = SexyVector2(line->mUnk0xec, line->mUnk0xf4);
	}
	return true;
}

// STUB: POPCAPGAME1 0x00481db0
void Brick::CreateImage(int param_1)
{
}

// FUNCTION: POPCAPGAME1 0x004827d0
void Brick::CreateImage()
{
	if (mPegInfo == NULL) {
		LoadImage();
		return;
	}

	int image = mPegInfo->mPegType - 1;
	if (image < 0 || image >= 4) {
		image = 0;
	}
	if (mPegInfo->mUnk0x14) {
		image += 4;
	}
	CreateImage(image);
}

// FUNCTION: POPCAPGAME1 0x00482810
void Brick::DrawBrick(Graphics* g, int param_2)
{
	CreateImage(param_2);
	MemoryImage* image = static_cast<MemoryImage*>(mUnk0x4f4[param_2]);
	if (!g->mIs3D && mUnk0x11c == 0.0f && !mUnk0x2e &&
		ModVal(0, "SEXY_SEXYMODVALc:\\gamesrc\\cpp\\thunderball\\Brick.cpp13,997", true)) {
		mUnk0x184[param_2].Draw(
			g,
			mUnk0x114 + mUnk0xb8 - image->mWidth / 2,
			mUnk0x118 + mUnk0xbc - image->mHeight / 2);
		return;
	}

	DrawImage(g, image, mUnk0x114, mUnk0x118, mUnk0x128, g->mIs3D || mUnk0x2e, false);
}

// STUB: POPCAPGAME1 0x00485670
void Brick::InitFromParams()
{
}

// STUB: POPCAPGAME1 0x00486320
void Brick::CommonAttach(SexyVector2* param_1, SexyVector2* param_2, bool param_3, bool param_4)
{
}

// STUB: POPCAPGAME1 0x00486590
void Brick::AnchoredInit()
{
}

// STUB: POPCAPGAME1 0x00486630
void Brick::AnchoredStretch(int param_1, int param_2, bool param_3, bool param_4)
{
}

// STUB: POPCAPGAME1 0x004868b0
int Brick::AttachTo(Sexy::Brick* param_1, int param_2, int param_3, bool param_4)
{
	return 0;
}
