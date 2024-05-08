#include <iostream>
using namespace std;

void Tela_Profissional()
{
    cout << "------------------------------------------------" << endl;
    cout << "|==============================================|" << endl;
    cout << "|================= SIG-CLINIC =================|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|++++++++++++++++ PROFISSIONAL ++++++++++++++++|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|== 0-Voltar                                 ==|" << endl; // volta ao menu principal
    cout << "|== 1-Cadastrar                              ==|" << endl; // cadastra um profissional
    cout << "|== 2-Editar                                 ==|" << endl; // edita as informações de um profissional
    cout << "|== 3-Deletar                                ==|" << endl; // deleta um profissional
    cout << "|== 4-Buscar                                 ==|" << endl; // busca um profissional
    cout << "|== 5-Realizar Consulta                      ==|" << endl; // inicia uma consulta
    cout << "|==============================================|" << endl;
    cout << "------------------------------------------------" << endl;
}

int Escolha_Profissional()
{
    int opcao_profissional = 0;
    Tela_Profissional();
    cin >> opcao_profissional;

    switch (opcao_profissional)
    {
    case 0:
        cout << "Voltando ao menu principal" << endl;
        break;
    case 1:
        cout << "Cadastro de Profissional" << endl;
        break;
    case 2:
        cout << "Edição de Profissional" << endl;
        break;
    case 3:
        cout << "Eliminação de Profissional" << endl;
        break;
    case 4:
        cout << "Busca por Profissional" << endl;
        break;
    case 5:
        cout << "Realizando Consulta" << endl;
        break;
    default:
        cout << "Escolha uma opção válida" << endl;
        break;
    }
    return opcao_profissional;
}