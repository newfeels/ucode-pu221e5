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

#include <aws/ec2/model/InstanceLifecycle.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace EC2
  {
    namespace Model
    {
      namespace InstanceLifecycleMapper
      {

        static const int spot_HASH = HashingUtils::HashString("spot");
        static const int on_demand_HASH = HashingUtils::HashString("on-demand");


        InstanceLifecycle GetInstanceLifecycleForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == spot_HASH)
          {
            return InstanceLifecycle::spot;
          }
          else if (hashCode == on_demand_HASH)
          {
            return InstanceLifecycle::on_demand;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<InstanceLifecycle>(hashCode);
          }

          return InstanceLifecycle::NOT_SET;
        }

        Aws::String GetNameForInstanceLifecycle(InstanceLifecycle enumValue)
        {
          switch(enumValue)
          {
          case InstanceLifecycle::spot:
            return "spot";
          case InstanceLifecycle::on_demand:
            return "on-demand";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace InstanceLifecycleMapper
    } // namespace Model
  } // namespace EC2
} // namespace Aws
