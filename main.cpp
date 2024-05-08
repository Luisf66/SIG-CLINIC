#include <iostream>
using namespace std;

// prototipação das funções
// Telas
void Tela_Principal();
void Tela_Paciente();
void Tela_Profissional();
// Escolhas
int Escolha_Principal();
int Escolha_Paciente();
int Escolha_Profissional();

int main()
{
    Escolha_Principal();
    return 0;
}

void Tela_Principal()
{
    cout << "-----------------------------------------------" << endl;
    cout << "|=============================================|" << endl;
    cout << "|================ SIG-CLINIC =================|" << endl;
    cout << "|=============================================|" << endl;
    cout << "|+++++++++++++++++++ Menu ++++++++++++++++++++|" << endl;
    cout << "|=============================================|" << endl;
    cout << "|== 0-Encerrar                              ==|" << endl; // Encerra a aplicação
    cout << "|== 1-Paciente                              ==|" << endl; // Leva ao módulo de pacientes
    cout << "|== 2-Profissional                          ==|" << endl; // Leva ao módulo de profissionais
    cout << "|== 3-Agendamento                           ==|" << endl; // Leva ao módulo de agendamento
    cout << "|=============================================|" << endl;
    cout << "-----------------------------------------------" << endl;
}

int Escolha_Principal()
{
    int opcao_principal = 0;
    do
    {
        Tela_Principal();
        cin >> opcao_principal;
        switch (opcao_principal)
        {
        case 0:
            cout << "Encerrando aplicação" << endl;
            break;
        case 1:
            cout << "Abrindo módulo Paciente" << endl;
            Escolha_Paciente();
            break;
        case 2:
            cout << "Abrindo módulo Profissional" << endl;
            Escolha_Profissional();
            break;
        case 3:
            cout << "Abrindo módulo Agendamento" << endl;
            break;
        default:
            cout << "Escolha uma opção dentre as listadas" << endl;
            break;
        }
    } while (opcao_principal != 0);
    return opcao_principal;
}

void Tela_Paciente()
{
    cout << "------------------------------------------------" << endl;
    cout << "|==============================================|" << endl;
    cout << "|================= SIG-CLINIC =================|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|+++++++++++++++++ PACIENTES ++++++++++++++++++|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|== 0-Voltar                                 ==|" << endl; // volta ao menu principal
    cout << "|== 1-Cadastrar                              ==|" << endl; // cadastra um paciente
    cout << "|== 2-Editar                                 ==|" << endl; // edita as informações de um paciente
    cout << "|== 3-Deletar                                ==|" << endl; // deleta um paciente
    cout << "|== 4-Buscar                                 ==|" << endl; // busca um paciente
    cout << "|== 5-Checar Consulta                        ==|" << endl; // checa as consultas de um paciente
    cout << "|== 6-Pagamento                              ==|" << endl; // paga uma consulta de um paciente
    cout << "|==============================================|" << endl;
    cout << "------------------------------------------------" << endl;
}

int Escolha_Paciente()
{
    int opcao_paciente = 0;
    Tela_Paciente();
    cin >> opcao_paciente;

    switch (opcao_paciente)
    {
    case 0:
        cout << "Voltando ao menu principal" << endl;
        break;
    case 1:
        cout << "Cadastro de Paciente" << endl;
        break;
    case 2:
        cout << "Edição de Paciente" << endl;
        break;
    case 3:
        cout << "Eliminação de Paciente" << endl;
        break;
    case 4:
        cout << "Busca por Paciente" << endl;
        break;
    case 5:
        cout << "Checando Consulta" << endl;
        break;
    case 6:
        cout << "Informe o método de pagamento" << endl;
        break;
    default:
        cout << "Escolha uma opção válida" << endl;
        break;
    }
    return opcao_paciente;
}

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