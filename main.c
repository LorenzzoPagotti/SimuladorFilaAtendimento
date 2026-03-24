#include "simulador.h" // isso ja da include em td que precisa

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
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantos minutos a simulacao deve durar? ");
            scanf("%d", &tempo);
            executarSimulacao(tempo);
            break;

        case 2:
            printf("Saindo do simulador...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 2);

    return 0;
}