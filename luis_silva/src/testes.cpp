#include <iostream>
#include <string>
#include "headers/celula.hpp"
#include "headers/arvore.hpp"

using namespace std;

int main(){
    CelulaNo* a = new CelulaNo("a");
    ArvoreBinaria arvore = ArvoreBinaria(a);

    CelulaNo* aa = new CelulaNo("aa");
    CelulaNo* aaa = new CelulaNo("aaa");
    CelulaNo* aab = new CelulaNo("aab");

    CelulaNo* ab = new CelulaNo("ab");
    CelulaNo* aba = new CelulaNo("aba");
    CelulaNo* abb = new CelulaNo("abb");
    CelulaNo* abbb = new CelulaNo("abbb");

    arvore.insere(aa);
    arvore.insere(aaa);
    arvore.insere(aab);
    arvore.insere(ab);
    arvore.insere(aba);
    arvore.insere(abb);
    arvore.insere(abbb);

    arvore.remove("ab");

    arvore.imprime(arvore.getRaiz());

    return 0;
}