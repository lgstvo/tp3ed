#include <string>
#include <iostream>
#include "celula.hpp"

CelulaNo::CelulaNo(){
    this->nome = "";
    this->filho_esquerdo = NULL;
    this->filho_direito = NULL;
}

CelulaNo::CelulaNo(std::string nome){
    this->nome = nome;
    this->filho_esquerdo = NULL;
    this->filho_direito = NULL;
}

std::string CelulaNo::getNome(){
    return this->nome;
}

CelulaNo* CelulaNo::getDireito(){
    return this->filho_direito;
}

CelulaNo* CelulaNo::getEsquerdo(){
    return this->filho_esquerdo;
}

void CelulaNo::setNome(std::string nome){
    this->nome = nome;
}

void CelulaNo::setDireito(CelulaNo* Celula){
    this->filho_direito = Celula;
}

void CelulaNo::setEsquerdo(CelulaNo* Celula){
    this->filho_esquerdo = Celula;
}

