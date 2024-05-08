#include <iostream>
using namespace std;

void Tela_Agendamento()
{
    cout << "------------------------------------------------" << endl;
    cout << "|==============================================|" << endl;
    cout << "|================= SIG-CLINIC =================|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|+++++++++++++++++ AGENDAMENTO ++++++++++++++++|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|== 0-Voltar                                 ==|" << endl; // volta ao menu principal
    cout << "|== 1-Agendar                                ==|" << endl; // cadastra um agendamento
    cout << "|== 2-Remarcar                               ==|" << endl; // remarca um agendamento
    cout << "|== 3-Cancelar                               ==|" << endl; // cancela um agendamento
    cout << "|== 4-Buscar                                 ==|" << endl; // busca um agendamento
    cout << "|==============================================|" << endl;
    cout << "------------------------------------------------" << endl;
}

int Escolha_Agendamento()
{
    int opcao_agendamento = 0;
    Tela_Agendamento();
    cin >> opcao_agendamento;

    switch (opcao_agendamento)
    {
    case 0:
        cout << "Voltando ao menu principal" << endl;
        break;
    case 1:
        cout << "Agendamento" << endl;
        break;
    case 2:
        cout << "Remarcar" << endl;
        break;
    case 3:
        cout << "Cancelar agendamento" << endl;
        break;
    case 4:
        cout << "Busca por agendamento" << endl;
        break;
    default:
        cout << "Escolha uma opção válida" << endl;
        break;
    }
    return opcao_agendamento;
}