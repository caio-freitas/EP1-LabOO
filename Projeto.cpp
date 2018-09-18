#define MAXIMO_ATIVIDADES 10
#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

Projeto::Projeto(string nome):
  nome(nome){
      quantidadeDeAtividades=0;
    //Implementar
}
Projeto::~Projeto(){
    //Implementar
}

string Projeto::getNome(){
    return this->nome;
}

bool Projeto::adicionar(Atividade* a){
    if (this->quantidadeDeAtividades>=MAXIMO_RECURSOS)
        return false;
    else {
        atividades[quantidadeDeAtividades] = a;
        quantidadeDeAtividades++;
        return true;
    }
}

Atividade** Projeto::getAtividades(){
    return atividades;
}

int Projeto::getQuantidadeDeAtividades(){
    return this->quantidadeDeAtividades;
}

bool Projeto::adicionarRecurso(Pessoa* p){
    if (this->quantidadeDePessoas>=MAXIMO_RECURSOS || jaAdicionada(p))
        return false;
    else {
        pessoas[quantidadeDePessoas] = p;
        quantidadeDePessoas++;
        return true;
    }
}
Pessoa** Projeto::getPessoas(){
    return pessoas;
}
int Projeto::getQuantidadeDePessoas(){
    return this->quantidadeDePessoas;
}

int Projeto::getDuracao(){
    int i;
    duracao = 0;
    for (i=0; i<quantidadeDeAtividades; i++){
        duracao = duracao + atividades[i]->getHorasNecessarias();
    }
}
double Projeto::getCusto(){
     int i;
    custo = 0;
    for (i=0; i<quantidadeDeAtividades; i++){
        custo = custo + atividades[i]->getCusto();
    }
}

void Projeto::imprimir(){
    int i;
    cout << getNome() << " - " << getDuracao() << " dias -  R$" << getCusto() << endl;
    for (i=0; i<quantidadeDeAtividades; i++){
        atividades[i]->imprimir();
    }
}

bool Projeto::jaAdicionada(Pessoa* p) {
  int i;
  for (i=0; i<this->quantidadeDePessoas; i++) {
    if(p == pessoas[i])
      return true;
  }
  return false;
}
