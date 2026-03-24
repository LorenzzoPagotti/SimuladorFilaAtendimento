#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void executarSimulacao(int tempo_total_minutos);
void imprimir_estatisticas(int tempo_total, int n_clientes_atendidos);

#endif