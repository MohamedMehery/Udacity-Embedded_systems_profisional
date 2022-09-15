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

int main(void)
{
    uint8_t parr[4][11] = {
        "25/06/2022",
        "25/50",
        "25/60/2022",
        '\0'
    };
    ST_terminalData_t inputs[4] = {0};
    strcpy(inputs[0].transactionDate , parr[0]);
    strcpy(inputs[1].transactionDate , parr[1]);
    strcpy(inputs[2].transactionDate , parr[2]);
    strcpy(inputs[2].transactionDate , parr[3]);

    EN_terminalError_t outputs[4] = {OK};
    outputs[0] = getTransactionDate(&inputs[0]);
    outputs[1] = getTransactionDate(&inputs[1]);
    outputs[2] = getTransactionDate(&inputs[2]);
    outputs[3] = getTransactionDate(&inputs[3]);   
    for(int i = 0 ; i < 4 ; i++)
    {
        switch (outputs[i])
        {
        case WRONG_DATE:
                printf("WRONG_DATE\n");
            break;
        
        default:
                printf("OK\n");
            break;
        }
    }
    
    return 0;
}

