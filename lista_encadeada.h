#include <stdio.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista
Lista;

Lista* criarLista();
Lista* inserirLista(Lista* l, int i);
Lista* exibirLista(Lista* l);
void verificarVazia(Lista* l);
Lista* buscarLista(Lista* l, int v);
Lista* excluirLista(Lista* l, int v);
void liberaLista(Lista* l);
Lista* inserirListaOrdemCrescrente(Lista*, int i);

void liberaLista(Lista *l){
    Lista *p = l;
    while(p != NULL){
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

Lista* excluirLista(Lista *l, int v){
    Lista *ant = NULL;
    Lista *p = l;
    
    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return l;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

Lista* buscarLista(Lista *l, int v) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p; // Retorna o nó se o valor for encontrado
        }
    }
    return NULL; // Retorna NULL se não encontrado
}

void verificarVazia(Lista *l) {
    if (l == NULL) {
        printf("A lista esta vazia.\n");
    } else {
        printf("A lista nao esta vazia.\n");
    }
}

Lista* exibirLista(Lista *l){
    Lista *p;
    for(p = l; p != NULL; p = p->prox){
        printf("%d\n", p->info);
    }
}

Lista* inserirLista(Lista *lista, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo -> info = i;
    novo -> prox = lista;
    return novo;
};

Lista* inserirListaCrescente(Lista *lista, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;

    // Caso a lista esteja vazia ou o novo elemento deva ser o primeiro
    if (lista == NULL || i < lista->info) {
        novo->prox = lista; // Novo elemento aponta para o antigo primeiro
        return novo; // O novo elemento se torna o novo primeiro
    }

    // Caso contrário, percorre a lista para encontrar a posição correta
    Lista* atual = lista;
    Lista* anterior = NULL;

    while (atual != NULL && atual->info < i) {
        anterior = atual;
        atual = atual->prox;
    }

    // Insere o novo elemento na posição correta
    anterior->prox = novo; // O nó anterior agora aponta para o novo
    novo->prox = atual; // O novo nó aponta para o próximo

    return lista;
	
}

Lista* criarLista(){
    return NULL;
};

