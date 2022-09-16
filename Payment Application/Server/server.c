#include "server.h"


ST_accountsDB_t accounts[255] = {0};
ST_transaction_t trans[255] = {0};
int account_index = __INT32_MAX__;

EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
	if (isValidAccount(&transData->cardHolderData)==ACCOUNT_NOT_FOUND) {
		transData->transState = DECLINED_STOLEN_CARD;
		//if (saveTransaction(transData) == SAVING_FAILED)return INTERNAL_SERVER_ERROR;
		return DECLINED_STOLEN_CARD;
	}
	if (isAmountAvailable(&transData->terminalData)==LOW_BALANCE) {
		transData->transState = DECLINED_INSUFFECIENT_FUND;
		//if(saveTransaction(transData) == SAVING_FAILED)return INTERNAL_SERVER_ERROR;
		return DECLINED_INSUFFECIENT_FUND;
	}
	transData->transState = APPROVED;
	accounts[account_index].balance -= transData->terminalData.transAmount;
	if (saveTransaction(transData) == SAVING_FAILED) {
		return INTERNAL_SERVER_ERROR;
	}
	return APPROVED;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	uint8_t* PAN =cardData->primaryAccountNumber;
	//linear search through AccountsDB
	int is_exist = 0;
	int i, j;
	for (i = 0; i < 255; i++) {
		//if not empty(no more records)
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
		}
		else {
			break;
		}
	}
	if (!is_exist) {
		return DECLINED_STOLEN_CARD;
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

// int main(void)
// {
//     printf("No error\n");
//     return 0;
// }
