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
#include <aws/rekognition/Rekognition_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace Rekognition
{
namespace Model
{

  /**
   * <p>The Kinesis data stream Amazon Rekognition to which the analysis results of a
   * Amazon Rekognition stream processor are streamed. For more information, see
   * CreateStreamProcessor in the Amazon Rekognition Developer Guide.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/rekognition-2016-06-27/KinesisDataStream">AWS
   * API Reference</a></p>
   */
  class AWS_REKOGNITION_API KinesisDataStream
  {
  public:
    KinesisDataStream();
    KinesisDataStream(Aws::Utils::Json::JsonView jsonValue);
    KinesisDataStream& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline const Aws::String& GetArn() const{ return m_arn; }

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline bool ArnHasBeenSet() const { return m_arnHasBeenSet; }

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline void SetArn(const Aws::String& value) { m_arnHasBeenSet = true; m_arn = value; }

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline void SetArn(Aws::String&& value) { m_arnHasBeenSet = true; m_arn = std::move(value); }

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline void SetArn(const char* value) { m_arnHasBeenSet = true; m_arn.assign(value); }

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline KinesisDataStream& WithArn(const Aws::String& value) { SetArn(value); return *this;}

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline KinesisDataStream& WithArn(Aws::String&& value) { SetArn(std::move(value)); return *this;}

    /**
     * <p>ARN of the output Amazon Kinesis Data Streams stream.</p>
     */
    inline KinesisDataStream& WithArn(const char* value) { SetArn(value); return *this;}

  private:

    Aws::String m_arn;
    bool m_arnHasBeenSet;
  };

} // namespace Model
} // namespace Rekognition
} // namespace Aws
