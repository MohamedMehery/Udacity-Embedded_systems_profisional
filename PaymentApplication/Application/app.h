#ifndef _APP_H_
#define _APP_H_

#include "../Server/server.h"
#include "../Terminal/terminal.h"
#include "../Card/card.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

void appStart(void);
void fill_data(
	ST_cardData_t* cardData,
	ST_terminalData_t* termData,
	ST_transaction_t * transdata
);


#endif
