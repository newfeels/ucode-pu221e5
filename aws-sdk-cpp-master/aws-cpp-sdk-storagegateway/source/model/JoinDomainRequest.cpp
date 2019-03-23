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

#include <aws/storagegateway/model/JoinDomainRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::StorageGateway::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

JoinDomainRequest::JoinDomainRequest() : 
    m_gatewayARNHasBeenSet(false),
    m_domainNameHasBeenSet(false),
    m_organizationalUnitHasBeenSet(false),
    m_domainControllersHasBeenSet(false),
    m_userNameHasBeenSet(false),
    m_passwordHasBeenSet(false)
{
}

Aws::String JoinDomainRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_gatewayARNHasBeenSet)
  {
   payload.WithString("GatewayARN", m_gatewayARN);

  }

  if(m_domainNameHasBeenSet)
  {
   payload.WithString("DomainName", m_domainName);

  }

  if(m_organizationalUnitHasBeenSet)
  {
   payload.WithString("OrganizationalUnit", m_organizationalUnit);

  }

  if(m_domainControllersHasBeenSet)
  {
   Array<JsonValue> domainControllersJsonList(m_domainControllers.size());
   for(unsigned domainControllersIndex = 0; domainControllersIndex < domainControllersJsonList.GetLength(); ++domainControllersIndex)
   {
     domainControllersJsonList[domainControllersIndex].AsString(m_domainControllers[domainControllersIndex]);
   }
   payload.WithArray("DomainControllers", std::move(domainControllersJsonList));

  }

  if(m_userNameHasBeenSet)
  {
   payload.WithString("UserName", m_userName);

  }

  if(m_passwordHasBeenSet)
  {
   payload.WithString("Password", m_password);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection JoinDomainRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "StorageGateway_20130630.JoinDomain"));
  return headers;

}




