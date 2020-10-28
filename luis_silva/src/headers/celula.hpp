#ifndef CELULA
#define CELULA
#include <string>

class CelulaNo{

    private:
        std::string nome;
        CelulaNo* filho_esquerdo;
        CelulaNo* filho_direito;

    public:
        CelulaNo();
        CelulaNo(std::string);

        std::string getNome();
        CelulaNo* getEsquerdo();
        CelulaNo* getDireito();

        void setNome(std::string);
        void setEsquerdo(CelulaNo*);
        void setDireito(CelulaNo*);

};

#endif