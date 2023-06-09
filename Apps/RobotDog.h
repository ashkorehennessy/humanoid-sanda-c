/*******************************************************Copyright*********************************************************
**                                            北京博创兴盛机器人技术有限公司
**                                                       研发部
**                                               http://robot.up-tech.com
**
**-------------------------------------------------------文件信息---------------------------------------------------------
** 文件名称:			SystemInit.h
** 最后修订日期:		2009-05-31
** 最后版本:			1.0
** 描述:				系统服务函数，用于通讯相应，实时调试
**
**------------------------------------------------------------------------------------------------------------------------
** 创建人:			律晔
** 创建日期:			2009-05-31
** 版本:				1.0
** 描述:				通讯相应
**
**------------------------------------------------------------------------------------------------------------------------
** 修订人:			
** 修订日期:		
** 版本:			
** 描述:		    
**
**------------------------------------------------------------------------------------------------------------------------
** 修订人:			
** 修订日期:	    
** 版本:		    
** 描述:            
**
*************************************************************************************************************************/
#ifndef ROBOTDOG_H_
#define ROBOTDOG_H_

#include "ConfigTypes.h"
#include "Apps/SystemTask.h"


#define		ROBOTDOG_GLOBALS

#ifndef		ROBOTDOG_GLOBALS
	#define ROBOTDOG_EXT
#else 
	#define ROBOTDOG_EXT  extern
#endif 


/*************************************************************************************************************************
														函数声明
*************************************************************************************************************************/
/*************************************************************************************************************************
** 函数名称:			SlowlyWalk
**
** 函数描述:			4自由度同步位置控制
**
**
** 输入变量:			const int16* vector, uint8 first_id, uint16 ref_time, uint16* calc_time;
** 返回值:			void;
**
** 使用宏或常量:		None;
** 使用全局变量:		None;
**
** 调用函数:			None;
**
** 创建人:			律晔
** 创建日期:			2009-10-20
**------------------------------------------------------------------------------------------------------------------------
** 修订人:
** 修订日期:
**------------------------------------------------------------------------------------------------------------------------
*************************************************************************************************************************/
ROBOTDOG_EXT void SlowlyWalk(void);


/*************************************************************************************************************************
** 函数名称:			TurnAround
**
** 函数描述:			转弯控制
**
**
** 输入变量:			const int16* vector, uint8 first_id, uint16 ref_time, uint16* calc_time;
** 返回值:			void;
**
** 使用宏或常量:		None;
** 使用全局变量:		None;
**
** 调用函数:			None;
**
** 创建人:			律晔
** 创建日期:			2009-10-21
**------------------------------------------------------------------------------------------------------------------------
** 修订人:
** 修订日期:
**------------------------------------------------------------------------------------------------------------------------
*************************************************************************************************************************/
ROBOTDOG_EXT void TurnLeft(void);
ROBOTDOG_EXT void TurnRight(void);

ROBOTDOG_EXT void RobotDog_Behavior(void);
ROBOTDOG_EXT void Test(void);


#endif
/*************************************************************************************************************************
**                                                      文件结束
*************************************************************************************************************************/
