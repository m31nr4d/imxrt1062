/**
 * @file      mpu.c
 * @author    Ario@Permadev
 * @brief     Memory Protection Unit impl.
 * @version   0.1
 * @date      2021-08-29
 *
 * @copyright Copyright (c) 2021, MIT-License included in project toplevel dir
 *
 */

#include "mpu.h"

/**
 * @note The values of the MPU_RASR registers from reset are UNKNOWN. All
 * MPU_RASR registers must be programmed as either enabled or disabled, before
 * enabling the MPU using the MPU_CTRL register.
 **/
void
configure_mpu()
{
  // This is not the actual body I am looking to create
  // But it will show order of execution needed when doing these things
  uint8_t placeholder_region = 0x1;
  uint8_t power = 0x4;
  // Preamble
  MPU_RNR_REQ_REGIONS(placeholder_region); // request sepcific region

  MPU_RBAR_VALID_W_0; // Apply base addr. to RBAR from RNR
  // MPU_RBAR_REGION_W(region); // Sets RBAR region directly

  MPU_RASR_SET_REGION_SIZE(power); // sets region size to (2^(x+1)) bytes
  MPU_RASR_ENABLE; // Enables region, has no effect until MPU_CTRL.ENABLE is
  // set MPU_RASR_DISABLE; // Disables region, has no effect until
  // MPU_CTRL.ENABLE is set

  // Preamble, if region size is over  2^8 (256) Bytes
  // MPU_RASR_EN_SUBREGION(0x0); // Enables subregion x, x = [0,7]
  // MPU_RASR_DIS_SUBREGION(0x0); // Disable subregion x, x = [0,7]
  // ...

  // Lock/Unlock execution
  // MPU_RASR_NOT_PERMIT_EXEC; // Lock region
  MPU_RASR_PERMIT_EXEC; // Unlock region

  // Access privilege
  // MPU_RASR_AP_NO_RW;    // Sets: No Read/Write access
  MPU_RASR_AP_PRIVL_RW; // Sets: Read/Write Privileged access
  // MPU_RASR_AP_FULL_RW; // Sets: Read/Write, Full access
  // MPU_RASR_AP_PRIVL_RO; // Sets: Read Only, Privileged access
  // MPU_RASR_AP_FULL_RO;  // Sets: Read Only, Full access
  // MPU_RASR_AP_FULL_RO2; // Sets: Read Only, Full access

  // Decide whether to have shareable bits in the S field
  MPU_RASR_SET_S; // Sets _a_ to shareable in TEX,C,B
  // MPU_RASR_CLR_S; // Sets _a_ to non-shareable in TEX,C,B

  // Read TEX, C, B values
  tex_enc_e  tex_attr = MPU_RASR_READ_ATTR_TEX;
  cbit_enc_e c_attr = MPU_RASR_READ_ATTR_C;
  bbit_enc_e b_attr = MPU_RASR_READ_ATTR_B;

  // Set MPU_CTRL_ENABLE after all RASR regions settings
  MPU_CTRL_ENABLE_BIT_SET;

  // MPU_CTRL_ENABLE_BIT_CLR;
}