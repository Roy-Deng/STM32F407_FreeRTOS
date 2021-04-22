#include "mifare_app.h"

uint8_t M1_Snr[8] = {0};
uint8_t Block_Data[16] = {0};
/*********************************************************************************************************
** 函数功能：读取余额
** 参    数: uchar ucAuthMod：keyA或者keyB
			 uint8_t sector：绝对块地址
			 uint8_t *key：秘钥:
** 返    回：MI_OK：成功
** 描    述：
*********************************************************************************************************/
Mifare_Status MifareCard_ReadBalance(uchar ucAuthMod , uint8_t block , uint8_t *key, uint32_t *balance)
{
	if(MI_OK != MIFARE1_Request())
	{
		return CARD_RUQUEST_ERR;  //无卡
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
