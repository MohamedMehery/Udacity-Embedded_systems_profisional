
#include "app.h"

// valid data
void fill_data(ST_cardData_t* cardData, ST_terminalData_t* termData
)
{
	// fill cardData
	strcpy(cardData->cardHolderName , "01234567890123456789");
	//fill expiry date
	strcpy(cardData->cardExpirationDate , "05/25");
	//fill cardPAN
	strcpy(cardData->primaryAccountNumber , "0123456789012345");

	//setMaxAmount
	termData->maxTransAmount = 500.02f;
	//setTransactionDate
	strcpy(termData->transactionDate , "25/06/2022");
	//set transamount
	termData->transAmount = 432.3f;
}

void appStart(void)
{

	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData;
	EN_terminalError_t terminal_error;

	fill_data(&cardData , &termData);

	EN_cardError_t card_status = getCardHolderName(&cardData);

	if (card_status == WRONG_NAME) {
		printf("WRONG_NAME\n");
	}
	card_status = getCardExpiryDate(&cardData);
	if (card_status == WRONG_EXP_DATE) {
		printf("WRONG_EXP_DATE\n");
	}
	card_status = getCardPAN(&cardData);
	if (card_status == WRONG_PAN) {
		printf("WRONG_PAN\n");
	}
	terminal_error = setMaxAmount(&termData);
	if (terminal_error == INVALID_MAX_AMOUNT) {
		printf("INVALID_MAX_AMOUNT\n");
	}
	terminal_error = getTransactionDate(&termData);
	if (terminal_error == WRONG_DATE) {
		printf("WRONG_DATE\n");
	}
	terminal_error = isCardExpired(&cardData, &termData);
	if (terminal_error == EXPIRED_CARD) {
		printf("EXPIRED_CARD\n");
		return;
	}
	terminal_error = getTransactionAmount(&termData);
	if (terminal_error == INVALID_AMOUNT) {
		printf("INVALID_AMOUNT\n");
	}
	terminal_error = isBelowMaxAmount(&termData);
	if (terminal_error == EXCEED_MAX_AMOUNT){
		printf("EXCEED_MAX_AMOUNT\n");
		return;
	}
	transData.cardHolderData = cardData;
	transData.terminalData = termData;
	EN_transState_t transtate = recieveTransactionData(&transData);
	if (transtate == DECLINED_STOLEN_CARD) {
		printf("DECLINED_STOLEN_CARD\n");
	}
	else if (transtate== DECLINED_INSUFFECIENT_FUND) {
		printf("DECLINED_INSUFFECIENT_FUND\n");
	}
	else if (transtate == APPROVED) {
		printf("APPROVED\n");

	}
	
}

// int main() {

// 	//appStart();
// 	ST_cardData_t cardData;
// 	ST_terminalData_t termData	;
// 	fill_data(&cardData , &termData);
// 	EN_cardError_t card_status = getCardHolderName(&cardData);

// 	mohamed();
//     return 0;
// }
