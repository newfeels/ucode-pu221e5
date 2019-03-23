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
#include <aws/devicefarm/DeviceFarm_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
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
namespace DeviceFarm
{
namespace Model
{

  /**
   * <p>A JSON object specifying the paths where the artifacts generated by the
   * customer's tests, on the device or in the test environment, will be pulled
   * from.</p> <p>Specify <code>deviceHostPaths</code> and optionally specify either
   * <code>iosPaths</code> or <code>androidPaths</code>.</p> <p>For web app tests,
   * you can specify both <code>iosPaths</code> and
   * <code>androidPaths</code>.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/devicefarm-2015-06-23/CustomerArtifactPaths">AWS
   * API Reference</a></p>
   */
  class AWS_DEVICEFARM_API CustomerArtifactPaths
  {
  public:
    CustomerArtifactPaths();
    CustomerArtifactPaths(Aws::Utils::Json::JsonView jsonValue);
    CustomerArtifactPaths& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline const Aws::Vector<Aws::String>& GetIosPaths() const{ return m_iosPaths; }

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline bool IosPathsHasBeenSet() const { return m_iosPathsHasBeenSet; }

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline void SetIosPaths(const Aws::Vector<Aws::String>& value) { m_iosPathsHasBeenSet = true; m_iosPaths = value; }

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline void SetIosPaths(Aws::Vector<Aws::String>&& value) { m_iosPathsHasBeenSet = true; m_iosPaths = std::move(value); }

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& WithIosPaths(const Aws::Vector<Aws::String>& value) { SetIosPaths(value); return *this;}

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& WithIosPaths(Aws::Vector<Aws::String>&& value) { SetIosPaths(std::move(value)); return *this;}

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddIosPaths(const Aws::String& value) { m_iosPathsHasBeenSet = true; m_iosPaths.push_back(value); return *this; }

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddIosPaths(Aws::String&& value) { m_iosPathsHasBeenSet = true; m_iosPaths.push_back(std::move(value)); return *this; }

    /**
     * <p>Comma-separated list of paths on the iOS device where the artifacts generated
     * by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddIosPaths(const char* value) { m_iosPathsHasBeenSet = true; m_iosPaths.push_back(value); return *this; }


    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline const Aws::Vector<Aws::String>& GetAndroidPaths() const{ return m_androidPaths; }

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline bool AndroidPathsHasBeenSet() const { return m_androidPathsHasBeenSet; }

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline void SetAndroidPaths(const Aws::Vector<Aws::String>& value) { m_androidPathsHasBeenSet = true; m_androidPaths = value; }

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline void SetAndroidPaths(Aws::Vector<Aws::String>&& value) { m_androidPathsHasBeenSet = true; m_androidPaths = std::move(value); }

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& WithAndroidPaths(const Aws::Vector<Aws::String>& value) { SetAndroidPaths(value); return *this;}

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& WithAndroidPaths(Aws::Vector<Aws::String>&& value) { SetAndroidPaths(std::move(value)); return *this;}

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddAndroidPaths(const Aws::String& value) { m_androidPathsHasBeenSet = true; m_androidPaths.push_back(value); return *this; }

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddAndroidPaths(Aws::String&& value) { m_androidPathsHasBeenSet = true; m_androidPaths.push_back(std::move(value)); return *this; }

    /**
     * <p>Comma-separated list of paths on the Android device where the artifacts
     * generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddAndroidPaths(const char* value) { m_androidPathsHasBeenSet = true; m_androidPaths.push_back(value); return *this; }


    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline const Aws::Vector<Aws::String>& GetDeviceHostPaths() const{ return m_deviceHostPaths; }

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline bool DeviceHostPathsHasBeenSet() const { return m_deviceHostPathsHasBeenSet; }

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline void SetDeviceHostPaths(const Aws::Vector<Aws::String>& value) { m_deviceHostPathsHasBeenSet = true; m_deviceHostPaths = value; }

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline void SetDeviceHostPaths(Aws::Vector<Aws::String>&& value) { m_deviceHostPathsHasBeenSet = true; m_deviceHostPaths = std::move(value); }

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& WithDeviceHostPaths(const Aws::Vector<Aws::String>& value) { SetDeviceHostPaths(value); return *this;}

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& WithDeviceHostPaths(Aws::Vector<Aws::String>&& value) { SetDeviceHostPaths(std::move(value)); return *this;}

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddDeviceHostPaths(const Aws::String& value) { m_deviceHostPathsHasBeenSet = true; m_deviceHostPaths.push_back(value); return *this; }

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddDeviceHostPaths(Aws::String&& value) { m_deviceHostPathsHasBeenSet = true; m_deviceHostPaths.push_back(std::move(value)); return *this; }

    /**
     * <p>Comma-separated list of paths in the test execution environment where the
     * artifacts generated by the customer's tests will be pulled from.</p>
     */
    inline CustomerArtifactPaths& AddDeviceHostPaths(const char* value) { m_deviceHostPathsHasBeenSet = true; m_deviceHostPaths.push_back(value); return *this; }

  private:

    Aws::Vector<Aws::String> m_iosPaths;
    bool m_iosPathsHasBeenSet;

    Aws::Vector<Aws::String> m_androidPaths;
    bool m_androidPathsHasBeenSet;

    Aws::Vector<Aws::String> m_deviceHostPaths;
    bool m_deviceHostPathsHasBeenSet;
  };

} // namespace Model
} // namespace DeviceFarm
} // namespace Aws