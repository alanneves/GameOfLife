#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


char **Progresso(char **matrizPrincipal, int TotLin, int TotCol) { // Fun��o para simular a evolu��o em uma matriz auxiliar e depois na matriz principal
    int i, j, Aux[TotLin][TotCol];

    for (i = 0; i < TotLin; i++) { //preenchendo matriz auxiliar
        for (j = 0; j < TotCol; j++) {
            Aux[i][j] = '.';
        }
    }

    for (i = 1; i < TotLin-1; i++) {
        for (j = 1; j < TotCol-1; j++) {
            if (matrizPrincipal[i][j] == 'O') {
                    //Uma c�lula viva morre de solid�o se tiver menos de duas vizinhas vivas
                    //Uma c�lula viva morre por superpopula��o se tiver mais que tr�s vizinhas vivas
                if ((ContadorCelulasVizinhas(matrizPrincipal, i, j) > 3) || (ContadorCelulasVizinhas(matrizPrincipal, i, j) < 2)){
                    Aux[i][j] = '.';
                }
                    //Uma c�lula viva sobrevive se tiver duas ou tr�s vizinhas vivas
                if ((ContadorCelulasVizinhas(matrizPrincipal, i, j) == 2) || (ContadorCelulasVizinhas(matrizPrincipal, i, j) ==  3)) {
                    Aux[i][j] = 'O';
                }
            }
                     //Uma c�lula morta ganha vida se tiver exatamente tr�s vizinhas vivas
            if ((ContadorCelulasVizinhas(matrizPrincipal, i, j) ==  3) && (matrizPrincipal[i][j] == '.'))  {
                Aux[i][j] = 'O';
            }
        }
    }

    for (i = 1; i < TotLin-1; i++) { // Transformando o tabuleiro anterior em um novo
        for (j = 1; j < TotCol-1; j++) {
            matrizPrincipal[i][j] = Aux[i][j];
        }
    }
    return (matrizPrincipal);
}


void FreeMatriz(char **matrizPrincipal, int TotLin){ // Fun��o utilizada para liberar espa�o utilizado pela matriz
    int i;

    for (i = 0; i < TotLin; i++){
        free(matrizPrincipal[i]);
    }

    free(matrizPrincipal);
}

char** AlocaMatriz (int TotLin, int TotCol) { //Fun��o para alocar a matriz
    int i;
    char **matriz;

    matriz = (char **)malloc(TotLin*sizeof(char *));

    for (i = 0; i < TotLin; i++) {
        matriz[i] = (char *)malloc(TotCol*sizeof(char));
    }

    return matriz;
}
char** ReiniciarMatriz (char** matrizPrincipal, int TotLin, int TotCol) {
    int i, j;

    for (i = 0; i < TotLin; i++) {
        for (j = 0; j < TotCol; j++) {
            matrizPrincipal[i][j] = '.';
        }
    }
    return (matrizPrincipal);
}


void VidaEterna1 (char **matrizPrincipal, int geracoes) {   //Primeira op��o do menu

    int TotLin = 4, TotCol = 4, i, j, cont;

    matrizPrincipal = AlocaMatriz(TotLin, TotCol);
    ReiniciarMatriz(matrizPrincipal, TotLin, TotCol);
    for (i = 0; i < TotLin; i++) { /* Gera Tabuleiro da primeira gera��o */
        for (j = 0; j < TotCol; j++) {
            if (i == 1 && (j == 2 || j == 3) ||
                (i == 2 && (j == 2 || j == 3))) {
                matrizPrincipal[i][j] = 'O';
            }
            else{
                matrizPrincipal[i][j] = '.';
            }
        }
    }
    for (cont = 0; cont < geracoes; cont++) { //Loop para simular um n�mero N de vezes o progresso das c�lulas
        ImprimeMatriz(matrizPrincipal, TotLin, TotCol);
        Progresso (matrizPrincipal, TotLin, TotCol);
    }

    FreeMatriz(matrizPrincipal, TotLin);

}

