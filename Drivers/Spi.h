/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			Spi.h
** ����޶�����:		2009-03-30
** ���汾:			1.0
** ����:				Spi�ı�׼��ɽӿ�
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2009-03-30
** �汾:				1.0
** ����:				�����豸�ĳ�ʼ���������ʵĵ����������жϡ����������������õ�
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
#ifndef SPI_H_
#define SPI_H_

#include "ConfigTypes.h"
#include "Lib/Queue.h"
#include "Drivers/Led.h"
#include "Drivers/Uart.h"
#include "Drivers/VirtualUart.h"


#define		SPI_GLOBALS

#ifndef   SPI_GLOBALS
     #define SPI_EXT     
#else 
     #define SPI_EXT  extern
#endif 


/*************************************************************************************************************************
														Ӳ������
*************************************************************************************************************************/
#define SPI_DDR				DDRB
#define SPI_PORT			PORTB
#define SPI_PIN				PINB

#define SPI_MISO_BIT		3
#define SPI_MOSI_BIT		2
#define SPI_SCK_BIT			1
#define SPI_SS_BIT			0


#define SPI_SPCR			SPCR					// ���ƼĴ���
/*************************************************************************************************************************
 *  7    6    5   4     3    2    1    0
 * SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0
 *
 * Bit 7 �C SPIE: SPI �ж�ʹ��
 * 		��λ��,ֻҪ SPSR �Ĵ����� SPIF �� SREG �Ĵ�����ȫ���ж�ʹ��λ��λ,�ͻ�����
 * 		SPI �жϡ�
 * Bit 6 �C SPE: SPI ʹ��
 * 		SPE ��λ��ʹ�� SPI��
 * Bit 5 �C DORD: ���ݴ���
 * 		DORD ��λʱ���ݵ� LSB ���ȷ���;�������ݵ� MSB ���ȷ��͡�
 * Bit 4 �C MSTR: �� / ��ѡ��
 * 		MSTR ��λʱѡ������ģʽ,  ����Ϊ�ӻ��� ��� MSTR Ϊ ��1��,SS����Ϊ����,��������,
 * 		�� MSTR ������,�Ĵ��� SPSR �� SPIF ��λ�� �û������������� MSTR ��������ģʽ��
 * Bit 3 �C CPOL: ʱ�Ӽ���
 * 		CPOLΪ�߱�ʾ����ʱSCKΪ�ߵ�ƽ;����,��ʾ����ʱSCKΪ�͵�ƽ��
 *
 * CPOL		��ʼ��		������
 *  0		������		�½���
 *  1		�½���		������
 *
 * Bit 2 �C CPHA: ʱ����λ
 * 		CPHA ������������ SCK ����ʼ�ز��������� SCK �Ľ����ز�����
 *
 * CPHA		��ʼ��		������
 *   0		����			����
 *   1		����			����
 *
 * Bits 1, 0 �C SPR1, SPR0: SPI ʱ������ѡ�� 1 �� 0
 *
 * SPI2X	SPR1	SPR0	SCK Ƶ��
 *   0		 0		 0		fosc /4
 *   0		 0		 1		fosc /16
 *   0		 1		 0		fosc /64
 *   0		 1		 1		fosc /128
 *   1		 0		 0		fosc /2
 *   1		 0		 1		fosc /8
 *   1		 1		 0		fosc /32
 *   1		 1		 1		fosc /64
 *
*************************************************************************************************************************/

#define SPI_SPSR			SPSR					// ״̬�Ĵ���
/*************************************************************************************************************************
 *  7    6   5 4 3 2 1   0
 * SPIF WCOL �C �C �C �C �C SPI2X
 *
 * Bit 7 �C SPIF: SPI �жϱ�־
 * 		���з��ͽ�����,SPIF ��λ������ʱ�Ĵ��� SPCR �� SPIE ��ȫ���ж�ʹ��λ��λ,SPI
 * 		�жϼ���������� SPI Ϊ����, SS ����Ϊ����,�ұ�����, SPIF Ҳ����λ�������ж�
 * 		���̺� SPIF �Զ����㡣���߿���ͨ���ȶ� SPSR,�����ŷ��� SPDR ���� SPIF ���㡣
 * Bit 6 �C WCOL: д��ͻ��־
 * 		�ڷ��͵��ж� SPI ���ݼĴ��� SPDR д���ݽ���λ WCOL��WCOL ����ͨ���ȶ� SPSR,
 * 		�����ŷ��� SPDR �����㡣
 * Bit 0 �C SPI2X:SPI ����
 * 		��λ�� SPI ���ٶȼӱ�����Ϊ����,�� SCK Ƶ�ʿɴ� CPU Ƶ�ʵ�һ�롣��Ϊ�ӻ�,ֻ
 * 		�ܱ�֤ fosc /4��
 *
*************************************************************************************************************************/

#define SPI_SPDR			SPDR					// ���ݼĴ���


/*************************************************************************************************************************
 * 													���Ʋ�������
*************************************************************************************************************************/
#define	SPI_SPCR_SPR_OFFSET			0x00								// ʱ��Ƶ�ʿ���ƫ��
#define	SPI_SPCR_SPR_MASK			0x03 << SPI_SPCR_SPR_OFFSET			// ʱ��Ƶ�ʿ�������

