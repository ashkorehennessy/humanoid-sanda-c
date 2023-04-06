/*******************************************************Copyright*********************************************************
**                                            ����������ʢ�����˼������޹�˾
**                                                       �з���
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------�ļ���Ϣ---------------------------------------------------------
** �ļ�����:			PPM.h
** ����޶�����:  	2009-03-03
** ���汾:			1.0
** ����:				ʹ��16λTIMER�Ŀ���PWMģʽʵ��8·PPM����(API)
**
**------------------------------------------------------------------------------------------------------------------------
** ������:			����
** ��������:			2008-08-05
** �汾:				1.0
** ����:				ʹ��16λTIMER�Ŀ���PWMģʽʵ��8·PPM����(API)
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
#ifndef PPM_H_
#define PPM_H_

#include "ConfigTypes.h"
#include "Drivers/Timer.h"
#include "Drivers/Led.h"

#define		PPM_GLOBALS


#ifndef   PPM_GLOBALS
     #define PPM_EXT     
#else 
     #define PPM_EXT  extern
#endif 

#define PPM_PORT_ALONE			0
/*************************************************************************************************************************
                                                  PPM����˿ڶ���
*************************************************************************************************************************/
#if PPM_PORT_ALONE

	#define PPM0_PORT			PORTC							// ����PPM�����ʹ�õĶ˿����ݼĴ���
	#define PPM0_PORT_BIT		PC0								// ����˿���ÿһλ��PPM��ŵĶ�Ӧ��ϵ
	#define PPM0_DDR			DDRC							// ����PPM�����ʹ�õĶ˿ڷ���Ĵ���
	#define PPM0_DDR_BIT		DDC0

	#define PPM1_PORT			PORTC		
	#define PPM1_PORT_BIT		PC1	
	#define PPM1_DDR			DDRC	
	#define PPM1_DDR_BIT		DDC1

	#define PPM2_PORT			PORTC		
	#define PPM2_PORT_BIT		PC2	
	#define PPM2_DDR			DDRC	
	#define PPM2_DDR_BIT		DDC2

	#define PPM3_PORT			PORTC		
	#define PPM3_PORT_BIT		PC3	
	#define PPM3_DDR			DDRC	
	#define PPM3_DDR_BIT		DDC3

	#define PPM4_PORT			PORTC	
	#define PPM4_PORT_BIT		PC4		
	#define PPM4_DDR			DDRC	
	#define PPM4_DDR_BIT		DDC4

	#define PPM5_PORT			PORTC	
	#define PPM5_PORT_BIT		PC5		
	#define PPM5_DDR			DDRC	
	#define PPM5_DDR_BIT		DDC5

	#define PPM6_PORT			PORTC	
	#define PPM6_PORT_BIT		PC6		
	#define PPM6_DDR			DDRC	
	#define PPM6_DDR_BIT		DDC6

	#define PPM7_PORT			PORTC		
	#define PPM7_PORT_BIT		PC7			
	#define PPM7_DDR			DDRC	
	#define PPM7_DDR_BIT		DDC7

#else
	
	#define PPM_PORT			PORTC							// ����PPM�����ʹ�õĶ˿����ݼĴ���
	#define PPM_DDR				DDRC							// ����PPM�����ʹ�õĶ˿ڷ���Ĵ���

#endif

/*************************************************************************************************************************
                                                 ��ʱ��Ӳ����ض���
*************************************************************************************************************************/

#define PPM_COMPARE_INT		SIG_OUTPUT_COMPARE3A					// �����ж��������
#define PPM_TIMER_STATE		timer3_control.state					// ��ʱ��״̬��������
#define SetTimerPosition	(timer3_control.pSetCompareRegisterA)	// ����PPMλ�����ýӿں���


/*************************************************************************************************************************
                                                PPM����ֵ���������
*************************************************************************************************************************/
#define PPM_TOP_VAL			(uint16)(F_CPU / 400)				// 2.5ms��Ӧ�ڵ�ǰ����Ƶ�ʵ�ֵ����ֵΪ���������ֵ��
																// ��������Ϊ��2.5 * 10^(-3) * F_CPU
