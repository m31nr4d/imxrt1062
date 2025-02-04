/**
 * @file      iomux_manager.h
 * @author    Ario@Permadev
 * @brief
 * @version   0.1
 * @date      2021-08-29
 *
 * @copyright Copyright (c) 2021, MIT-License included in project toplevel dir
 *
 */

#ifndef IOMUX_MANAGER_H
#define IOMUX_MANAGER_H

#include "gpio_handler.h"
// #include "lcdif_handler.h"
// #include "qtimer_handler.h"
// #include "flexpwm_handler.h"
// #include "armtrace_handler.h"
// #include "flexio_handler.h"
// #include "srcboot_handler.h"
// #include "enet_handler.h"

typedef union {
  // SStoredDEVICE _device;
  // SStoredDEVICE _device;
  // SStoredDEVICE _device;
  // SStoredDEVICE _device;
  // SStoredDEVICE _device;
  gpiodev_s gpio_device;
  // SStoredDEVICE _device;
  // SStoredDEVICE _device;
} iomux_manager_t;

#endif // IOMUX_MANAGER_H