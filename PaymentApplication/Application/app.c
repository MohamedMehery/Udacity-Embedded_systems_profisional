
#include "app.h"
extern ST_accountsDB_t accounts[255];
extern ST_transaction_t trans[255];
extern int account_index;

// valid data
void fill_data(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	// fill cardData
	strcpy(cardData->cardHolderName , "01234567890123456789");
	//fill expiry date
	strcpy(cardData->cardExpirationDate , "05/26");
	//fill cardPAN
	strcpy(cardData->primaryAccountNumber , "0123456789012345");

	//setMaxAmount
	termData->maxTransAmount = 500.02f;
	//setTransactionDate
	strcpy(termData->transactionDate , "25/06/2022");
	//set transamount
	termData->transAmount = 432.3f;
    //account fill
    accounts[account_index].balance = termData->maxTransAmount;
    strcpy(accounts[account_index].primaryAccountNumber , cardData->cardExpirationDate);
    trans[account_index].cardHolderData = *cardData;
    trans[account_index].terminalData = *termData;
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
		return;
	}
	card_status = getCardExpiryDate(&cardData);
	if (card_status == WRONG_EXP_DATE) {
		printf("WRONG_EXP_DATE\n");
		return;
	}
	card_status = getCardPAN(&cardData);
	if (card_status == WRONG_PAN) {
		printf("WRONG_PAN\n");
		return;
	}
	terminal_error = setMaxAmount(&termData);
	if (terminal_error == INVALID_MAX_AMOUNT) {
		printf("INVALID_MAX_AMOUNT\n");
		return;
	}
	terminal_error = getTransactionDate(&termData);
	if (terminal_error == WRONG_DATE) {
		printf("WRONG_DATE\n");
		return;
	}
	terminal_error = isCardExpired(&cardData, &termData);
	if (terminal_error == EXPIRED_CARD) {
		printf("EXPIRED_CARD\n");
		return;
	}
	terminal_error = getTransactionAmount(&termData);
	if (terminal_error == INVALID_AMOUNT) {
		printf("INVALID_AMOUNT\n");
		return;
	}
	terminal_error = isBelowMaxAmount(&termData);
	if (terminal_error == EXCEED_MAX_AMOUNT){
		printf("EXCEED_MAX_AMOUNT\n");
		return;
	}
	transData.cardHolderData = cardData;
	transData.terminalData = termData;

	EN_transState_t transtate = recieveTransactionData(&transData);
    EN_serverError_t save_error =  saveTransaction(&transData);
	if (transtate == DECLINED_STOLEN_CARD) {
		printf("DECLINED_STOLEN_CARD\n");
		return;
	}
	else if (transtate== DECLINED_INSUFFECIENT_FUND) {
		printf("DECLINED_INSUFFECIENT_FUND\n");
		return;
	}
	else if (transtate == APPROVED) {
		printf("APPROVED\n");

	}

}

// int main() {

// 	//appStart();
//     return 0;
// }
