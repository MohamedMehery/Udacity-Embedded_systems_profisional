#include "card.h"

EN_cardError_t  getCardHolderName(ST_cardData_t*cardData)
{
    EN_cardError_t result = OK;
    if(!cardData->cardHolderName)
    {
        result = WRONG_NAME;
        return result;
    }
    else
    {
        int len = strlen(cardData->cardHolderName);
        if((len < 20) ||  (len > 24))
        {
            result = WRONG_NAME ;
            return result;
        }
    }

    return result;
}

EN_cardError_t  getCardExpiryDate(ST_cardData_t *cardData)
{
    EN_cardError_t result = WRONG_EXP_DATE;

    int len = strlen(cardData->cardExpirationDate);
    if ((len == 5) && ((cardData->cardExpirationDate!=0))) 
    {
        if((cardData->cardExpirationDate[2]) != ('/')){
            return result ;
            }
        int month = ( (cardData->cardExpirationDate[0] - '0')*10 + (cardData->cardExpirationDate[1]-'0') );
        int year = ( (cardData->cardExpirationDate[3] - '0')*10 + (cardData->cardExpirationDate[4]-'0') );
        if((month < 1) || (month > 12)){
            return result;
            }
        if((year < 1) || (year>99) ){
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

// getCardHolderName test code
// int main()
// {
//     ST_cardData_t inputs[4];
//     uint8_t parr[4][25] = {
//        "01234567890123456789",
//         "0123456789012345678901234",
//         "012345678901234",
//         '\0'
//     };


//     strcpy(inputs[0].cardHolderName , parr[0]);
//     strcpy(inputs[1].cardHolderName , parr[1]);
//     strcpy(inputs[2].cardHolderName , parr[2]);
//     strcpy(inputs[2].cardHolderName , parr[3]);

//     EN_cardError_t outputs[4] = {OK};

//     outputs[0] = getCardHolderName(&inputs[0]);
//     outputs[1] = getCardHolderName(&inputs[1]);
//     outputs[2] = getCardHolderName(&inputs[2]);
//     outputs[3] = getCardHolderName(&inputs[3]);
    
//     for(int i = 0 ; i < 4 ; i++)
//     {
//         switch (outputs[i])
//         {
//         case WRONG_NAME:
//                 printf("WRONG_NAME\n");
//             break;
        
//         default:
//                 printf("OK\n");
//             break;
//         }
//     }
// }

int main(void)
{
    uint8_t parr[4][6] = {
        "05/25",
        "25/50",
        "5/5",
        "0"
    };
    ST_cardData_t inputs[4] = {0};
    strcpy(inputs[0].cardExpirationDate , parr[0]);
    strcpy(inputs[1].cardExpirationDate , parr[1]);
    strcpy(inputs[2].cardExpirationDate , parr[2]);
    strcpy(inputs[2].cardExpirationDate , parr[3]);

    EN_cardError_t outputs[4] = {OK};
    outputs[0] = getCardExpiryDate(&inputs[0]);
    outputs[1] = getCardExpiryDate(&inputs[1]);
    outputs[2] = getCardExpiryDate(&inputs[2]);
    outputs[3] = getCardExpiryDate(&inputs[3]);   
    for(int i = 0 ; i < 4 ; i++)
    {
        switch (outputs[i])
        {
        case WRONG_EXP_DATE:
                printf("WRONG_EXP_DATE\n");
            break;
        
        default:
                printf("OK\n");
            break;
        }
    }
    
    return 0;
}
