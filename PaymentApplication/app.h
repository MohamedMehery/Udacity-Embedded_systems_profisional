#ifndef _APP_H_
#define _APP_H_

#include "server.h"
#include "terminal.h"
#include "card.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

void appStart(void);
void fill_data(
	ST_cardData_t* cardData,
	ST_terminalData_t* termData
);


#endif
