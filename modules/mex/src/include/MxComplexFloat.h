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
#include "MxTypes.h"
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    //=============================================================================
    NLSMEX_IMPEXP
    mxDouble*
    mxGetPiSeparatedComplex(const mxArray* pm);
    //=============================================================================
    NLSMEX_IMPEXP
    void
    mxSetPiSeparatedComplex(mxArray* pm, double* pr);
    //=============================================================================
    NLSMEX_IMPEXP
    mxDouble*
    mxGetPiInterleavedComplex(const mxArray* pm);
    //=============================================================================
    NLSMEX_IMPEXP
    void
    mxSetPiInterleavedComplex(mxArray* pm, double* pr);
    //=============================================================================
    NLSMEX_IMPEXP
    void*
    mxGetImagDataSeparatedComplex(const mxArray* pm);
    //=============================================================================
    NLSMEX_IMPEXP
    void
    mxSetImagDataSeparatedComplex(mxArray* pm, void* pi);
    //=============================================================================
#ifdef MX_HAS_INTERLEAVED_COMPLEX
#define mxGetPi mxGetPiInterleavedComplex
#define mxSetPi mxSetPiInterleavedComplex
#else
#define mxGetPi mxGetPiSeparatedComplex
#define mxSetPi mxSetPiSeparatedComplex
#define mxGetImagData mxGetImagDataSeparatedComplex
#define mxSetImagData mxSetImagDataSeparatedComplex
#endif
//=============================================================================
#ifdef __cplusplus
}
#endif
//=============================================================================