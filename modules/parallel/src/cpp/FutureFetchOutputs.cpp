//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <tuple>
#include "FutureFetchOutputs.hpp"
#include "Error.hpp"
#include "NelsonConfiguration.hpp"
#include "WaitFutures.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOfVector
FutureFetchOutputs(Evaluator* eval, FevalFutureObject* fevalFutureObject)
{
    ArrayOfVector result;
    WaitFinishedOrFailedFuture(eval, fevalFutureObject);
    bool valid = false;
    std::tuple<ArrayOfVector, Exception> resultOrFuture = fevalFutureObject->get(valid);
    result = std::get<0>(resultOrFuture);
    Exception e = std::get<1>(resultOrFuture);
    if (!e.getMessage().empty()) {
        std::wstring errorMessage
            = _W("One or more futures resulted in an error.") + L"\n\n" + e.getMessage();
        Error(errorMessage, L"Nelson:parallel:future:ExecutionError");
    }
    return result;
}
//=============================================================================
}
//=============================================================================
