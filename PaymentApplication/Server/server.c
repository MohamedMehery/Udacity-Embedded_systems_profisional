
#include "server.h"


ST_accountsDB_t accounts[255] = {0};
ST_transaction_t trans[255] = {0};
int account_index = 0;
int pivot = 0;
int transnumber = 0 ;
void showdatabase(void)
{
	int iterator = 0;
	for(iterator = 0 ; iterator < pivot ; iterator++)
	{
		printf("Account #%d pin is %s	", iterator+1 , accounts[iterator].primaryAccountNumber);
		printf("Balance = %.2f	\n", accounts[iterator].balance);
	}
}

// void fill_accounts(void)
// {
// 	int iterator = 0;
// 	for(iterator = 0 ; iterator < 5 ; iterator++)
// 	{
// 		accounts[iterator].balance = 2000.0 ;
// 		account_index++;
// 		pivot++;
// 	}
// 	strcpy(accounts[0].primaryAccountNumber , "8989374615436851");
// 	strcpy(accounts[1].primaryAccountNumber , "3439374615436851");
// 	strcpy(accounts[2].primaryAccountNumber , "8444422615436851");
// 	strcpy(accounts[3].primaryAccountNumber , "8339374111436851");
// 	strcpy(accounts[4].primaryAccountNumber , "7779374615455551");
// }

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	if (isValidAccount(&(transData->cardHolderData) )==ACCOUNT_NOT_FOUND) {
		transData->transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;

	}
	if (isAmountAvailable(&transData->terminalData)==LOW_BALANCE) {
		transData->transState = DECLINED_INSUFFECIENT_FUND;		return DECLINED_INSUFFECIENT_FUND;
		if(saveTransaction(transData) == SAVING_FAILED)return INTERNAL_SERVER_ERROR;
	}
	transData->transState = APPROVED;
	accounts[account_index].balance -= transData->terminalData.transAmount;
	printf("The account new Balance = %.2f\n", accounts[account_index].balance );

	if (saveTransaction(transData) == SAVING_FAILED) {
		return INTERNAL_SERVER_ERROR;
	}
	return APPROVED;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	if(cardData == NULL)
	{
		return ACCOUNT_NOT_FOUND;
	}
	#define PAN  cardData->primaryAccountNumber

	int is_exist = 0;
	int i, j;
	for (i = 0; i < 255; i++) {

		if (accounts[i].primaryAccountNumber[0] != '\0') {
			int equal = 1;
			for (j = 0; j < 20; j++) {
				if (accounts[i].primaryAccountNumber[j] != PAN[j]) {
					equal = 0;		
					break;
				}
			}
			if (equal) {
				is_exist = 1;
				account_index = i;
				break;
			}
			else
			{
				
			}
		}
		else {
			//break;
		}
	}
	
	if (!is_exist) {
		return ACCOUNT_NOT_FOUND;
	}
	return OK_server;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	if (accounts[account_index].balance < termData->transAmount) {
		return LOW_BALANCE;
	}
	return OK_server;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	if((account_index > 254) || (account_index < 0)) return SAVING_FAILED;

	if (transData->transState == APPROVED) {
		trans[account_index].transState = APPROVED;
	}
	else if (transData->transState == DECLINED_INSUFFECIENT_FUND) {
		trans[account_index].transState = DECLINED_INSUFFECIENT_FUND;
	}
	else if (transData->transState == DECLINED_STOLEN_CARD) {
		trans[account_index].transState = DECLINED_STOLEN_CARD;
	}
	trans[account_index].transactionSequenceNumber += 1 ;
	return OK_server;
}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	if((account_index > 254) || (account_index < 0)) return INVALID_CARD;

	if (trans[account_index].transState == APPROVED) {
		transData->transState  = APPROVED;
	}
	else if (trans[account_index].transState == DECLINED_INSUFFECIENT_FUND) {
		transData->transState  = DECLINED_INSUFFECIENT_FUND;
	}
	else if (trans[account_index].transState == DECLINED_STOLEN_CARD) {
		transData->transState  = DECLINED_STOLEN_CARD;
	}	
	return OK_server;
}


