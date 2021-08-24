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
assert_isequal(nargin('mod'), 2)
assert_isequal(nargout('mod'), 1)
%=============================================================================
R = mod(6, uint64(4));
REF = uint64(2);
assert_isequal(R, REF);
assert_isequal(class(R), 'uint64');
%=============================================================================
R = mod(uint64(6), 4);
REF = uint64(2);
assert_isequal(R, REF);
assert_isequal(class(R), 'uint64');
%=============================================================================
R = mod(uint64(6), uint64(4));
REF = uint64(2);
assert_isequal(R, REF);
assert_isequal(class(R), 'uint64');
%=============================================================================
R = mod(single([-6, 6, 0]), [4, 0, 4]);
REF = single([2 6 0]);
assert_isequal(R, REF);
assert_isequal(class(R), 'single');
%=============================================================================
R = mod([], []);
REF = [];
assert_isequal(R, REF);
assert_isequal(class(R), 'double');
%=============================================================================
R = mod(0.94, 0.01);
REF = 0;
assert_isequal(R, REF);
assert_isequal(class(R), 'double');
%=============================================================================
R = mod(66, 44);
REF = 22;
assert_isequal(R, REF);
%=============================================================================
R = mod(NaN, 44);
REF = NaN,
assert_isequal(R, REF);
%=============================================================================
R = mod(Inf, 44);
REF = NaN;
assert_isequal(R, REF);
%=============================================================================
R = mod(-Inf, 44);
REF = NaN;
assert_isequal(R, REF);
%=============================================================================
R = mod(-66, 44);
REF = 22;
assert_isequal(R, REF);
%=============================================================================
R = mod(-6, 4);
REF = 2;
assert_isequal(R, REF);
%=============================================================================
R = mod(0, 4);
REF = 0;
assert_isequal(R, REF);
%=============================================================================
R = mod([-6, 6, 0], [4, 4, 4]);
REF = [2 2 0];
assert_isequal(R, REF);
%=============================================================================
R = mod([-6; 6; 0], [4; 4; 4]);
REF = [2; 2; 0];
assert_isequal(R, REF);
%=============================================================================
R = mod([-6, 6; 0, 4], [4, 4 ; 4, 1]);
REF =  [2 2; 0 0];
assert_isequal(R, REF);
%=============================================================================
R = mod(6, 0);
REF = 6;
assert_isequal(R, REF);
%=============================================================================
R = mod(-6, 0);
REF = -6;
assert_isequal(R, REF);
%=============================================================================
R = mod([-6, 6, 0], [4, 0, 4]);
REF = [2 6 0];
assert_isequal(R, REF);
%=============================================================================
R = mod([-6; 6; 0], [4; 0; 4]);
REF = [2; 6; 0];
assert_isequal(R, REF);
%=============================================================================
R = mod([-6; 6; 0], single([4; 0; 4]));
REF = single([2; 6; 0]);
assert_isequal(R, REF);
assert_isequal(class(R), 'single');
%=============================================================================
R = mod([-6, 6; 0, 4], [4, 0 ; 4, 1]);
REF = [2 6; 0 0];
assert_isequal(R, REF);
assert_isequal(class(R), 'double');
%=============================================================================
R = mod([-6, 6; 0, 4], [0, 0 ; 0, 0]);
REF = [-6, 6; 0, 4];
assert_isequal(R, REF);
%=============================================================================
R = mod([-6, 6; 0, 4], 0);
REF = [-6, 6; 0, 4];
assert_isequal(R, REF);
%=============================================================================
R = mod([-6, 6; 0, 4], 4);
REF = [2 2; 0 0];
assert_isequal(R, REF);
%=============================================================================
R = mod(-6, [0,0; 0,0]);
REF = [-6 -6; -6 -6];
assert_isequal(R, REF);
%=============================================================================
R = mod(-6, [4,0; 4,1]);
REF = [2 -6; 2 0];
assert_isequal(R, REF);
%=============================================================================
R = mod(-6, [4,2; 4,1]);
REF = [2 0; 2 0];
assert_isequal(R, REF);
%=============================================================================
R = mod(-6, [4,2; 4,1]);
REF = [2 0; 2 0];
assert_isequal(R, REF);
%=============================================================================
R = mod(uint64 (6), uint64 (4));
REF = uint64 (2);
assert_isequal(R, REF);
%=============================================================================
R = mod(uint64([1:6]), uint64(4));
REF = uint64([1   2   3   0   1   2]);
assert_isequal(R, REF);
%=============================================================================
R = mod(uint64([1:6]), uint64(0));
REF = uint64([ 1   2   3   4   5   6]);
assert_isequal(R, REF);
%=============================================================================
assert_checkerror('R = mod(uint64(6), int64(4));', _('Integers must be combined with integers of the same class.'));
%=============================================================================
R = mod(uint64(6), 4);
REF = uint64(2);
assert_isequal(R, REF);
%=============================================================================
R = mod(2.1, 0.1);
REF = 0;
assert_isequal(R, REF);
%=============================================================================
R = mod(2.1, 0.2);
REF = 0.1;
assert_isapprox(R, REF, 1e-5);
%=============================================================================