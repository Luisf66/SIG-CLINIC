#include <iostream>
#include <string>
#include "Paciente.hpp"
#include "cstdlib"
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class Paciente
{
private:
    unsigned int id;
    string nome;
    string endereco;
    string telefone;
    string email;
    int nascimento[3];
    char genero;
    bool status;

public:
    Paciente()
    {
        id = 1;
        status = false;
    }
    // set
    void setNascimento(int dia, int mes, int ano)
    {
        nascimento[0] = dia;
        nascimento[1] = mes;
        nascimento[2] = ano;
    }
    void setNome(string novoNome)         { nome = novoNome; }
    void setGenero(char novoGenero)       { genero = novoGenero; }
    void setTelefone(string novoTelefone) { telefone = novoTelefone; }
    void setEndereco(string novoEndereco) { endereco = novoEndereco; }
    void setEmail(string novoEmail)       { email = novoEmail; }
    void setId(unsigned int novoId)       { id = novoId; }
    void setStatus(bool novoStatus)       { status = novoStatus; }
    // get
    int *getNascimento()                  { return nascimento; }
    unsigned int getId()                  { return id; }
    bool getStatus()                      { return status; }
    string getNome()                      { return nome; }
    char getGenero()                      { return genero; }
    string getTelefone()                  { return telefone; }
    string getEndereco()                  { return endereco; }
    string getEmail()                     { return email; }
    //
    void ExibirDadosCadastrados()
    {
        cout << "|==============================================|" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "ID: " << id << endl;
        cout << "Paciente: " << nome << endl;
        cout << "Data de nascimento: " << nascimento[0] << "/" << nascimento[1] << "/" << nascimento[2] << endl;
        cout << "Sexo: " << genero << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Endereço: " << endereco << endl;
        cout << "E-mail: " << email << endl;
    }
};

void SalvarPacienteJson(Paciente& paciente)
{
    json pacienteJson;
    pacienteJson["id"] = paciente.getId();
    pacienteJson["nome"] = paciente.getNome();
    pacienteJson["nascimento"] = {paciente.getNascimento()[0], paciente.getNascimento()[1], paciente.getNascimento()[2]};
    pacienteJson["genero"] = string(1, paciente.getGenero()); // Converte o char para uma string
    pacienteJson["telefone"] = paciente.getTelefone();
    pacienteJson["endereco"] = paciente.getEndereco();
    pacienteJson["email"] = paciente.getEmail();
    pacienteJson["status"] = paciente.getStatus();

    ofstream arquivo("pacientes.json", ios_base::app);
    if (arquivo.is_open()) {
        if (arquivo.tellp() != 0) { // Verifica se o arquivo não está vazio
            arquivo << ","; // Adiciona vírgula entre os objetos
        }
        arquivo << pacienteJson.dump(4); // Escreve o objeto JSON no arquivo
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }
}

void Tela_Paciente()
{
    system("clear");
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
    static unsigned int nextId = 1;
    Paciente NovoPaciente;
    string nomePaciente;
    int dia, mes, ano;
    char generoPaciente;
    string telefonePaciente;
    string enderecoPaciente;
    string emailPaciente;
    system("clear");
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
    NovoPaciente.setNome(nomePaciente);
    //----------------------------------------------------------------//
    cout << "|== NASCIMENTO DIA                           ==|" << endl;
    cin >> dia;
    cout << "|== NASCIMENTO MÊS                           ==|" << endl;
    cin >> mes;
    cout << "|== NASCIMENTO ANO                           ==|" << endl;
    cin >> ano;
    NovoPaciente.setNascimento(dia, mes, ano);
    // int *dataNascimento = NovoPaciente.getNascimento();
    cin.ignore();
    //----------------------------------------------------------------//
    cout << "|== SEXO (F ou M)                            ==|" << endl;
    cin >> generoPaciente;
    NovoPaciente.setGenero(generoPaciente);
    cin.ignore();
    //----------------------------------------------------------------//
    cout << "|== TELEFONE ( xx xxxxx-xxxx)                ==|" << endl;
    getline(cin, telefonePaciente);
    NovoPaciente.setTelefone(telefonePaciente);
    //----------------------------------------------------------------//
    cout << "|== ENDEREÇO                                 ==|" << endl;
    getline(cin, enderecoPaciente);
    NovoPaciente.setEndereco(enderecoPaciente);
    //----------------------------------------------------------------//
    cout << "|== E-MAIL                                   ==|" << endl;
    getline(cin, emailPaciente);
    NovoPaciente.setEmail(emailPaciente);
    //----------------------------------------------------------------//
    NovoPaciente.setId(nextId);   // Atribui o ID atual ao paciente
    NovoPaciente.setStatus(true); // Define o status do paciente como ativo
    NovoPaciente.ExibirDadosCadastrados(); // exibe os dados cadastrados
    SalvarPacienteJson(NovoPaciente); // Salva todos os dados em arquivo JSON
    nextId++; // Incrementa o ID para o próximo paciente
    //----------------------------------------------------------------//
}
