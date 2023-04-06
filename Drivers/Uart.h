/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			Uart.h
** ����޶�����:		2009-03-07
** ���汾:			1.0
** ����:				Uart�ı�׼��ɽӿ�(API)
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2009-03-07
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
#ifndef UART_H_
#define UART_H_

#include "ConfigTypes.h"
#include "Lib/Queue.h"
#include "Drivers/Led.h"


#define		UART_GLOBALS

#ifndef   UART_GLOBALS
     #define UART_EXT     
#else 
     #define UART_EXT  extern
#endif 

#define UART0_BSU_EN			1
#define UART0_ISR_MODE			0

/*************************************************************************************************************************
														Ӳ���궨��
*************************************************************************************************************************/
// UCSRnA
/*************************************************************************************************************************
 *	7		6		5		4		3		2		1		0
 *	RXCn	TXCn	UDREn	FEn		DORn	UPEn	U2Xn	MPCMn
 *
 * Bit 7 �C RXCn: USART ���ս���
 * Bit 6 �C TXCn: USART ���ͽ���
 * Bit 5 �C UDREn: USART ���ݼĴ�����
 * Bit 4 �C FEn: ֡����
 * Bit 3 �C DORn: ���ݹ���
 * Bit 2 �C UPEn: ��żУ�����
 * Bit 1 �C U2Xn: ���ٷ���
 * Bit 0 �C MPCMn: �ദ����ͨ��ģʽ
*************************************************************************************************************************/

// UCSRnB
/*************************************************************************************************************************
 *	7		6		5		4		3		2		1		0
 *	RXCIEn	TXCIEn	UDRIEn	RXENn	TXENn	UCSZn2	RXB8n	TXB8n
 *
 * Bit 7 �C RXCIEn: ���ս����ж�ʹ��
 * Bit 6 �C TXCIE: ���ͽ����ж�ʹ��
 * Bit 5 �C UDRIEn: USART ���ݼĴ������ж�ʹ��
 * Bit 4 �C RXENn: ����ʹ��
 * Bit 3 �C TXENn: ����ʹ��
 * Bit 2 �C UCSZn2: �ַ�����
 * Bit 1 �C RXB8n: ��������λ8
 * Bit 0 �C TXB8n: ��������λ8
*************************************************************************************************************************/

// UCSRnC
/*************************************************************************************************************************
 *	7		6		5		4		3		2		1		0
 *	�C		UMSELn	UPMn1	UPMn0	USBSn	UCSZn1	UCSZn0	UCPOLn
 *
 * Bit 6 �C UMSELn: USART ģʽѡ��,0 �첽����,1 ͬ������
 * Bit 5:4 �C UPMn1:0: ��żУ��ģʽ
 * 		UPMn1	UPMn0			��żģʽ
 * 		0		0 				��ֹ
 * 		0		1				����
 * 		1		0				żУ��
 * 		1		1				��У��
 * Bit 3 �C USBSn: ֹͣλѡ��
 * 		USBSn 					ֹͣλλ��
 * 		0						1-bit
 * 		1						2-bits
 * Bit 2:1 �C UCSZn1:0: �ַ�����
 * 		UCSZn2	UCSZn1	UCSZn0 	�ַ�����
 * 		0		0		0		5 λ
 * 		0		0		1		6 λ
 * 		0		1		0		7 λ
 * 		0		1		1		8 λ
 *		1		0		0		����
 *		1		0		1		����
 *		1		1		0		����
 *		1		1		1		9 λ
 * Bit 0 �C UCPOLn: ʱ�Ӽ���
 *		UCPOLn	�������ݵĸı�(TxDn ���ŵ����)	�������ݵĲ���(RxDn ���ŵ�����)
 *		0		XCKn������						XCKn �½���
 *		1		XCKn�½���						XCKn ������
 *
*************************************************************************************************************************/


#define UART_BAUDRATE_1X		0								// ������ģʽѡ��
#define UART_BAUDRATE_2X		1

#define UART_U2X_BIT			1

#define UART0_UDR				UDR0							// UART0��Ӳ���Ĵ���
#define UART0_UCSRA				UCSR0A
#define UART0_UCSRB				UCSR0B
#define UART0_UCSRC				UCSR0C

#define UART0_UBRR_H			UBRR0H
#define UART0_UBRR_L			UBRR0L

#define UART0_BAUDRATE			1000000							// UART0Ĭ�ϲ�����

#define UART1_UDR				UDR1							// UART1��Ӳ���Ĵ���
#define UART1_UCSRA				UCSR1A
#define UART1_UCSRB				UCSR1B
#define UART1_UCSRC				UCSR1C

#define UART1_UBRR_H			UBRR1H
#define UART1_UBRR_L			UBRR1L

#define UART1_BAUDRATE			115200							// UART1Ĭ�ϲ�����


#define UART0_PORT				PORTE							// ���������ʹ�õĶ˿����ݼĴ���
#define UART0_RX_PORT_BIT		PE0								// 
#define UART0_TX_PORT_BIT		PE1	
#define UART0_DDR				DDRE							// ������ʹ�õĶ˿ڷ���Ĵ���
#define UART0_RX_DDR_BIT		DDE0							
#define UART0_TX_DDR_BIT		DDE1

#define UART1_PORT				PORTD		
#define UART1_RX_PORT_BIT		PD2
#define UART1_TX_PORT_BIT		PD3
#define UART1_DDR				DDRD
#define UART1_RX_DDR_BIT		DDD2
#define UART1_TX_DDR_BIT		DDD3

#define UART0_EN_PORT			PORTA							
#define UART0_RX_EN_PORT_BIT	PA1								
#define UART0_TX_EN_PORT_BIT	PA0	
#define UART0_EN_DDR			DDRA							
#define UART0_RX_EN_DDR_BIT		DDA1							
#define UART0_TX_EN_DDR_BIT		DDA0


/*************************************************************************************************************************
														�ṹ�嶨��
*************************************************************************************************************************/
typedef struct SUartContorl
{
	volatile uint8		state;									// ״̬��־

	BUFFER_QUEUE		str_rx_buffer;							// �������ջ�����
	BUFFER_QUEUE		str_tx_buffer;							// �������ͻ�����

	tVoidVoid*			pInit;
	tVoidUint8Uint32*	pSetBaudRate;							// ���ò�����
	tVoidUint8*			pSendByte;								// ����1�ֽڱ���
	tUint8Puint8*		pReceiveByte;							// ����1�ֽڱ���
	tVoidUint8*			pWriteTxBuffer;							// ��Ԫ��д�뷢�ͻ������
	tVoidVoid*			pSendTxBuffer;							// �����ͻ�������е����ݷ���
	tUint8Void*			pTestReceiveBuffer;						// ���Խ��ջ����Ƿ��������
	tVoidVoid*			pClearReceiveBuffer;
}UART_CONTROL_STRUCT;


/*************************************************************************************************************************
														���ƽṹ������
*************************************************************************************************************************/
UART_EXT UART_CONTROL_STRUCT uart0_control;
UART_EXT UART_CONTROL_STRUCT uart1_control;


#endif
/*************************************************************************************************************************
**														�ļ�����
*************************************************************************************************************************/
