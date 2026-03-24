#include "simulador.h"

void executarSimulacao(int tempo_total_minutos)
{
    int tempo_espera_total = 0;
    int numero_limite = 100;
    int id = 0;
    int tempo_restante_caixa = 0;

    Fila *Fila_nova = criarFila();

    for (int i = 0; i < tempo_total_minutos; i++)
    {

        int valor_aleatorio = rand() % (numero_limite + 1);

        if (valor_aleatorio > 50)
        {
            printf("Cliente encontrado! Tempo ate achar: %d min\n", i);

            Cliente Novo_Cliente;
            Novo_Cliente.id_cliente = id++;
            Novo_Cliente.tempo_chegada = i;

            if (Novo_Cliente.id_cliente == 100)
            {
                printf("Numero maximo de clientes atingido\n");
                break;
            }

            enqueue(Fila_nova, Novo_Cliente);
        }
        else
        {
            printf("Que azar... Cliente nao encontrado XD\n");
        }

        if (tempo_restante_caixa > 0)
        {
            tempo_restante_caixa--;
        }

        if (tempo_restante_caixa == 0 && !filaVazia(Fila_nova))
        {
            Cliente cliente_atendido = dequeue(Fila_nova);

            int tempo_esperado = i - cliente_atendido.tempo_chegada;
            tempo_espera_total += tempo_esperado;

            tempo_restante_caixa = (rand() % 6) + 3;

            printf("Cliente %d atendido com sucesso! Tempo aguardando na fila: %d min\n", cliente_atendido.id_cliente, tempo_esperado);
        }
        Sleep(1500);
    }

    if (id > 0)
    {
        float tempo_medio = (float)tempo_espera_total / id;

        printf("\n--- RESULTADO FINAL DA SIMULACAO ---\n");
        printf("Total de clientes que entraram: %d\n", id);
        printf("Tempo de espera total: %d minutos\n", tempo_espera_total);
        printf("Tempo Medio de Espera: %.2f minutos\n", tempo_medio);
    }
    else
    {
        printf("\n\nNenhum cliente entrou na simulacao.\n\n");
    }

    destruirFila(Fila_nova);
}