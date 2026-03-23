#ifndef FILA_H
#define FILA_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Cliente
{
    int id_cliente;

    int tempo_chegada; // MINUTOS que o cliente chegou (de 1 até 59)

    char nome[50];

    int tempo_estimado_atendimento;

} Cliente;


typedef struct No
{
    Cliente info_cliente;

    struct No* proximo_no;

} No;


typedef struct Fila
{
    No* head; // o primeiro da fila (quem vai sair primeiro)

    No* tail; // ultimo da fila (vai colocar gente nova aqui)

} Fila;



Fila* criarFila(); // cria a fila e retorna o ponteiro para a fila nova

bool filaVazia(Fila* fila_para_conferir); // booleana pra checar se a fila ta vazia (mt importante)

void enqueue(Fila* fila, Cliente cliente);

Cliente dequeue(Fila* fila); // depois de tirar alguem da fila, ela vai retornar quem ela tirou. importantissimo pra calcular o tempo e pegar as informacoes do cliente

void destruirFila(Fila* fila_para_destruir);

void imprimirFila(Fila* fila);

#endif