#define PPM_MAX_VAL			(uint16)(F_CPU / 400 - 10)			// ���������Ƚ�ƥ��ֵ��������жϷ�����10������
#define PPM_MIN_VAL			(uint16)(F_CPU / 2000)				// 0.5ms��Ӧ�ڵ�ǰ����Ƶ�ʵ�ֵ����ֵΪ��������С�Ƚ�ƥ��ֵ��
																// ��������Ϊ��0.5 * 10^(-3) * F_CPU
#define PPM_MIDDLE_VAL		(uint16)((3 * F_CPU) / 2000)		// 1.5ms��Ӧ�ڵ�ǰ����Ƶ�ʵ�ֵ�����ڳ�ʼ��

#define PPM_MAX_SPEED		(uint16)((PPM_MAX_VAL - PPM_MIN_VAL) / 15)
																// ������ٶȣ���0.1��60��Ϊ����ת�����
																// �൱��12��ÿ20ms��
																// �м���ʽ��(PPM_MAX_VAL - PPM_MIN_VAL) * 12 / 180

#define PPM_SERVO_MODE		0x0F
#define PPM_MOTO_MODE		0xF0

#define PPM_BROADCASTING	0x1E								// �㲥ͨ����, Ϊ0xFE - 0xE0, ����PPM�ڶ��ID���б�������E0--EF��

/*************************************************************************************************************************
                                                	�ṹ�嶨��
*************************************************************************************************************************/
typedef struct													// ����ppm��״̬�ṹ��ͨ���Ըýṹ��Ĳ��������Ըı�PPM��״̬
{
	volatile uint16 speed;										// PPM�ٶ�
	volatile uint16 target_position;							// PPMĿ��λ��	
	volatile uint16 current_position;							// PPM��ǰλ��
	volatile uint16 cw_limit;									// ˳ʱ��λ������(��Сֵ)
	volatile uint16 ccw_limit;									// ��ʱ��λ������(���ֵ)
	
	volatile uint8 mode;
	volatile uint8 enable_torque;								// Ť�����ʹ�ܱ�־
}PPM_STATE_STRUCT;


typedef uint8 (tSetPpmLimit)(uint8 channel, uint16 ccw, uint16 cw);
typedef uint8 (tGetPpmLimit)(uint8 channel, uint16* ccw, uint16* cw);
typedef uint8 (tGetPpmPosition)(uint8 channel, uint16* position);
typedef uint8 (tStopPpm)(uint8 id);
typedef uint8 (tSetPpmPosition)(uint8 channel, uint16 position, uint16 speed);
typedef uint8 (tSetPpmAcceleration)(uint8 channel, uint16 acceleration);
typedef uint8 (tSetPpmVelocity)(uint8 channel, uint8 direction, uint16 velocity);
typedef uint8 (tRunPpm)(uint8 channel);
typedef void (tInitPpm)(void);

typedef struct SPpmControl										// ����ppm�Ŀ��ƽṹ
{
	volatile uint8 state;
	volatile uint8 channel;										// PPMͨ��
	volatile uint8 channel_Mapping[8];
	
	tSetPpmLimit* pSetPpmLimit;
	tGetPpmLimit* pGetPpmLimit;
	tGetPpmPosition* pGetPpmPosition;
	tStopPpm* pStopPpm;
	tSetPpmAcceleration* pSetPpmAcceleration;
	tSetPpmVelocity* pSetPpmVelocity;
	
	tSetPpmPosition* pSetPpmPosition;							// λ�����ú���ָ��
	tRunPpm* pRunPpm;											// λ�ñ��ִ�к���ָ��
	tInitPpm* pInit;											// ��ʼ��ָ��
}PPM_CONTROL_STRUCT;

/*************************************************************************************************************************
                                                         ��������
*************************************************************************************************************************/


/*************************************************************************************************************************
                                                       ���ƽṹ������
*************************************************************************************************************************/
PPM_EXT PPM_CONTROL_STRUCT ppm_control;


#endif
/*************************************************************************************************************************
**                                                      �ļ�����
*************************************************************************************************************************/
