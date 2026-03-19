#ifndef ARVORE_H
#define ARVORE_H

#define MAX 100

void inicializar(int arvore[], int i);
void inserir(int arvore[], int i, int v);
void inserirVarios(int arvore[], int valores[], int tamanho, int k);
void imprimir(int arvore[], int i, int nivel);
int buscarAlvo(int arvore[], int i, int v);
int buscarMenor(int arvore[], int i);
int buscarMaior(int arvore[], int i);
int buscarSucessor(int arvore[], int i, int v);
int buscarPredecessor(int arvore[], int i, int v);

#endif
