#include <stdio.h>
#include <string.h>
#define Total_Caracs 50
#define Total_Linhas 100
int main() 
{
    int N, i, k, j, l, x, achouspace, maior, tamanho_atual, first=0;
    char frase[Total_Caracs+2], matriz_frase[Total_Linhas][Total_Caracs+2], aux[Total_Caracs+2];
    while (scanf("%d", &N) && N != 0) 
    {
        getchar(); 
        maior = 0;
        for (i = 0; i < N; i++) 
        {
            fgets(frase, sizeof(frase), stdin); 
            j = strlen(frase);
            if (frase[j - 1] == '\n')
            {
                j=j-1;
                frase[j] = '\0';
            }
            x = 0;
            achouspace = 1;
            for (k = 0; k < j; k++) 
            {
                if (frase[k] != ' ' || achouspace==0) 
                    frase[x++] = frase[k];
                achouspace = (frase[k] == ' ');
            }
            if (x > 0 && frase[x - 1] == ' ') 
                x--;
            frase[x] = '\0';
            tamanho_atual = strlen(frase);
            if (tamanho_atual > maior) 
                maior = tamanho_atual;
            strcpy(matriz_frase[i], frase);
        }
        if(first>0)
            printf("\n");
        first=1;
        for (l = 0; l < N; l++) 
        {
            tamanho_atual = strlen(matriz_frase[l]);
            strcpy(aux, "");
            for (i = 0; i < maior - tamanho_atual; i++) 
                aux[i] = ' ';
            strcpy(aux + (maior - tamanho_atual), matriz_frase[l]); 
           
            printf("%s\n", aux);
        }
    }
}