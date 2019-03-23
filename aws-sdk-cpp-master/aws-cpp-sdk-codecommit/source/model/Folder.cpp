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

#include <aws/codecommit/model/Folder.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace CodeCommit
{
namespace Model
{

Folder::Folder() : 
    m_treeIdHasBeenSet(false),
    m_absolutePathHasBeenSet(false),
    m_relativePathHasBeenSet(false)
{
}

Folder::Folder(JsonView jsonValue) : 
    m_treeIdHasBeenSet(false),
    m_absolutePathHasBeenSet(false),
    m_relativePathHasBeenSet(false)
{
  *this = jsonValue;
}

Folder& Folder::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("treeId"))
  {
    m_treeId = jsonValue.GetString("treeId");

    m_treeIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("absolutePath"))
  {
    m_absolutePath = jsonValue.GetString("absolutePath");

    m_absolutePathHasBeenSet = true;
  }

  if(jsonValue.ValueExists("relativePath"))
  {
    m_relativePath = jsonValue.GetString("relativePath");

    m_relativePathHasBeenSet = true;
  }

  return *this;
}

JsonValue Folder::Jsonize() const
{
  JsonValue payload;

  if(m_treeIdHasBeenSet)
  {
   payload.WithString("treeId", m_treeId);

  }

  if(m_absolutePathHasBeenSet)
  {
   payload.WithString("absolutePath", m_absolutePath);

  }

  if(m_relativePathHasBeenSet)
  {
   payload.WithString("relativePath", m_relativePath);

  }

  return payload;
}

} // namespace Model
} // namespace CodeCommit
} // namespace Aws
