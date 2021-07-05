// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

#include <Windows.h>
#include <string>

#include "../../lsMisc/CreateFolderIniPath.h"
#include "../../lsMisc/CreateCompleteDirectory.h"
#include "../../lsMisc/UTF16toUTF8.h"
#include "../../lsMisc/OpenCommon.h"
#include "../../lsMisc/stdosd/stdosd.h"
#include "../../profile/cpp/Profile/include/ambiesoft.profile.h"

#define I18N(s) (s)

const wchar_t STR_BARNDIRECTORYNAME[] = L"barn";
const char SECTION_OPTION[] = "Option";
const char KEY_BARNFOLDER[] = "BarnFolder";
#endif //PCH_H
