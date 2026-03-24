#include "simulador.h"

void executarSimulacao(int tempo_total_minutos)
{
    int tempo_espera_total = 0;
    int numero_limite = 100;
    int id = 0;
    int caixa_livre = 1;

    Fila *Fila_nova = criarFila();

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

            enqueue(Fila_nova, Novo_Cliente);
        }
        else
        {
            printf("Que azar... Cliente não encontrado XD\n");
        }

        if (caixa_livre == 1 && !filaVazia(Fila_nova))
        {
            Cliente clinte_atendido = dequeue(Fila_nova);
            int tempo_esperado = i - clinte_atendido.tempo_chegada;
            tempo_espera_total += tempo_esperado;
            caixa_livre = 0;
        }

        caixa_livre = 1;
    }

    if (id > 0)
    {
        imprimir_estatisticas(tempo_espera_total, id);
        {
            if (id > 0)
            {
                int tempo_medio = tempo_espera_total / id;
                printf("\n--- RESULTADO FINAL DA SIMULACAO ---\n");
                printf("Total de clientes atendidos: %d\n", id);
                printf("Tempo de espera total: %d minutos\n", tempo_espera_total);
                printf("Tempo Médio de Espera: %d minutos\n", tempo_medio);
            }
            else
            {
                printf("\nNenhum cliente foi atendido na simulação.\n");
            }
        }
    }

    destruirFila(Fila_nova);
}