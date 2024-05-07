#include <iostream>
using namespace std;

// prototipação das funções
void Tela_Principal();
int Tela_Paciente();
int Tela_Profissional();

int main()
{
    Tela_Principal();
    return 0;
}

void Tela_Principal()
{
    int opcao_principal = 0;    // variável para seleção no menu principal
    int opcao_paciente = 0;     // variável para seleção no menu paciente
    int opcao_profissional = 0; // variável para seleção no menu profissional
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
            default:
                cout << "Escolha uma opção dentre as listadas" << endl;
                break;
            }
            //------------------FIM DO MENU PACIENTE-----------------------//
            break;
        case 2:
            cout << "Abrindo módulo Profissional" << endl;
            //-----------------SELEÇÃO NO MENU PROFISSIONAL----------------//
            opcao_profissional = Tela_Profissional();
            switch (opcao_profissional)
            {
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
                cout << "Iniciando Consulta" << endl;
                break;
            default:
                cout << "Escolha uma opção dentre as listadas" << endl;
                break;
            }
            //-----------------FIM DO MENU PROFISSIONAL-------------------//
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
    cout << "------------------------------------------------" << endl;
    cout << "|==============================================|" << endl;
    cout << "|=================SIG-CLINIC===================|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|++++++++++++++++++PACIENTES+++++++++++++++++++|" << endl;
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
    cin >> opcao_paciente;
    return opcao_paciente;
}

int Tela_Profissional()
{
    int opcao_profissional = 0;
    cout << "------------------------------------------------" << endl;
    cout << "|==============================================|" << endl;
    cout << "|==================SIG-CLINIC==================|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|+++++++++++++++++PROFISSIONAL+++++++++++++++++|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|== 0-Voltar                                 ==|" << endl; // volta ao menu principal
    cout << "|== 1-Cadastrar                              ==|" << endl; // cadastra um profissional
    cout << "|== 2-Editar                                 ==|" << endl; // edita as informações de um profissional
    cout << "|== 3-Deletar                                ==|" << endl; // deleta um profissional
    cout << "|== 4-Buscar                                 ==|" << endl; // busca um profissional
    cout << "|== 5-Realizar Consulta                      ==|" << endl; // inicia uma consulta
    cout << "|==============================================|" << endl;
    cout << "------------------------------------------------" << endl;
    cin >> opcao_profissional;
    return opcao_profissional;
}