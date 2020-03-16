/****************************************************
  Copyright
  FileName:
  Author:        Version :          Date:
  Description:     
  Version:          
  Function List:  

  History:           
      <author>  <time>   <version >   <desc>

****************************************************/

/***------Include---------****/
//引用的C库头文件
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//Log 需要引用的头文件
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
/*************************************************
  Function:       
  Description:  led灯初始化
  Calls:              
  Called By:      
  Table Accessed:
  Table Updated: 
  Input:        
                     
  Output:       
  Return:         
  Others:      
*************************************************/
static void leds_init(void)
{
	ret_code_t err_code;
	
	//初始化BSP指示灯
	err_code = bsp_init(BSP_INIT_LEDS, NUULL);
	APP_ERROR_CHECK(err_code);
}
/*************************************************
  Function:       
  Description:  初始化日志打印模块
  Calls:              
  Called By:      
  Table Accessed:
  Table Updated: 
  Input:        
                     
  Output:       
  Return:         
  Others:      
*************************************************/
static void log_init(void)
{
	//初始化log程序模块
	ret_code_t err_code = NRF_LOG_INIT(NULL);
	APP_ERROR_CHECK(err_code);
	
	//设置log输出终端（根据sdk_config.h中的配置设置输出终端为UART或RTT）
	NRF_LOG_DEFAULT_BACKENDS_INIT();
}

/*************************************************
  Function:       
  Description:  空闲状态处理函数，处理挂起的日志
  Calls:              
  Called By:      
  Table Accessed:
  Table Updated: 
  Input:        
                     
  Output:       
  Return:         
  Others:      
*************************************************/
static void idle_state_handle(void)
{
	//处理挂起的log
	if(NRF_LOG_PROCESS() == false)
	{
		
	}
}
//主函数
int main(void)
{
	//初始化log程序模块
	log_init();
	
	//log打印信息
	NRF_LOG_INFO("this is a print test");
	
	while(true)
	{
		//处理挂起的LOG和运行电源管理
		idle_state_handle();
	}
}
