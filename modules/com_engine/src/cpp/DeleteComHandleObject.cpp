//=============================================================================
// Copyright (c) 2016-2017 Allan CORNET (Nelson)
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
#include <Windows.h>
#include "DeleteComHandleObject.hpp"
#include "HandleManager.hpp"
#include "ComHandleObject.hpp"
//=============================================================================
namespace Nelson {
    //=============================================================================
    bool DeleteComHandleObject(ArrayOf A)
    {
        bool res = false;
        if (A.isHandle())
        {
            if (!A.isEmpty())
            {
                Dimensions dims = A.getDimensions();
                nelson_handle *qp = (nelson_handle*)A.getDataPointer();
                for (size_t k = 0; k < dims.getElementCount(); k++)
                {
                    nelson_handle hl = qp[k];
                    HandleGenericObject *hlObj = HandleManager::getInstance()->getPointer(hl);
                    if (hlObj)
                    {
                        if (hlObj->getCategory() != COM_CATEGORY_STR)
                        {
                            throw Exception(_W("COM handle expected."));
                        }
                        ComHandleObject *comhandleobj = (ComHandleObject *)hlObj;
                        VARIANT *pVariant = (VARIANT *)comhandleobj->getPointer();
                        if (pVariant)
                        {
							VariantClear(pVariant);
							delete pVariant;
                            comhandleobj->setPointer(nullptr);
                        }
                        delete comhandleobj;
                        HandleManager::getInstance()->removeHandle(hl);
                        res = true;
                    }
                }
            }
            else
            {
                throw Exception(_W("COM valid handle expected."));
            }
        }
        return res;
    }
    //=============================================================================
}
//=============================================================================