#include "fila.h"
#include <stdio.h>


Fila* criarFila()
{
    Fila* nova_fila = (Fila*) malloc(sizeof(Fila)); // alocando espaco pra uma fila a mais

    nova_fila->head = NULL;
    nova_fila->tail = NULL;

    return nova_fila;
}

bool filaVazia(Fila* fila)
{
    return (fila->head == NULL); // retorna se o comeco da fila está vazio ou nao.
}

void enqueue(Fila* fila, Cliente cliente)
{
    No* novo_no = (No*) malloc(sizeof(No));

    novo_no->info_cliente = cliente;

    novo_no->proximo_no = NULL;

    if (filaVazia(fila)) // se a fila ta vazia, o comeco e o final é o mesmo (so 1 cliente), entao coloca o mesmo valor no inicio e final da fila atual
    {
        fila->head = novo_no;
        fila->tail = novo_no;
    }
    else
    {
        fila->tail->proximo_no = novo_no;
        fila->tail = novo_no;
    }
}

Cliente dequeue(Fila* fila)
{
    if (filaVazia(fila))
    {
        printf ("A FILA TA VAZIA. NAO USA DEQUEUE COM A FILA VAZIA PORQUE VAI CRASHAR O PROGRAMA");
        Cliente kaua_bobinho;
        kaua_bobinho.id_cliente = -1;
        return kaua_bobinho;
    }

    Cliente cliente_atendido = fila->head->info_cliente; // salvando o cliente atendido pra nao perder a info

    No* no_para_liberar = fila->head; // salva o da frente pra liberar depois;

    fila->head = fila->head->proximo_no;

    if (fila->head == NULL) fila->tail = NULL; // se o fim da fila for null, a fila acabou. assim, para evitar crash, a gente coloca como null o tail da fila tb

    free(no_para_liberar);

    return cliente_atendido;

}

void destruirFila(Fila* fila_para_destruir)
{
    if (fila_para_destruir == NULL) return;
    
    while (!filaVazia(fila_para_destruir))
    {
        dequeue(fila_para_destruir);
    }

    free(fila_para_destruir);
}