// //fill accounts test
// int main(void)
// {
// 	int iterator;
//     // printf("No error\n");
// 	fill_accounts();
// 	for(iterator = 0 ; iterator < account_index ; iterator++)
// 	{
// 		printf("\t%.2f\n", accounts[iterator].balance);
// 		printf("\t%s\n", accounts[iterator].primaryAccountNumber);
// 	}	
//     return 0;
// }


void Readconcel2(char* cardholdername ,
				char* cardexpiredate,
				char* pan,
				char* transdate,
				float* transamount)
{
	printf("Enter card holder name\n");
	scanf("%s",cardholdername);
	printf("Enter card expiration date\n");
	scanf("%s",cardexpiredate);
	printf("Enter card pan\n");
	scanf("%s",pan);
	printf("Enter transaction date\n");
	scanf("%s",transdate);	
	printf("Enter transaction amount\n");
	scanf("%f",transamount);	
}

// valid data
void fill_data2(ST_cardData_t* cardData, ST_terminalData_t* termData , ST_transaction_t* transdata)
{

	char cardholdername[25] = {0};
	char cardexpirationdate[6] = {0};
	char pan[20] = {0};
	char transdate[11] = {0};
	float transamount = 0.0f;
	Readconcel2(cardholdername , cardexpirationdate, pan , transdate, &transamount);

	//transaction fill data


	// fill cardData
	strcpy(cardData->cardHolderName ,cardholdername);
	//fill expiry date
	strcpy(cardData->cardExpirationDate , cardexpirationdate);
	//fill cardPAN
	strcpy(cardData->primaryAccountNumber , pan);

	//setMaxAmount for ATM machine
	termData->maxTransAmount = 20000.0f;
	//setTransactionDate
	strcpy(termData->transactionDate , transdate);
	//set transamount
	termData->transAmount = transamount;
    //account fill account balance
    // accounts[account_index].balance = 5000.0f;
    // strcpy(accounts[account_index].primaryAccountNumber , "0123456789012345678");
	
	strcpy(transdata->cardHolderData.cardExpirationDate , cardData->cardExpirationDate);
	strcpy(transdata->cardHolderData.cardHolderName , cardData->cardHolderName);
	strcpy(transdata->cardHolderData.primaryAccountNumber ,cardData->primaryAccountNumber);

	transdata->terminalData.maxTransAmount = termData->maxTransAmount;
	strcpy(transdata->terminalData.transactionDate , termData->transactionDate);
	transdata->terminalData.transAmount = termData->transAmount;

	transdata->transactionSequenceNumber = transnumber++;
	trans[account_index] = *transdata;

}

//recieveTransactionData
// int main(void)
// {
// 	ST_cardData_t cardData;
// 	ST_terminalData_t termData;
// 	ST_transaction_t transData;
// 	fill_accounts();
// 	fill_data2(&cardData , &termData , &transData);
// 	EN_transState_t transtate = recieveTransactionData(&transData);
// 	// account_index = 500;
//     EN_serverError_t save_error =  saveTransaction(&transData);
// 	if (transtate == DECLINED_STOLEN_CARD) {
// 		printf("DECLINED_STOLEN_CARD\n");
// 	}
// 	else if (transtate== DECLINED_INSUFFECIENT_FUND) {
// 		printf("DECLINED_INSUFFECIENT_FUND\n");
// 	}
// 	else if (transtate == APPROVED) {
// 		printf("APPROVED\n");
// 		// showdatabase();
// 	}
// 	if(save_error == SAVING_FAILED) printf("SAVING_FAILED\n");
// 	else
// 	{
// 		printf("Transaction serquence number is %d \n",trans[account_index].transactionSequenceNumber);
// 		printf("OK_server\n");
// 	}
//     return 0;
// }

