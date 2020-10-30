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
    
    if(getRaiz() != NULL)
    {
        comparador_atual = getRaiz();
    }
    else
    {
        setRaiz(celula);
        return;
    }

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

CelulaNo *ArvoreBinaria::acharMaior(CelulaNo* starting_point)
{
    CelulaNo* mostRightChildOfLeftBranch;
    if (starting_point->getEsquerdo() == NULL)
    {
        return starting_point->getDireito();
    }
    else if (starting_point->getDireito() == NULL)
    {
        return starting_point->getEsquerdo();
    }
    else
    {
        mostRightChildOfLeftBranch = starting_point->getEsquerdo();
        while (mostRightChildOfLeftBranch->getDireito() != NULL)
        {
            mostRightChildOfLeftBranch = mostRightChildOfLeftBranch->getDireito();
        }
        return mostRightChildOfLeftBranch;
    }
}


void ArvoreBinaria::atualizarParentesco(CelulaNo* node, CelulaNo* novo_no)
{
    if (node == NULL)
    {
        return;
    }
    CelulaNo *parent = node->getPai();
    if (parent == NULL)
    {
        setRaiz(novo_no);
        if (novo_no != NULL)
        {
            novo_no->setPai(NULL);
        }
    }
    else
    {
        if (parent->getEsquerdo() != NULL && parent->getEsquerdo()->getNome() == node->getNome())
        {
            parent->setEsquerdo(novo_no);
        }
        else if (parent->getDireito() != NULL && parent->getDireito()->getNome() == node->getNome())
        {
            parent->setDireito(novo_no);
        }
    }
}

void ArvoreBinaria::remove(std::string nome)
{
    CelulaNo *auxNode = getRaiz();
    while (auxNode->getNome() != nome)
    {
        if (auxNode->getNome().compare(nome) > 0)
        {
            auxNode = auxNode->getEsquerdo();
        }
        else if (auxNode->getNome().compare(nome) < 0)
        {
            auxNode = auxNode->getDireito();
        }
    }
    CelulaNo *substituteNode = acharMaior(auxNode);
    if (substituteNode == NULL)
    {
        atualizarParentesco(auxNode, NULL);
        return;
    }

    auxNode->setNome(substituteNode->getNome());

    if (substituteNode == auxNode->getEsquerdo() && auxNode->getDireito() != NULL)
    {
        substituteNode->setDireito(auxNode->getDireito());
    }

    if (substituteNode->getEsquerdo() != NULL || substituteNode->getDireito() != NULL)
    {
        substituteNode->getPai()->setEsquerdo(substituteNode->getEsquerdo());
        substituteNode->getPai()->setDireito(substituteNode->getDireito());
        return;
    }

    atualizarParentesco(substituteNode, NULL);
    free(substituteNode);
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