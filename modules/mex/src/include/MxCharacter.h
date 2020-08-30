//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include "nlsMex_exports.h"
#include "mex.h"
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    //=============================================================================
    NLSMEX_IMPEXP
    char*
    mxArrayToString(const mxArray* array_ptr);
    //=============================================================================
    NLSMEX_IMPEXP
    char*
    mxArrayToUTF8String(const mxArray* array_ptr);
    //=============================================================================
    NLSMEX_IMPEXP
    bool
    mxIsChar(const mxArray* pm);
    //=============================================================================
    NLSMEX_IMPEXP
    mxChar*
    mxGetChars(const mxArray* array_ptr);
    //=============================================================================
    NLSMEX_IMPEXP
    int
    mxGetString(const mxArray* pm, char* str, mwSize strlen);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateString(const char* str);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateCharMatrixFromStrings(mwSize m, const char** str);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateCharArray(mwSize ndim, const mwSize* dims);
    //=============================================================================
    NLSMEX_IMPEXP
    mxArray*
    mxCreateStringFromNChars(const char* str, mwSize n);
    //=============================================================================
    NLSMEX_IMPEXP
    void
    mxGetNChars(const mxArray* pa, char* buf, mwSize nChars);
//=============================================================================
#ifdef __cplusplus
}
#endif
//=============================================================================