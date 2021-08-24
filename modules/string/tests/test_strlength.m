%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% This program is free software; you can redistribute it and/or
% modify it under the terms of the GNU Lesser General Public
% License as published by the Free Software Foundation; either
% version 2.1 of the License, or (at your option) any later version.
%
% Alternatively, you can redistribute it and/or
% modify it under the terms of the GNU General Public License as
% published by the Free Software Foundation; either version 2 of
% the License, or (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Lesser General Public
% License along with this program. If not, see <http://www.gnu.org/licenses/>.
% LICENCE_BLOCK_END
%=============================================================================
assert_isequal(nargin('strlength'), 1);
assert_isequal(nargout('strlength'), 1);
%=============================================================================
c = 'Hello, Mad World';
res = strlength(c);
ref = 16;
assert_isequal(res, ref);
%=============================================================================
c = {'Hello, Mad World'};
res = strlength(c);
ref = 16;
assert_isequal(res, ref);
%=============================================================================
c = {''};
res = strlength(c);
ref = 0;
assert_isequal(res, ref);
%=============================================================================
c = '';
res = strlength(c);
ref = 0;
assert_isequal(res, ref);
%=============================================================================
c = {};
res = strlength(c);
ref = [];
assert_isequal(res, ref);
%=============================================================================
c = {'abs.docx','data.gz';'code.nlf','results.nlf'};
res = strlength(c);
ref = [8 7; 8 11];
assert_isequal(res, ref);
%=============================================================================
cmd = 'res = strlength(1)';
assert_checkerror(cmd, _('Wrong type for argument #1: string or cell expected.'));
%=============================================================================
B = ["Nel", NaN, "son"; "is", "open", "source"];
R = strlength(B);
REF = [3   NaN     3;    2     4     6];
assert_isequal(R, REF);
%=============================================================================