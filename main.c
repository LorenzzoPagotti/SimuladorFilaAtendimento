#include "simulador.h"

int main()
{
    int opcao;
    int tempo;
    srand(time(NULL));

    do
    {
        printf("\n\n=== SIMULADOR DE FILA DE ATENDIMENTO ===\n");
        printf("\n1. Rodar Simulacao");
        printf("\n2. Sair\n");

        printf ("Digite uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) 
        {
            while (getchar() != '\n'); 
            
            opcao = 0; 
        }

        switch (opcao)
        {
        case 1:
            printf("Quantos minutos a simulacao deve durar? ");
            
            if (scanf("%d", &tempo) != 1) 
            {
                while (getchar() != '\n');
                printf("Erro: Voce deve digitar um numero inteiro para o tempo!\n");
            }
            else 
            {
                executarSimulacao(tempo);
            }
            break;

        case 2:
            printf("Saindo do simulador...\n");
            break;

        default:
            printf("Opcao invalida! Digite 1 ou 2.\n");
        }

    } while (opcao != 2);

    return 0;
}