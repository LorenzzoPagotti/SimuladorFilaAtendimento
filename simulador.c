#include "simulador.h"

void executarSimulacao(int tempo_total_minutos)
{
    int numero_limite = 100;
    int id = 0;

    for (int i = 0; i < tempo_total_minutos; i++)
    {
        int valor_aleatorio = rand() % (numero_limite + 1);

        if (valor_aleatorio > 50)
        {
            printf("Cliente encontrado!\n Tempo até achar: %d\n", i);

            Cliente Novo_Cliente;
            Novo_Cliente.id_cliente = id++;
            Novo_Cliente.tempo_chegada = i;

            if (Novo_Cliente.id_cliente == 100)
            {
                printf("Número máximo de clientes atingido\n");
                break;
            }
        }
        else
        {
            printf("Que azar... Cliente não encontrado XD\n");
        }
    }
}