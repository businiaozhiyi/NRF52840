//引用的C库头文件
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
//Log需要引用的头文件
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

//初始化日志打印模块
static void log_init(void)
{
    //初始化log程序模块
	  ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);
    //设置log输出终端（根据sdk_config.h中的配置设置输出终端为UART或者RTT）
    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

//空闲状态处理函数。处理挂起的日志
static void idle_state_handle(void)
{
    //处理挂起的log
	  if (NRF_LOG_PROCESS() == false)
    {

    }
}


//主函数
int main(void)
{
		//初始化log程序模块
	log_init();

	//LOG打印信息
  NRF_LOG_INFO("BLE Template example:Log use JLINK-RTT as output terminal");

  //主循环
	while(true)
	{
		//处理挂起的LOG和运行电源管理
		idle_state_handle();
	}

}
