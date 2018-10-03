#include <iostream>
#include "Pessoa.h"
#include "Atividade.h"
#include "Projeto.h"

using namespace std;





/*Recursos são adicionados ao projeto, pessoas são adicionadas às atividades*/
int main() {
    string nomeProjeto;
    int opcao;
    cout << "Digite o nome do Projeto:  ";
    cin >> nomeProjeto ;
    Projeto* proj = new Projeto(nomeProjeto);
    do{
            /** Menu do Projeto **/
        cout << "1 - Adicionar pessoa" << endl;
        cout << "2 - Adicionar atividade" << endl;
        cout << "3 - Imprimir projeto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha a opcao: ";
        cin >> opcao;
        if (opcao==1) {
                /** Menu para Adicionar Pessoas **/
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
        else if (opcao==2) {
            /** Menu para Adicionar Atividades **/
            string nome;
            int option;
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
                option = 1;
                while (ans=='s'&& option != 0) {
                    Pessoa** persons;
                    persons = proj->getPessoas();
                    for(i=0; i< proj->getQuantidadeDePessoas(); i++) {
                        cout << i+1 << " - ";
                        persons[i]->imprimir();
                    }
                    cout << "Escolha uma pessoa ou 0 para cancelar: ";
                    cin >> option;
                    if(option != 0) {
                        if(atividade->adicionar(persons[option-1]) == 0)
                          cout << "Nao foi possivel adicionar a pessoa" << endl;
                        else {
                          cout << "Adicionado a atividade" << endl;
                            }
                        }
                }
        //delete atividade;
            }
        }
        else if (opcao==3)
            proj->imprimir();
    } while(opcao!=0);


    delete proj;
    return 0;
}
