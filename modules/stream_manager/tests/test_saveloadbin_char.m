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
addpath([fileparts(nfilename('fullpathext'), 'path'), '/loadsavebin']);
%=============================================================================
% unicode characters
A = 'NelSon 象形字';
savebin([tempdir(), 'test_saveload_char.bin'], 'A');
REF = A;
clear A;
loadbin([tempdir(), 'test_saveload_char.bin']);
assert_isequal(A, REF);
%=============================================================================
% unicode
A = ['NelSon';
'is    ';
'not   ';
'LensOn'];
savebin([tempdir(), 'test_saveload_char.bin'], 'A');
REF = A;
clear A;
loadbin([tempdir(), 'test_saveload_char.bin']);
assert_isequal(A, REF);
%=============================================================================
% nd array char
A = ones(3, 4, 6);
A = char(A);
savebin([tempdir(), 'test_saveload_char.bin'], 'A');
REF = A;
clear A;
loadbin([tempdir(), 'test_saveload_char.bin']);
assert_isequal(A, REF);
%=============================================================================