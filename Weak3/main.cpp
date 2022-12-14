//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct polynomial {
//    int exponenet;     // ě§ě
//    float coefficient; // ęłě
//};
//
//int termCntArr[] = {0, 0, 0};
//
//void draw(polynomial *P, int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%8.3f %8d\n", P[i].coefficient, P[i].exponenet);
//    }
//}
//
//int cmp(const void *A, const void *B) {
//    if (((polynomial *)A)->exponenet < ((polynomial *)B)->exponenet) {
//        return 1;
//    } else if (((polynomial *)A)->exponenet > ((polynomial *)B)->exponenet) {
//        return -1;
//    } else {
//        return 0;
//    }
//}
//
//polynomial *padd(polynomial *A, polynomial *B) {
//    polynomial *temp = (polynomial *)malloc(sizeof(polynomial) * (termCntArr[0] + termCntArr[1]));
//    int aTerm = 0;
//    int bTerm = 0;
//    int tempTerm = 0;
//
//    while (1) {
//        if (aTerm >= termCntArr[0] && bTerm >= termCntArr[1]) {
//            break;
//        }
//        if (A[aTerm].exponenet > B[bTerm].exponenet) {
//            temp[tempTerm].exponenet = A[aTerm].exponenet;
//            temp[tempTerm++].coefficient = A[aTerm++].coefficient;
//            continue;
//        } else if (A[aTerm].exponenet < B[bTerm].exponenet) {
//            temp[tempTerm].exponenet = B[bTerm].exponenet;
//            temp[tempTerm++].coefficient = B[bTerm++].coefficient;
//            continue;
//        } else if (A[aTerm].exponenet == B[bTerm].exponenet) {
//            temp[tempTerm].exponenet = A[aTerm].exponenet;
//            temp[tempTerm++].coefficient = A[aTerm++].coefficient + B[bTerm++].coefficient;
//            continue;
//        }
//    }
//    termCntArr[2] = tempTerm;
//    return temp;
//}
//
//polynomial *pmul(polynomial *A, polynomial *B) {
//    int cycle = termCntArr[0];
//    termCntArr[0] = 0;
//    polynomial *D = (polynomial *)malloc(sizeof(polynomial) * 0);
//    for (int i = 0; i < cycle; i++) {
//        polynomial *Ci = (polynomial *)malloc(sizeof(polynomial) * termCntArr[1]);
//        for (int j = 0; j < termCntArr[1]; j++) {
//            Ci[j].exponenet = A[i].exponenet + B[j].exponenet;
//            Ci[j].coefficient = A[i].coefficient * B[j].coefficient;
//        }
//        printf("C%d(x)\n", i + 1);
//        draw(Ci, termCntArr[1]);
//        D = padd(D, Ci);
//        D = (polynomial *)realloc(D, (sizeof(polynomial) * termCntArr[2]));
//        termCntArr[0] = termCntArr[2];
//        free(Ci);
//    }
//
//    return D;
//}
//
//int main() {
//    int initSize[] = {10, 10};
//    polynomial *A = (polynomial *)malloc(sizeof(polynomial) * initSize[0]);
//    polynomial *B = (polynomial *)malloc(sizeof(polynomial) * initSize[1]);
//
//    while (1) {
//
//        int tempExpo;   // ě§ě
//        float tempCoef; // ęłě
//        printf("A(x)ě í­ě ěë Ľíě¸ě. (coef expon) : ");
//        scanf("%f %d", &tempCoef, &tempExpo);
//
//        if (tempExpo == -1) {
//            break; // -1 ěë Ľě ě˘ëŁ
//        }
//
//        if (termCntArr[0] == initSize[0] - 1) {
//            initSize[0] *= 2;
//            A = (polynomial *)realloc(A, sizeof(polynomial) * initSize[0]);
//        }
//        A[termCntArr[0]].exponenet = tempExpo;
//        A[termCntArr[0]].coefficient = tempCoef;
//        termCntArr[0] += 1;
//    }
//    qsort((polynomial *)A, termCntArr[0], sizeof(polynomial), cmp);
//
//    printf("ë¤í­ě A(x)\n");
//    printf("    coef    expon\n");
//    for (int i = 0; i < termCntArr[0]; i++) {
//        printf("%8.3f %8d\n", A[i].coefficient, A[i].exponenet);
//    }
//
//    while (1) {
//
//        int tempExpo;   // ě§ě
//        float tempCoef; // ęłě
//        printf("B(x)ě í­ě ěë Ľíě¸ě. (coef expon) : ");
//        scanf("%f %d", &tempCoef, &tempExpo);
//
//        if (tempExpo == -1) {
//            break; // -1 ěë Ľě ě˘ëŁ
//        }
//
//        if (termCntArr[1] == initSize[1] - 1) {
//            initSize[1] *= 2;
//            B = (polynomial *)realloc(B, sizeof(polynomial) * initSize[1]);
//        }
//        B[termCntArr[1]].exponenet = tempExpo;
//        B[termCntArr[1]].coefficient = tempCoef;
//        termCntArr[1] += 1;
//    }
//    qsort((polynomial *)B, termCntArr[1], sizeof(polynomial), cmp);
//
//    printf("ë¤í­ě B(x)\n");
//    printf("    coef    expon\n");
//    for (int i = 0; i < termCntArr[1]; i++) {
//        printf("%8.3f %8d\n", B[i].coefficient, B[i].exponenet);
//    }
//
//    polynomial *D;
//    D = padd(A, B);
//    printf("3.2 ë¤í­ě ë§ě\në¤í­ě ë§ě ę˛°ęłź : D(x)\n");
//    printf("    coef    expon\n");
//    draw(D, termCntArr[2]);
//
//    D = pmul(A, B);
//    printf("D(x) ęłąě\n");
//    draw(D, termCntArr[2]);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct polynomial {
    int exponenet;     // ě§ě
    float coefficient; // ęłě
};

