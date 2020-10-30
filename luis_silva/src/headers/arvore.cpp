#include "celula.hpp"
#include "arvore.hpp"
#include <string>
#include <iostream>

ArvoreBinaria::ArvoreBinaria()
{
    CelulaNo *raiz = new CelulaNo;
    this->raiz = raiz;
}

ArvoreBinaria::ArvoreBinaria(CelulaNo *raiz)
{
    this->raiz = raiz;
}

CelulaNo *ArvoreBinaria::getRaiz()
{
    return this->raiz;
}

void ArvoreBinaria::setRaiz(CelulaNo *raiz)
{
    this->raiz = raiz;
}

void ArvoreBinaria::insere(CelulaNo *celula)
{
    CelulaNo *comparador_atual;
    comparador_atual = getRaiz();

    while (1)
    {
        if (comparador_atual->getNome() > celula->getNome())
        {
            if (comparador_atual->getEsquerdo() == NULL)
            {
                comparador_atual->setEsquerdo(celula);
                celula->setPai(comparador_atual);
                break;
            }
            else
            {
                comparador_atual = comparador_atual->getEsquerdo();
            }
        }
        else
        {
            if (comparador_atual->getDireito() == NULL)
            {
                comparador_atual->setDireito(celula);
                celula->setPai(comparador_atual);
                break;
            }
            else
            {
                comparador_atual = comparador_atual->getDireito();
            }
        }
    }
}

CelulaNo *ArvoreBinaria::acharMaior(CelulaNo *starting_point)
{
    CelulaNo *maior = new CelulaNo();
    maior = starting_point;

    while (1)
    {
        if (maior->getDireito() != NULL)
        {
            maior = maior->getDireito();
        }
        else
        {
            if (maior->getEsquerdo() != NULL)
            {
                maior = maior->getEsquerdo();
            }
            else
            {
                return maior;
            }
        }
    }
}

void ArvoreBinaria::remove(std::string nome)
{
    CelulaNo *comparador_atual;
    CelulaNo *sucessor_esquerdo = new CelulaNo();
    CelulaNo *sucessor_direito = new CelulaNo();
    comparador_atual = getRaiz();

    while (1)
    {
        if (comparador_atual->getNome() == nome)
        {
            sucessor_esquerdo = comparador_atual->getEsquerdo();
            sucessor_direito = comparador_atual->getDireito();

            if (sucessor_esquerdo == NULL && sucessor_direito == NULL)
            {
                if (comparador_atual->getPai() != NULL)
                {
                    if (comparador_atual->getPai()->getNome() > comparador_atual->getNome())
                    {
                        comparador_atual->getPai()->setEsquerdo(NULL);
                    }
                    else if (comparador_atual->getPai()->getNome() < comparador_atual->getNome())
                    {
                        comparador_atual->getPai()->setDireito(NULL);
                    }
                }
                else
                {
                    setRaiz(NULL);
                }
                delete comparador_atual;
                break;
            }

            if (sucessor_esquerdo != NULL && sucessor_direito == NULL)
            {
                if (comparador_atual->getPai() != NULL)
                {
                    sucessor_esquerdo->setPai(comparador_atual->getPai());

                    if (comparador_atual->getPai()->getEsquerdo() == NULL)
                    {
                        comparador_atual->getPai()->setDireito(sucessor_esquerdo);
                    }
                    else
                    {
                        sucessor_esquerdo->getPai()->setEsquerdo(sucessor_esquerdo);
                        sucessor_esquerdo->getPai()->setDireito(sucessor_direito);
                    }
                }
                else
                {
                    setRaiz(sucessor_esquerdo);
                    sucessor_esquerdo->setPai(comparador_atual->getPai());
                }
                delete comparador_atual;
                break;
            }

            else if (sucessor_esquerdo == NULL && sucessor_direito != NULL)
            {
                if (comparador_atual->getPai() == NULL)
                {
                    setRaiz(sucessor_direito);
                }
                else
                {
                    comparador_atual->getPai()->setDireito(sucessor_direito);
                    sucessor_direito->setPai(comparador_atual->getPai());
                }
                delete comparador_atual;
                break;
            }

            if (sucessor_esquerdo != NULL && sucessor_direito != NULL)
            {
                if (sucessor_esquerdo->getDireito() == NULL)
                {
                    sucessor_esquerdo->setPai(comparador_atual->getPai());
                    sucessor_esquerdo->setDireito(sucessor_direito);
                    if (comparador_atual->getPai() != NULL)
                    {
                        sucessor_esquerdo->getPai()->setDireito(sucessor_esquerdo);
                    }
                    else
                    {
                        setRaiz(sucessor_esquerdo);
                        sucessor_esquerdo->setPai(comparador_atual->getPai());
                    }
                }
                delete comparador_atual;
                break;
            }
            else
            {
                sucessor_esquerdo = acharMaior(sucessor_esquerdo);
                sucessor_direito->setPai(sucessor_esquerdo);
                if (sucessor_esquerdo->getPai()->getEsquerdo() == sucessor_esquerdo)
                {
                    sucessor_esquerdo->getPai()->setEsquerdo(NULL);
                }
                else
                {
                    sucessor_esquerdo->getPai()->setDireito(NULL);
                }
            }
            sucessor_esquerdo->setPai(comparador_atual->getPai());
            sucessor_esquerdo->setDireito(sucessor_direito);

            if (comparador_atual->getPai() != NULL)
            {
                sucessor_esquerdo->getPai()->setDireito(sucessor_esquerdo);
            }
            else
            {
                setRaiz(sucessor_esquerdo);
                sucessor_esquerdo->setPai(comparador_atual->getPai());
            }
            sucessor_esquerdo->setEsquerdo(comparador_atual->getEsquerdo());
            delete comparador_atual;
            break;
        }
        else if (comparador_atual->getNome() > nome)
        {
            comparador_atual = comparador_atual->getEsquerdo();
        }
        else
        {
            comparador_atual = comparador_atual->getDireito();
        }
    }
}

