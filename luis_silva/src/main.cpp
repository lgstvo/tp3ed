#include <iostream>
#include <string>

int main(){

    int numero_operacoes, numero_E_D, numero_encriptado;
    char letra_operacao;
    std::string palavra;

    std::cin >> numero_operacoes;

    while(numero_operacoes){

        std::cin >> letra_operacao;

        if(letra_operacao == 'i'){
            std::cin >> palavra;

            // [COMENTÁRIO] INSERE NA ARVORE
        }

        if(letra_operacao == 's'){
            std::cin >> palavra;

            // [COMENTÁRIO]  REMOVE PALAVRA

            std::cin >> palavra;

            // [COMENTÁRIO]  INSERE NA ARVORE

        }

        if(letra_operacao == 'e'){
            std::cin >> numero_E_D;

            for(int i = 0; i < numero_E_D; i++){
                std::cin >> palavra;

                // [COMENTÁRIO]  caminhamento pre ordem para achar palavra
                // [COMENTÁRIO]  numero_encriptado = ;
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

                // [COMENTÁRIO]  acha palavra na casa numero_encriptado
                // [COMENTÁRIO]  palavra = ;
                std::cout << palavra;

                if(i != numero_E_D-1){
                    std::cout << " ";
                }
                else{
                    std::cout << std::endl;
                }
            }
        }

        numero_operacoes--;
    }


    return 0;
}