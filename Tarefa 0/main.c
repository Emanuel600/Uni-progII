#include <stdio.h>
#include <stdbool.h>

#define SET_BIT(Y, BIT) Y = Y | (1 << BIT)
#define CLR_BIT(Y,BIT) Y = Y & ~(1 << BIT)
#define CLP_BIT(Y,BIT) Y = Y ^ (1 << BIT)
#define TST_BIT(Y, BIT) ( (Y & (1 << BIT)) > 0 )// "Retorna" valor do bit na posi��o BIT

int main(){
    //Esta parte o professor j� fez, mais um \n para facilitar leitura na sa�da
    int dado_hex = 0;

    SET_BIT(dado_hex, 4);
    printf("Dado, 4 bit: 0x%.4x\n", dado_hex);

    SET_BIT(dado_hex, 2);
    printf("Dado, 2 bit: 0x%.4x\n\n", dado_hex);

    //Limpar bit na posi��o 2 para reverter ao primeiro valor determinado (testando se est� funcionando)
    CLR_BIT(dado_hex, 2);
    printf("Dado, removendo o terceiro bit: 0x%.4x\n", dado_hex);
    //Limpar bit na posi��o 4 para reverter ao valor inicial (testando se est� funcionando)
    CLR_BIT(dado_hex, 4);
    printf("Dado, removendo o quinto bit: 0x%.4x\n\n", dado_hex);

    bool i = TST_BIT(dado_hex, 2);

    printf("Valor do bit na posicao 2: %d\n", i);
    printf("Dado em hexa: 0x%.4x\n\n", dado_hex);

    //Ativar o bit e usar TST_BIT para ver se est� funcionando como devia
    SET_BIT(dado_hex, 2);
    i = TST_BIT(dado_hex, 2);

    printf("Dado em hexa: 0x%.4x\n\n", dado_hex);
    printf("Valor do bit na posicao 2: %d\n\n", i);

    //Ver se o bit � complementado ao chamar CLP_BIT
    CLP_BIT(dado_hex, 2); //Complementa o bit
    i = TST_BIT(dado_hex, 2); //Registra o valor do bit depois de complement�-lo

    printf("Valor do bit na posicao 2 depois de complemeta-lo: %d\n", i);
    printf("Dado final em hexa: 0x%.4x\n\n", dado_hex);

    return 0;
}