// íěŹ ë¤í­ě í­ě ę°ě, 0ë˛ě§¸ ě¸ëąě¤ë A, 1ë˛ě§¸ ě¸ëąě¤ë B, 2ë˛ě§¸ ě¸ëąě¤ë A+Bí ë¤í­ěě í­ěę°ě
int termCntArr[] = {0, 0, 0};

// ë¤í­ě ěśë Ľ í¨ě
void draw(polynomial *P, int n) {
    for (int i = 0; i < n; i++) {
        printf("%8.3f %8d\n", P[i].coefficient, P[i].exponenet);
    }
}

// ę° ëšęľ í¨ě íľě ë Ź í¨ě ě ë Ź, ë´ëŚźě°¨ě ëšęľ.
int cmp(const void *A, const void *B) {
    if (((polynomial *)A)->exponenet < ((polynomial *)B)->exponenet) {
        return 1;
    } else if (((polynomial *)A)->exponenet > ((polynomial *)B)->exponenet) {
        return -1;
    } else {
        return 0;
    }
}

// ë¤í­ě ëíę¸° í¨ě
polynomial *padd(polynomial *A, polynomial *B) {
    // ěěëĄ ëíę¸° í ę°ě ě ěĽíë ë¤í­ě
    polynomial *temp = (polynomial *)malloc(sizeof(polynomial) * (termCntArr[0] + termCntArr[1]));
    // A ě ě¸ëąě¤
    int aTerm = 0;
    // Bě ě¸ëąě¤
    int bTerm = 0;
    // Tempě ě¸ëąě¤
    int tempTerm = 0;

    while (1) {
        // Aě¸ëąě¤ě Bě¸ëąě¤ę° í­ě ę°ě ě´ěěź ë íěś, ëśëąěě´ == ě´ ěëëź >= ěźëĄ íë ě´ě ë
        //ěëěě aTermě´ë bTerm ëě¤ íëę° termCntArr[i]ę°ëëŠ´ ë¤í­ěě´ ě ěĽë ę°ě ëě´ 0,0 ě ę°ëŚŹí¤ę¸° ëëŹ¸ě
        //  ë§ě˝ aTermě´ termCntArr[0]ě´ëëŠ´ ë¤ě ë°ëłľëŹ¸ěě, Aě ě§ěě ęłěę° 0, 0 ě´ęł  ë¤ëĽ¸ í ë¤í­ěě(B) ë§ě§ë§
        //  ě§ěę° 0ě´ëŠ´
        // Běě ě§ěę° ëíŹę˛ ëë ę˛ě´ ěëëź Aěě ě§ěě ę°ë¤ęł  íě íę¸° ëëŹ¸ě aTermě´ ëśëě´íę˛
        // termCntArr[0]ě´ěě´ ëë¤. ě¤ë˛ íëĄě°ę° ěźě´ëě§ë ěě ě ě´ě ëě í ëší ë¤í­ěë¤ě ě¤ě  í­ě ę°ěëł´ë¤ íŹę˛
        // ěŹě´ěŚëĽź ě¤Źę¸° ëëŹ¸ě
        if (aTerm >= termCntArr[0] && bTerm >= termCntArr[1]) {
            break;
        }
        // Aě§ěę° í´ ë ěě ë¤í­ěě ě§ěęłź ęłěëĽź ëŁě´ěŁźęł  ě¸ëąě¤ëĽź +1 í´ě¤
        if (A[aTerm].exponenet > B[bTerm].exponenet) {
            temp[tempTerm].exponenet = A[aTerm].exponenet;
            temp[tempTerm++].coefficient = A[aTerm++].coefficient;
            continue;
        }
            // Bě§ěę° í´ ë ěě ë¤í­ěě ě§ěě ęłěëĽź ëŁě´ěŁźęł  ě¸ë°ě¤ëĽź +1 í´ě¤
        else if (A[aTerm].exponenet < B[bTerm].exponenet) {
            temp[tempTerm].exponenet = B[bTerm].exponenet;
            temp[tempTerm++].coefficient = B[bTerm++].coefficient;
            continue;
        }
            // Aě§ěě B ě§ěę° ę°ě ë.
        else if (A[aTerm].exponenet == B[bTerm].exponenet) {
            temp[tempTerm].exponenet = A[aTerm].exponenet;
            temp[tempTerm++].coefficient = A[aTerm++].coefficient + B[bTerm++].coefficient;
            continue;
        }
    }
    // A+Bě í­ě ę°ě tempTermě ěë°ě´í¸ í´ě¤
    termCntArr[2] = tempTerm;
    // ëí ë¤í­ě ë°í
    return temp;
}

