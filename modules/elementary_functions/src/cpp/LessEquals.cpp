//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include "LessEquals.hpp"
#include "RelationOperator.hpp"
#include "complex_abs.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
logical
realComparatorLessEquals(const ArrayOf& A, const ArrayOf& B, indexType idxA, indexType idxB)
{
    switch (A.getDataClass()) {
    case NLS_LOGICAL: {
        logical* ptrA = (logical*)A.getDataPointer();
        logical* ptrB = (logical*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_UINT8: {
        uint8* ptrA = (uint8*)A.getDataPointer();
        uint8* ptrB = (uint8*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_INT8: {
        int8* ptrA = (int8*)A.getDataPointer();
        int8* ptrB = (int8*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_UINT16: {
        uint16* ptrA = (uint16*)A.getDataPointer();
        uint16* ptrB = (uint16*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_INT16: {
        int16* ptrA = (int16*)A.getDataPointer();
        int16* ptrB = (int16*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_UINT32: {
        uint32* ptrA = (uint32*)A.getDataPointer();
        uint32* ptrB = (uint32*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_INT32: {
        int32* ptrA = (int32*)A.getDataPointer();
        int32* ptrB = (int32*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_UINT64: {
        uint64* ptrA = (uint64*)A.getDataPointer();
        uint64* ptrB = (uint64*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_INT64: {
        int64* ptrA = (int64*)A.getDataPointer();
        int64* ptrB = (int64*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_SINGLE: {
        single* ptrA = (single*)A.getDataPointer();
        single* ptrB = (single*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_DOUBLE: {
        double* ptrA = (double*)A.getDataPointer();
        double* ptrB = (double*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    case NLS_CHAR: {
        charType* ptrA = (charType*)A.getDataPointer();
        charType* ptrB = (charType*)B.getDataPointer();
        return (ptrA[idxA] <= ptrB[idxB]);
    } break;
    }
    return false;
}
//=============================================================================
logical
complexComparatorLessEquals(const ArrayOf& A, const ArrayOf& B, indexType idxA, indexType idxB)
{
    switch (A.getDataClass()) {
    case NLS_SCOMPLEX: {
        single* ptrA = (single*)A.getDataPointer();
        single* ptrB = (single*)B.getDataPointer();
        return complex_abs<single>(ptrA[2 * idxA], ptrA[2 * idxA + 1])
            <= complex_abs<single>(ptrB[2 * idxB], ptrB[2 * idxB + 1]);
    } break;
    case NLS_DCOMPLEX: {
        double* ptrA = (double*)A.getDataPointer();
        double* ptrB = (double*)B.getDataPointer();
        return complex_abs<double>(ptrA[2 * idxA], ptrA[2 * idxA + 1])
            <= complex_abs<double>(ptrB[2 * idxB], ptrB[2 * idxB + 1]);
    } break;
    }
    return false;
}
//=============================================================================
logical
stringArrayComparatorLessEquals(const ArrayOf& A, const ArrayOf& B, indexType idxA, indexType idxB)
{
    if (A.getDataClass() == NLS_STRING_ARRAY) {
        ArrayOf* ptrA = (ArrayOf*)A.getDataPointer();
        ArrayOf* ptrB = (ArrayOf*)B.getDataPointer();
        if (ptrA[idxA].isCharacterArray() && ptrB[idxB].isCharacterArray()) {
            return ptrA[idxA].getContentAsWideString() <= ptrB[idxB].getContentAsWideString();
        }
    }
    return false;
}
//=============================================================================
ArrayOf
LessEquals(ArrayOf& A, ArrayOf& B, bool& needToOverload)
{
    needToOverload = false;
    return relationOperator(A, B, L"<=", &realComparatorLessEquals, &complexComparatorLessEquals,
        &stringArrayComparatorLessEquals, needToOverload);
}
//=============================================================================
}
//=============================================================================
