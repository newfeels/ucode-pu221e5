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

#include <aws/dms/model/EncodingTypeValue.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace DatabaseMigrationService
  {
    namespace Model
    {
      namespace EncodingTypeValueMapper
      {

        static const int plain_HASH = HashingUtils::HashString("plain");
        static const int plain_dictionary_HASH = HashingUtils::HashString("plain-dictionary");
        static const int rle_dictionary_HASH = HashingUtils::HashString("rle-dictionary");


        EncodingTypeValue GetEncodingTypeValueForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == plain_HASH)
          {
            return EncodingTypeValue::plain;
          }
          else if (hashCode == plain_dictionary_HASH)
          {
            return EncodingTypeValue::plain_dictionary;
          }
          else if (hashCode == rle_dictionary_HASH)
          {
            return EncodingTypeValue::rle_dictionary;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<EncodingTypeValue>(hashCode);
          }

          return EncodingTypeValue::NOT_SET;
        }

        Aws::String GetNameForEncodingTypeValue(EncodingTypeValue enumValue)
        {
          switch(enumValue)
          {
          case EncodingTypeValue::plain:
            return "plain";
          case EncodingTypeValue::plain_dictionary:
            return "plain-dictionary";
          case EncodingTypeValue::rle_dictionary:
            return "rle-dictionary";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace EncodingTypeValueMapper
    } // namespace Model
  } // namespace DatabaseMigrationService
} // namespace Aws
