#ifndef PROJETO_H
#define PROJETO_H
#define MAXIMO_ATIVIDADES 10
#include <iostream>
#include <string>
#include "Atividade.h"

using namespace std;

class Projeto{
public:
  Projeto(string nome);
  ~Projeto();

  string getNome();

  bool adicionar(Atividade* a);
  Atividade** getAtividades();
  int getQuantidadeDeAtividades();

  bool adicionarRecurso(Pessoa* p);
  Pessoa** getPessoas();
  int getQuantidadeDePessoas();


  int getDuracao();
  void setDuracao();
  double getCusto();
  void setCusto();

  void imprimir();

private:
    int quantidadeDeAtividades;
    int quantidadeDePessoas;
    Atividade* atividades[MAXIMO_ATIVIDADES];
    Pessoa* pessoas[MAXIMO_RECURSOS];
    bool jaAdicionada(Pessoa* p);
    int duracao;
    double custo;
    string nome;
  /*Criar Métodos*/
};

#endif
