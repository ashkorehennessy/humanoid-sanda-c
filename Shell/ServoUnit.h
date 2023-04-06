/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			ServoUnit.h
** ����޶�����:		2009-03-23
** ���汾:			1.0
** ����:				�������ִ���������ڽ���ִ�ж������ģ���ָ�ͳ��PPM������DynamixelProtocolЭ��ջ��UART�ӿڡ�
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2009-03-19
** �汾:				1.0
** ����:				ִ�еľ��幦�ܺ����Ĳ��������뷵��ֵ�ķ�װ��
**
**------------------------------------------------------------------------------------------------------------------------
** �޶���:			����
** �޶�����:			2009-10-28
** �汾:				2.0
** ����:				�����߲������ִӶ�����������з������
**
**------------------------------------------------------------------------------------------------------------------------
** �޶���:			
** �޶�����:	    
** �汾:		    
** ����:            
**
*************************************************************************************************************************/
#ifndef SERVOUNIT_H_
#define SERVOUNIT_H_

#include "ConfigTypes.h"

#include "Drivers/Timer.h"
#include "Drivers/Led.h"
#include "Drivers/Ppm.h"
#include "Drivers/Uart.h"

#include "Lib/DynamixelProtocol.h"
#include "Lib/Mapping.h"

#include "Shell/TtlBusUnit.h"


#define		SERVOUNIT_GLOBALS

#ifndef   SERVOUNIT_GLOBALS
     #define SERVOUNIT_EXT     
#else 
     #define SERVOUNIT_EXT  extern
#endif 



/*************************************************************************************************************************
                                                       ģʽ�����ֶ���
*************************************************************************************************************************/
#define SERVO_MODE_SERVO				0x00
#define SERVO_MODE_MOTO					0x01

#define SERVO_EN						0x01			// ʹ��
#define SERVO_DIS						0x00			// ��ʹ��

#define SERVO_PPM_ID					0x0E
/*************************************************************************************************************************
                                                         �ṹ�嶨��
*************************************************************************************************************************/


typedef struct
{
	PPM_CONTROL_STRUCT*			p_ppm_control;

	uint16						last_position[BSU_MAX_SYNC_DEVICE_LENGTH];
	uint16						last_velocity[BSU_MAX_SYNC_DEVICE_LENGTH];

	uint8						node_mapping[32];

	tUint8Uint8Puint8*			pTest;
	tUint8Uint8Uint8*			pSetMode;
	tUint8Uint8Uint8*			pSetTorqueEnable;

	tUint8Uint8Uint16Uint16*	pSetPosition;
	tUint8Uint8Uint16Uint16*	pSetRegPosition;
	tUint8Uint8Uint16Uint16*	pSetSyncPosition;

	tUint8Uint8Uint8Uint16*		pSetVelocity;
	tUint8Uint8Uint8Uint16*		pSetRegVelocity;
	tUint8Uint8Uint8Uint16*		pSetSyncVelocity;

	tUint8Uint8Uint16Uint16*	pSetAngleLimit;
	tUint8Uint8Uint8*			pSetId;

	tUint8Uint8Puint16*			pGetPosition;
	tUint8Uint8Puint16*			pGetLoad;
	tUint8Uint8Puint16Puint16*	pGetAngleLimit;

	tUint8Void*					pAction;
	tUint8Void*					pActionSync;
	tVoidPuint8Uint8*			pInitNodeBuffer;

	tUint8Uint8Uint16Uint16Puint16Puint16* pCalcVelocity;
}SERVO_CONTROL_STRUCT;


/*************************************************************************************************************************
                                                       ���ƽṹ������
*************************************************************************************************************************/
SERVOUNIT_EXT SERVO_CONTROL_STRUCT servo_control;

/*************************************************************************************************************************
                                                         ��������
*************************************************************************************************************************/


#endif
/*************************************************************************************************************************
**                                                      �ļ�����
*************************************************************************************************************************/
