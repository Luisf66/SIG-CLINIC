#include <iostream>
using namespace std;

void Tela_Principal();

int main()
{
    Tela_Principal();
    return 0;
}

void Tela_Principal()
{
    int opcao_principal = 0;
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
        switch (opcao_principal)
        {
        case 0:
            cout << "Encerrando aplicação" << endl;
            break;
        case 1:
            cout << "Abrindo módulo Paciente" << endl;
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
    } while (opcao_principal != 0);
}