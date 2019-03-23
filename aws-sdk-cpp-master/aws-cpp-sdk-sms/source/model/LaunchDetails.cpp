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

#include <aws/sms/model/LaunchDetails.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace SMS
{
namespace Model
{

LaunchDetails::LaunchDetails() : 
    m_latestLaunchTimeHasBeenSet(false),
    m_stackNameHasBeenSet(false),
    m_stackIdHasBeenSet(false)
{
}

LaunchDetails::LaunchDetails(JsonView jsonValue) : 
    m_latestLaunchTimeHasBeenSet(false),
    m_stackNameHasBeenSet(false),
    m_stackIdHasBeenSet(false)
{
  *this = jsonValue;
}

LaunchDetails& LaunchDetails::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("latestLaunchTime"))
  {
    m_latestLaunchTime = jsonValue.GetDouble("latestLaunchTime");

    m_latestLaunchTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("stackName"))
  {
    m_stackName = jsonValue.GetString("stackName");

    m_stackNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("stackId"))
  {
    m_stackId = jsonValue.GetString("stackId");

    m_stackIdHasBeenSet = true;
  }

  return *this;
}

JsonValue LaunchDetails::Jsonize() const
{
  JsonValue payload;

  if(m_latestLaunchTimeHasBeenSet)
  {
   payload.WithDouble("latestLaunchTime", m_latestLaunchTime.SecondsWithMSPrecision());
  }

  if(m_stackNameHasBeenSet)
  {
   payload.WithString("stackName", m_stackName);

  }

  if(m_stackIdHasBeenSet)
  {
   payload.WithString("stackId", m_stackId);

  }

  return payload;
}

} // namespace Model
} // namespace SMS
} // namespace Aws
