#include "ImageMgr.h"
#include "SexyAppFramework/Common.h"
#include "ThunderballApp.h"

#include <SexyAppFramework/Image.h>
#include <SexyAppFramework/DDImage.h>
#include <SexyAppFramework/MemoryImage.h>
#include <SexyAppFramework/SexyApp.h>

using namespace Sexy;

// FUNCTION: POPCAPGAME1 0x00464960
ImageMgr::ImageMgr()
{
}

// SYNTHETIC: POPCAPGAME1 0x00464a00
// Sexy::ImageMgr::`scalar deleting destructor'

// FUNCTION: POPCAPGAME1 0x00461020
ImageMgr::~ImageMgr()
{
}

// FUNCTION: POPCAPGAME1 0x0044b580
void ImageMgr::AddDeleteImage(Image* theImage)
{
	if (theImage != NULL) {
		mDeleteImages.insert(theImage);
	}
}

// TEMPLATE: POPCAPGAME1 0x0050ee50
// std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,bool,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,bool> >,0> >::_Erase

// TEMPLATE: POPCAPGAME1 0x00409450
// std::_Tree<std::_Tset_traits<Sexy::MemoryImage *,std::less<Sexy::MemoryImage *>,std::allocator<Sexy::MemoryImage *>,0> >::_Erase

// FUNCTION: POPCAPGAME1 0x00457610
void ImageMgr::Clear()
{
	for (std::map<std::string, MemoryImage*>::iterator it = mImages.begin(); it != mImages.end(); ++it) {
		delete it->second;
	}
	for (std::set<Image*>::iterator it = mDeleteImages.begin(); it != mDeleteImages.end(); ++it) {
		delete *it;
	}
	mImages.clear();
	mDeleteImages.clear();
}

// TEMPLATE: POPCAPGAME1 0x00452bf0
// std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Sexy::ResourceManager::BaseRes *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Sexy::ResourceManager::BaseRes *> >,0> >::insert(struct std::pair<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const, int> const &)

// FUNCTION: POPCAPGAME1 0x00457760
MemoryImage* ImageMgr::GetImage(const std::string& theName, bool* param_2, bool param_3)
{
	std::pair<std::map<std::string, MemoryImage*>::iterator, bool> anImage = 
        mImages.insert(std::map<std::string, MemoryImage*>::value_type(theName, (MemoryImage*)NULL));

	std::map<std::string, MemoryImage*>::iterator it = anImage.first;

	if (it->second == NULL) {
		if (param_3) {
			it->second = GetThunderballApp()->GetImage(theName, param_3);
		  
			if (param_2 != NULL) {
				*param_2 = false;
			}
		} else {
			if (param_2 != NULL) {
				*param_2 = true;
			}
		}
	} else {
		if (param_2 != NULL) {
			*param_2 = false;
		}
	}

	return it->second;

}

// FUNCTION: POPCAPGAME1 0x0045c560
void ImageMgr::PutImage(std::string* theName, MemoryImage* theImage, bool param_3)
{
	MemoryImage*& anOldImage = mImages[*theName];
	if (anOldImage != theImage) {
		if (param_3 && anOldImage != NULL) {
			delete anOldImage;
		}
		anOldImage = theImage;
	}
}
