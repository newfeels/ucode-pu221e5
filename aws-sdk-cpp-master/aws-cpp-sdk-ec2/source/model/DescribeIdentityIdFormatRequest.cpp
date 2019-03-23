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

#include <aws/ec2/model/DescribeIdentityIdFormatRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

DescribeIdentityIdFormatRequest::DescribeIdentityIdFormatRequest() : 
    m_principalArnHasBeenSet(false),
    m_resourceHasBeenSet(false)
{
}

Aws::String DescribeIdentityIdFormatRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=DescribeIdentityIdFormat&";
  if(m_principalArnHasBeenSet)
  {
    ss << "PrincipalArn=" << StringUtils::URLEncode(m_principalArn.c_str()) << "&";
  }

  if(m_resourceHasBeenSet)
  {
    ss << "Resource=" << StringUtils::URLEncode(m_resource.c_str()) << "&";
  }

  ss << "Version=2016-11-15";
  return ss.str();
}


void  DescribeIdentityIdFormatRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}