void VidaEterna2 (char **matrizPrincipal, int geracoes) { //Primeira op��o do menu

    int TotLin = 5,
    TotCol = 7,
    i, j,cont;

    matrizPrincipal = AlocaMatriz(TotLin, TotCol);
    ReiniciarMatriz(matrizPrincipal, TotLin, TotCol);

    for (i = 0; i < TotLin; i++) {
        for (j = 0; j < TotCol; j++) {
            if ((i == 1 && (j == 4 || j == 5)) ||
                (i == 2 && (j == 1 || j == 3 || j == 5)) ||
                (i == 3 && (j == 1 || j == 2))) {
                matrizPrincipal[i][j] = 'O';
        }
    }
}

   for (cont = 0; cont < geracoes; cont++) { //Loop para simular um n�mero N de vezes o progresso das c�lulas
        ImprimeMatriz(matrizPrincipal, TotLin, TotCol);
        Progresso (matrizPrincipal, TotLin, TotCol);
    }

    FreeMatriz(matrizPrincipal, TotLin);
}


void Blinker (char **matrizPrincipal, int geracoes) { //Terceira op��o do menu

    int TotLin = 5,
    TotCol = 5,
    i, j, cont;

    matrizPrincipal = AlocaMatriz(TotLin, TotCol);
    ReiniciarMatriz(matrizPrincipal, TotLin, TotCol);
    for (i = 0; i < TotLin; i++) { /* Gera Tabuleiro da primeira gera��o */
        for (j = 0; j < TotCol; j++) {
            matrizPrincipal[i][j] = '.';
            if (i == 2 && (j != 0 && j != 4)) { /* C�lulas inicialmente vivas */
                matrizPrincipal[i][j] = 'O';
            }
        }
    }

    for (cont = 0; cont < geracoes; cont++) { //Loop para simular um n�mero N de vezes o progresso das c�lulas
        ImprimeMatriz(matrizPrincipal, TotLin, TotCol);
        Progresso (matrizPrincipal, TotLin, TotCol);
    }

    FreeMatriz(matrizPrincipal, TotLin);
}
void Sapo (char **matrizPrincipal, int geracoes) { //Quarta op��o do menu

    int TotLin = 6,
    TotCol = 6,
    i, j, cont;

    matrizPrincipal = AlocaMatriz(TotLin, TotCol);
    ReiniciarMatriz(matrizPrincipal, TotLin, TotCol);

    for (i = 0; i < TotLin; i++) { /* Gera Tabuleiro da primeira gera��o */
        for (j = 0; j < TotCol; j++) {
            if ((i == 2 && (j != 0 && j != 1 && j != 5)) ||
                (i == 3 && (j != 0 && j != 4 && j != 5))) { /* C�lulas inicialmente vivas */
                matrizPrincipal[i][j] = 'O';
            }
        }
    }

    for (cont = 0; cont < geracoes; cont++) { //Loop para simular um n�mero N de vezes o progresso das c�lulas
        ImprimeMatriz(matrizPrincipal, TotLin, TotCol);
        Progresso (matrizPrincipal, TotLin, TotCol);
    }

    FreeMatriz(matrizPrincipal, TotLin);

}

void Glider (char **matrizPrincipal, int geracoes) { //Quinta op��o do menu

    int TotLin = 20,
    TotCol = 20,
    i, j, cont;

    matrizPrincipal = AlocaMatriz(TotLin, TotCol);
    ReiniciarMatriz(matrizPrincipal, TotLin, TotCol);

    for (i = 0; i < TotLin; i++) { /* Gera Tabuleiro da primeira gera��o */
        for (j = 0; j < TotCol; j++) {
            if ((i == 6 && (j == 8 || j == 7 || j == 6)) ||
                (i == 7 && j == 6) ||
                (i == 8 && j == 7)){ /* C�lulas inicialmente vivas */
                matrizPrincipal[i][j] = 'O';
            }
        }
    }


    for (cont = 0; cont < geracoes; cont++) { //Loop para simular um n�mero N de vezes o progresso das c�lulas
        ImprimeMatriz(matrizPrincipal, TotLin, TotCol);
        Progresso (matrizPrincipal, TotLin, TotCol);
    }

    FreeMatriz(matrizPrincipal, TotLin);
}

