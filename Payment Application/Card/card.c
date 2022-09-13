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

// test code
int main()
{
    ST_cardData_t inputs[4];
    uint8_t parr[4][25] = {
       "01234567890123456789",
        "0123456789012345678901234",
        "012345678901234",
        '\0'
    };


    strcpy(inputs[0].cardHolderName , parr[0]);
    strcpy(inputs[1].cardHolderName , parr[1]);
    strcpy(inputs[2].cardHolderName , parr[2]);
    strcpy(inputs[2].cardHolderName , parr[3]);

    EN_cardError_t outputs[4] = {OK};

    outputs[0] = getCardHolderName(inputs[0].cardHolderName);
    outputs[1] = getCardHolderName(inputs[1].cardHolderName);
    outputs[2] = getCardHolderName(inputs[2].cardHolderName);
    outputs[3] = getCardHolderName(inputs[3].cardHolderName);
    
    for(int i = 0 ; i < 4 ; i++)
    {
        switch (outputs[i])
        {
        case WRONG_NAME:
                printf("WRONG_NAME\n");
            break;
        
        default:
                printf("OK\n");
            break;
        }
    }
}
