#include "server.h"


ST_accountsDB_t accounts[255] = {0};
ST_transaction trans[255] = {0};
int account_index = __INT32_MAX__;



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

EN_serverError_t saveTransaction(ST_transaction* transData)
{
	FILE* ptr;
	ptr = fopen("./INFO.txt", "r");
	if (!ptr) {
		return SAVING_FAILED;
	}
	int transnum;
	fscanf(ptr, "%d", &transnum);
	fclose(ptr);
	ptr = fopen("./INFO.txt", "w");
	fprintf(ptr, "%d", transnum+1);
	fclose(ptr);
	transData->transactionSequenceNumber = transnum+1;
	ptr = fopen("./TransactionsDB.txt", "a");
	if (!ptr) {
		return SAVING_FAILED;
	}
	//-=Transaction=-
	//	-Card Holder Name:
	//	-PAN:
	//	-Expiry Date:
	//	-Amount:
	//	-Max Amount:
	//	-Transaction State:
	//	-Transaction Sequence Number:
	fprintf(ptr, "-=Transaction=-\n");
	fprintf(ptr, "\tCard Holder Name: %s\n", transData->cardHolderData.cardHolderName);
	fprintf(ptr, "\t-PAN: %s\n", transData->cardHolderData.primaryAccountNumber);
	fprintf(ptr, "\t-Expiry Date: %s\n", transData->cardHolderData.cardExpirationDate);
	fprintf(ptr, "\t-Amount: %f\n", transData->terminalData.transAmount);
	fprintf(ptr, "\t-Max Amount: %f\n", transData->terminalData.maxTransAmount);
	fprintf(ptr, "\t-Transaction State: ");
	if (transData->transState == APPROVED) {
		fprintf(ptr, "APPROVED\n");
	}
	else if (transData->transState == DECLINED_INSUFFECIENT_FUND) {
		fprintf(ptr, "DECLINED_INSUFFECIENT_FUND\n");
	}
	else if (transData->transState == DECLINED_STOLEN_CARD) {
		fprintf(ptr, "DECLINED_STOLEN_CARD\n");
	}
	fprintf(ptr, "\t-Transaction Sequence Number: %d\n\n", transData->transactionSequenceNumber);
	fclose(ptr);
	return OK_server;
}

EN_transStat_t recieveTransactionData(ST_transaction *transData)
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


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction* transData)
{
	return OK_server;
}

int main(void)
{
    printf("No error\n");
    return 0;
}
