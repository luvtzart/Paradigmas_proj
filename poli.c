#include <stdlib.h>
#include <stdio.h>

#include "poli.h"

// Luiza Marinho de Mesquita - 10438045
// Marina Cantarelli Barroca - 10740412

// link do trab no git = https://github.com/luvtzart/Paradigmas_proj


polinomio * poli_create(int grau){
    polinomio *valor = (polinomio *)malloc(sizeof(polinomio));
    if (valor == NULL) {
        return NULL;
    }

    valor -> grau = grau;
    valor -> termos = 0;
    valor -> coeficientes = (int *)calloc(grau + 1, sizeof(int));
    if (valor -> coeficientes == NULL) {
        free(valor);
        return NULL;
    }
    
    // TODO: Implemente aqui a solucao para operacao create

    return valor;
}

void poli_destroy(polinomio **p){
    if(p && *p){
        polinomio *valor = *p;

        free(valor -> coeficientes);
        free(valor);

        *p = NULL;
    }
    // TODO: Implemente aqui a solucao para operacao destroy
    return;
}

int poli_ins_termo(polinomio *p, int exp, int coef) {
    // TODO: Implemente aqui a solucao para operacao insere coeficiente
    if(p == NULL || exp < 0 || exp > p->grau) {
        return 0; // Expoente inválido
    }
    if( p -> coeficientes[exp] == 0 && coef != 0) {
        p -> termos++; // incrementa o número de termos válidos
    } else if (p -> coeficientes[exp] != 0 && coef == 0) {
        p -> termos--; // dec o número de termos válidos
        //return 0;
    
    }
    p -> coeficientes[exp] = coef;
    return 0;
}

int poli_get_termo(polinomio *p, int exp, int *coef){
    // TODO: Implemente aqui a solucao para operacao get coeficiente
    // int aux = p -> grau
    if (coef != NULL && p != NULL && exp >= 0 && exp <= p -> grau && p -> coeficientes[exp] != 0){
        *coef = p -> coeficientes[exp];
        return 1;
    }

    return 0;
}

int calcula_px(polinomio *p, int x){
    // TODO: Implemente aqui a solucao para operacao calcula o valor de P(x) 
    int result = 0;
    int aux = 1;
    for(int i = 0; i <= p -> grau; i++){
        result += p -> coeficientes[i] * aux;
        aux = aux * x;
    }  
    return result;
}

polinomio * poli_soma(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que soma dois polinomios e gera um terceiro
    if(p == NULL || q == NULL) return NULL;
    
    int grau = (p -> grau > q -> grau) ? p -> grau : q -> grau; //retorna maior grau
    polinomio *result = poli_create(grau); // cria um polinomio como resultado da equação

    for(int i = 0; i <= p-> grau; i++){
        result-> coeficientes[i] += p-> coeficientes[i]; 
    }

    for(int i = 0; i <= q->grau; i++){
        result -> coeficientes[i] += q -> coeficientes[i];
    }
    // soma os resultados da soma dos polinomios
    for(int i = 0; i <= grau; i++){
        if(result -> coeficientes[i] != 0){
            result -> termos++;
        }
    }

    return result;
}

polinomio * poli_mult(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que multiplica dois polinomios e gera um terceiro
    if(p == NULL || q == NULL) return NULL;
    
    int grau = p-> grau + q-> grau; // soma os termos, visto que se trata da mult
    polinomio *result = poli_create(grau);

    // mesmo esquema que a soma, porém com o for integrado e no final multiplicando q e p
    for(int i = 0; i <= p-> grau; i++){
        for(int j = 0; j <= q-> grau; j++){
        result-> coeficientes[i + j] += q-> coeficientes[j] * p-> coeficientes[i];
        }
    }

    for(int i = 0; i <= grau; i++){
        if(result -> coeficientes[i] != 0){
            result -> termos++;
        }
    }

    return result;
}

polinomio * poli_div(polinomio *p, polinomio *q){
    // TODO: Implemente aqui a solucao para operacao que divide dois polinomios e gera um terceiro
    if(p == NULL || q == NULL) return NULL;
    if(q->grau == 0 && q->coeficientes[0] == 0) return NULL; // para operação com 0!
    
    int grau = p-> grau - q-> grau; // diminui os termos, visto que se trata da div
    if(grau < 0){
        return poli_create(0); // satisfaz teste 204
    }
    polinomio *result = poli_create(grau);
    polinomio *resto = poli_create(p-> grau); // novo polinomio p fzr o resto da divisao

    // mesmo esquema que a soma, porém com o for integrado e no final multiplicando q e p
    for(int i = 0; i <= p-> grau; i++){
        resto-> coeficientes[i] = p-> coeficientes[i];
    }
        
    for(int i = p-> grau; i >= q-> grau; i--){ // começa no maior grau e dps vai pro menor
        if(resto-> coeficientes[i] != 0){
            int coef = resto-> coeficientes[i] / q-> coeficientes[q-> grau];
            int novo = i - q-> grau; // novo valor do expoente após div
            result-> coeficientes[novo] = coef;

            for(int j = 0; j <= q-> grau; j++){
                resto-> coeficientes[novo + j] -= coef * q-> coeficientes[j]; // parecido com mult, porem com -= e * coef
            }
        }
    }
    

    for(int i = 0; i <= grau; i++){
        if(result -> coeficientes[i] != 0){
            result -> termos++; //conta os termos
        }
    }

    poli_destroy(&resto);
    return result; 
}


