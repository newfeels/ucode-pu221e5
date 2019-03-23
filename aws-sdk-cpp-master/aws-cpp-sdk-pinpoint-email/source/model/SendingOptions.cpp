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

#include <aws/pinpoint-email/model/SendingOptions.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace PinpointEmail
{
namespace Model
{

SendingOptions::SendingOptions() : 
    m_sendingEnabled(false),
    m_sendingEnabledHasBeenSet(false)
{
}

SendingOptions::SendingOptions(JsonView jsonValue) : 
    m_sendingEnabled(false),
    m_sendingEnabledHasBeenSet(false)
{
  *this = jsonValue;
}

SendingOptions& SendingOptions::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("SendingEnabled"))
  {
    m_sendingEnabled = jsonValue.GetBool("SendingEnabled");

    m_sendingEnabledHasBeenSet = true;
  }

  return *this;
}

JsonValue SendingOptions::Jsonize() const
{
  JsonValue payload;

  if(m_sendingEnabledHasBeenSet)
  {
   payload.WithBool("SendingEnabled", m_sendingEnabled);

  }

  return payload;
}

} // namespace Model
} // namespace PinpointEmail
} // namespace Aws