int ArvoreBinaria::pesquisaEncriptar(std::string nome_retirar, CelulaNo *no, int contador, int *achei)
{
    if (!*achei)
    {
        if (no->getNome() == nome_retirar)
        {
            *achei = 1;
            return contador;
        }
        else if (no->getEsquerdo() != NULL && no->getDireito() != NULL)
        {

            contador++;
            contador = pesquisaEncriptar(nome_retirar, no->getEsquerdo(), contador, achei);

            if (!*achei)
            {
                contador++;
                contador = pesquisaEncriptar(nome_retirar, no->getDireito(), contador, achei);
            }
        }
        else if (no->getEsquerdo() != NULL)
        {
            contador++;
            contador = pesquisaEncriptar(nome_retirar, no->getEsquerdo(), contador, achei);
        }
        else if (no->getDireito() != NULL)
        {
            contador++;
            contador = pesquisaEncriptar(nome_retirar, no->getDireito(), contador, achei);
        }
        else if (!*achei && no->getEsquerdo() == NULL && no->getDireito() == NULL)
        {
            return contador;
        }
    }

    return contador;
}

int ArvoreBinaria::encriptar(std::string nome_retirar)
{

    int contador = 1;
    int encontradoPointer = 0;
    int *achei = &encontradoPointer;

    contador = pesquisaEncriptar(nome_retirar, getRaiz(), contador, achei);

    if (contador != -1)
        std::cout << contador << " ";

    return 0;
}

int ArvoreBinaria::pesquisaDecriptar(CelulaNo *no, int contador, int *achei)
{

    if (!*achei)
    {
        if (contador == 1)
        {
            *achei = 1;
            std::cout << no->getNome() << " ";
            return 0;
        }
        else
        {
            contador--;
            if (no->getEsquerdo() != NULL)
            {
                contador = pesquisaDecriptar(no->getEsquerdo(), contador, achei);
            }
            if (no->getDireito() != NULL)
            {
                contador = pesquisaDecriptar(no->getDireito(), contador, achei);
            }
        }
    }
    return contador;
}

void ArvoreBinaria::decriptar(int posicaoPalavra)
{
    int encontradoPointer = 0;
    int *achei = &encontradoPointer;

    pesquisaDecriptar(getRaiz(), posicaoPalavra, achei);
}

void ArvoreBinaria::imprime(CelulaNo *raiz)
{
    if (raiz != NULL)
    {
        std::cout << raiz->getNome() << std::endl;
        imprime(raiz->getEsquerdo());
        imprime(raiz->getDireito());
    }
}