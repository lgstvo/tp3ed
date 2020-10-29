#include <iostream>
#include <string>
#include "headers/celula.hpp"
#include "headers/arvore.hpp"

int main(){

    int numero_operacoes, numero_E_D, numero_encriptado, contador_encriptado;
    char letra_operacao;
    std::string palavra;
    CelulaNo* palavra_no;
    ArvoreBinaria Arvore;

    while(std::cin >> letra_operacao){

        if(letra_operacao == 'i'){
            std::cin >> palavra;
            palavra_no = new CelulaNo(palavra);
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

                
                numero_encriptado = Arvore.procura(Arvore.getRaiz(), palavra, 0);
                std::cout << numero_encriptado;
                
                if(i != numero_E_D-1){
                    std::cout << " ";
                }
                else{
                    std::cout << std::endl;
                }
            }
        }

        if(letra_operacao == 'd'){
            std::cin >> numero_E_D;

            for(int i = 0; i < numero_E_D; i++){
                std::cin >> numero_encriptado;
                
                contador_encriptado = 1;
                Arvore.procura(Arvore.getRaiz(), numero_encriptado, contador_encriptado);
                if(i != numero_E_D-1 && i != 0){
                    std::cout << " ";
                }
                else{
                    if(i != 0) std::cout << std::endl;
                }
            }
        }

        numero_operacoes--;
    }


    return 0;
}