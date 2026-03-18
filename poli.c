#include <stdlib.h>
#include <stdio.h>

#include "poli.h"

polinomio * poli_create(int grau){
    polinomio *valor = (polinomio *)malloc(sizeof(polinomio));
    if (valor == NULL) {
        return NULL;
    }

    valor->grau = grau;
    valor->termos = 0;
    valor->coeficientes = (int *)calloc(grau + 1, sizeof(int));
    if (valor->coeficientes == NULL) {
        free(valor);
        return NULL;
    }
    // TODO: Implemente aqui a solucao para operacao create

    return valor;
}

void poli_destroy(polinomio **p){
    // TODO: Implemente aqui a solucao para operacao destroy


    return;
}

int poli_ins_termo(polinomio *p, int exp, int coef) {
    // TODO: Implemente aqui a solucao para operacao insere coeficiente

    return 0;
}

int poli_get_termo(polinomio *p, int exp, int *coef){
    // TODO: Implemente aqui a solucao para operacao get coeficiente

    return 0;
}

int calcula_px(polinomio *p, int x){
    // TODO: Implemente aqui a solucao para operacao calcula o valor de P(x)     
    
    return 0;
}

polinomio * poli_soma(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que soma dois polinomios e gera um terceiro

    return NULL;
}

polinomio * poli_mult(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que multiplica dois polinomios e gera um terceiro

    return NULL;
}

polinomio * poli_div(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que divide dois polinomios e gera um terceiro

    return NULL;
}


