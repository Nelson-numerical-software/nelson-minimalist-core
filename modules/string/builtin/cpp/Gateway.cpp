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
#include "NelsonGateway.hpp"
#include "charBuiltin.hpp"
#include "containsBuiltin.hpp"
#include "countBuiltin.hpp"
#include "endsWithBuiltin.hpp"
#include "int2strBuiltin.hpp"
#include "mat2strBuiltin.hpp"
#include "replaceBuiltin.hpp"
#include "sprintfBuiltin.hpp"
#include "startsWithBuiltin.hpp"
#include "str2doubleBuiltin.hpp"
#include "strcmpBuiltin.hpp"
#include "strfindBuiltin.hpp"
#include "strlengthBuiltin.hpp"
#include "strncmpBuiltin.hpp"
#include "strrepBuiltin.hpp"
#include "tolowerBuiltin.hpp"
#include "toupperBuiltin.hpp"
#include "strtrimBuiltin.hpp"
#include "stringBuiltin.hpp"
#include "stringsBuiltin.hpp"
#include "deblankBuiltin.hpp"
#include "convertStringsToCharsBuiltin.hpp"
#include "convertCharsToStringsBuiltin.hpp"
#include "blanksBuiltin.hpp"
#include "matchesBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"string";
//=============================================================================
static const nlsGateway gateway[] = {
    { "char", (void*)Nelson::StringGateway::charBuiltin, 1, -1, CPP_BUILTIN_WITH_EVALUATOR },
    { "strcmp", (void*)Nelson::StringGateway::strcmpBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "strcmpi", (void*)Nelson::StringGateway::strcmpiBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "strncmp", (void*)Nelson::StringGateway::strncmpBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "strncmpi", (void*)Nelson::StringGateway::strncmpiBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "matches", (void*)Nelson::StringGateway::matchesBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "tolower", (void*)Nelson::StringGateway::tolowerBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "lower", (void*)Nelson::StringGateway::tolowerBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "toupper", (void*)Nelson::StringGateway::toupperBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "upper", (void*)Nelson::StringGateway::toupperBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "strfind", (void*)Nelson::StringGateway::strfindBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "sprintf", (void*)Nelson::StringGateway::sprintfBuiltin, 2, -1, CPP_BUILTIN_WITH_EVALUATOR },
    { "int2str", (void*)Nelson::StringGateway::int2strBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "str2double", (void*)Nelson::StringGateway::str2doubleBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "mat2str", (void*)Nelson::StringGateway::mat2strBuiltin, 1, -2, CPP_BUILTIN_WITH_EVALUATOR },
    { "startsWith", (void*)Nelson::StringGateway::startsWithBuiltin, 1, -3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "endsWith", (void*)Nelson::StringGateway::endsWithBuiltin, 1, -3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "contains", (void*)Nelson::StringGateway::containsBuiltin, 1, -3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "count", (void*)Nelson::StringGateway::countBuiltin, 1, -3, CPP_BUILTIN_WITH_EVALUATOR },
    { "strrep", (void*)Nelson::StringGateway::strrepBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "replace", (void*)Nelson::StringGateway::replaceBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "strtrim", (void*)Nelson::StringGateway::strtrimBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "deblank", (void*)Nelson::StringGateway::deblankBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "strlength", (void*)Nelson::StringGateway::strlengthBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "string", (void*)Nelson::StringGateway::stringBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "strings", (void*)Nelson::StringGateway::stringsBuiltin, 1, -1, CPP_BUILTIN_WITH_EVALUATOR },
    { "convertStringsToChars", (void*)Nelson::StringGateway::convertStringsToCharsBuiltin, -1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "convertCharsToStrings", (void*)Nelson::StringGateway::convertCharsToStringsBuiltin, -1, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "blanks", (void*)Nelson::StringGateway::blanksBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },

};
//=============================================================================
NLSGATEWAYFUNC(gateway)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVE(gateway)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
