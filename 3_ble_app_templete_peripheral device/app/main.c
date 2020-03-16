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
//���õ�C��ͷ�ļ�
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//Log ��Ҫ���õ�ͷ�ļ�
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
/*************************************************
  Function:       
  Description:  led�Ƴ�ʼ��
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
	
	//��ʼ��BSPָʾ��
	err_code = bsp_init(BSP_INIT_LEDS, NUULL);
	APP_ERROR_CHECK(err_code);
}
/*************************************************
  Function:       
  Description:  ��ʼ����־��ӡģ��
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
	//��ʼ��log����ģ��
	ret_code_t err_code = NRF_LOG_INIT(NULL);
	APP_ERROR_CHECK(err_code);
	
	//����log����նˣ�����sdk_config.h�е�������������ն�ΪUART��RTT��
	NRF_LOG_DEFAULT_BACKENDS_INIT();
}

/*************************************************
  Function:       
  Description:  ����״̬������������������־
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
	//��������log
	if(NRF_LOG_PROCESS() == false)
	{
		
	}
}
//������
int main(void)
{
	//��ʼ��log����ģ��
	log_init();
	
	//log��ӡ��Ϣ
	NRF_LOG_INFO("this is a print test");
	
	while(true)
	{
		//��������LOG�����е�Դ����
		idle_state_handle();
	}
}
