#define MAXIMO_RECURSOS 10
#include <iostream>
#include <cmath>
#include "Atividade.h"
#include "Pessoa.h"


Atividade::Atividade(string nome, int horasNecessarias): //Construtor
  nome(nome), horasNecessarias(horasNecessarias) {       //Inicialização das variáveis com 0
  duracao = 0;
  quantidadeDePessoas = 0;
  custo = 0;
}
Atividade::~Atividade(){
  cout << "Atividade " << this->nome << " apagada" << endl;
}

string Atividade::getNome(){
  return this->nome;
}
int Atividade::getHorasNecessarias(){
  return this->horasNecessarias;
}

bool Atividade::adicionar(Pessoa* recurso){
  if (this->quantidadeDePessoas>=MAXIMO_RECURSOS || jaAdicionada(recurso))
    return false;
  else {
    pessoas[quantidadeDePessoas] = recurso;
    quantidadeDePessoas++;
    this->setDuracao();
    return true;
  }
}
Pessoa** Atividade::getPessoas(){
  return pessoas;
}
int Atividade::getQuantidadeDePessoas(){
  return this->quantidadeDePessoas;
}

int Atividade::getDuracao(){
    if (quantidadeDePessoas == 0)
        return -1;
    return duracao;
}

double Atividade::getCusto(){
  int i=0;
  double custo=0;
  for (i=0; i<quantidadeDePessoas; i++)
    custo = custo + pessoas[i]->getCusto(duracao);
  return custo;
}

void Atividade::imprimir(){
    if (getDuracao()==-1)
        cout << "Nao ha pessoas cadastradas para a atividade " << nome << endl;
    else
        cout << nome << " - " << getDuracao() << " dias - R$" << getCusto() << endl; /*Se não tiver nenhuma pessoa, imprime oq??*/
}


/*A seguinte função retorna TRUE se uma pessoa passada como parametro
já foi adicionada ao vetor pessoas, e FALSE caso contrário*/
bool Atividade::jaAdicionada(Pessoa* p) {
  int i;
  for (i=0; i<this->quantidadeDePessoas; i++) {
    if(p == pessoas[i])
      return true;
  }
  return false;
}

void Atividade::setDuracao() {
    int totaldehoras=0;
    int i=0;
    for(i=0; i<quantidadeDePessoas; i++)
        totaldehoras = pessoas[i]->getHorasDiarias();
    this->duracao = ceil(this->horasNecessarias/totaldehoras);
}

