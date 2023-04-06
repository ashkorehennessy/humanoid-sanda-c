/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			UpRobotProtocol.h
** ����޶�����:		2009-03-16
** ���汾:			1.0
** ����:				������ʢ�����˼������޹�˾����Ļ����˿���UARTͨѶЭ���Э��ջ
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2009-03-16
** �汾:				1.0
** ����:				�������ɿ��ƽṹ�岢д���ͻ��壻
**					����UART���ջ����������ݣ�����״̬�ṹ�壻
**
**------------------------------------------------------------------------------------------------------------------------
** �޶���:
** �޶�����:
** �汾:
** ����:
**
**------------------------------------------------------------------------------------------------------------------------
** �޶���:
** �޶�����:
** �汾:
** ����:
**
*************************************************************************************************************************/
#ifndef UPROBOTPROTOCOL_H_
#define UPROBOTPROTOCOL_H_


#include "ConfigTypes.h"
#include "Drivers/Uart.h"
#include "Drivers/Led.h"

#define		UPROBOTPROTOCOL_GLOBALS

#ifndef   UPROBOTPROTOCOL_GLOBALS
     #define UPROBOTPROTOCOL_EXT     
#else 
     #define UPROBOTPROTOCOL_EXT  extern
#endif 




/*************************************************************************************************************************
**                                                    Э����ؿ�����
*************************************************************************************************************************/
#define UPROBOT_START1 							0x55
#define UPROBOT_START2 							0xAA


#define UPROBOT_MSSR_MAX_PARAMETER_LENGTH		0x08			// ���������
																// ����������̨�����ݰ�����Ϊ150bit������һ�η��ͳ���
																// ��ҪС��15byte���������������Ȳ��ܴ���15 - 7 = 8
#define UPROBOT_MRSS_MAX_PARAMETER_LENGTH		0x07



/*************************************************************************************************************************
**                                                     �ṹ�嶨��
*************************************************************************************************************************/
typedef struct
{
	uint8 device_id;											// �豸ID
	uint8 functional_unit;										// ���ܵ�Ԫ����
	uint8 method_code;											// ��������
	uint8 state_byte;											// ״̬��־��
	uint8 parameter_length;										// ��������

	uint8 parameter[UPROBOT_MRSS_MAX_PARAMETER_LENGTH];			// ��������
}UPROBOT_MRSS_STRUCT;											// UpRobot�������մӻ����ͽṹ��


typedef struct
{
	uint8 device_id;											// �豸ID
	uint8 functional_unit;										// ���ܵ�Ԫ����
	uint8 method_code;											// ��������
	
	uint8 parameter_length;										// ��������
	uint8 parameter[UPROBOT_MSSR_MAX_PARAMETER_LENGTH];			// ��������
}UPROBOT_MSSR_STRUCT;											// UpRobot�������ʹӻ����սṹ��


typedef uint8 (tUpRobotSlaveRxPacket)(UPROBOT_MSSR_STRUCT* p_uprobot_receive, UART_CONTROL_STRUCT* p_uart_control);
typedef uint8 (tUpRobotSlaveTxPacket)(UPROBOT_MRSS_STRUCT* p_uprobot_send, UART_CONTROL_STRUCT* p_uart_control);
typedef uint8 (tUpRobotMasterTxPacket)(UPROBOT_MSSR_STRUCT* p_uprobot_send, UART_CONTROL_STRUCT* p_uart_control);
typedef uint8 (tUpRobotMasterRxPacket)(UPROBOT_MRSS_STRUCT* p_uprobot_receive, UART_CONTROL_STRUCT* p_uart_control);


typedef struct
{
	tUpRobotMasterRxPacket* pUpRobotMasterRxPacket;				// ����ָ�붨��
	tUpRobotMasterTxPacket* pUpRobotMasterTxPacket;
	tUpRobotSlaveRxPacket* pUpRobotSlaveRxPacket;				// ����ָ�붨��
	tUpRobotSlaveTxPacket* pUpRobotSlaveTxPacket;
}UPROBOT_CONTROL_STRUCT;


typedef struct
{
	UPROBOT_MSSR_STRUCT str_slave_receive;						// �������սṹ��
	UPROBOT_MRSS_STRUCT str_slave_send;							// �������ͽṹ��
	UPROBOT_MRSS_STRUCT str_master_receive;						// �������սṹ��
	UPROBOT_MSSR_STRUCT str_master_send;						// �������ͽṹ��
}UPROBOT_STACK_STR_STRUCT;

/*************************************************************************************************************************
                                                       ���ƽṹ������
*************************************************************************************************************************/
UPROBOTPROTOCOL_EXT UPROBOT_CONTROL_STRUCT uprobot_control;


#endif
/*************************************************************************************************************************
**                                                      �ļ�����
*************************************************************************************************************************/
