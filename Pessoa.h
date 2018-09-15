#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    double valorPorHora;
    int horasDiarias;

public:
  Pessoa(string nome, double valorPorHora, int horasDiarias);
  ~Pessoa();

  string getNome();
  double getValorPorHora();
  int getHorasDiarias();
  double getCusto(int dias);

  void imprimir();
};

#endif // PESSOA_H
