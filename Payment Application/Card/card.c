#include "card.h"

EN_cardError_t  getCardHolderName(ST_cardData_t*cardData)
{
    EN_cardError_t result = OK;
    if(!cardData)
    {
        result = WRONG_NAME;
        return result;
    }
    else
    {
        int len = strlen(cardData->cardHolderName);
        if(len < 20 || len >24)
        {
            result = WRONG_NAME ;
            return result;
        }
    }

    return result;
}

