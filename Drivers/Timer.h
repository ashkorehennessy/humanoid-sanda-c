/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			Timer.h
** ����޶�����:		2009-03-18
** ���汾:			1.0
** ����:				ʹ��16λTIMER�Ŀ���PWMģʽʵ��2.5ms����ж���0.5-2.49ms�ɱ�ıȽ��ж�
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2008-03-18
** �汾:				1.0
** ����:				2.5ms����ж�Ϊϵͳʹ�õĲ���������ж���Kernel�е�Isp.c�д����Ƚ�ƥ���ж���Api�е�Ppm.c�д���
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
#ifndef TIMER_H_
#define TIMER_H_

#include "ConfigTypes.h"

#define		TIMER_GLOBALS

#ifndef   TIMER_GLOBALS
     #define TIMER_EXT     
#else 
     #define TIMER_EXT  extern
#endif 


/*************************************************************************************************************************
														 Ӳ���궨��
*************************************************************************************************************************/
#define TIMER0_OCR					OCR0

#define TIMER1_OCRA_H				OCR1AH
#define TIMER1_OCRA_L				OCR1AL
#define TIMER1_OCRB_H				OCR1BH
#define TIMER1_OCRB_L				OCR1BL
#define TIMER1_OCRC_H				OCR1CH
#define TIMER1_OCRC_L				OCR1CL

#define TIMER2_OCR					OCR2

#define TIMER3_OCRA_H				OCR3AH
#define TIMER3_OCRA_L				OCR3AL
#define TIMER3_OCRB_H				OCR3BH
#define TIMER3_OCRB_L				OCR3BL
#define TIMER3_OCRC_H				OCR3CH
#define TIMER3_OCRC_L				OCR3CL

#define TIMER0_TCNT					TCNT0

#define TIMER1_TCNT_H				TCNT1H
#define TIMER1_TCNT_L				TCNT1L

#define TIMER1_ICR_H				ICR1H
#define TIMER1_ICR_L				ICR1L

#define TIMER3_TCNT_H				TCNT3H
#define TIMER3_TCNT_L				TCNT3L

#define TIMER3_ICR_H				ICR3H
#define TIMER3_ICR_L				ICR3L

#define TIMER2_TCNT					TCNT2

#define TIMER1_TCCRA				TCCR1A
#define TIMER3_TCCRA				TCCR3A
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 *	COM1A1	COM1A0	COM1B1	COM1B0	COM1C1	COM1C0	WGM11	WGM10
 * Bit 7:6 �C COMnA1:0: ͨ��A �ıȽ����ģʽ
 * Bit 5:4 �C COMnB1:0: ͨ��B �ıȽ����ģʽ
 * Bit 3:2 �C COMnC1:0: ͨ��C �ıȽ����ģʽ
 * Bit 1:0 �C WGMn1:0: ���η���ģʽ
*************************************************************************************************************************/

#define TIMER1_TCCRB				TCCR1B
#define TIMER3_TCCRB				TCCR3B
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 * 	ICNC1	ICES1	�C		WGM13	WGM12	CS12	CS11	CS10
 * Bit 7 �C ICNCn: ���벶׽����������
 * Bit 6 �C ICESn: ���벶׽������ѡ��
 * Bit 5 �C ����λ
 * Bit 4:3 �C WGMn3:2: ���η���ģʽ
 * Bit 2:0 �C CSn2:0: ʱ��ѡ��
*************************************************************************************************************************/

#define TIMER1_TCCRC				TCCR1C
#define TIMER3_TCCRC				TCCR3C
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 * 	FOC1A	FOC1B	FOC1C	-		-		-		-		-
 * Bit 7 �C FOCnA: ǿ������Ƚ�ͨ��A
 * Bit 6 �C FOCnB: ǿ������Ƚ�ͨ��B
 * Bit 5 �C FOCnC: ǿ������Ƚ�ͨ��C
*************************************************************************************************************************/

