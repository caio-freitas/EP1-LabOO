#include "Pessoa.h"
#include <iostream>


Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias):
  nome(nome), valorPorHora(valorPorHora), horasDiarias(horasDiarias){
}

Pessoa::~Pessoa(){
    cout << "Pessoa" << nome << "apagada" << endl;
}

string Pessoa::getNome(){
    return nome;
}
double Pessoa::getValorPorHora(){
    return valorPorHora;
}
int Pessoa::getHorasDiarias(){
    return horasDiarias;
}
double Pessoa::getCusto(int dias){
    return dias * horasDiarias * valorPorHora;
}

void Pessoa::imprimir(){
    cout << this->nome << " - R$" << this->valorPorHora << " - " << this->horasDiarias << "h por dia" << endl;
}
