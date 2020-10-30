#include <iostream>
#include <string>
#include "headers/celula.hpp"
#include "headers/arvore.hpp"

int main(){

    int numero_operacoes, numero_E_D, numero_encriptado;
    char letra_operacao;
    std::string palavra;
    CelulaNo* palavra_no;
    ArvoreBinaria Arvore;

    while(std::cin >> letra_operacao){

        if(letra_operacao == 'i'){
            std::cin >> palavra;
            palavra_no = new CelulaNo(palavra);
            if(Arvore.getRaiz()->getNome() == ""){
                Arvore.setRaiz(palavra_no);
            }
            else 
                Arvore.insere(palavra_no);
        }

        if(letra_operacao == 's'){
            std::cin >> palavra;

            Arvore.remove(palavra);

            std::cin >> palavra;
            palavra_no = new CelulaNo(palavra);
            Arvore.insere(palavra_no);

        }

        if(letra_operacao == 'e'){
            std::cin >> numero_E_D;

            for(int i = 0; i < numero_E_D; i++){
                std::cin >> palavra;

                numero_encriptado = Arvore.encriptar(palavra);
                
            }
            std::cout << std::endl;
        }

        if(letra_operacao == 'd'){
            std::cin >> numero_E_D;

            for(int i = 0; i < numero_E_D; i++){
                std::cin >> numero_encriptado;
                
                Arvore.decriptar(numero_encriptado);
            }
            std::cout << std::endl;
        }

        numero_operacoes--;
    }


    return 0;
}