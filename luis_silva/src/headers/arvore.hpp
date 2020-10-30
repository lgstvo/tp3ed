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
        CelulaNo* acharMaior(CelulaNo*);
        void imprime(CelulaNo*);

        int pesquisaEncriptar(std::string, CelulaNo*, int, int*);
        int pesquisaDecriptar(CelulaNo*, int, int*);

        int encriptar(std::string);
        void decriptar(int);
        void atualizarParentesco(CelulaNo*,CelulaNo*);

};

#endif