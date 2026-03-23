#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void gerar_numero_rand(void);
void imprimir_estatisticas(int tempo_total, int n_clientes_atendidos)
{
    if (n_clientes_atendidos > 0)
    {
        int tempo_medio = tempo_total / n_clientes_atendidos;
        printf("\n--- RESULTADO FINAL DA SIMULACAO ---\n");
        printf("Total de clientes atendidos: %d\n", n_clientes_atendidos);
        printf("Tempo de espera total: %d minutos\n", tempo_total);
        printf("Tempo Médio de Espera: %d minutos\n", tempo_medio);
    }
    else
    {
        printf("\nNenhum cliente foi atendido na simulação.\n");
    }
}

#endif