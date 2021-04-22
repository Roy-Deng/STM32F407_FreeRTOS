#include "mifare_app.h"

uint8_t M1_Snr[8] = {0};
uint8_t Block_Data[16] = {0};
/*********************************************************************************************************
** �������ܣ���ȡ���
** ��    ��: uchar ucAuthMod��keyA����keyB
			 uint8_t sector�����Կ��ַ
			 uint8_t *key����Կ:
** ��    �أ�MI_OK���ɹ�
** ��    ����
*********************************************************************************************************/
Mifare_Status MifareCard_ReadBalance(uchar ucAuthMod , uint8_t block , uint8_t *key, uint32_t *balance)
{
	if(MI_OK != MIFARE1_Request())
	{
		return CARD_RUQUEST_ERR;  //�޿�
	}
	if(MI_OK != MIFARE1_Anticoll(SELECT_CASCADE_LEVEL_1, M1_Snr))
	{
		return CARD_ANTICOLL_ERR;
	}
	if(MI_OK != MIFARE1_Select(SELECT_CASCADE_LEVEL_1, M1_Snr))
	{
		return CARD_SELECT_ERR;
	}
	MIFARE1_LoadKey(ucAuthMod , 0 , block , key);
	if(MI_OK != MIFARE1_Authent(ucAuthMod , M1_Snr , 0, block))
	{
		return CARD_AUTHEN_ERR;
	}
//	if(MI_OK != MIFARE1_ReadPicc( block , Block_Data))
//	{
//		return CARD_READ_ERR;
//	}
	if(MI_OK != MIFARE1_ReadWallet( block , balance))
	{
		return CARD_READ_ERR;
	}
	return MI_OK;
}
