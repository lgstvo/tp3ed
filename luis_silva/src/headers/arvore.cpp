#include "celula.hpp"
#include "arvore.hpp"
#include <string>

ArvoreBinaria::ArvoreBinaria(){
    CelulaNo* raiz = new CelulaNo;
    this->raiz = raiz;
}

ArvoreBinaria::ArvoreBinaria(CelulaNo* raiz){
    this->raiz = raiz;
}

CelulaNo* ArvoreBinaria::getRaiz(){
    return this->raiz;
}

void ArvoreBinaria::setRaiz(CelulaNo* raiz){
    this->raiz = raiz;
}

void ArvoreBinaria::insere(CelulaNo* celula){
    CelulaNo* comparador_atual;
    comparador_atual = getRaiz();

    while(1){
        if(comparador_atual->getNome() > celula->getNome()){
            if(comparador_atual->getEsquerdo() == NULL){
                comparador_atual->setEsquerdo(celula);
                celula->setPai(comparador_atual);
                break;
            }
            else{
                comparador_atual = comparador_atual->getEsquerdo();
            }
        }
        else{
            if(comparador_atual->getDireito() == NULL){
                comparador_atual->setDireito(celula);
                celula->setPai(comparador_atual);
                break;
            }
            else{
                comparador_atual = comparador_atual->getDireito();
            }
        }
    }
    
}

CelulaNo* ArvoreBinaria::acharMaior(CelulaNo* starting_point){
    CelulaNo* maior = new CelulaNo();
    maior = starting_point;

    while(1){
        if(maior->getDireito() != NULL){
            maior = maior->getDireito();
        }
        else{
            if(maior->getEsquerdo() != NULL){
                maior = maior->getEsquerdo();
            }
            else{
                return maior;
            }
        }
    }
}

void ArvoreBinaria::remove(std::string nome){
    CelulaNo* comparador_atual;
    CelulaNo* sucessor_esquerdo;
    CelulaNo* sucessor_direito;
    bool folha, um_filho, dois_filhos;
    comparador_atual = getRaiz();

    while(1){
        if(comparador_atual->getNome() == nome){
            sucessor_esquerdo = comparador_atual->getEsquerdo();
            sucessor_direito = comparador_atual->getDireito();

            folha = sucessor_esquerdo == NULL && sucessor_direito == NULL;
            um_filho = (sucessor_esquerdo == NULL && sucessor_direito != NULL) || (sucessor_esquerdo != NULL && sucessor_direito == NULL);
            dois_filhos = sucessor_esquerdo != NULL && sucessor_direito != NULL;

            if(folha){
                delete comparador_atual;
                break;
            }

            if(um_filho){
                if(sucessor_esquerdo == NULL){
                    comparador_atual->getPai()->setDireito(sucessor_direito);
                    sucessor_direito->setPai(comparador_atual->getPai());
                    delete comparador_atual;
                    break;
                }
                else{
                    comparador_atual->getPai()->setEsquerdo(sucessor_esquerdo);
                    sucessor_esquerdo->setPai(comparador_atual->getPai());
                    delete comparador_atual;
                    break;
                }
            }

            if(dois_filhos){
                // MAIOR FILHO A DIREITA DA SUBARVORE DA ESQUERDA
                sucessor_esquerdo = acharMaior(sucessor_esquerdo);
                sucessor_direito->setPai(sucessor_esquerdo);

                if(sucessor_esquerdo->getPai()->getEsquerdo() == sucessor_esquerdo){
                    sucessor_esquerdo->getPai()->setEsquerdo(NULL);
                }
                else{
                    sucessor_esquerdo->getPai()->setDireito(NULL);
                }

                sucessor_esquerdo->setPai(comparador_atual->getPai());
                sucessor_esquerdo->setDireito(sucessor_direito);
                sucessor_esquerdo->getPai()->setDireito(sucessor_esquerdo);
            }

        }
        else if(comparador_atual->getNome() > nome){
            comparador_atual = comparador_atual->getEsquerdo();
        }
        else{
            comparador_atual = comparador_atual->getDireito();
        }
    }
}

int ArvoreBinaria::procura(std::string nome){

}

std::string ArvoreBinaria::procura(int index){
    
}

