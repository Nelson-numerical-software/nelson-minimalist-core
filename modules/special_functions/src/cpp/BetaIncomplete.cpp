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
#include <Eigen/Dense>
#include <boost/math/special_functions/beta.hpp>
#include "nlsConfig.h"
#include "BetaIncomplete.hpp"
#include "Error.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
inline Dimensions
maxDimensions(Dimensions& a, Dimensions& b)
{
    Dimensions ret;
    for (unsigned int i = 0; i < std::min(a.getLength(), b.getLength()); i++) {
        ret[i] = (a.getAt(i, false) > b.getAt(i, false)) ? a.getAt(i, false) : b.getAt(i, false);
    }
    return ret;
}
//=============================================================================
template <class T>
ArrayOf
BetaIncomplete(const Dimensions& retDims, Class destinationType, indexType maxLen, const ArrayOf& X,
    const ArrayOf& Y, const ArrayOf& Z, bool isLower)
{
    T* result = (T*)ArrayOf::allocateArrayOf(
        destinationType, retDims.getElementCount(), stringVector(), false);
    ArrayOf res = ArrayOf(destinationType, retDims, result);
    auto* ptrX = (T*)X.getDataPointer();
    auto* ptrY = (T*)Y.getDataPointer();
    auto* ptrZ = (T*)Z.getDataPointer();
    bool fails = false;
    if (isLower) {
#if defined(_NLS_WITH_OPENMP)
#pragma omp parallel for
#endif
        for (ompIndexType i = 0; i < (ompIndexType)maxLen; ++i) {
            T x = (X.isScalar()) ? ptrX[0] : ptrX[i];
            T y = (Y.isScalar()) ? ptrY[0] : ptrY[i];
            T z = (Z.isScalar()) ? ptrZ[0] : ptrZ[i];
            try {
                result[i] = boost::math::ibeta(y, z, x);
            } catch (...) {
                fails = true;
            }
        }
    } else {
#if defined(_NLS_WITH_OPENMP)
#pragma omp parallel for
#endif
        for (ompIndexType i = 0; i < (ompIndexType)maxLen; ++i) {
            T x = (X.isScalar()) ? ptrX[0] : ptrX[i];
            T y = (Y.isScalar()) ? ptrY[0] : ptrY[i];
            T z = (Z.isScalar()) ? ptrZ[0] : ptrZ[i];
            try {
                result[i] = 1 - boost::math::ibeta(y, z, x);
            } catch (...) {
                fails = true;
            }
        }
    }
    if (fails) {
        Error(_("Error evaluating betainc."));
    }
    return res;
}
//=============================================================================
ArrayOf
BetaIncomplete(
    const ArrayOf& X, const ArrayOf& Y, const ArrayOf& Z, bool isLower, bool& needOverload)
{
    ArrayOf res;
    if (X.getDataClass() == NLS_DOUBLE || X.getDataClass() == NLS_SINGLE && !X.isSparse()) {
        needOverload = false;
    } else {
        needOverload = true;
        return res;
    }
    if (Y.getDataClass() == NLS_DOUBLE || Y.getDataClass() == NLS_SINGLE && !Y.isSparse()) {
        needOverload = false;
    } else {
        needOverload = true;
        return res;
    }
    if (Z.getDataClass() == NLS_DOUBLE || Z.getDataClass() == NLS_SINGLE && !Z.isSparse()) {
        needOverload = false;
    } else {
        needOverload = true;
        return res;
    }
    indexType maxLen = std::max(X.getLength(), std::max(Y.getLength(), Z.getLength()));
    Dimensions dimsX = X.getDimensions();
    Dimensions dimsY = Y.getDimensions();
    Dimensions dimsZ = Z.getDimensions();
    Dimensions dimsMaxYZ = maxDimensions(dimsY, dimsZ);
    Dimensions retDims = maxDimensions(dimsX, dimsMaxYZ);
    if (!(X.isScalar()) && !retDims.equals(X.getDimensions())) {
        Error(_("Wrong size for #1 argument."));
    }
    if (!(Y.isScalar()) && !retDims.equals(Y.getDimensions())) {
        Error(_("Wrong size for #2 argument."));
    }
    if (!(Z.isScalar()) && !retDims.equals(Z.getDimensions())) {
        Error(_("Wrong size for #3 argument."));
    }
    if (!Y.isPositive()) {
        Error(_("Wrong value for #2 argument. positive value expected."));
    }
    if (!Z.isPositive()) {
        Error(_("Wrong value for #3 argument. positive value expected."));
    }
    if (X.getDataClass() == NLS_DOUBLE) {
        ArrayOf YY(Y);
        ArrayOf ZZ(Z);
        YY.promoteType(NLS_DOUBLE);
        ZZ.promoteType(NLS_DOUBLE);

        Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>> matX(
            (double*)X.getDataPointer(), 1, dimsX.getElementCount());
        bool isBetween0and1 = ((matX.array() >= 0).all() && (matX.array() <= 1).all());
        if (!isBetween0and1) {
            Error(_("Wrong value for #1 argument. [0, 1] values expected."));
        }
        res = BetaIncomplete<double>(retDims, NLS_DOUBLE, maxLen, X, YY, ZZ, isLower);
    } else if (X.getDataClass() == NLS_SINGLE) {
        ArrayOf YY(Y);
        ArrayOf ZZ(Z);
        YY.promoteType(NLS_SINGLE);
        ZZ.promoteType(NLS_SINGLE);

        Eigen::Map<Eigen::Matrix<single, Eigen::Dynamic, Eigen::Dynamic>> matX(
            (single*)X.getDataPointer(), 1, dimsX.getElementCount());
        bool isBetween0and1 = ((matX.array() >= 0).all() && (matX.array() <= 1).all());
        if (!isBetween0and1) {
            Error(_("Wrong value for #1 argument. [0, 1] values expected."));
        }
        res = BetaIncomplete<single>(retDims, NLS_SINGLE, maxLen, X, YY, ZZ, isLower);
    } else {
        needOverload = true;
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================