﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/appstream/model/UserStackAssociationErrorCode.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace AppStream
  {
    namespace Model
    {
      namespace UserStackAssociationErrorCodeMapper
      {

        static const int STACK_NOT_FOUND_HASH = HashingUtils::HashString("STACK_NOT_FOUND");
        static const int USER_NAME_NOT_FOUND_HASH = HashingUtils::HashString("USER_NAME_NOT_FOUND");
        static const int INTERNAL_ERROR_HASH = HashingUtils::HashString("INTERNAL_ERROR");


        UserStackAssociationErrorCode GetUserStackAssociationErrorCodeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == STACK_NOT_FOUND_HASH)
          {
            return UserStackAssociationErrorCode::STACK_NOT_FOUND;
          }
          else if (hashCode == USER_NAME_NOT_FOUND_HASH)
          {
            return UserStackAssociationErrorCode::USER_NAME_NOT_FOUND;
          }
          else if (hashCode == INTERNAL_ERROR_HASH)
          {
            return UserStackAssociationErrorCode::INTERNAL_ERROR;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<UserStackAssociationErrorCode>(hashCode);
          }

          return UserStackAssociationErrorCode::NOT_SET;
        }

        Aws::String GetNameForUserStackAssociationErrorCode(UserStackAssociationErrorCode enumValue)
        {
          switch(enumValue)
          {
          case UserStackAssociationErrorCode::STACK_NOT_FOUND:
            return "STACK_NOT_FOUND";
          case UserStackAssociationErrorCode::USER_NAME_NOT_FOUND:
            return "USER_NAME_NOT_FOUND";
          case UserStackAssociationErrorCode::INTERNAL_ERROR:
            return "INTERNAL_ERROR";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace UserStackAssociationErrorCodeMapper
    } // namespace Model
  } // namespace AppStream
} // namespace Aws