#define TIMER0_TCCR					TCCR0
#define TIMER2_TCCR					TCCR2
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 * 	FOC0	WGM00	COM01	COM00	WGM01	CS02	CS01	CS00
 * Bit 7 �C FOC0: ǿ������Ƚ�
 * Bit 6, 3 �C WGM01:0: ���β���ģʽ
 * Bit 5:4 �C COM01:0: �Ƚ�ƥ�����ģʽ
 * Bit 2:0 �C CS02:0: ʱ��ѡ��
 *
 * ģʽ		WGM01		WGM00		T/C�Ĺ���ģʽ	TOP		OCR0�ĸ���ʱ��		TOV0 ����λʱ��
 * 0		0			0			��ͨ				0xFF	��������				MAX
 * 1		0			1			PWM����λ����	0xFF	TOP					BOTTOM
 * 2		1			0			CTC				OCR0	��������				MAX
 * 3		1			1			����PWM			0xFF	TOP					MAX
*************************************************************************************************************************/

#define TIMER_ASSR					ASSR						/* �첽״̬�Ĵ����� ASSR */
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 * 	�C		�C		�C		�C		AS0		TCN0UB	OCR0UB	TCR0UB
 * Bit 3 �C AS0: �첽T/C0
 * Bit 2 �C TCN0UB: T/C0 ������
 * Bit 1 �C OCR0UB: ����ȽϼĴ���0 ������
 * Bit 0 �C TCR0UB:T/C ���ƼĴ���0 ������
*************************************************************************************************************************/

#define TIMER_TIMSK					TIMSK						/* �жϿ��ƼĴ����� TIMSK */
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 *	OCIE2	TOIE2	TICIE1	OCIE1A	OCIE1B	TOIE1	OCIE0	TOIE0
 * Bit 7 �C OCIE2:T/C2 ����Ƚ�ƥ���ж�ʹ��
 * Bit 6 �C TOIE2:T/C2 ����ж�ʹ��
 * Bit 5 �C TICIE1: T/C1 ���벶׽�ж�ʹ��
 * Bit 4 �C OCIE1A:T/C1 ����Ƚ� A ƥ���ж�ʹ��
 * Bit 3 �C OCIE1B:T/C1 ����Ƚ� B ƥ���ж�ʹ��
 * Bit 2 �C TOIE1:T/C1 ����ж�ʹ��
 * Bit 1 �C OCIE0: T/C0 ����Ƚ�ƥ���ж�ʹ��
 * Bit 0 �C TOIE0: T/C0 ����ж�ʹ��
*************************************************************************************************************************/
#define TIMER_ETIMSK				ETIMSK						/* �жϿ��ƼĴ�����ETIMSK */
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 *	�C		�C		TICIE3	OCIE3A	OCIE3B	TOIE3	OCIE3C	OCIE1C
 * Bit 7:6 �C ����λ
 * Bit 5 �C TICIE3:T/C3, ���벶׽�ж�ʹ��
 * Bit 4 �C OCIE3A:T/C3 ����Ƚ� A ƥ���ж�ʹ��
 * Bit 3 �C OCIE3B:T/C3 ����Ƚ� B ƥ���ж�ʹ��
 * Bit 2 �C TOIE3:T/C3 ����ж�ʹ��
 * Bit 1 �C OCIE3C:T/C3 ����Ƚ� C ƥ���ж�ʹ��
 * Bit 0 �C OCIE1C:T/C1 ����Ƚ� C ƥ���ж�ʹ��
*************************************************************************************************************************/
#define TIMER_TIFR					TIFR						/* �жϱ�־�Ĵ����� TIFR */
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 *	OCF2	TOV2	ICF1	OCF1A	OCF1B	TOV1	OCF0	TOV0
 * Bit 7 �C OCF2: ����Ƚϱ�־2
 * Bit 6 �C TOV2:T/C2 �����־
 * Bit 5 �C ICF1:T/C1 ���벶׽��־λ
 * Bit 4 �C OCF1A:T/C1 ����Ƚ� A ƥ���־λ
 * Bit 3 �C OCF1B:T/C1 ����Ƚ� B ƥ���־λ
 * Bit 2 �C TOV1:T/C1 �����־
 * Bit 1 �C OCF0: ����Ƚϱ�־0
 * Bit 0 �C TOV0:T/C0 �����־
