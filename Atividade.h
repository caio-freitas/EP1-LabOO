#ifndef ATIVIDADE_H
#define ATIVIDADE_H
#define MAXIMO_RECURSOS 10
#include <iostream>
#include <string>
#include "Pessoa.h"

using namespace std;

class Atividade {
private:
  string nome;
  int horasNecessarias;
  Pessoa* pessoas[MAXIMO_RECURSOS];
  int quantidadeDePessoas;
  int duracao;
  double custo;
  /*Métodos*/
  bool jaAdicionada(Pessoa* p);
  void setDuracao();


public:
  Atividade(string nome, int horasNecessarias);
  ~Atividade();

  string getNome();
  int getHorasNecessarias();

  bool adicionar(Pessoa* recurso);
  Pessoa** getPessoas();
  int getQuantidadeDePessoas();

  int getDuracao();

  double getCusto();

  void imprimir();


};
#endif
