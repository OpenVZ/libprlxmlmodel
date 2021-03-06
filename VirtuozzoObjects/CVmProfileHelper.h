/*
 * CVmProfileHelper.h: Set of simple methods which help to work with
 * VM config profile.
 *
 * Copyright (c) 1999-2017, Parallels International GmbH
 * Copyright (c) 2017-2019 Virtuozzo International GmbH. All rights reserved.
 *
 * This file is part of Virtuozzo SDK. Virtuozzo SDK is free
 * software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/> or write to Free Software Foundation,
 * 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
 *
 * Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */


#ifndef CVmProfileHelper_H
#define CVmProfileHelper_H

#include <prlsdk/PrlEnums.h>
#include <prlsdk/PrlErrorsValues.h>
#include "../VmConfig/CVmConfiguration.h"
#include "../HostHardwareInfo/CHostHardwareInfo.h"


namespace CVmProfileHelper
{

PRL_RESULT set_vm_profile(PRL_VIRTUAL_MACHINE_PROFILE profile,
			  const CHostHardwareInfo& host_info,
			  CVmConfiguration& vm_config);

// Retrun -1 - no changes in profile, 0 - return to original profile, 1 - profile is custom
int check_vm_custom_profile(const CHostHardwareInfo& host_info,
							const CVmConfiguration& cfg1,
							const CVmConfiguration& cfg2,
							bool check_diff = true);

bool are_profiles_supported(PRL_UINT32 osVersion);

}

#endif	// CVmProfileHelper_H
