#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main()
{
    Lista *l;
    l = criarLista();
    l = inserirLista(l, 10);
    l = inserirLista(l, 20);
    l = inserirLista(l, 30);
    l = inserirLista(l, 40);
    exibirLista(l); // Exibe a lista

    // Buscar um elemento
    Lista* x = buscarLista(l, 10); // Buscando 10
    if (x != NULL) {
        printf("\nO elemento buscado é: %d\n", x->info); // Deve imprimir 10
    } else {
        printf("Elemento não encontrado.\n");
    }

    // Verifica se a lista está vazia
    verificarVazia(l);
    
    l = excluirLista(l, 30);
    printf("Exclui o numero 30 da lista\n");
    exibirLista(l); 
    
    printf("Inseri o numero 45 de forma crescente\n");
    l = inserirListaCrescente(l, 45);
    exibirLista(l);
    printf("Inseri o numero 6 de forma crescente\n");
    l = inserirListaCrescente(l, 6);
    exibirLista(l);
    printf("Inseri o numero 7 de forma crescente\n");
    l = inserirListaCrescente(l, 7);
    exibirLista(l);
      
    
    liberaLista(l); // Libera a memória da lista ao final
    
   
    return 0;
    
}
