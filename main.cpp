#include <iostream>
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

using namespace std;



int menuProjeto(Projeto* proj) {
    int opcao;
    cout << "1 - Adicionar pessoa" << endl;
    cout << "2 - Adicionar atividade" << endl;
    cout << "3 - Imprimir projeto" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha a opcao: ";
    cin >> opcao;
    return opcao;
}

void menuAdicionarPessoa(Projeto* proj) {
    string nome;
    int valor, horas;
    cout << "Nome: ";
    cin >> nome;
    cout << "Valor por hora (em R$): ";
    cin >> valor;
    cout << "Horas diarias: ";
    cin >> horas;
    Pessoa* pers = new Pessoa(nome, valor, horas);
    if (!proj->adicionarRecurso(pers)) {
        cout << "Nao eh possivel adicionar uma nova pessoa" << endl;
    }
}

void imprimirRecursos(Projeto* proj) {
    Pessoa** persons;
    persons = proj->getPessoas();
    int i;
    for(i=1; i<proj->getQuantidadeDeAtividades(); i++) {
        cout << i << " - ";
        persons[i]->imprimir();
    }
}

void menuAdicionarAtividade(Projeto* proj) {
    string nome;
    char ans;
    int horas, i;
    cout << "Nome: ";
    cin >> nome;
    cout << "Horas necessarias: ";
    cin >> horas;
    if(proj->getQuantidadeDeAtividades()< MAXIMO_ATIVIDADES){
        Atividade* atividade = new Atividade(nome, horas);
        proj->adicionar(atividade);
        cout << "Deseja adicionar um recurso (s/n): ";
        cin >> ans;
        if (ans=='s') {
            imprimirRecursos(proj);
        }
    }
}

/*Recursos são adicionados ao projeto, pessoas são adicionadas às atividades*/
int main() {
    string nomeProjeto;
    int opcao;
    cout << "Digite o nome do Projeto:  ";
    cin >> nomeProjeto ;
    Projeto* proj = new Projeto(nomeProjeto);
    do{
        opcao = menuProjeto(proj);
        if (opcao==1)
            menuAdicionarPessoa(proj);
        else if (opcao==2)
            menuAdicionarAtividade(proj);
        else if (opcao==3)
            proj->imprimir();
    } while(opcao!=0);


    delete proj;
    return 0;
}
