/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			DynamixelProtocol.h
** ����޶�����:		2009-03-11
** ���汾:			1.0
** ����:				Robotis��˾�����Dynamixel�����ŷ�����Э���Э��ջ
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2009-03-11
** �汾:				1.0
** ����:				 �������ɿ��ƽṹ�岢д���ͻ��壻
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
#ifndef DYNAMIXELPROTOCOL_H_
#define DYNAMIXELPROTOCOL_H_


#include "ConfigTypes.h"

#include "ConfigTypes.h"
#include "Drivers/Uart.h"
#include "Drivers/Led.h"


#define		DYNAMIXELPROTOCOL_GLOBALS

#ifndef   DYNAMIXELPROTOCOL_GLOBALS
     #define DYNAMIXELPROTOCOL_EXT     
#else 
     #define DYNAMIXELPROTOCOL_EXT  extern
#endif 


/*************************************************************************************************************************
**                                                    Instruction
*************************************************************************************************************************/
#define INST_PING 						0x01
#define INST_READ 						0x02
#define INST_WRITE 						0x03
#define INST_REG_WRITE 					0x04
#define INST_ACTION 					0x05
#define INST_RESET 						0x06
#define INST_DIGITAL_RESET 				0x07
#define INST_SYSTEM_READ 				0x0C
#define INST_SYSTEM_WRITE 				0x0D
#define INST_SYNC_WRITE 				0x83
#define INST_SYNC_REG_WRITE 			0x84


/*************************************************************************************************************************
**                                                    Э�������
*************************************************************************************************************************/
#define BSU_START1 						0xFF
#define BSU_START2 						0xFF


#define BSU_MAX_PARAMETER_LENGTH		0x0F				//���������

#define BSU_BROADCASTING_ID				0xFE

#define BSU_MAX_SYNC_DEVICE_LENGTH		0x20
#define BSU_MAX_SYNC_PARAMETER_LENGTH	0x04


/*************************************************************************************************************************
**                                                     �ṹ�嶨��
*************************************************************************************************************************/
typedef struct SBsuSyncSend
{
	uint8 update_amount;												// �豸���ݸ�������
	uint8 update_mapping[BSU_MAX_SYNC_DEVICE_LENGTH];					// �豸���ݸ���ӳ���

	uint8 first_address;												// �׵�ַ
	uint8 parameter_length;												// ��������

	uint8 write_parameter[BSU_MAX_SYNC_DEVICE_LENGTH][BSU_MAX_SYNC_PARAMETER_LENGTH];	// д�Ĵ�������
}BSU_SYNC_SEND_STRUCT;													// Dynamixelͬ�����Ϳ��ƽṹ��
/*************************************************************************************************************************
** ����id�ţ���ѯid_mappingӳ���device_amount�εõ��������ţ�����������update_mappingӳ����еĻ������ŶԱȣ�
** �Ƚ�ѭ��update_amount�Σ�����Ƚ�ƥ�䣬��update_amount�����£�����update_mapping[update_amount]���滺��
** ���ţ�update_amount++��������Ĳ���д��write_parameter[��������][];
*************************************************************************************************************************/

typedef struct SBsuSend
{
	uint8 device_id;										// �豸ID
	uint8 instruction_byte;									// ������
	uint8 first_address;									// �׵�ַ

	uint8 read_length;										// ���Ĵ�������

	uint8 parameter_length;									// ��������
	uint8 write_parameter[BSU_MAX_PARAMETER_LENGTH];		// д�Ĵ�������
}BSU_SEND_STRUCT;											// Dynamixel���Ϳ��ƽṹ��


typedef struct SBsuReceive
{
	uint8 device_id;										// �豸ID
	uint8 error_byte;										// �����־��
	uint8 parameter_length;									// ��������

	uint8 receive_parameter[BSU_MAX_PARAMETER_LENGTH];		// �Ĵ�������
}BSU_RECEIVE_STRUCT;										// Dynamixel���տ��ƽṹ��


typedef uint8 (tRxBsuPacket)(BSU_RECEIVE_STRUCT *p_bsu_receive, UART_CONTROL_STRUCT* p_uart_control);
typedef uint8 (tTxBsuPacket)(BSU_SEND_STRUCT* p_bsu_send, UART_CONTROL_STRUCT* p_uart_control);
typedef uint8 tTxBsuSyncPacket(BSU_SYNC_SEND_STRUCT* p_sync_send, const uint8* p_id_mapping, UART_CONTROL_STRUCT* p_uart_control);

typedef struct SBsuControl
{
	tRxBsuPacket* pRxPacket;
	tTxBsuPacket* pTxPacket;
	tTxBsuSyncPacket* pTxSyncPacket;
}BSU_CONTROL_STRUCT;										// Dynamixel���ƽṹ��


typedef struct SBsuStackStr
{
	BSU_RECEIVE_STRUCT bsu_receive;
	BSU_SEND_STRUCT bsu_send;
}BSU_STACK_STR_STRUCT;										// Dynamixel���ͽ��ջ���ṹ��


/*************************************************************************************************************************
**                                                     �ṹ������
*************************************************************************************************************************/
DYNAMIXELPROTOCOL_EXT BSU_CONTROL_STRUCT bsu_control;


#endif
/*************************************************************************************************************************
**                                                      �ļ�����
*************************************************************************************************************************/
