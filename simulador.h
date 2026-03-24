#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void executarSimulacao(int tempo_total_minutos);
void gerar_numero_rand(void);
void imprimir_estatisticas(int tempo_total, int n_clientes_atendidos);

#endif