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
test_h5load_file = [tempdir(), 'test_h5load_cell.nh5'];
if isfile(test_h5load_file)
  rmfile(test_h5load_file);
end
%=============================================================================
A = {1, 2; 3, 4};
B = {1, A; A, 2};
C = {A, 4; 5, B};
savenh5(test_h5load_file, 'C');
C_REF = C;
clear('A', 'B', 'C');
st = loadnh5(test_h5load_file);
assert_isequal(C_REF, st.C);
%=============================================================================