*************************************************************************************************************************/
#define TIMER_ETIFR					ETIFR						/* �жϱ�־�Ĵ�����ETIFR */
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 *	�C		�C		ICF3	OCF3A	OCF3B	TOV3	OCF3C	OCF1C
 * Bit 7:6 �C ����λ
 * Bit 5 �C ICF3:T/C3 ���벶׽��־λ
 * Bit 4 �C OCF3A:T/C3 ����Ƚ� A ƥ���־λ
 * Bit 3 �C OCF3B:T/C3 ����Ƚ� B ƥ���־λ
 * Bit 2 �C TOV3:T/C3 �����־
 * Bit 1 �C OCF3C:T/C3 ����Ƚ� C ƥ���־λ
 * Bit 0 �C OCF1C:T/C1 ����Ƚ� C ƥ���־λ
*************************************************************************************************************************/
#define TIMER_SFIOR					SFIOR						/* ���⹦��IO�Ĵ��� */
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 *	TSM		�C		�C		�C		ACME	PUD		PSR0	PSR321
 * Bit 7 �C TSM:T/C ͬ��ģʽ
 * Bit 1 �C PSR0: T/C0 Ԥ��Ƶ����λ
 * Bit 0 �C PSR321: T/C3��T/C2 �� T/C1 Ԥ��Ƶ����λ
*************************************************************************************************************************/


/*************************************************************************************************************************
														  Ӳ�������궨��
*************************************************************************************************************************/
#define TIMER3_TOP_VAL			(uint16)(F_CPU / 400)			// 2.5ms��Ӧ�ڵ�ǰ����Ƶ�ʵ�ֵ����ֵΪ���������ֵ��
																// ��������Ϊ��2.5 * 10^(-3) * F_CPU

#define TIMER3_INIT_COM_VAL		(uint16)(F_CPU / 2000)			// 0.5ms��Ӧ�ڵ�ǰ����Ƶ�ʵ�ֵ����ֵΪ��������С�Ƚ�ƥ��ֵ��
																// ��������Ϊ��0.5 * 10^(-3) * F_CPU


/*************************************************16λ��ʱ����ģʽ�趨**************************************************/
#define TIMER16_WGM10_MASK			0x03
#define TIMER16_WGM32_MASK			0x18

/*************************************************************************************************************************
��ʱ��/ ����������ģʽ			TOPOCR1x	����ʱ��TOV1		��λʱ��
0		��ͨģʽ					0xFFFF		��������			MAX
1		8λ��λ����PWM			0x00FF		TOP				BOTTOM
2		9λ��λ����PWM			0x01FF		TOP				BOTTOM
3		10λ��λ����PWM			0x03FF		TOP				BOTTOM
4		CTC						OCR1A		��������			MAX
5		8λ����PWM				0x00FF		TOP				TOP
6		9λ����PWM				0x01FF		TOP				TOP
7		10λ����PWM				0x03FF		TOP				TOP
8		��λ��Ƶ������PWM		ICR1		BOTTOM			BOTTOM
9		��λ��Ƶ������PWM		OCR1A		BOTTOM			BOTTOM
10		��λ����PWM				ICR1		TOP				BOTTOM
11		��λ����PWM				OCR1A		TOP				BOTTOM
12		CTC						ICR1		��������			MAX
13		����						�C			�C				�C
14		����PWM					ICR1		TOP				TOP
15		����PWM					OCR1A		TOP				TOP
*************************************************************************************************************************/
#define TIMER16_MODE_NORMAL			0x00

#define TIMER16_MODE_PWM_P8			0x01
#define TIMER16_MODE_PWM_P9			0x02
#define TIMER16_MODE_PWM_P10		0x03

#define TIMER16_MODE_CTC_OCR		0x04

#define TIMER16_MODE_PWM_FA8		0x05
#define TIMER16_MODE_PWM_FA9		0x06
#define TIMER16_MODE_PWM_FA10		0x07

#define TIMER16_MODE_PWM_PFICR		0x08
#define TIMER16_MODE_PWM_PFOCR		0x09

#define TIMER16_MODE_PWM_PICR		0x0A
#define TIMER16_MODE_PWM_POCR		0x0B

#define TIMER16_MODE_CTC_ICR		0x0C

#define TIMER16_MODE_PWM_FAICR		0x0E
#define TIMER16_MODE_PWM_FAOCR		0x0F

/********************************************* 16λ��ʱ���ķ�Ƶ�趨*****************************************************/
#define TIMER_CS_MASK				0x07