// ë¤í­ě ęłąě í¨ě
polynomial *pmul(polynomial *A, polynomial *B) {
    // Aí­ě ę°ěë§íź ęłąíëŻëĄ cycle ëłěě ëŁě´ě¤
    int cycle = termCntArr[0];
    // ęłąíí ëí  ë formatě D = padd(D,Ci) ě´ëŻëĄ ě˛ě Dě í­ě ę°ěë 0ěźëĄí´ě¤. D + Ci ííě´ëŻëĄ Dę°
    // termCntArr[0], Cię° termCntArr[1]ě í­ě ę°ěëĽź ę°ě§.
    termCntArr[0] = 0;
    // ë¤í­ě D ëě í ëš
    polynomial *D = (polynomial *)malloc(sizeof(polynomial) * 0);

    for (int i = 0; i < cycle; i++) {
        // A[i] * BëĽź ęłąí´ě ě ěĽí  Ci ë¤í­ě ëě  í ëš
        polynomial *Ci = (polynomial *)malloc(sizeof(polynomial) * termCntArr[1]);
        // ęłąí´ě§ë Bë í­ě´ termCntArr[1] ę° ë§íź ěěźëŻëĄ ë°ëłľëŹ¸
        for (int j = 0; j < termCntArr[1]; j++) {
            Ci[j].exponenet = A[i].exponenet + B[j].exponenet;
            Ci[j].coefficient = A[i].coefficient * B[j].coefficient;
        }
        printf("singul_mul - C%d(x)\n", i + 1);
        // ęłąí´ě§ Ci ę° ěśë Ľ
        draw(Ci, termCntArr[1]);
        // ęłąí´ě§ ę° ëíę¸°
        D = padd(D, Ci);
        // D = D + Ci ě´ę¸° ëëŹ¸ě ëí´ě§ Dě í­ěę°ě ěë°ě´í¸
        termCntArr[0] = termCntArr[2];
        // ëě í ëší Ci í´ě 
        free(Ci);
        D = (polynomial *)realloc(D, (sizeof(polynomial) * termCntArr[2]));
    }
    // ęłąěę˛°ęłź ë°í
    return D;
}

