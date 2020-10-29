#ifndef ARVORE
#define ARVORE

#include "celula.hpp"

class ArvoreBinaria{

    private:
        CelulaNo* raiz;

    public:
        ArvoreBinaria();
        ArvoreBinaria(CelulaNo* raiz);

        CelulaNo* getRaiz();
        void setRaiz(CelulaNo*);

        void insere(CelulaNo*);
        void remove(std::string);
        int procura(CelulaNo*, std::string, int);
        bool procura(CelulaNo*, int, int&);
        int preenche_posicao(CelulaNo*, int);
        CelulaNo* acharMaior(CelulaNo*);
        void imprime(CelulaNo*);
};

#endif