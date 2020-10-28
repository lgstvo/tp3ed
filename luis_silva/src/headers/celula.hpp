#ifndef CELULA
#define CELULA
#include <string>

class CelulaNo{

    private:
        std::string nome;
        CelulaNo* filho_esquerdo;
        CelulaNo* filho_direito;
        CelulaNo* pai;

    public:
        CelulaNo();
        CelulaNo(std::string);

        std::string getNome();
        CelulaNo* getEsquerdo();
        CelulaNo* getDireito();
        CelulaNo* getPai();

        void setNome(std::string);
        void setEsquerdo(CelulaNo*);
        void setDireito(CelulaNo*);
        void setPai(CelulaNo*);

};

#endif