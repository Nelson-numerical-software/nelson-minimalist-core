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
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include <algorithm>
#include "slicot_tg01adBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    tg01ad_(const char* JOB, int* L, int* N, int* M, int* P, double* THRESH, double* A, int* LDA,
        double* E, int* LDE, double* B, int* LDB, double* C, int* LDC, double* LSCALE,
        double* RSCALE, double* DWORK, int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, E_OUT, B_OUT, C_OUT, LSCALE, RSCALE, INFO] = slicot_tg01ad(JOB, THRESH, A_IN, E_IN, B_IN,
// C_IN)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_tg01adBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 7) {
        Error(ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 6) {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf JOB = argIn[0];
    Dimensions dimsJOB = JOB.getDimensions();
    std::string JOB_string = JOB.getContentAsCString();
    const char* JOB_ptr = JOB_string.c_str();
    ArrayOf THRESH = argIn[1];
    Dimensions dimsTHRESH = THRESH.getDimensions();
    THRESH.promoteType(NLS_DOUBLE);
    double* THRESH_ptr = (double*)THRESH.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf A = argIn[2];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double* A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf E = argIn[3];
    Dimensions dimsE = E.getDimensions();
    E.promoteType(NLS_DOUBLE);
    ArrayOf E_output = E;
    E_output.ensureSingleOwner();
    double* E_output_ptr = (double*)E_output.getDataPointer();
    ArrayOf B = argIn[4];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    ArrayOf B_output = B;
    B_output.ensureSingleOwner();
    double* B_output_ptr = (double*)B_output.getDataPointer();
    ArrayOf C = argIn[5];
    Dimensions dimsC = C.getDimensions();
    C.promoteType(NLS_DOUBLE);
    ArrayOf C_output = C;
    C_output.ensureSingleOwner();
    double* C_output_ptr = (double*)C_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf L = ArrayOf::int32VectorConstructor(1);
    int* L_ptr = (int*)L.getDataPointer();
    L_ptr[0] = (int)A.getDimensions().getRows();
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getDimensions().getColumns();
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)B.getDimensions().getColumns();
    ArrayOf P = ArrayOf::int32VectorConstructor(1);
    int* P_ptr = (int*)P.getDataPointer();
    P_ptr[0] = (int)C.getDimensions().getRows();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)L.getContentAsInteger32Scalar());
    ArrayOf LDE = ArrayOf::int32VectorConstructor(1);
    int* LDE_ptr = (int*)LDE.getDataPointer();
    LDE_ptr[0] = std::max(1, (int)L.getContentAsInteger32Scalar());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = std::max(1, (int)L.getContentAsInteger32Scalar());
    ArrayOf LDC = ArrayOf::int32VectorConstructor(1);
    int* LDC_ptr = (int*)LDC.getDataPointer();
    LDC_ptr[0] = std::max(1, (int)P.getContentAsInteger32Scalar());
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(
        1, 3 * ((int)L.getContentAsInteger32Scalar() + (int)N.getContentAsInteger32Scalar()));
    double* DWORK_ptr = (double*)DWORK.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf LSCALE_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)1, (indexType)(int)L.getContentAsInteger32Scalar());
    double* LSCALE_output_ptr = (double*)LSCALE_output.getDataPointer();
    ArrayOf RSCALE_output = ArrayOf::doubleMatrix2dConstructor(
        (indexType)1, (indexType)(int)N.getContentAsInteger32Scalar());
    double* RSCALE_output_ptr = (double*)RSCALE_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsJOB.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    if (!dimsTHRESH.isScalar()) {
        Error(_W("Input argument #2: scalar expected."));
    }
    Dimensions dimsA_expected(
        std::max(1, (int)L.getContentAsInteger32Scalar()), (int)N.getContentAsInteger32Scalar());
    if (!dimsA.equals(dimsA_expected)) {
        Error(_("Input argument #3: wrong size.") + " " + dimsA_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsE_expected(
        std::max(1, (int)L.getContentAsInteger32Scalar()), (int)N.getContentAsInteger32Scalar());
    if (!dimsE.equals(dimsE_expected)) {
        Error(_("Input argument #4: wrong size.") + " " + dimsE_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsB_expected(
        std::max(1, (int)L.getContentAsInteger32Scalar()), (int)M.getContentAsInteger32Scalar());
    if (!dimsB.equals(dimsB_expected)) {
        Error(_("Input argument #5: wrong size.") + " " + dimsB_expected.toString() + " "
            + "expected" + ".");
    }
    Dimensions dimsC_expected(
        std::max(1, (int)P.getContentAsInteger32Scalar()), (int)N.getContentAsInteger32Scalar());
    if (!dimsC.equals(dimsC_expected)) {
        Error(_("Input argument #6: wrong size.") + " " + dimsC_expected.toString() + " "
            + "expected" + ".");
    }
    // CALL EXTERN FUNCTION
    try {
        tg01ad_(JOB_ptr, L_ptr, N_ptr, M_ptr, P_ptr, THRESH_ptr, A_output_ptr, LDA_ptr,
            E_output_ptr, LDE_ptr, B_output_ptr, LDB_ptr, C_output_ptr, LDC_ptr, LSCALE_output_ptr,
            RSCALE_output_ptr, DWORK_ptr, INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("tg01ad function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval.push_back(A_output);
    }
    if (nLhs > 1) {
        retval.push_back(E_output);
    }
    if (nLhs > 2) {
        retval.push_back(B_output);
    }
    if (nLhs > 3) {
        retval.push_back(C_output);
    }
    if (nLhs > 4) {
        retval.push_back(LSCALE_output);
    }
    if (nLhs > 5) {
        retval.push_back(RSCALE_output);
    }
    if (nLhs > 6) {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