/*************************************************************************************************************************
0 ��ʱ��Դ (T/C ֹͣ)
1 clkI/O/1 ( ��Ԥ��Ƶ)
2 clkI/O/8 ( ����Ԥ��Ƶ��)
3 clkI/O/64 ( ����Ԥ��Ƶ��)
4 clkI/O/256 ( ����Ԥ��Ƶ��)
5 clkI/O/1024 ( ����Ԥ��Ƶ��)
6 �ⲿTx ���ţ��½�������
7 �ⲿTx ���ţ�����������
*************************************************************************************************************************/
#define TIMER16_PRESCALE_STOP		0x00
#define TIMER16_PRESCALE_1			0x01
#define TIMER16_PRESCALE_8			0x02
#define TIMER16_PRESCALE_64			0x03
#define TIMER16_PRESCALE_256		0x04
#define TIMER16_PRESCALE_1024		0x05
#define TIMER16_PRESCALE_TxFALL		0x06
#define TIMER16_PRESCALE_TxRISE		0x07


/********************************************* 16λ��ʱ�����ж��趨*****************************************************/
#define TIMER16_IMR_MASK			0x3C

/*************************************************************************************************************************
 * TIMSK
 * Bit 7 �C OCIE2:T/C2 ����Ƚ�ƥ���ж�ʹ��
 * Bit 6 �C TOIE2:T/C2 ����ж�ʹ��
 * Bit 5 �C TICIE1: T/C1 ���벶׽�ж�ʹ��
 * Bit 4 �C OCIE1A:T/C1 ����Ƚ� A ƥ���ж�ʹ��
 * Bit 3 �C OCIE1B:T/C1 ����Ƚ� B ƥ���ж�ʹ��
 * Bit 2 �C TOIE1:T/C1 ����ж�ʹ��
 * Bit 1 �C OCIE0: T/C0 ����Ƚ�ƥ���ж�ʹ��
 * Bit 0 �C TOIE0: T/C0 ����ж�ʹ��
**************************************************************************************************************************
 * ETIMSK
 * Bit 5 �C TICIE3:T/C3, ���벶׽�ж�ʹ��
 * Bit 4 �C OCIE3A:T/C3 ����Ƚ� A ƥ���ж�ʹ��
 * Bit 3 �C OCIE3B:T/C3 ����Ƚ� B ƥ���ж�ʹ��
 * Bit 2 �C TOIE3:T/C3 ����ж�ʹ��
 * Bit 1 �C OCIE3C:T/C3 ����Ƚ� C ƥ���ж�ʹ��
 * Bit 0 �C OCIE1C:T/C1 ����Ƚ� C ƥ���ж�ʹ��
*************************************************************************************************************************/
#define TIMER16_IMR_OCIC				0x08				// ����Ƚ� C ƥ���ж�ʹ��
#define TIMER16_IMR_ICI					0x05				// ���벶׽�ж�ʹ��
#define TIMER16_IMR_OCIA				0x04				// ����Ƚ� A ƥ���ж�ʹ��
#define TIMER16_IMR_OCIB				0x03				// ����Ƚ� B ƥ���ж�ʹ��
#define TIMER16_IMR_OI					0x02				// ����ж�ʹ��


/***************************************** 16λ��ʱ���ıȽ����ͨ��ģʽ����*********************************************/
#define TIMER16_COMA_MASK			0xC0
#define TIMER16_COMB_MASK			0x30
#define TIMER16_COMC_MASK			0x0C

/*************************************************************************************************************************
Bit 7:6 �C COM1A1:0: ͨ��A �ıȽ����ģʽ
Bit 5:4 �C COM1B1:0: ͨ��B �ıȽ����ģʽ

	COMx1				COMx0
	0					0				��ͨ�˿ڲ����� OC1A/OC1B δ����
	0					1				�Ƚ�ƥ��ʱOC1A/OC1B ��ƽȡ��
	1					0				�Ƚ�ƥ��ʱ����OC1A/OC1B( ����͵�ƽ)
	1					1				�Ƚ�ƥ��ʱ��λ OC1A/OC1B ( ����ߵ�ƽ)
*************************************************************************************************************************/
#define TIMER_PWM_DISCONNECT		0x00
#define TIMER_PWM_TOGGLE			0x01
#define TIMER_PWM_CLEAR				0x02
#define TIMER_PWM_SET				0x03

