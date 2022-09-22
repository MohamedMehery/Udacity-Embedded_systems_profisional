
#include "app.h"
extern ST_accountsDB_t accounts[255];
extern ST_transaction_t trans[255];
extern int account_index;

static int transnumber ;

void Readconcel(char* cardholdername ,
				char* cardexpiredate,
				char* PAN,
				char* transdate,
				float* transamount)
{
	printf("Enter card holder name\n");
	scanf("%s",cardholdername);
	printf("Enter card expiration date\n");
	scanf("%s",cardexpiredate);
	printf("Enter card PAN\n");
	scanf("%s",PAN);
	printf("Enter transaction date\n");
	scanf("%s",transdate);	
	printf("Enter transaction amount\n");
	scanf("%f",transamount);	
}

// valid data
void fill_data(ST_cardData_t* cardData, ST_terminalData_t* termData , ST_transaction_t* transdata)
{

	char cardholdername[25] = {0};
	char cardexpirationdate[6] = {0};
	char PAN[20] = {0};
	char transdate[11] = {0};
	float transamount = 0.0f;
	Readconcel(cardholdername , cardexpirationdate,PAN , transdate, &transamount);

	//transaction fill data


	// fill cardData
	strcpy(cardData->cardHolderName ,cardholdername);
	//fill expiry date
	strcpy(cardData->cardExpirationDate , cardexpirationdate);
	//fill cardPAN
	strcpy(cardData->primaryAccountNumber , PAN);

	//setMaxAmount for ATM machine
	termData->maxTransAmount = 20000.0f;
	//setTransactionDate
	strcpy(termData->transactionDate , transdate);
	//set transamount
	termData->transAmount = transamount;
    //account fill account balance
    accounts[account_index].balance = 5000.0f;
    strcpy(accounts[account_index].primaryAccountNumber , "0123456789012345678");
	
	transdata->cardHolderData = *cardData;
	transdata->terminalData = *termData;	
	transdata->transactionSequenceNumber = transnumber++;
	trans[account_index] = *transdata;

}

void appStart(void)
{

	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData;
	EN_terminalError_t terminal_error;

	fill_data(&cardData , &termData , &transData);

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
