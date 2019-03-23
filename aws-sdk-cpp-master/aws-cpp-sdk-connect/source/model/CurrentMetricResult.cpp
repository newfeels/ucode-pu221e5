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

#include <aws/connect/model/CurrentMetricResult.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Connect
{
namespace Model
{

CurrentMetricResult::CurrentMetricResult() : 
    m_dimensionsHasBeenSet(false),
    m_collectionsHasBeenSet(false)
{
}

CurrentMetricResult::CurrentMetricResult(JsonView jsonValue) : 
    m_dimensionsHasBeenSet(false),
    m_collectionsHasBeenSet(false)
{
  *this = jsonValue;
}

CurrentMetricResult& CurrentMetricResult::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("Dimensions"))
  {
    m_dimensions = jsonValue.GetObject("Dimensions");

    m_dimensionsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Collections"))
  {
    Array<JsonView> collectionsJsonList = jsonValue.GetArray("Collections");
    for(unsigned collectionsIndex = 0; collectionsIndex < collectionsJsonList.GetLength(); ++collectionsIndex)
    {
      m_collections.push_back(collectionsJsonList[collectionsIndex].AsObject());
    }
    m_collectionsHasBeenSet = true;
  }

  return *this;
}

JsonValue CurrentMetricResult::Jsonize() const
{
  JsonValue payload;

  if(m_dimensionsHasBeenSet)
  {
   payload.WithObject("Dimensions", m_dimensions.Jsonize());

  }

  if(m_collectionsHasBeenSet)
  {
   Array<JsonValue> collectionsJsonList(m_collections.size());
   for(unsigned collectionsIndex = 0; collectionsIndex < collectionsJsonList.GetLength(); ++collectionsIndex)
   {
     collectionsJsonList[collectionsIndex].AsObject(m_collections[collectionsIndex].Jsonize());
   }
   payload.WithArray("Collections", std::move(collectionsJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace Connect
} // namespace Aws
