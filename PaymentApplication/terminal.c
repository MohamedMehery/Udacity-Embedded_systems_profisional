
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
        result = OK;
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
    int termDatayear = ( (termData->transactionDate[9] - '0')*10 + (termData->transactionDate[10]-'0') );
    int cardDatamonth = ( (cardData->cardExpirationDate[0] - '0')*10 + (cardData->cardExpirationDate[1]-'0') );        
    int cardDatayear = ( (cardData->cardExpirationDate[3] - '0')*10 + (cardData->cardExpirationDate[4]-'0') );    

    EN_terminalError_t result = EXPIRED_CARD;
    if( cardDatayear < termDatayear )return result;
    if( cardDatamonth < termDatamonth )return result;
    result = OK;
    return result;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t * termData)
{
    EN_terminalError_t result = INVALID_AMOUNT;
    if( termData->transAmount <= 0.0f)return result;
    result = OK;
    return result;    
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t * termData)
{
    EN_terminalError_t result = EXCEED_MAX_AMOUNT;
    if( termData->transAmount > termData->maxTransAmount)return result;
    result = OK;
    return result;    

}

EN_terminalError_t setMaxAmount(ST_terminalData_t * termData)
{
    EN_terminalError_t result = INVALID_MAX_AMOUNT;
    if( termData->transAmount <= 0.0f)return result;
    result = OK;
    return result;    
}

// test gettransactionDate
// int main(void)
// {
//     uint8_t parr[4][11] = {
//         "25/06/2022",
//         "25/50",
//         "25/60/2022",
//         '\0'
//     };
//     ST_terminalData_t inputs[4] = {0};
//     strcpy(inputs[0].transactionDate , parr[0]);
//     strcpy(inputs[1].transactionDate , parr[1]);
//     strcpy(inputs[2].transactionDate , parr[2]);
//     strcpy(inputs[2].transactionDate , parr[3]);

//     EN_terminalError_t outputs[4] = {OK};
//     outputs[0] = getTransactionDate(&inputs[0]);
//     outputs[1] = getTransactionDate(&inputs[1]);
//     outputs[2] = getTransactionDate(&inputs[2]);
//     outputs[3] = getTransactionDate(&inputs[3]);   
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         switch (outputs[i])
//         {
//         case WRONG_DATE:
//                 printf("WRONG_DATE\n");
//             break;
        
//         default:
//                 printf("OK\n");
//             break;
//         }
//     }
    
//     return 0;
// }


// // test isCardExpired
// int main(void)
// {
//     uint8_t carddate[4][11] = {
//         "28/03/2023",
//         "27/04/2024",
//         "26/05/2025",
//         "25/06/2026"
//     };
//     uint8_t termdate[4][6] = {
//         "05/25",
//         "05/25",
//         "03/25",
//         "05/25"
//     };
//     ST_terminalData_t carddates[4] = {0};
//     ST_cardData_t termdates[11] = {0};

//     strcpy(carddates[0].transactionDate , carddate[0]);
//     strcpy(carddates[1].transactionDate , carddate[1]);
//     strcpy(carddates[2].transactionDate , carddate[2]);
//     strcpy(carddates[3].transactionDate , carddate[3]);
//     strcpy(termdates[0].cardExpirationDate , termdate[0]);
//     strcpy(termdates[1].cardExpirationDate , termdate[1]);
//     strcpy(termdates[2].cardExpirationDate , termdate[2]);
//     strcpy(termdates[3].cardExpirationDate , termdate[3]);    

//     EN_terminalError_t outputs[4] = {OK};
//     outputs[0] = isCardExpired(&termdates[0], &carddates[0]);
//     outputs[1] = isCardExpired(&termdates[1], &carddates[1]);
//     outputs[2] = isCardExpired(&termdates[2], &carddates[2]);
//     outputs[3] = isCardExpired(&termdates[3], &carddates[3]);
    
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         switch (outputs[i])
//         {
//         case EXPIRED_CARD:
//                 printf("EXPIRED_CARD\n");
//             break;
        
//         default:
//                 printf("OK\n");
//             break;
//         }
//     }
    
//     return 0;
// }

//getTransactionAmount
// int main(void)
// {
//     float testcases[4] = { 500.02f , 65.5f , -65.5f , 0.0f};
//     ST_terminalData_t inputs[4] = {0};
//     inputs[0].transAmount = testcases[0];
//     inputs[1].transAmount = testcases[1];
//     inputs[2].transAmount = testcases[2];
//     inputs[3].transAmount = testcases[3];

//     EN_terminalError_t outputs[4] = {OK};
//     outputs[0] = getTransactionAmount(&inputs[0]);
//     outputs[1] = getTransactionAmount(&inputs[1]);
//     outputs[2] = getTransactionAmount(&inputs[2]);
//     outputs[3] = getTransactionAmount(&inputs[3]);   
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         switch (outputs[i])
//         {
//         case INVALID_AMOUNT:
//                 printf("INVALID_AMOUNT\n");
//             break;
        
//         default:
//                 printf("OK\n");
//             break;
//         }
//     }
    
//     return 0;
// }

// int main(void)
// {
//     float testcases[4] = { 500.02f , 65.5f , 33.5f , 520.0f};
//     float maxcredit[4] = { 900.00f , 55.5f , 1000.0f , 0.0f};

//     ST_terminalData_t inputs[4] = {0};
//     inputs[0].transAmount = testcases[0];
//     inputs[1].transAmount = testcases[1];
//     inputs[2].transAmount = testcases[2];
//     inputs[3].transAmount = testcases[3];

//     inputs[0].maxTransAmount = maxcredit[0];
//     inputs[1].maxTransAmount = maxcredit[1];
//     inputs[2].maxTransAmount = maxcredit[2];
//     inputs[3].maxTransAmount = maxcredit[3];

//     EN_terminalError_t outputs[4] = {OK};
//     outputs[0] = isBelowMaxAmount(&inputs[0]);
//     outputs[1] = isBelowMaxAmount(&inputs[1]);
//     outputs[2] = isBelowMaxAmount(&inputs[2]);
//     outputs[3] = isBelowMaxAmount(&inputs[3]);   
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         switch (outputs[i])
//         {
//         case EXCEED_MAX_AMOUNT:
//                 printf("EXCEED_MAX_AMOUNT\n");
//             break;
        
//         default:
//                 printf("OK\n");
//             break;
//         }
//     }
    
//     return 0;
// }

// int main(void)
// {
//     float testcases[4] = { 500.02f , 65.5f , -65.5f , 0.0f};
//     ST_terminalData_t inputs[4] = {0};
//     inputs[0].transAmount = testcases[0];
//     inputs[1].transAmount = testcases[1];
//     inputs[2].transAmount = testcases[2];
//     inputs[3].transAmount = testcases[3];

//     EN_terminalError_t outputs[4] = {OK};
//     outputs[0] = setMaxAmount(&inputs[0]);
//     outputs[1] = setMaxAmount(&inputs[1]);
//     outputs[2] = setMaxAmount(&inputs[2]);
//     outputs[3] = setMaxAmount(&inputs[3]);   
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         switch (outputs[i])
//         {
//         case INVALID_MAX_AMOUNT:
//                 printf("INVALID_MAX_AMOUNT\n");
//             break;
        
//         default:
//                 printf("OK\n");
//             break;
//         }
//     }
    
//     return 0;
// }