#define SPI_PERSCALE_4				0x00								// F_CPU / 4
#define SPI_PERSCALE_16				0x01								// F_CPU / 16
#define SPI_PERSCALE_64				0x02								// F_CPU / 64
#define SPI_PERSCALE_128			0x03								// F_CPU / 128
#define SPI_PERSCALE_2				0x04								// F_CPU / 2
#define SPI_PERSCALE_8				0x05								// F_CPU / 8
#define SPI_PERSCALE_32				0x06								// F_CPU / 32

#define SPI_SPCR_CLOCKMODE_OFFSET	0x02								// ʱ�Ӽ�����λģʽƫ��
#define SPI_SPCR_CLOCKMODE_MASK		0x03 << SPI_SPCR_CLOCKMODE_OFFSET	// ʱ�Ӽ�����λģʽ����

#define SPI_CLOCKMODE_RISING		0x00								// ��������ʼ
#define SPI_CLOCKMODE_FALLING		0x01								// �½�����ʼ
#define SPI_CLOCKMODE_SAMPLING		0x00								// ��ʼ�ز���
#define SPI_CLOCKMODE_SETING		0x01								// ��ʼ������

#define SPI_MODE_MASTER				0x01								// ����ģʽ
#define SPI_MODE_SLAVE				0x00								// �ӻ�ģʽ

#define SPI_SEND_FILLER				0xF0								// ���ڽ����ӻ����ݵ������


/*************************************************************************************************************************
 * 													����״̬�����ֶ���
*************************************************************************************************************************/
#define SPI_SEND_STATE_WAITSEND			0									// �ȴ�����
#define SPI_SEND_STATE_SENDING			1									// ������
#define SPI_SEND_STATE_WAITUPDATE		2									// �ȴ�����
#define SPI_SEND_STATE_UPDATING			3									// ������
#define SPI_RECEIVE_STATE_WAITRECEIVE	0									// �ȴ�����
#define SPI_RECEIVE_STATE_RECEIVING	1										// ������

#define SPI_DATA_LENGTH_OFFSET			0									// ���ͳ���ƫ����
#define SPI_DATA_LENGTH_MASK			0x0F << SPI_DATA_LENGTH_OFFSET		// ���ͳ�������
#define SPI_DATA_DEVICE_OFFSET			4									// �����豸ƫ����
#define SPI_DATA_DEVICE_MASK			0x0F << SPI_DATA_DEVICE_OFFSET		// �����豸����

#define SPI_RECEIVE_CONTROL_WORD		0									// �������ݰ������������֡�
#define SPI_RECEIVE_PACKET				1									// �������ݰ����������ݰ���


/*************************************************************************************************************************
 * 													�����豸���
*************************************************************************************************************************/
//Rs422:
//		��������			����		0x01
#define SPI_DEVICE_UART_RECEIVE		0x01
//		����������		����		0x02
#define SPI_DEVICE_UART_BAUD		0x02
//		��������			����		0x03
#define SPI_DEVICE_UART_SEND		0x03
//AudioPluse:
//		��������д��		����		0x04
#define SPI_DEVICE_AUDIO_QUEUE		0x04
//		����������д��		����		0x05
#define SPI_DEVICE_AUDIO_ALONE		0x05
//		����				����		0x06
#define SPI_DEVICE_AUDIO_START		0x06
//		����ֹͣ			����		0x07
#define SPI_DEVICE_AUDIO_MUTE		0x07
//SystemVoltage:
//		��ѹ��ȡ			����		0x08
#define SPI_DEVICE_VOLTAGE_READ		0x08
//		��ѹ������ѹ����	����		0x09
#define SPI_DEVICE_VOLTAGE_MAX		0x09
//		Ƿѹ������ѹ����	����		0x0A
#define SPI_DEVICE_VOLTAGE_MIN		0x0A
//PowerAlame:
//		��Դ����			����		0x0B
#define SPI_DEVICE_POWER_ALAME		0x0B


/*************************************************************************************************************************
 * 													���ƽṹ�嶨��
*************************************************************************************************************************/
typedef struct SSpiControl
{
	uint8 				state;					// SPI״̬

	BUFFER_QUEUE		str_send_queue;			// ���Ͷ���

	uint8				send_device;			// �豸���ͱ��
	uint8				send_length;			// ������г���
	uint8				send_state;				// ״̬

	uint8				receive_state;			// ����״̬
	uint8				receive_index;			// ��������
	uint8				receive_length;			// �������ݳ���
	uint8				receive_device;			// ����������Դ
	uint8				receive_counter;		// ���ռ�����

	uint8				switch_asynchronous;	// �첽״̬�л���־

	tVoidVoid* 			pInit;
	tVoidVoid*			pEnableInterrupt;
	tVoidVoid*			pDisableInterrupt;
	tVoidUint8*			pSetClockRate;
	tVoidUint8Uint8*	pSetClockMode;
	tVoidUint8*			pSetMode;
	tVoidUint8*			pStartTransport;
	tUint8Uint8Puint8*	pTransportByte;
	tVoidUint8*			pWriteSendBuffer;
}SPI_CONTROL_STRUCT;


/*************************************************************************************************************************
���ƽṹ������
*************************************************************************************************************************/
SPI_EXT SPI_CONTROL_STRUCT spi_control;


#endif
/*************************************************************************************************************************
**                                                      �ļ�����
*************************************************************************************************************************/
