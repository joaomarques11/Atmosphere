/*
 * Copyright (c) 2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "utils.h"
#include "spinlock.h"
typedef struct FpuRegisterCache {
    u128                q[32];
    u64                 fpsr;
    u64                 fpcr;
    u32                 coreId;
    bool                valid;
    bool                dirty;
} FpuRegisterCache;

// Only for the current core:

FpuRegisterCache *fpuGetRegisterCache(void);
FpuRegisterCache *fpuReadRegisters(void);
void fpuCommitRegisters(void);
void fpuCleanInvalidateRegisterCache(void);
