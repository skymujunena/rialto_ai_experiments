/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2023 Sky UK
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "HealthcheckServiceFactory.h"
#include "HealthcheckService.h"
#include "ITimer.h"

namespace rialto::servermanager::common
{
HealthcheckServiceFactory::HealthcheckServiceFactory(std::chrono::seconds healthcheckInterval)
    : m_kHealthcheckFrequency{healthcheckInterval}
{
}

std::unique_ptr<IHealthcheckService>
HealthcheckServiceFactory::createHealthcheckService(ISessionServerAppManager &appManager) const
{
    return std::make_unique<HealthcheckService>(appManager, firebolt::rialto::common::ITimerFactory::getFactory(),
                                                m_kHealthcheckFrequency);
}
} // namespace rialto::servermanager::common
