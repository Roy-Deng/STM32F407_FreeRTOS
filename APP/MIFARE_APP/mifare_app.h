#ifndef __MIFARE_APP_H
#define __MIFARE_APP_H
#include "rc523_driver.h"
#include "picc_rc523_lib.h"
#include "mifare1_operate.h"
#include  "system.h"

typedef enum
{
	CARD_RUQUEST_ERR = 1,
	CARD_ANTICOLL_ERR   ,
	CARD_SELECT_ERR     ,
	CARD_AUTHEN_ERR     ,
	CARD_READ_ERR       ,
	
}Mifare_Status;


#endif