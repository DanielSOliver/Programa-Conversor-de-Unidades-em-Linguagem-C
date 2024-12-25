#include <stdio.h>
#include <math.h>

/*este programa realiza conversões de Bit, Bytes, kilobytes, Megabytes, Gigabytes e Terabytes*/

int main() {
    const double fatorConversao = 8.0; // Definição da constante para conversão de bits para bytes (8 bits = 1 byte)
    int unidadeOrigem, unidadeDestino; // Variáveis para armazenar as unidades de origem e destino escolhidas pelo usuário
    
    double valor, resultado; // Variáveis para armazenar o valor a ser convertido e o resultado da conversão


    printf("Conversor de unidades:\n"); // Exibe as opções de unidades disponíveis para conversão
    printf("0. Bits\n");
    printf("1. Bytes\n");
    printf("2. Kilobytes (KB)\n");
    printf("3. Megabytes (MB)\n");
    printf("4. Gigabytes (GB)\n");
    printf("5. Terabytes (TB)\n");

    printf("Escolha o tipo de unidade que voce deseja converter (0-5): ");
    scanf("%d", &unidadeOrigem);

    printf("Escolha em qual tipo de unidade que voce deseja converter (0-5): ");
    scanf("%d", &unidadeDestino);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    if (unidadeOrigem >= 0 && unidadeOrigem <= 5 && unidadeDestino >= 0 && unidadeDestino <= 5) {
        resultado = valor;// Verifica se as unidades de origem e destino são válidas (entre 0 e 5)

        if (unidadeOrigem < unidadeDestino) // Realiza a conversão caso a unidade de origem seja menor que a unidade de destino
        {
            for (int i = unidadeOrigem; i < unidadeDestino; i++) {
                resultado /= (i == 0 ? fatorConversao : 1024);
            }
        } else if (unidadeOrigem > unidadeDestino)// Multiplica pelo fator de conversão apropriado
         {
            for (int i = unidadeOrigem; i > unidadeDestino; i--) {
                resultado *= (i - 1 == 0 ? fatorConversao : 1024);
            }
        }

        printf("O resultado da conversao eh: %.2f\n", resultado); // Exibe o resultado da conversão
    } else {
        printf("Unidades invalidas! Escolha valores entre 0 e 5.\n"); // Exibe uma mensagem de erro caso as unidades sejam inválidas
    }

    return 0;
}