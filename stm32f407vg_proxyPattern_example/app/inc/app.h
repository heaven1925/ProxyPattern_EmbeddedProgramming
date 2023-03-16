/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 16.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Proxy Design Pattern Embedded Software Programming Application
********************************************************************************/

#ifndef __APP_H__
#define	__APP_H__

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"

#include "main.h"

void MainAPP_StartUP(void);
void MainAPP(void);

/*
 * Sensor object class
*/
typedef struct
{
	ADC_HandleTypeDef	hadc;
	uint16_t 			sensorVal1;
	uint16_t 			sensorVal2;
	uint16_t 			sensorVal3;
}SensorObj_Type;

/*
 * Sensor method class
 */
typedef struct
{
	uint32_t (*readSensor)(SensorObj_Type* self ,uint32_t readChannel);
}SensorOps_Type;

/*
 * Sensor defined base class
 */
typedef struct
{
	SensorObj_Type  obj;
	SensorOps_Type  ops;
}Sensor_Type;

uint32_t Real_readSensor(SensorObj_Type* self ,uint32_t readChannel);

/*
 * Sensor Read Constructor function
*/
static inline void SensorCTOR(Sensor_Type* const self, uint16_t _sensorVal1, uint16_t _sensorVal2, uint16_t _sensorVal3 , ADC_HandleTypeDef _hadc )
{
	static const SensorOps_Type vTable =
	{
			&Real_readSensor
	};
	/* Virtual pointer function attachment */
	self->ops = vTable;

	/* Sensor val Init value construct */
	self->obj.sensorVal1 = _sensorVal1;
	self->obj.sensorVal2 = _sensorVal2;
	self->obj.sensorVal3 = _sensorVal3;

	/* AdcHandler construct */
	self->obj.hadc 	 = _hadc;
};

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/*********** Proxy Design Pattern Example *****************/

/*
 * Real Sensor Object
 */
typedef struct
{
	Sensor_Type	sensor;
}RealSensor_Type;

/*
 * Proxy Sensor Type
 */
typedef struct
{
	Sensor_Type 	 sensor;
	RealSensor_Type* realSensor;
}ProxySensor_Type;




//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]


#endif /* __APP_H__ */
