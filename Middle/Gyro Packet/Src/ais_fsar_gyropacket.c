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


/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "ais_fsar_gyropacket.h"

/******************************************************************************
 * PRIVATE TYPEDEF
 ******************************************************************************/

/******************************************************************************
 * PRIVATE CONSTANTS
 ******************************************************************************/

/******************************************************************************
 * PRIVATE MACROS
 ******************************************************************************/

/******************************************************************************
 * PRIVATE VARIABLES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTIONS PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/


uint16_t Gyroscope_CRCCalc(uint8_t *data, uint16_t length)
{
    uint16_t crc = 0u;
    while (length)
    {
        length--;
        crc = crc ^ ((uint16_t)*data++ << 8u);
        for (uint8_t i = 0u; i < 8u; i++)
        {
            if (crc & 0x8000u)
            {
                crc = (crc << 1u) ^ 0x1021u;
            }
            else
            {
                crc = crc << 1u;
            }
        }
    }
    return crc;
}


void ToString( Gyro_PackageTypeDef package)
{
    printf("gyro_x: %lf",package.Data.Gyro_X);
    printf("gyro_y: %lf",package.Data.Gyro_Y);
    printf("gyro_z: %lf",package.Data.Gyro_Z);
    printf("acce_x: %lf",package.Data.Acce_X);
    printf("acce_y: %lf",package.Data.Acce_Y);
    printf("acce_z: %lf",package.Data.Acce_Z);
    printf("temperature: %lf",package.Data.Temperature);
}