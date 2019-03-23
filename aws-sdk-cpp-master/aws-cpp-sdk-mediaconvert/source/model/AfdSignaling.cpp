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

#include <aws/mediaconvert/model/AfdSignaling.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace MediaConvert
  {
    namespace Model
    {
      namespace AfdSignalingMapper
      {

        static const int NONE_HASH = HashingUtils::HashString("NONE");
        static const int AUTO_HASH = HashingUtils::HashString("AUTO");
        static const int FIXED_HASH = HashingUtils::HashString("FIXED");


        AfdSignaling GetAfdSignalingForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == NONE_HASH)
          {
            return AfdSignaling::NONE;
          }
          else if (hashCode == AUTO_HASH)
          {
            return AfdSignaling::AUTO;
          }
          else if (hashCode == FIXED_HASH)
          {
            return AfdSignaling::FIXED;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<AfdSignaling>(hashCode);
          }

          return AfdSignaling::NOT_SET;
        }

        Aws::String GetNameForAfdSignaling(AfdSignaling enumValue)
        {
          switch(enumValue)
          {
          case AfdSignaling::NONE:
            return "NONE";
          case AfdSignaling::AUTO:
            return "AUTO";
          case AfdSignaling::FIXED:
            return "FIXED";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace AfdSignalingMapper
    } // namespace Model
  } // namespace MediaConvert
} // namespace Aws