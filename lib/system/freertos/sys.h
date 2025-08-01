/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 * Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	freertos/sys.h
 * @brief	FreeRTOS system primitives for libmetal.
 */

#ifndef __METAL_SYS__H__
#error "Include metal/sys.h instead of metal/freertos/sys.h"
#endif

#ifndef __METAL_FREERTOS_SYS__H__
#define __METAL_FREERTOS_SYS__H__

#include <metal/errno.h>
#include <metal/cpu.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef METAL_MAX_DEVICE_REGIONS
#define METAL_MAX_DEVICE_REGIONS 1
#endif

#define metal_yield() metal_cpu_yield()

/** Structure for FreeRTOS libmetal runtime state. */
struct metal_state {

	/** Common (system independent) data. */
	struct metal_common_state common;
};

#ifdef METAL_INTERNAL

/**
 * @brief restore interrupts to state before disable_global_interrupt()
 */
void sys_irq_restore_enable(unsigned int flags);

/**
 * @brief disable all interrupts
 */
unsigned int sys_irq_save_disable(void);

#endif /* METAL_INTERNAL */

#ifdef __cplusplus
}
#endif

#endif /* __METAL_FREERTOS_SYS__H__ */
