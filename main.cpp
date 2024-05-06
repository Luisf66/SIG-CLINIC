#include <iostream>
using namespace std;

void Tela_Principal();
int Tela_Paciente();

int main()
{
    Tela_Principal();
    return 0;
}

void Tela_Principal()
{
    int opcao_principal = 0; // variável para seleção no menu principal
    int opcao_paciente = 0;  // variável para seleção no menu paciente
    // Tela principal
    do
    {
        cout << "-----------------------------------------------" << endl;
        cout << "|=============================================|" << endl;
        cout << "|=================SIG-CLINIC==================|" << endl;
        cout << "|=============================================|" << endl;
        cout << "|+++++++++++++++++++++++++++++++++++++++++++++|" << endl;
        cout << "|=============================================|" << endl;
        cout << "|== 0-Encerrar                              ==|" << endl; // Encerra a aplicação
        cout << "|== 1-Paciente                              ==|" << endl; // Leva ao módulo de pacientes
        cout << "|== 2-Profissional                          ==|" << endl; // Leva ao módulo de profissionais
        cout << "|== 3-Agendamento                           ==|" << endl; // Leva ao módulo de agendamento
        cout << "|=============================================|" << endl;
        cout << "-----------------------------------------------" << endl;
        cin >> opcao_principal;
        //------------------SELEÇÃO NO MENU PRINCIPAL-------------------------//
        switch (opcao_principal)
        {
        case 0:
            cout << "Encerrando aplicação" << endl;
            break;
        case 1:
            cout << "Abrindo módulo Paciente" << endl;
            //------------------SELEÇÃO NO MENU PACIENTE-----------------------//
            opcao_paciente = Tela_Paciente();
            switch (opcao_paciente)
            {
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
                cout << "Checagem de Consulta" << endl;
                break;
            case 6:
                cout << "Pagamento de consulta" << endl;
                break;
            case 7:
                cout << "Agendamento de consulta" << endl;
                break;
            default:
                cout << "Escolha uma opção dentre as listadas" << endl;
                break;
            }
            //------------------FIM DO MENU PACIENTE-----------------------//
            break;
        case 2:
            cout << "Abrindo módulo Profissional" << endl;
            break;
        case 3:
            cout << "Abrindo módulo Agendamento" << endl;
            break;
        default:
            cout << "Escolha uma opção dentre as listadas" << endl;
            break;
        }
        //------------------FIM DO MENU PRINCIPAL-------------------------//
    } while (opcao_principal != 0);
}

int Tela_Paciente()
{
    int opcao_paciente = 0;
    cout << "-----------------------------------------------" << endl;
    cout << "|=============================================|" << endl;
    cout << "|=================SIG-CLINIC==================|" << endl;
    cout << "|=============================================|" << endl;
    cout << "|++++++++++++++++++PACIENTES++++++++++++++++++|" << endl;
    cout << "|=============================================|" << endl;
    cout << "|== 0-Voltar                                ==|" << endl; // volta ao menu principal
    cout << "|== 1-Cadastrar                             ==|" << endl; // cadastra um paciente
    cout << "|== 2-Editar                                ==|" << endl; // edita as informações de um paciente
    cout << "|== 3-Deletar                               ==|" << endl; // deleta um paciente
    cout << "|== 4-Buscar                                ==|" << endl; // busca um paciente
    cout << "|== 5-Checar Consulta                       ==|" << endl; // checa as consultas de um paciente
    cout << "|== 6-Pagamento                             ==|" << endl; // paga uma consulta de um paciente
    cout << "|== 7-Agendamento                           ==|" << endl; // agenda uma consulta para um paciente
    cout << "|=============================================|" << endl;
    cout << "-----------------------------------------------" << endl;
    cin >> opcao_paciente;
    return opcao_paciente;
}