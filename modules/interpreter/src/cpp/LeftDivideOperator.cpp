//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "ArrayOf.hpp"
#include "Evaluator.hpp"
#include "OverloadBinaryOperator.hpp"
#include "LeftDivide.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
Evaluator::leftDivideOperator(AbstractSyntaxTreePtr t)
{
    callstack.pushID((size_t)t->getContext());
    ArrayOf retval = this->leftDivideOperator(expression(t->down), expression(t->down->right));
    callstack.popID();
    return retval;
}
//=============================================================================
ArrayOf
Evaluator::leftDivideOperator(const ArrayOf& A, const ArrayOf& B)
{
    ArrayOf res;
    bool bSuccess = false;
    if ((overloadOnBasicTypes || needToOverloadOperator(A) || needToOverloadOperator(B))
        && !isOverloadAllowed()) {
        res = OverloadBinaryOperator(this, A, B, "mldivide", bSuccess);
    }
    if (!bSuccess) {
        bool needToOverload = false;
        res = LeftDivide(A, B, needToOverload);
        if (needToOverload) {
            res = OverloadBinaryOperator(this, A, B, "mldivide");
        }
    }
    return res;
}
//=============================================================================
}
//=============================================================================
