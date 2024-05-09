#include <iostream>
using namespace std;
#include "Paciente.h"

class Paciente
{
private:
    string nome;
    string endereco;
    string telefone;
    string email;
    int nascimento[3];
    char genero;

public:
    //set
    void setNome(string novoNome)
    {
        nome = novoNome;
    }
    void setNascimento(int dia, int mes, int ano)
    {
        nascimento[0] = dia;
        nascimento[1] = mes;
        nascimento[2] = ano;
    }
    void setGenero(char novoGenero)
    {
        genero = novoGenero;
    }
    //get
    int *getNascimento()
    {
        return nascimento;
    }
};

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
        Cadastrar_Paciente();
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

void Cadastrar_Paciente()
{
    Paciente novoPaciente;
    string nomePaciente;
    int dia, mes, ano;
    char genero;
    //----------------------------------------------------------------//
    cout << "------------------------------------------------" << endl;
    cout << "|==============================================|" << endl;
    cout << "|================= SIG-CLINIC =================|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|++++++++ PREENCHA A FICHA DO PACIENTE ++++++++|" << endl;
    cout << "|==============================================|" << endl;
    cout << "|== NOME                                     ==|" << endl;
    //----------------------------------------------------------------//
    cin.ignore();
    getline(cin, nomePaciente);
    novoPaciente.setNome(nomePaciente);
    //----------------------------------------------------------------//
    cout << "|== NASCIMENTO DIA                           ==|" << endl;
    cin >> dia;
    cout << "|== NASCIMENTO MÊS                           ==|" << endl;
    cin >> mes;
    cout << "|== NASCIMENTO ANO                           ==|" << endl;
    cin >> ano;
    novoPaciente.setNascimento(dia, mes, ano);
    int *dataNascimento = novoPaciente.getNascimento();
    //----------------------------------------------------------------//
    cout << "|== SEXO (F ou M)                            ==|" << endl;
    cin >> genero;
    novoPaciente.setGenero(genero);
    cout << "|== TELEFONE ( xx xxxxx-xxxx)                ==|" << endl;
    cout << "|== ENDEREÇO                                 ==|" << endl;
    cout << "|== E-MAIL                                   ==|" << endl;
    cout << "|==============================================|" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Paciente: " << nomePaciente << endl;
    cout << "Data de nascimento: " << dataNascimento[0] << "/" << dataNascimento[1] << "/" << dataNascimento[2] << endl;
    cout << "SEXO: " << genero << endl;
}