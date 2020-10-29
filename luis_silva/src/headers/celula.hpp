#ifndef CELULA
#define CELULA
#include <string>

class CelulaNo{

    private:
        std::string nome;
        CelulaNo* filho_esquerdo;
        CelulaNo* filho_direito;
        CelulaNo* pai;
        int posicao;

    public:
        CelulaNo();
        CelulaNo(std::string);

        std::string getNome();
        CelulaNo* getEsquerdo();
        CelulaNo* getDireito();
        CelulaNo* getPai();
        int getPosicao();

        void setPosicao(int);
        void setNome(std::string);
        void setEsquerdo(CelulaNo*);
        void setDireito(CelulaNo*);
        void setPai(CelulaNo*);

};

#endif