#define TIMER_PWM0_PORT				PORTB
#define TIMER_PWM0_DDR				DDRB
#define TIMER_PWM1_PORT				PORTB
#define TIMER_PWM1_DDR				DDRB
#define TIMER_PWM2_PORT				PORTB
#define TIMER_PWM2_DDR				DDRB
#define TIMER_PWM3_PORT				PORTE
#define TIMER_PWM3_DDR				DDRE

#define TIMER_PWM0_BIT				4
#define TIMER_PWM1A_BIT				5
#define TIMER_PWM1B_BIT				6
#define TIMER_PWM1C_BIT				7
#define TIMER_PWM2_BIT				7
#define TIMER_PWM3A_BIT				3
#define TIMER_PWM3B_BIT				4
#define TIMER_PWM3C_BIT				5


/********************************************* 8λ��ʱ�����ж��趨*****************************************************/

/*************************************************************************************************************************
 * TIMSK
 * Bit 7 �C OCIE2:T/C2 ����Ƚ�ƥ���ж�ʹ��
 * Bit 6 �C TOIE2:T/C2 ����ж�ʹ��
 * Bit 1 �C OCIE0: T/C0 ����Ƚ�ƥ���ж�ʹ��
 * Bit 0 �C TOIE0: T/C0 ����ж�ʹ��
*************************************************************************************************************************/
#define TIMER8_IMR_OCI				0x01
#define TIMER8_IMR_OI				0x00

/********************************************* 8λ��ʱ���ķ�Ƶ�趨*****************************************************/

/*************************************************************************************************************************
Timer0
0 ��ʱ��Դ (T/C ֹͣ)
1 clkI/O/1 ( ��Ԥ��Ƶ)
2 clkI/O/8 ( ����Ԥ��Ƶ��)
3 clkI/O/32 ( ����Ԥ��Ƶ��)
4 clkI/O/64 ( ����Ԥ��Ƶ��)
5 clkI/O/128 ( ����Ԥ��Ƶ��)
6 clkI/O/256 ( ����Ԥ��Ƶ��)
7 clkI/O/1024 ( ����Ԥ��Ƶ��)
*************************************************************************************************************************/
#define TIMER0_PRESCALE_STOP		0x00
#define TIMER0_PRESCALE_1			0x01
#define TIMER0_PRESCALE_8			0x02
#define TIMER0_PRESCALE_32			0x03
#define TIMER0_PRESCALE_64			0x04
#define TIMER0_PRESCALE_128			0x05
#define TIMER0_PRESCALE_256			0x06
#define TIMER0_PRESCALE_1024		0x07


/*************************************************************************************************************************
Timer2
0 ��ʱ��Դ (T/C ֹͣ)
1 clkI/O/1 ( ��Ԥ��Ƶ)
2 clkI/O/8 ( ����Ԥ��Ƶ��)
3 clkI/O/64 ( ����Ԥ��Ƶ��)
4 clkI/O/256 ( ����Ԥ��Ƶ��)
5 clkI/O/1024 ( ����Ԥ��Ƶ��)
6 �ⲿT2 ���ţ��½�������
7 �ⲿT2 ���ţ�����������
*************************************************************************************************************************/
#define TIMER2_PRESCALE_STOP		0x00
#define TIMER2_PRESCALE_1			0x01
#define TIMER2_PRESCALE_8			0x02
#define TIMER2_PRESCALE_64			0x03
#define TIMER2_PRESCALE_256			0x04
#define TIMER2_PRESCALE_1024		0x05
#define TIMER2_PRESCALE_T1FALL		0x06
#define TIMER2_PRESCALE_T1RISE		0x07


/********************************************* 8λ��ʱ���Ĺ���ģʽ�趨*****************************************************/
#define TIMER8_WGM_MASK				0x48
#define TIMER8_WGM0_OFFSET			0x06
#define TIMER8_WGM1_OFFSET			0x03
/*************************************************************************************************************************
 * 	7		6		5		4		3		2		1		0
 * 	FOC0	WGM00	COM01	COM00	WGM01	CS02	CS01	CS00
 * Bit 7 �C FOC0: ǿ������Ƚ�
 * Bit 6, 3 �C WGM01:0: ���β���ģʽ
 * Bit 5:4 �C COM01:0: �Ƚ�ƥ�����ģʽ
 * Bit 2:0 �C CS02:0: ʱ��ѡ��
 *
 * ģʽ		WGM01		WGM00		T/C�Ĺ���ģʽ	TOP		OCR0�ĸ���ʱ��		TOV0 ����λʱ��
 * 0		0			0			��ͨ				0xFF	��������				MAX
 * 1		0			1			PWM����λ����	0xFF	TOP					BOTTOM
 * 2		1			0			CTC				OCR0	��������				MAX
 * 3		1			1			����PWM			0xFF	TOP					MAX
*************************************************************************************************************************/
#define TIMER8_MODE_NORMAL			0x00
#define TIMER8_MODE_PWM_P			0x01
#define TIMER8_MODE_CTC_OCR			0x02
#define TIMER8_MODE_PWM_FA			0x03


