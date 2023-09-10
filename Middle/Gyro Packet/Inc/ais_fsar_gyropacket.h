/**
  ******************************************************************************
  * @file    ais_fsar_gyropacket.h
  * @author  TungBT23
  * @version
  * @date
  * @brief
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifndef AIS_FSAR_GYROPACKET_H_
#define AIS_FSAR_GYROPACKET_H_
/******************************************************************************
 * INCLUDES
 ******************************************************************************/
#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"


/******************************************************************************
 * EXPORTED TYPEDEF
 ******************************************************************************/

/**
 * @brief Struct example
 * @note  Struct shoulde be name [Module name]_[Function of Struct]TypeDef
 * @note  Struct members should capitalized every word
 */
typedef struct{
    double Gyro_X;
    double Gyro_Y;
    double Gyro_Z;
    double Acce_X;
    double Acce_Y;
    double Acce_Z;
    double Temperature;
}__attribute__((packed))Gyro_DataTypeDef;

typedef struct {
    uint8_t Preamble[2];
    uint8_t Package_Version;
    uint8_t Timestamp[6];
    Gyro_DataTypeDef Data ;
    uint8_t Used;
    uint8_t Reserve[2];
    uint8_t CRC[2];
}__attribute__((packed)) Gyro_PackageTypeDef;

typedef union union_frame{
    Gyro_PackageTypeDef Strc;
    uint8_t Frame[70];
} package_frame;

/******************************************************************************
 * EXPORTED CONSTANTS
 ******************************************************************************/


/******************************************************************************
 * EXPORTED MACROS
 ******************************************************************************/

/******************************************************************************
 * EXPORTED VARIABLES
 ******************************************************************************/

/******************************************************************************
 * EXPORTED FUNCTIONS PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * EXPORTED FUNCTIONS
 ******************************************************************************/
uint16_t Gyroscope_CRCCalc(uint8_t *data, uint16_t lenght)
#endif /* AIS_FSAR_GYROPACKET_H_ */