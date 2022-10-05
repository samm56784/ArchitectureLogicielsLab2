#pragma once
#include "fonctions.h"

void ToucheEntrée(Lecture &Lec)
{
    REFERENCE_TIME rtNow = 0, rtEnd;
    char lettre = 'Z';
    //FILTER_STATE state;
    state etat = INITIAL;
    long evCode;
    Lec.hr = Lec.pSeeking->GetPositions(NULL, &rtEnd);
    while (lettre!='Q')
    {
        lettre = _getch();
        lettre = toupper(lettre);
        switch (lettre)
        {
        case 'A':
            Lec.fastforward();
            break;
        case 'P':
           // hr = pControl->GetState(0, (OAFilterState*)&state);
            if (etat == PAUSED)
            {
                Lec.play();
            }
            else
            {
                Lec.pause();
            }
            break;

        case 'R':
            Lec.rewind();
            break;
        case 'Q':
            Lec.quit();
            break;
        default:
            cout << "Caractere invalide !\n";
            break;
        }

    }

}
