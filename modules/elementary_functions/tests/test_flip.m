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
A = 'no word, no bond, row on.';
B = flip(A);
assert_isequal(B, '.no wor ,dnob on ,drow on');
%=============================================================================
A = eye(2, 3);
B = flip(A, 1);
REF = [ 0     1     0;1     0     0];
assert_isequal(B, REF);
%=============================================================================
B = flip(A, 2);
REF = [ 0     0     1;0     1     0];
assert_isequal(B, REF);
%=============================================================================
B = flip(A, 3);
REF = [1     0     0;0     1     0];
assert_isequal(B, REF);
%=============================================================================
A = [];
A(1:2,1:2,1) = [5 6; 7 8];
A(1:2,1:2,2) = [1 2; 3 4];
B = flip(A, 1);
REF = [];
REF(1:2,1:2,1) = [7 8;5 6];
REF(1:2,1:2,2) = [3 4;1 2];
assert_isequal(B, REF);
%=============================================================================
A = [];
A(1:2,1:2,1) = [5 6; 7 8];
A(1:2,1:2,2) = [1 2; 3 4];
B = flip(A, 2);
REF = [];
REF(1:2,1:2,1) = [6 5;8 7];
REF(1:2,1:2,2) = [2 1;4 3];
assert_isequal(B, REF);
%=============================================================================
A = [];
A(1:2,1:2,1) = [5 6; 7 8];
A(1:2,1:2,2) = [1 2; 3 4];
B = flip(A, 3);
REF = [];
REF(1:2,1:2,1) = [1 2;3 4];
REF(1:2,1:2,2) = [5 6;7 8];
assert_isequal(B, REF);
%=============================================================================
A = [];
A(1:2,1:2,1) = [5 6; 7 8];
A(1:2,1:2,2) = [1 2; 3 4];
B = flip(A);
REF = flip(A, 1);
assert_isequal(B, REF);
%=============================================================================