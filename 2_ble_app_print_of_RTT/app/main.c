//���õ�C��ͷ�ļ�
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
//Log��Ҫ���õ�ͷ�ļ�
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

//��ʼ����־��ӡģ��
static void log_init(void)
{
    //��ʼ��log����ģ��
	  ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);
    //����log����նˣ�����sdk_config.h�е�������������ն�ΪUART����RTT��
    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

//����״̬������������������־
static void idle_state_handle(void)
{
    //��������log
	  if (NRF_LOG_PROCESS() == false)
    {

    }
}


//������
int main(void)
{
		//��ʼ��log����ģ��
	log_init();

	//LOG��ӡ��Ϣ
  NRF_LOG_INFO("BLE Template example:Log use JLINK-RTT as output terminal");

  //��ѭ��
	while(true)
	{
		//��������LOG�����е�Դ����
		idle_state_handle();
	}

}
