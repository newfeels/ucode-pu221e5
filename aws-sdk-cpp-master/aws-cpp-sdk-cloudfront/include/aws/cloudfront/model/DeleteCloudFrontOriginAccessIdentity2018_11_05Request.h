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
#include <aws/cloudfront/CloudFrontRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace CloudFront
{
namespace Model
{

  /**
   * <p>Deletes a origin access identity.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/cloudfront-2018-11-05/DeleteCloudFrontOriginAccessIdentityRequest">AWS
   * API Reference</a></p>
   */
  class AWS_CLOUDFRONT_API DeleteCloudFrontOriginAccessIdentity2018_11_05Request : public CloudFrontRequest
  {
  public:
    DeleteCloudFrontOriginAccessIdentity2018_11_05Request();
    
    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DeleteCloudFrontOriginAccessIdentity"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The origin access identity's ID.</p>
     */
    inline const Aws::String& GetId() const{ return m_id; }

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline bool IdHasBeenSet() const { return m_idHasBeenSet; }

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline void SetId(const Aws::String& value) { m_idHasBeenSet = true; m_id = value; }

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline void SetId(Aws::String&& value) { m_idHasBeenSet = true; m_id = std::move(value); }

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline void SetId(const char* value) { m_idHasBeenSet = true; m_id.assign(value); }

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline DeleteCloudFrontOriginAccessIdentity2018_11_05Request& WithId(const Aws::String& value) { SetId(value); return *this;}

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline DeleteCloudFrontOriginAccessIdentity2018_11_05Request& WithId(Aws::String&& value) { SetId(std::move(value)); return *this;}

    /**
     * <p>The origin access identity's ID.</p>
     */
    inline DeleteCloudFrontOriginAccessIdentity2018_11_05Request& WithId(const char* value) { SetId(value); return *this;}


    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline const Aws::String& GetIfMatch() const{ return m_ifMatch; }

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline bool IfMatchHasBeenSet() const { return m_ifMatchHasBeenSet; }

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline void SetIfMatch(const Aws::String& value) { m_ifMatchHasBeenSet = true; m_ifMatch = value; }

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline void SetIfMatch(Aws::String&& value) { m_ifMatchHasBeenSet = true; m_ifMatch = std::move(value); }

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline void SetIfMatch(const char* value) { m_ifMatchHasBeenSet = true; m_ifMatch.assign(value); }

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline DeleteCloudFrontOriginAccessIdentity2018_11_05Request& WithIfMatch(const Aws::String& value) { SetIfMatch(value); return *this;}

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline DeleteCloudFrontOriginAccessIdentity2018_11_05Request& WithIfMatch(Aws::String&& value) { SetIfMatch(std::move(value)); return *this;}

    /**
     * <p>The value of the <code>ETag</code> header you received from a previous
     * <code>GET</code> or <code>PUT</code> request. For example:
     * <code>E2QWRUHAPOMQZL</code>.</p>
     */
    inline DeleteCloudFrontOriginAccessIdentity2018_11_05Request& WithIfMatch(const char* value) { SetIfMatch(value); return *this;}

  private:

    Aws::String m_id;
    bool m_idHasBeenSet;

    Aws::String m_ifMatch;
    bool m_ifMatchHasBeenSet;
  };

} // namespace Model
} // namespace CloudFront
} // namespace Aws
