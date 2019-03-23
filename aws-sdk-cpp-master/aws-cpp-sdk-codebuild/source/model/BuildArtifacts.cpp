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

#include <aws/codebuild/model/BuildArtifacts.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace CodeBuild
{
namespace Model
{

BuildArtifacts::BuildArtifacts() : 
    m_locationHasBeenSet(false),
    m_sha256sumHasBeenSet(false),
    m_md5sumHasBeenSet(false),
    m_overrideArtifactName(false),
    m_overrideArtifactNameHasBeenSet(false),
    m_encryptionDisabled(false),
    m_encryptionDisabledHasBeenSet(false),
    m_artifactIdentifierHasBeenSet(false)
{
}

BuildArtifacts::BuildArtifacts(JsonView jsonValue) : 
    m_locationHasBeenSet(false),
    m_sha256sumHasBeenSet(false),
    m_md5sumHasBeenSet(false),
    m_overrideArtifactName(false),
    m_overrideArtifactNameHasBeenSet(false),
    m_encryptionDisabled(false),
    m_encryptionDisabledHasBeenSet(false),
    m_artifactIdentifierHasBeenSet(false)
{
  *this = jsonValue;
}

BuildArtifacts& BuildArtifacts::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("location"))
  {
    m_location = jsonValue.GetString("location");

    m_locationHasBeenSet = true;
  }

  if(jsonValue.ValueExists("sha256sum"))
  {
    m_sha256sum = jsonValue.GetString("sha256sum");

    m_sha256sumHasBeenSet = true;
  }

  if(jsonValue.ValueExists("md5sum"))
  {
    m_md5sum = jsonValue.GetString("md5sum");

    m_md5sumHasBeenSet = true;
  }

  if(jsonValue.ValueExists("overrideArtifactName"))
  {
    m_overrideArtifactName = jsonValue.GetBool("overrideArtifactName");

    m_overrideArtifactNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("encryptionDisabled"))
  {
    m_encryptionDisabled = jsonValue.GetBool("encryptionDisabled");

    m_encryptionDisabledHasBeenSet = true;
  }

  if(jsonValue.ValueExists("artifactIdentifier"))
  {
    m_artifactIdentifier = jsonValue.GetString("artifactIdentifier");

    m_artifactIdentifierHasBeenSet = true;
  }

  return *this;
}

JsonValue BuildArtifacts::Jsonize() const
{
  JsonValue payload;

  if(m_locationHasBeenSet)
  {
   payload.WithString("location", m_location);

  }

  if(m_sha256sumHasBeenSet)
  {
   payload.WithString("sha256sum", m_sha256sum);

  }

  if(m_md5sumHasBeenSet)
  {
   payload.WithString("md5sum", m_md5sum);

  }

  if(m_overrideArtifactNameHasBeenSet)
  {
   payload.WithBool("overrideArtifactName", m_overrideArtifactName);

  }

  if(m_encryptionDisabledHasBeenSet)
  {
   payload.WithBool("encryptionDisabled", m_encryptionDisabled);

  }

  if(m_artifactIdentifierHasBeenSet)
  {
   payload.WithString("artifactIdentifier", m_artifactIdentifier);

  }

  return payload;
}

} // namespace Model
} // namespace CodeBuild
} // namespace Aws
