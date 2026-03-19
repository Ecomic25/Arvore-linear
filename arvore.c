#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arvore.h"

void inicializar(int arvore[], int i){
    if(i >= MAX){
        return;
    }
    
    arvore[i] = INT_MIN;
    
    inicializar(arvore, i + 1);
}

void inserir(int arvore[], int i, int v){
    if(i >= MAX){
        printf("\nTentando acessar espaço fora dos limites!");
        return;
    }
    
    if(arvore[i] == INT_MIN){
        arvore[i] = v;
    }
    
    else if(v < arvore[i]){
        inserir(arvore, (2 * i) + 1, v);
    }
    
    else if(v > arvore[i]){
        inserir(arvore, (2 * i) + 2, v);
    }
    else{
        printf("\nNao aceitamos numeros repetidos!");
        return;
    }
}

void inserirVarios(int arvore[], int valores[], int tamanho, int k){
    if(k >= tamanho){
        return;
    }
    
    inserir(arvore, 0, valores[k]);
    
    inserirVarios(arvore, valores, tamanho, k + 1);
}

void imprimir(int arvore[], int i, int nivel){
    
    if(i < MAX && arvore[i] != INT_MIN){
        imprimir(arvore, (2 * i) + 2, nivel + 1);
        printf("%*s -> %d\n", nivel * 5, "", arvore[i]);
        imprimir(arvore, (2 * i) + 1, nivel + 1);
    }
}

int buscarAlvo(int arvore[], int i, int v){
    if(i >= MAX || arvore[i] == INT_MIN){
        return INT_MIN;
    }
    
    if(arvore[i] == v){
        return i;
    }
    
    else if(v < arvore[i]){
        return buscarAlvo(arvore, (2 * i) + 1, v);
    }
    
    else{
        return buscarAlvo(arvore, (2 * i) + 2, v);
    }
}

int buscarMenor(int arvore[], int i){
    if(i >= MAX || arvore[i] == INT_MIN){
        return INT_MIN;
    }
    
    int temp = buscarMenor(arvore, (2 * i) + 1);
    
    if(temp == INT_MIN){
        return i;
    }
    
    else{
        return temp;
    }
}

int buscarMaior(int arvore[], int i){
    if(i >= MAX || arvore[i] == INT_MIN){
        return INT_MIN;
    }
    
    int temp = buscarMaior(arvore, (2 * i) + 2);
    
    if(temp == INT_MIN){
        return i;
    }
    
    else{
        return temp;
    }
}

int buscarSucessor(int arvore[], int i, int v){
    if(i >= MAX || arvore[i] == INT_MIN){
        return INT_MIN;
    }
    
    if(arvore[i] <= v){
        return buscarSucessor(arvore, (2 * i) + 2, v);
    }
    
    else{
        int temp = buscarSucessor(arvore, (2 * i) + 1, v);
        
        if(temp == INT_MIN){
            return i;
        }
        
        else{
            return temp;
        }
    }
}

int buscarPredecessor(int arvore[], int i, int v){
    if(i >= MAX || arvore[i] == INT_MIN){
        return INT_MIN;
    }
    
    if(arvore[i] >= v){
        return buscarPredecessor(arvore, (2 * i) + 1, v);
    }
    
    else{
        int temp = buscarPredecessor(arvore, (2 * i) + 2, v);
        
        if(temp == INT_MIN){
            return i;
        }
        
        else{
            return temp;
        }
    }
}






