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
        int procura(std::string);
        std::string procura(int);

        CelulaNo* acharMaior(CelulaNo*);
};

#endif