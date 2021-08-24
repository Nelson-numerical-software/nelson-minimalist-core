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
R = ["nel" "son"];
REF = [string('nel') string('son')];
assert_isequal(R, REF);
%=============================================================================
R1 = ["nel" "son"];
R2 = ["nel", "son"];
assert_isequal(R1, R2);
%=============================================================================
R = ["Nelson" "manages"; "string" "array"];
REF = strings(2, 2);
REF(1, 1) = 'Nelson';
REF(1, 2) = 'manages';
REF(2, 1) = 'string';
REF(2, 2) = 'array';
assert_isequal(R, REF);
%=============================================================================
R = { "nel" "son"};
REF = {string('nel') string('son')};
assert_isequal(R, REF);
%=============================================================================