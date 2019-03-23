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

#include <aws/lightsail/model/UpdateLoadBalancerAttributeRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Lightsail::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateLoadBalancerAttributeRequest::UpdateLoadBalancerAttributeRequest() : 
    m_loadBalancerNameHasBeenSet(false),
    m_attributeName(LoadBalancerAttributeName::NOT_SET),
    m_attributeNameHasBeenSet(false),
    m_attributeValueHasBeenSet(false)
{
}

Aws::String UpdateLoadBalancerAttributeRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_loadBalancerNameHasBeenSet)
  {
   payload.WithString("loadBalancerName", m_loadBalancerName);

  }

  if(m_attributeNameHasBeenSet)
  {
   payload.WithString("attributeName", LoadBalancerAttributeNameMapper::GetNameForLoadBalancerAttributeName(m_attributeName));
  }

  if(m_attributeValueHasBeenSet)
  {
   payload.WithString("attributeValue", m_attributeValue);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateLoadBalancerAttributeRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "Lightsail_20161128.UpdateLoadBalancerAttribute"));
  return headers;

}




