%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('atand'), -1);
assert_isequal(nargout('atand'), 1);
%=============================================================================
x = [1 0 -1 0];
y = [0 1 0 -1];
R = atan2d(y, x);
REF = [     0    90   180   -90];
assert_isequal(R, REF);
%=============================================================================