int main() {
    // ě´ę¸° ë¤í­ě ěŹě´ěŚ, 0ë˛ě§¸ ě¸ëąě¤ë A, 1ë˛ě§¸ ě¸ëąě¤ë B
    int initSize[] = {10, 10};
    polynomial *A = (polynomial *)malloc(sizeof(polynomial) * initSize[0]);
    polynomial *B = (polynomial *)malloc(sizeof(polynomial) * initSize[1]);

    printf("3.1. ë¤í­ě ěěą\n");
    while (1) {

        int tempExpo;   // ě§ě
        float tempCoef; // ęłě
        printf("A(x)ě í­ě ěë Ľíě¸ě. (coef expon) : ");
        scanf("%f %d", &tempCoef, &tempExpo);

        if (tempExpo == -1) {
            break; // ě§ě -1 ěë Ľě ě˘ëŁ
        }

        // ěë Ľë í­ě´ sizeę° ëëŠ´ ěë ěŹě´ěŚ ëë°°ë§íź ěŹí ëš, ěŹě´ěŚ ę° ëë°°í´ě¤
        if (termCntArr[0] == initSize[0] - 1) {
            A = (polynomial *)realloc(A, sizeof(polynomial) * initSize[0] * 2);
            initSize[0] *= 2;
        }

        // ę°ëŁę¸°
        A[termCntArr[0]].exponenet = tempExpo;
        A[termCntArr[0]].coefficient = tempCoef;
        // í­ě ę°ě +1 ěš´ě´í
        termCntArr[0] += 1;
    }
    // stdlib.h íěźě ë¤ě´ěë íľě ë Źí¨ě
    qsort((polynomial *)A, termCntArr[0], sizeof(polynomial), cmp);

    // ë¤í­ě A ěśë Ľ
    printf("ë¤í­ě A(x)\n");
    printf("    coef    expon\n");
    draw(A, termCntArr[0]);

    // ěě ë¤í­ě Aě ę°ě ëĄě§
    while (1) {

        int tempExpo;   // ě§ě
        float tempCoef; // ęłě
        printf("B(x)ě í­ě ěë Ľíě¸ě. (coef expon) : ");
        scanf("%f %d", &tempCoef, &tempExpo);

        if (tempExpo == -1) {
            break; // -1 ěë Ľě ě˘ëŁ
        }

        if (termCntArr[1] == initSize[1] - 1) {
            B = (polynomial *)realloc(B, sizeof(polynomial) * initSize[1] * 2);
            initSize[1] *= 2;
        }
        B[termCntArr[1]].exponenet = tempExpo;
        B[termCntArr[1]].coefficient = tempCoef;
        termCntArr[1] += 1;
    }
    ăĄ((polynomial *)B, termCntArr[1], sizeof(polynomial), cmp);

    // ë¤í­ě Běśë Ľ
    printf("ë¤í­ě B(x)\n");
    printf("    coef    expon\n");
    for (int i = 0; i < termCntArr[1]; i++) {
        printf("%8.3f %8d\n", B[i].coefficient, B[i].exponenet);
    }

    // ë¤í­ě D ěěą
    polynomial *D;
    // A+B ë¤í­ě ë§ěí´ě¤, ěśë Ľ
    D = padd(A, B);
    printf("3.2 ë¤í­ě ë§ě\në¤í­ě ë§ě ę˛°ęłź : D(x)\n");
    printf("    coef    expon\n");
    draw(D, termCntArr[2]);

    // A*B ë¤í­ě ęłąě, ěśë Ľ
    printf("3.3 ë¤í­ě ęłąě\n");
    D = pmul(A, B);
    printf("D(x) ęłąě\n");
    draw(D, termCntArr[2]);

    // ëě í ëš í´ě 
    free(A);
    free(B);
    free(D);
}