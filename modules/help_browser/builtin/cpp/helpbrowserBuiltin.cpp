//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "helpbrowserBuiltin.hpp"
#include "Error.hpp"
#include "HelpBrowser.hpp"
#include "ToCellString.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::HelpBrowserGateway::helpbrowserBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    if (argIn.size() == 0) {
        nargoutcheck(nLhs, 0, 0);
        std::wstring msg;
        if (!HelpBrowser::getInstance()->startBrowser(msg)) {
            Error(msg);
        }
    } else if (argIn.size() == 1) {
        std::wstring param1 = argIn[0].getContentAsWideString();
        if (param1 == L"-attributes") {
            nargoutcheck(nLhs, 0, 1);
            ArrayOfVector retval;
            retval << ToCellStringAsColumn(HelpBrowser::getInstance()->getAttributes());
            return retval;
        } else if (param1 == L"-close") {
            nargoutcheck(nLhs, 0, 0);
            HelpBrowser::getInstance()->closeBrowser();
        } else if (param1 == L"-clearcache") {
            nargoutcheck(nLhs, 0, 0);
            HelpBrowser::getInstance()->clearCache();
        } else if (param1 == L"-isavailable") {
            nargoutcheck(nLhs, 0, 1);
            ArrayOfVector retval;
            retval << ArrayOf::logicalConstructor(HelpBrowser::getInstance()->isAvailable());
            return retval;
        } else if (param1 == L"-sync") {
            nargoutcheck(nLhs, 0, 0);
            HelpBrowser::getInstance()->syncBrowser();
        } else {
            Error(ERROR_WRONG_ARGUMENT_1_VALUE);
        }
    } else if (argIn.size() == 2) {
        nargoutcheck(nLhs, 0, 0);
        std::wstring param1 = argIn[0].getContentAsWideString();
        if (param1 == L"-register") {
            wstringVector param2 = argIn[1].getContentAsWideStringVector(true);
            HelpBrowser::getInstance()->registerHelpFiles(param2);
        } else if (param1 == L"-unregister") {
            wstringVector param2 = argIn[1].getContentAsWideStringVector(true);
            HelpBrowser::getInstance()->unregisterHelpFiles(param2);
        } else if (param1 == L"-name") {
            std::wstring param2 = argIn[1].getContentAsWideString();
            HelpBrowser::getInstance()->showDocByName(param2);
        } else if (param1 == L"-identifier") {
            std::wstring param2 = argIn[1].getContentAsWideString();
            HelpBrowser::getInstance()->showDocByIdentifier(param2);
        } else if (param1 == L"-show") {
            std::wstring param2 = argIn[1].getContentAsWideString();
            if ((param2 == L"contents") || (param2 == L"index") || (param2 == L"bookmarks")
                || (param2 == L"search")) {
                std::wstring command = L"show " + param2;
                HelpBrowser::getInstance()->sendCommand(command);
            } else {
                Error(ERROR_WRONG_ARGUMENT_2_VALUE);
            }
        } else if (param1 == L"-hide") {
            std::wstring param2 = argIn[1].getContentAsWideString();
            if ((param2 == L"contents") || (param2 == L"index") || (param2 == L"bookmarks")
                || (param2 == L"search")) {
                std::wstring command = L"hide " + param2;
                HelpBrowser::getInstance()->sendCommand(command);
            } else {
                Error(ERROR_WRONG_ARGUMENT_2_VALUE);
            }
        } else if (param1 == L"-setsource") {
            std::wstring param2 = argIn[1].getContentAsWideString();
            std::wstring command = L"setSource " + param2;
            HelpBrowser::getInstance()->sendCommand(command);
        } else {
            Error(ERROR_WRONG_ARGUMENT_1_VALUE);
        }
    }
    ArrayOfVector retval;
    return retval;
}
//=============================================================================
