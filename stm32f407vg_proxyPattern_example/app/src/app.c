/*******************************************************************************
  * @file    app.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 16.03.2023 - ...
  * @rev     V1.0.0
  * @brief	 Proxy Design Pattern Embedded Software Programming Application
********************************************************************************/

#include "app.h"

/*
 * Real & Proxy Object Definition
 */
RealSensor_Type*	realSensor;
ProxySensor_Type	proxySensor = {0};


#if 1 /* Main Sensor Read Function Definition */

uint32_t Real_readSensor(SensorObj_Type* self ,uint32_t readChannel)
{
	uint32_t readValHandle;

	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = readChannel;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
	if (HAL_ADC_ConfigChannel(&self->hadc , &sConfig) != HAL_OK)
	{
	  Error_Handler();
	}

	HAL_ADC_Start(&self->hadc);
	HAL_ADC_PollForConversion(&self->hadc, 1000);
	readValHandle = HAL_ADC_GetValue(&self->hadc);
	HAL_ADC_Stop(&self->hadc);

	return readValHandle;

}

uint32_t Proxy_readSensor(ProxySensor_Type* sensorProxy, uint32_t readChannel )
{
	/* If proxy sensor not avaible create it */
	if( sensorProxy->realSensor == NULL )
	{
		// bellekte "realSensor" yapısının ayrılması
		sensorProxy->realSensor =  (RealSensor_Type*)malloc(sizeof(RealSensor_Type));

		// "realSensor" yapısının "sensor" üyesinin constructor fonksiyonunun çağrılması
		SensorCTOR(&sensorProxy->realSensor->sensor, 0, 0, 0, hadc1);

	}

#if 0
	/* If proxy real objects need to require you can use it. */
	sensorProxy->realSensor->sensor.obj = realSensor->sensor.obj;
	/* If proxy objects need to require you can use it. */
	sensorProxy->sensor.obj = realSensor->sensor.obj;
#endif

	/* read Sensor data's from proxy */
	return (sensorProxy->realSensor->sensor.ops.readSensor(&sensorProxy->realSensor->sensor.obj, readChannel));
}


#endif



void MainAPP(void)
{
	 // bellekte "realSensor" yapısının ayrılması
	 realSensor = (RealSensor_Type*)malloc(sizeof(RealSensor_Type));

	 // "realSensor" yapısının "sensor" üyesinin constructor fonksiyonunun çağrılması
	 SensorCTOR(&realSensor->sensor, 0, 0, 0, hadc1);

	for(;;)
	{
		/* Infinite Loop */
		realSensor->sensor.obj.sensorVal1 = Proxy_readSensor(&proxySensor , ADC_CHANNEL_0 );
		realSensor->sensor.obj.sensorVal2 = Proxy_readSensor(&proxySensor , ADC_CHANNEL_1 );
		realSensor->sensor.obj.sensorVal3 = Proxy_readSensor(&proxySensor , ADC_CHANNEL_2 );

		HAL_Delay(100);
	}
}
