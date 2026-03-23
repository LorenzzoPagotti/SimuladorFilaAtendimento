#include "simulador.h" // isso ja da include em td que precisa

int main()
{
    int opcao;
    int tempo;

    do
    {
        printf("=== SIMULADOR DE FILA DE ATENDIMENTO ===");
        printf("\n1. Rodar Simulação");
        printf("\n2. Sair");

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
            printf("Opção inválida!\n");
        }

    } while (opcao != 2);

    return 0;
}