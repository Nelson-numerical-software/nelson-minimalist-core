//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include "Error.hpp"
#include "slicot_sg02adBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
extern int sg02ad_ ( const char *DICO, const char *JOBB, const char *FACT, const char *UPLO, const char *JOBL, const char *SCAL, const char *SORT, const char *ACC, int *N, int *M, int *P,const double *A, int *LDA,const double *E, int *LDE,const double *B, int *LDB,const double *Q, int *LDQ,const double *R, int *LDR,const double *L, int *LDL, double *RCONDU, double *X, int *LDX, double *ALFAR, double *ALFAI, double *BETA, double *S, int *LDS, double *T, int *LDT, double *U, int *LDU, double *TOL, int *IWORK, double *DWORK, int *LDWORK, int *BWORK, int *IWARN, int *INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [RCONDU, X, ALFAR, ALFAI, BETA, S, T, U, IWARN, INFO] = slicot_sg02ad(DICO, JOBB, FACT, UPLO, JOBL, SCAL, SORT, ACC, P, A, E, B, Q, R, L, TOL)
//=============================================================================
ArrayOfVector Nelson::SlicotGateway::slicot_sg02adBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 10)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 16)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf DICO = argIn[0];
    Dimensions dimsDICO = DICO.getDimensions();
    std::string DICO_string = DICO.getContentAsCString();
    const char* DICO_ptr = DICO_string.c_str();
    ArrayOf JOBB = argIn[1];
    Dimensions dimsJOBB = JOBB.getDimensions();
    std::string JOBB_string = JOBB.getContentAsCString();
    const char* JOBB_ptr = JOBB_string.c_str();
    ArrayOf FACT = argIn[2];
    Dimensions dimsFACT = FACT.getDimensions();
    std::string FACT_string = FACT.getContentAsCString();
    const char* FACT_ptr = FACT_string.c_str();
    ArrayOf UPLO = argIn[3];
    Dimensions dimsUPLO = UPLO.getDimensions();
    std::string UPLO_string = UPLO.getContentAsCString();
    const char* UPLO_ptr = UPLO_string.c_str();
    ArrayOf JOBL = argIn[4];
    Dimensions dimsJOBL = JOBL.getDimensions();
    std::string JOBL_string = JOBL.getContentAsCString();
    const char* JOBL_ptr = JOBL_string.c_str();
    ArrayOf SCAL = argIn[5];
    Dimensions dimsSCAL = SCAL.getDimensions();
    std::string SCAL_string = SCAL.getContentAsCString();
    const char* SCAL_ptr = SCAL_string.c_str();
    ArrayOf SORT = argIn[6];
    Dimensions dimsSORT = SORT.getDimensions();
    std::string SORT_string = SORT.getContentAsCString();
    const char* SORT_ptr = SORT_string.c_str();
    ArrayOf ACC = argIn[7];
    Dimensions dimsACC = ACC.getDimensions();
    std::string ACC_string = ACC.getContentAsCString();
    const char* ACC_ptr = ACC_string.c_str();
    ArrayOf P = argIn[8];
    Dimensions dimsP = P.getDimensions();
    P.promoteType(NLS_INT32);
    int *P_ptr = (int*)P.getDataPointer();
    ArrayOf A = argIn[9];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    double *A_ptr = (double*)A.getDataPointer();
    ArrayOf E = argIn[10];
    Dimensions dimsE = E.getDimensions();
    E.promoteType(NLS_DOUBLE);
    double *E_ptr = (double*)E.getDataPointer();
    ArrayOf B = argIn[11];
    Dimensions dimsB = B.getDimensions();
    B.promoteType(NLS_DOUBLE);
    double *B_ptr = (double*)B.getDataPointer();
    ArrayOf Q = argIn[12];
    Dimensions dimsQ = Q.getDimensions();
    Q.promoteType(NLS_DOUBLE);
    double *Q_ptr = (double*)Q.getDataPointer();
    ArrayOf R = argIn[13];
    Dimensions dimsR = R.getDimensions();
    R.promoteType(NLS_DOUBLE);
    double *R_ptr = (double*)R.getDataPointer();
    ArrayOf L = argIn[14];
    Dimensions dimsL = L.getDimensions();
    L.promoteType(NLS_DOUBLE);
    double *L_ptr = (double*)L.getDataPointer();
    ArrayOf TOL = argIn[15];
    Dimensions dimsTOL = TOL.getDimensions();
    TOL.promoteType(NLS_DOUBLE);
    double *TOL_ptr = (double*)TOL.getDataPointer();
    // IN/OUT VARIABLES
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getDimensions().getRows();
    ArrayOf M = ArrayOf::int32VectorConstructor(1);
    int* M_ptr = (int*)M.getDataPointer();
    M_ptr[0] = (int)B.getDimensions().getColumns();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDE = ArrayOf::int32VectorConstructor(1);
    int* LDE_ptr = (int*)LDE.getDataPointer();
    LDE_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDB = ArrayOf::int32VectorConstructor(1);
    int* LDB_ptr = (int*)LDB.getDataPointer();
    LDB_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDQ = ArrayOf::int32VectorConstructor(1);
    int* LDQ_ptr = (int*)LDQ.getDataPointer();
    LDQ_ptr[0] = std::max(1, std::max((int)A.getDimensions().getRows(), (int)P.getContentAsInteger32Scalar()));
    ArrayOf LDR = ArrayOf::int32VectorConstructor(1);
    int* LDR_ptr = (int*)LDR.getDataPointer();
    LDR_ptr[0] = std::max(1, std::max((int)P.getContentAsInteger32Scalar(), (int)B.getDimensions().getColumns()));
    ArrayOf LDL = ArrayOf::int32VectorConstructor(1);
    int* LDL_ptr = (int*)LDL.getDataPointer();
    LDL_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDX = ArrayOf::int32VectorConstructor(1);
    int* LDX_ptr = (int*)LDX.getDataPointer();
    LDX_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDS = ArrayOf::int32VectorConstructor(1);
    int* LDS_ptr = (int*)LDS.getDataPointer();
    LDS_ptr[0] = std::max(1, 2 * (int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns());
    ArrayOf LDT = ArrayOf::int32VectorConstructor(1);
    int* LDT_ptr = (int*)LDT.getDataPointer();
    LDT_ptr[0] = std::max(1, 2 * (int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns());
    ArrayOf LDU = ArrayOf::int32VectorConstructor(1);
    int* LDU_ptr = (int*)LDU.getDataPointer();
    LDU_ptr[0] = std::max(1, 2 * (int)A.getDimensions().getRows());
    ArrayOf IWORK = ArrayOf::int32Matrix2dConstructor(std::max(1, std::max((int)B.getDimensions().getColumns(), 2 * (int)A.getDimensions().getRows())) , 1);
    int* IWORK_ptr = (int*)IWORK.getDataPointer();
    ArrayOf DWORK = ArrayOf::doubleMatrix2dConstructor(std::max(7*(2 * (int)A.getDimensions().getRows() + 1)+16, std::max(16 * (int)A.getDimensions().getRows(),std::max(2 * (int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns(),3 * (int)B.getDimensions().getColumns()))) , 1);
    double * DWORK_ptr = (double*)DWORK.getDataPointer();
    ArrayOf LDWORK = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_ptr = (int*)LDWORK.getDataPointer();
    LDWORK_ptr[0] = std::max(7*(2*(int)A.getDimensions().getRows()+1)+16, std::max(16*(int)A.getDimensions().getRows(),std::max(2*(int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns(), 3 * (int)B.getDimensions().getColumns())));
    ArrayOf BWORK = ArrayOf::int32Matrix2dConstructor(2 * (int)A.getDimensions().getRows() , 1);
    int* BWORK_ptr = (int*)BWORK.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf RCONDU_output = ArrayOf::doubleVectorConstructor(1);
    double *RCONDU_output_ptr = (double*)RCONDU_output.getDataPointer();
    ArrayOf X_output = ArrayOf::doubleMatrix2dConstructor((indexType)std::max(1, (int)A.getDimensions().getRows()), (indexType)(int)A.getDimensions().getRows());
    double *X_output_ptr = (double*)X_output.getDataPointer();
    ArrayOf ALFAR_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)2 * (int)A.getDimensions().getRows());
    double *ALFAR_output_ptr = (double*)ALFAR_output.getDataPointer();
    ArrayOf ALFAI_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)2 * (int)A.getDimensions().getRows());
    double *ALFAI_output_ptr = (double*)ALFAI_output.getDataPointer();
    ArrayOf BETA_output = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)2 * (int)A.getDimensions().getRows());
    double *BETA_output_ptr = (double*)BETA_output.getDataPointer();
    ArrayOf S_output = ArrayOf::doubleMatrix2dConstructor((indexType)std::max(1, 2 * (int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns()), (indexType)std::max(1, 2 * (int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns()));
    double *S_output_ptr = (double*)S_output.getDataPointer();
    ArrayOf T_output = ArrayOf::doubleMatrix2dConstructor((indexType)std::max(1, 2 * (int)A.getDimensions().getRows() + (int)B.getDimensions().getColumns()), (indexType)2 * (int)A.getDimensions().getRows());
    double *T_output_ptr = (double*)T_output.getDataPointer();
    ArrayOf U_output = ArrayOf::doubleMatrix2dConstructor((indexType)std::max(1, 2 * (int)A.getDimensions().getRows()), (indexType)2 * (int)A.getDimensions().getRows());
    double *U_output_ptr = (double*)U_output.getDataPointer();
    ArrayOf IWARN_output = ArrayOf::int32VectorConstructor(1);
    int *IWARN_output_ptr = (int*)IWARN_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int *INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsDICO.isScalar())
    {
        Error(eval, _W("Input argument #1: scalar expected."));
    }
    if (!dimsJOBB.isScalar())
    {
        Error(eval, _W("Input argument #2: scalar expected."));
    }
    if (!dimsFACT.isScalar())
    {
        Error(eval, _W("Input argument #3: scalar expected."));
    }
    if (!dimsUPLO.isScalar())
    {
        Error(eval, _W("Input argument #4: scalar expected."));
    }
    if (!dimsJOBL.isScalar())
    {
        Error(eval, _W("Input argument #5: scalar expected."));
    }
    if (!dimsSCAL.isScalar())
    {
        Error(eval, _W("Input argument #6: scalar expected."));
    }
    if (!dimsSORT.isScalar())
    {
        Error(eval, _W("Input argument #7: scalar expected."));
    }
    if (!dimsACC.isScalar())
    {
        Error(eval, _W("Input argument #8: scalar expected."));
    }
    if (!dimsP.isScalar())
    {
        Error(eval, _W("Input argument #9: scalar expected."));
    }
    Dimensions dimsA_expected(std::max(1, (int)A.getDimensions().getRows()), (int)A.getDimensions().getRows());
    if (!dimsA.equals(dimsA_expected))
    {
        Error(eval, _("Input argument #10: wrong size.") + " " + dimsA_expected.toString() + " " + "expected" + ".");
    }
    Dimensions dimsE_expected(std::max(1, (int)A.getDimensions().getRows()), (int)A.getDimensions().getRows());
    if (!dimsE.equals(dimsE_expected))
    {
        Error(eval, _("Input argument #11: wrong size.") + " " + dimsE_expected.toString() + " " + "expected" + ".");
    }
    Dimensions dimsQ_expected(std::max(1, std::max((int)A.getDimensions().getRows(), (int)P.getContentAsInteger32Scalar())), (int)A.getDimensions().getRows());
    if (!dimsQ.equals(dimsQ_expected))
    {
        Error(eval, _("Input argument #13: wrong size.") + " " + dimsQ_expected.toString() + " " + "expected" + ".");
    }
    Dimensions dimsR_expected(std::max(1, std::max((int)P.getContentAsInteger32Scalar(), (int)B.getDimensions().getColumns())), (int)B.getDimensions().getColumns());
    if (!dimsR.equals(dimsR_expected))
    {
        Error(eval, _("Input argument #14: wrong size.") + " " + dimsR_expected.toString() + " " + "expected" + ".");
    }
    if (!dimsTOL.isScalar())
    {
        Error(eval, _W("Input argument #16: scalar expected."));
    }
    // CALL EXTERN FUNCTION
    try
    {
        sg02ad_ ( DICO_ptr, JOBB_ptr, FACT_ptr, UPLO_ptr, JOBL_ptr, SCAL_ptr, SORT_ptr, ACC_ptr, N_ptr, M_ptr, P_ptr, A_ptr, LDA_ptr, E_ptr, LDE_ptr, B_ptr, LDB_ptr, Q_ptr, LDQ_ptr, R_ptr, LDR_ptr, L_ptr, LDL_ptr, RCONDU_output_ptr, X_output_ptr, LDX_ptr, ALFAR_output_ptr, ALFAI_output_ptr, BETA_output_ptr, S_output_ptr, LDS_ptr, T_output_ptr, LDT_ptr, U_output_ptr, LDU_ptr, TOL_ptr, IWORK_ptr, DWORK_ptr, LDWORK_ptr, BWORK_ptr, IWARN_output_ptr, INFO_output_ptr);
    }
    catch (std::runtime_error &e)
    {
        e.what();
        Error(eval, "sg02ad function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0)
    {
        retval.push_back(RCONDU_output);
    }
    if (nLhs > 1)
    {
        retval.push_back(X_output);
    }
    if (nLhs > 2)
    {
        retval.push_back(ALFAR_output);
    }
    if (nLhs > 3)
    {
        retval.push_back(ALFAI_output);
    }
    if (nLhs > 4)
    {
        retval.push_back(BETA_output);
    }
    if (nLhs > 5)
    {
        retval.push_back(S_output);
    }
    if (nLhs > 6)
    {
        retval.push_back(T_output);
    }
    if (nLhs > 7)
    {
        retval.push_back(U_output);
    }
    if (nLhs > 8)
    {
        retval.push_back(IWARN_output);
    }
    if (nLhs > 9)
    {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
