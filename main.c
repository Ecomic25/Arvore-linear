#include <stdio.h>
#include <limits.h>
#include "arvore.h"

int main()
{
    int arvore[MAX];
    
    printf("++++++--Iniciando arvore fodaplays--++++++\n\n");
    
    inicializar(arvore, 0);
    
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int qtd = sizeof(valores) / sizeof(valores[0]);
    
    inserirVarios(arvore, valores, qtd, 0);
    
    imprimir(arvore, 0, 0);
    
    printf("\n\nExibindo informações do numero 40!");
    int alvo = buscarAlvo(arvore, 0, 40);
    int sucessor = buscarSucessor(arvore, 0, 40);
    int predecessor = buscarPredecessor(arvore, 0, 40);
    
    if(alvo != INT_MIN){
        printf("\nO numero procurado está na posição %d da arvore(array)!", alvo);
    }
    else{
        printf("\nNumero não se encontra presente na arvore ou houve erro na busca!");
    }
    
    if(sucessor != INT_MIN){
        printf("\nO sucessor do numero procurado é %d (na posição %d)!", arvore[sucessor], sucessor);
    }
    else{
        printf("\nO numero não possui sucessor ou houve erro na busca!");
    }
    
    if(predecessor != INT_MIN){
        printf("\nO predecessor do numero procurado é %d (na posição %d)!\n", arvore[predecessor], predecessor);
    }
    else{
        printf("\nO numero não possui predecessor ou houve erro na busca!\n");
    }
    
    int menor = buscarMenor(arvore, 0);
    int maior = buscarMaior(arvore, 0);
    
    if(menor != INT_MIN){
        printf("\nO menor numero da arvore é o %d (na posição %d)!", arvore[menor], menor);
    }
    else{
        printf("\nOcorreu um erro no codigo de busca!");
    }
    
    if(maior != INT_MIN){
        printf("\nO maior numero da arvore é o %d (na posição %d)!", arvore[maior], maior);
    }
    else{
        printf("\nOcorreu um erro no codigo de busca!");
    }
    return 0;
}

