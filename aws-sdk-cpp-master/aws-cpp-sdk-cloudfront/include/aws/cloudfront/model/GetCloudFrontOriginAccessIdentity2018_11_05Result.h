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

#pragma once
#include <aws/cloudfront/CloudFront_EXPORTS.h>
#include <aws/cloudfront/model/CloudFrontOriginAccessIdentity.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace CloudFront
{
namespace Model
{
  /**
   * <p>The returned result of the corresponding request.</p><p><h3>See Also:</h3>  
   * <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/cloudfront-2018-11-05/GetCloudFrontOriginAccessIdentityResult">AWS
   * API Reference</a></p>
   */
  class AWS_CLOUDFRONT_API GetCloudFrontOriginAccessIdentity2018_11_05Result
  {
  public:
    GetCloudFrontOriginAccessIdentity2018_11_05Result();
    GetCloudFrontOriginAccessIdentity2018_11_05Result(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    GetCloudFrontOriginAccessIdentity2018_11_05Result& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);


    /**
     * <p>The origin access identity's information.</p>
     */
    inline const CloudFrontOriginAccessIdentity& GetCloudFrontOriginAccessIdentity() const{ return m_cloudFrontOriginAccessIdentity; }

    /**
     * <p>The origin access identity's information.</p>
     */
    inline void SetCloudFrontOriginAccessIdentity(const CloudFrontOriginAccessIdentity& value) { m_cloudFrontOriginAccessIdentity = value; }

    /**
     * <p>The origin access identity's information.</p>
     */
    inline void SetCloudFrontOriginAccessIdentity(CloudFrontOriginAccessIdentity&& value) { m_cloudFrontOriginAccessIdentity = std::move(value); }

    /**
     * <p>The origin access identity's information.</p>
     */
    inline GetCloudFrontOriginAccessIdentity2018_11_05Result& WithCloudFrontOriginAccessIdentity(const CloudFrontOriginAccessIdentity& value) { SetCloudFrontOriginAccessIdentity(value); return *this;}

    /**
     * <p>The origin access identity's information.</p>
     */
    inline GetCloudFrontOriginAccessIdentity2018_11_05Result& WithCloudFrontOriginAccessIdentity(CloudFrontOriginAccessIdentity&& value) { SetCloudFrontOriginAccessIdentity(std::move(value)); return *this;}


    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline const Aws::String& GetETag() const{ return m_eTag; }

    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline void SetETag(const Aws::String& value) { m_eTag = value; }

    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline void SetETag(Aws::String&& value) { m_eTag = std::move(value); }

    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline void SetETag(const char* value) { m_eTag.assign(value); }

    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline GetCloudFrontOriginAccessIdentity2018_11_05Result& WithETag(const Aws::String& value) { SetETag(value); return *this;}

    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline GetCloudFrontOriginAccessIdentity2018_11_05Result& WithETag(Aws::String&& value) { SetETag(std::move(value)); return *this;}

    /**
     * <p>The current version of the origin access identity's information. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline GetCloudFrontOriginAccessIdentity2018_11_05Result& WithETag(const char* value) { SetETag(value); return *this;}

  private:

    CloudFrontOriginAccessIdentity m_cloudFrontOriginAccessIdentity;

    Aws::String m_eTag;
  };

} // namespace Model
} // namespace CloudFront
} // namespace Aws