void LightweightSpaceship (char **matrizPrincipal, int geracoes) { //Sexta op��o do menu

    int TotLin = 20,
    TotCol = 20,
    i, j, cont;

    matrizPrincipal = AlocaMatriz(TotLin, TotCol);
    ReiniciarMatriz(matrizPrincipal, TotLin, TotCol);

    for (i = 0; i < TotLin; i++) {
        for (j = 0; j < TotCol; j++) {
            if ((i == 6 && (j == 3 || j == 4 || j == 5 || j == 6)) ||
                (i == 5 && (j == 2 || j == 6)) ||
                (i == 4 && j == 6) ||
                (i == 3 && (j == 2 || j == 5))){
                matrizPrincipal[i][j] = 'O';
            }
            else {
                matrizPrincipal[i][j] = '.';
            }
        }
    }



    for (cont = 0; cont < geracoes; cont++) { //Loop para simular um n�mero N de vezes o progresso das c�lulas
        ImprimeMatriz(matrizPrincipal, TotLin, TotCol);
        Progresso(matrizPrincipal, TotLin, TotCol);
    }
    FreeMatriz(matrizPrincipal, TotLin);
}

void ImprimeMatriz (char **matrizPrincipal, int TotLin, int TotCol) { //Fun��o para imprimir a matriz

    system("cls");

    int i, j;

    for (i = 0; i < TotLin; i++) {
        for (j = 0; j < TotCol; j++) {
            printf("%c", matrizPrincipal[i][j]);
        }
        printf("\n");
    }
    sleep(1);
}

int ContadorCelulasVizinhas (char** matrizPrincipal, int linha, int coluna) { // Fun��o para a contagem de c�lulas vivas ao lado
    int i, j, vivaslado=0;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (matrizPrincipal[linha+i][coluna+j] == 'O') {
                if (!(i == 0 && j == 0)) { // Verifica se a c�lula na contagem n�o � ela mesmo.
                    vivaslado = vivaslado + 1;
                }
            }
        }
    }
    return (vivaslado);
}
int main(){

    setlocale(LC_ALL, "Portuguese");

    char **matrizPrincipal;
    int MDJogo, geracoes;

    printf("\n-----------------JOGO DA VIDA-----------------");
    printf("\n\nOp��es:");
    printf("\n\nVidas Paradas");
    printf("\n\n\t1-Vida Eterna 1");
    printf("\n\t2-Vida Eterna 2");
    printf("\n\nOsciladores");
    printf("\n\n\t3-Blinker");
    printf("\n\t4-Sapo");
    printf("\n\nNaves Espaciais");
    printf("\n\n\t5-Glider");
    printf("\n\t6-Lightweight Spaceship");

    printf("\n\nPrimeiro, escolha quantas gera��es quer que sejam simuladas");
    scanf("%d", &geracoes);
    printf("\n\nEscolha uma modo de jogo!");
    scanf("%d", &MDJogo);

    if(MDJogo == 1){
        VidaEterna1(matrizPrincipal, geracoes);
    }else if(MDJogo == 2){
        VidaEterna2(matrizPrincipal, geracoes);
    }else if(MDJogo == 3){
        Blinker(matrizPrincipal, geracoes);
    }else if(MDJogo == 4){
        Sapo(matrizPrincipal, geracoes);
    }else if(MDJogo == 5){
        Glider(matrizPrincipal, geracoes);
    }else if(MDJogo == 6){
         LightweightSpaceship(matrizPrincipal, geracoes);
    }else{
        printf("\n\nModo de jogo inv�lido");
    }
    return 0;
}