/*************************************************************************************************************************
												��ʼ������
*************************************************************************************************************************/
// ��ʼ����ʹ�õĳ�ʼ��Ƶֵ
#define PRESCALE_1					1
#define PRESCALE_8					8
#define PRESCALE_64					54
#define PRESCALE_256				256
#define PRESCALE_1024				1024

// ��ʼ����Ƶֵ��256��Ƶ��
#define TIMER0_PRESCALE_VAL			PRESCALE_256
// ��ʼ���ж϶�ʱֵ��4ms��
#define TIMER0_TIMING_MS			2


/*************************************************************************************************************************
											���ݳ�ʼ��������е�����
*************************************************************************************************************************/
#if (1 == TIMER0_PRESCALE_VAL)
	#define  TIMER0_PRESCALE_INIT		TIMER0_PRESCALE_1
#elif (8 == TIMER0_PRESCALE_VAL)
	#define  TIMER0_PRESCALE_INIT		TIMER0_PRESCALE_8
#elif (64 == TIMER0_PRESCALE_VAL)
	#define  TIMER0_PRESCALE_INIT		TIMER0_PRESCALE_64
#elif (256 == TIMER0_PRESCALE_VAL)
	#define  TIMER0_PRESCALE_INIT		TIMER0_PRESCALE_256
#elif (1024 == TIMER0_PRESCALE_VAL)
	#define  TIMER0_PRESCALE_INIT		TIMER0_PRESCALE_1024
#else
	#error	!error: The value is meaningless in this model
#endif

// ���㶨ʱ������ֵ
#define TIMER0_RELOAD_VAL			(0x100 - (uint8)((TIMER0_TIMING_MS * (F_CPU / 1000)) / (uint32)TIMER0_PRESCALE_VAL ))

/*************************************************************************************************************************
												 �ṹ�嶨��
*************************************************************************************************************************/
typedef struct STimer16Control
{
	volatile uint8 state;

	tVoidVoid* pInit;
	tVoidUint16* pSetCounterRegister;
	tVoidUint16* pSetCompareRegisterA;
	tVoidUint16* pSetCompareRegisterB;
	tVoidUint16* pSetCompareRegisterC;
	tVoidUint16* pSetCaptureRegister;
	tVoidUint8* pSetMode;
	tVoidUint8* pSetPrescaler;
	tVoidUint8*	pSetCompareOutputAMode;
	tVoidUint8*	pSetCompareOutputBMode;
	tVoidUint8*	pSetCompareOutputCMode;
	tVoidUint8* pEnableInterrupt;
	tVoidUint8* pDisableInterrupt;

}TIMER16_CONTROL_STRUCT;


typedef struct STimer8Control
{
	volatile uint8 state;

	tVoidVoid* pInit;
	tVoidUint8* pSetCounterRegister;
	tVoidUint8* pSetCompareRegister;
	tVoidUint8* pSetMode;
	tVoidUint8* pSetPrescaler;
	tVoidUint8*	pSetCompareOutputMode;
	tVoidUint8* pEnableInterrupt;
	tVoidUint8* pDisableInterrupt;

}TIMER8_CONTROL_STRUCT;


/*************************************************************************************************************************
														���ƽṹ������
*************************************************************************************************************************/
TIMER_EXT TIMER8_CONTROL_STRUCT timer0_control;
TIMER_EXT TIMER16_CONTROL_STRUCT timer1_control;
TIMER_EXT TIMER16_CONTROL_STRUCT timer3_control;


/*************************************************************************************************************************
														��������
*************************************************************************************************************************/


#endif
/*************************************************************************************************************************
**														�ļ�����
*************************************************************************************************************************/
