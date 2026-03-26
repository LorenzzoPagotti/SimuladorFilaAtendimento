#include "simulador.h"

void executarSimulacao(int tempo_total_minutos)
{
    int tempo_espera_total = 0;
    int numero_limite = 100;
    int id = 1;
    int tempo_restante_caixa = 0;
    int clientes_atendidos = 0;

    Fila *Fila_nova = criarFila();

    for (int i = 0; i < tempo_total_minutos; i++)
    {
        printf("\n[Minuto %d]\n", i);

        int valor_aleatorio = rand() % (numero_limite + 1);

        if (valor_aleatorio > 50)
        {
            printf("Cliente encontrado! Tempo ate achar: %d min\n", i);

            Cliente Novo_Cliente;
            Novo_Cliente.id_cliente = id++;
            Novo_Cliente.tempo_chegada = i;

            sprintf(Novo_Cliente.nome, "Cliente %d", Novo_Cliente.id_cliente); 
            
            Novo_Cliente.tempo_estimado_atendimento = (rand() % 6) + 3;

            if (Novo_Cliente.id_cliente == 100)
            {
                printf("Numero maximo de clientes atingido\n");
                break;
            }

            printf("-> %s entrou no banco (Demorara %d min no caixa)\n", Novo_Cliente.nome, Novo_Cliente.tempo_estimado_atendimento);
            enqueue(Fila_nova, Novo_Cliente);
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

            clientes_atendidos++;

            tempo_restante_caixa = cliente_atendido.tempo_estimado_atendimento;

            printf("<- %s foi chamado pelo caixa. Tempo aguardando na fila: %d min\n", cliente_atendido.nome, tempo_esperado);
        }

        imprimirFila(Fila_nova);

        Sleep(1500);
    }

    if (clientes_atendidos > 0)
    {
        float tempo_medio = (float)tempo_espera_total / clientes_atendidos;

        printf("\n--- RESULTADO FINAL DA SIMULACAO ---\n");
        printf("Total de clientes que entraram: %d\n", id - 1);
        printf("Total de clientes atendidos: %d\n", clientes_atendidos);
        printf("Tempo de espera total: %d minutos\n", tempo_espera_total);
        printf("Tempo medio de espera: %.2f minutos\n", tempo_medio);
    }
    else
    {
        printf("\n\nNenhum cliente foi atendido na simulacao.\n\n");
    }

    destruirFila(Fila_nova);
}