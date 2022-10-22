
#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t * termData)
{
    EN_terminalError_t result = WRONG_DATE;

    int len = strlen(termData->transactionDate);
    if ((len == 10) && ((termData->transactionDate!=0)))
    {
        if((termData->transactionDate[2] != ('/')) && termData->transactionDate[5] != ('/')){
            return result ;
            }
        int month = ( (termData->transactionDate[3] - '0')*10 + (termData->transactionDate[4]-'0') );
        int day = ( (termData->transactionDate[0] - '0')*10 + (termData->transactionDate[1]-'0') );
        int year = ( (termData->transactionDate[8] - '0')*10 + (termData->transactionDate[9]-'0') );
        if((month < 1) || (month > 12)){
            return result;
        }
        if((year < 1) || (year>99) ){
            return result;
        }
        if((day < 1) || (day>31) ){
            return result;
        }
        result = TERMINAL_OK;
        return result;

    }
    else
    {
        return result;
    }
}


EN_terminalError_t isCardExpired(ST_cardData_t* cardData , ST_terminalData_t* termData)
{
    int termDatamonth = ( (termData->transactionDate[3] - '0')*10 + (termData->transactionDate[4]-'0') );
    int termDatayear = ((termData->transactionDate[7] - '0')*100 + (termData->transactionDate[8] - '0')*10 + (termData->transactionDate[9]-'0') );
    int cardDatamonth = ( (cardData->cardExpirationDate[0] - '0')*10 + (cardData->cardExpirationDate[1]-'0') );
    int cardDatayear = ( (cardData->cardExpirationDate[3] - '0')*10 + (cardData->cardExpirationDate[4]-'0') );
    EN_terminalError_t result = EXPIRED_CARD;
    if( cardDatayear < termDatayear )return result;
    if( cardDatamonth <= termDatamonth && (cardDatayear == termDatayear))return result;
    result = TERMINAL_OK;
    return result;
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t * termData)
{
    
    EN_terminalError_t result = INVALID_AMOUNT;
    if( termData->transAmount <= 0.0f)return result;
    result = TERMINAL_OK;
    return result;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t * termData)
{
    EN_terminalError_t result = EXCEED_MAX_AMOUNT;
    if( termData->transAmount > termData->maxTransAmount)return result;
    result = TERMINAL_OK;
    return result;

}

EN_terminalError_t setMaxAmount(ST_terminalData_t * termData)
{
    EN_terminalError_t result = INVALID_MAX_AMOUNT;
    if( termData->maxTransAmount <= 0.0f)return result;
    
    result = TERMINAL_OK;
    return result;
}

// // test gettransactionDate
// int main(void)
// {
//     ST_terminalData_t input ;
//     // ST_terminalData_t * input = NULL;

//     printf("Enter transactionDate\n");
//     scanf("%s",input.transactionDate);
//     EN_cardError_t outputs = OK;
//     outputs = getTransactionDate(&input);
//     switch (outputs)
//     {
//         case WRONG_DATE:
//             printf("WRONG_DATE\n");
//             break;
//         default:
//             printf("TERMINAL_OK\n");
//             break;
//     }

//     return 0;
// }


// // test isCardExpired
// int main(void)
// {
//     ST_terminalData_t input ;
//     ST_cardData_t cardinput;

//     // ST_terminalData_t * input = NULL;
//     // ST_terminalData_t * cardinput = NULL;

//     printf("Enter transactionDate\n");
//     scanf("%s",input.transactionDate);
//     printf("Enter card expire date\n");
//     scanf("%s",cardinput.cardExpirationDate);
//     EN_cardError_t outputs = TERMINAL_OK;
//     outputs = isCardExpired(&cardinput,&input);
//     switch (outputs)
//     {
//         case EXPIRED_CARD:
//             printf("EXPIRED_CARD\n");
//             break;
//         default:
//             printf("TERMINAL_OK\n");
//             break;
//     }

//     return 0;
// }

// //getTransactionAmount
// int main(void)
// {
//     ST_terminalData_t input ;

//     // ST_terminalData_t * input = NULL;
//     // ST_terminalData_t * cardinput = NULL;

//     printf("Enter getTransactionAmount\n");
//     scanf("%f",&input.transAmount);
 
//     EN_cardError_t outputs = TERMINAL_OK;
//     outputs = getTransactionAmount(&input);
//     switch (outputs)
//     {
//         case INVALID_AMOUNT:
//             printf("INVALID_AMOUNT\n");
//             break;
//         default:
//             printf("TERMINAL_OK\n");
//             break;
//     }

//     return 0;
// }


// int main(void)
// {
//     ST_terminalData_t input ;

//     // ST_terminalData_t * input = NULL;
//     // ST_terminalData_t * cardinput = NULL;

//     printf("Enter transAmount\n");
//     scanf("%f",&input.transAmount);
//     printf("Enter maxTransAmount\n");
//     scanf("%f",&input.maxTransAmount);

//     EN_cardError_t outputs = TERMINAL_OK;
//     outputs = isBelowMaxAmount(&input);
//     switch (outputs)
//     {
//         case EXCEED_MAX_AMOUNT:
//             printf("EXCEED_MAX_AMOUNT\n");
//             break;
//         default:
//             printf("TERMINAL_OK\n");
//             break;
//     }
//     return 0;
// }


// int main(void)
// {
//     ST_terminalData_t input ;

//     // ST_terminalData_t * input = NULL;
//     // ST_terminalData_t * cardinput = NULL;

//     printf("Enter maxTransAmount\n");
//     scanf("%f",&input.maxTransAmount);

//     EN_cardError_t outputs = TERMINAL_OK;
//     outputs = setMaxAmount(&input);
//     switch (outputs)
//     {
//         case INVALID_MAX_AMOUNT:
//             printf("INVALID_MAX_AMOUNT\n");
//             break;
//         default:
//             printf("TERMINAL_OK\n");
//             break;
//     }
//     return 0;
// }

