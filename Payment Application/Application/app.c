
#include "app.h"

void appStart(void)
{

	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData;
	EN_terminalError_t ret_term;
	EN_cardError_t ret_card = getCardHolderName(&cardData);

	while (ret_card == WRONG_NAME) {
		printf("WRONG_NAME\n");
	}
	while (ret_card == WRONG_EXP_DATE) {
		printf("WRONG_EXP_DATE\n");
	}
	ret_card = getCardPAN(&cardData);
	while (ret_card == WRONG_PAN) {
		printf("WRONG_PAN\n");
	}
	ret_term = setMaxAmount(&termData);
	while (ret_term == INVALID_AMOUNT) {
		printf("INVALID_AMOUNT\n");
	}
	ret_term = getTransactionDate(&termData);
	while (ret_term == WRONG_DATE) {
		printf("WRONG_DATE\n");
	}
	ret_term = isCardExpired(&cardData, &termData);
	if (ret_term == EXPIRED_CARD) {
		printf("EXPIRED_CARD\n");
		return;
	}
	ret_term = getTransactionAmount(&termData);
	while (ret_term == INVALID_AMOUNT) {
		printf("INVALID_AMOUNT\n");
	}
	ret_term = isBelowMaxAmount(&termData);
	if (ret_term == EXCEED_MAX_AMOUNT){
		printf("EXCEED_MAX_AMOUNT\n");
		return;
	}
	transData.cardHolderData = cardData;
	transData.terminalData = termData;
	EN_transState_t transSt = recieveTransactionData(&transData);
	if (transSt == DECLINED_STOLEN_CARD) {
		printf("DECLINED_STOLEN_CARD\n");
	}
	else if (transSt== DECLINED_INSUFFECIENT_FUND) {
		printf("DECLINED_INSUFFECIENT_FUND\n");
	}
	else if (transSt == APPROVED) {
		printf("APPROVED\n");

	}
	
}

int main()
{
    appStart();
    printf("No error\n");
    return 0;
}

