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
    string cpf;
    int nascimento[3];
    char genero;
    bool status;
    char convenio;    

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
    void setId(unsigned int novoId)       { id = novoId; }
    void setNome(string novoNome)         { nome = novoNome; }
    void setEndereco(string novoEndereco) { endereco = novoEndereco; }
    void setTelefone(string novoTelefone) { telefone = novoTelefone; }
    void setEmail(string novoEmail)       { email = novoEmail; }
    void setCpf(string novoCpf)           { cpf = novoCpf; }
    void setGenero(char novoGenero)       { genero = novoGenero; }
    void setStatus(bool novoStatus)       { status = novoStatus; }
    void setConvenio(char novoConvenio)   { convenio = novoConvenio; }
    // get
    int *getNascimento()                  { return nascimento; }
    unsigned int getId()                  { return id; }
    string getNome()                      { return nome; }
    string getEndereco()                  { return endereco; }
    string getTelefone()                  { return telefone; }
    string getEmail()                     { return email; }
    string getCpf()                       { return cpf;}
    char getGenero()                      { return genero; }
    bool getStatus()                      { return status; }
    char getConvenio()                    { return convenio;}
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
        cout << "CPF: " << cpf << endl;
        cout << "Convenio: " << convenio << endl;
    }
};

void CorrigirUltimoCaractere(ifstream& arquivo)
{
    arquivo.seekg(-1, ios_base::end); // Move o cursor de leitura para o último caractere
    char ultimoCaractere;
    arquivo.get(ultimoCaractere); // Lê o último caractere

    if (ultimoCaractere == ']')
    {
        ofstream arquivoEscrita("pacientes.json", ios_base::in | ios_base::out);
        if (arquivoEscrita.is_open())
        {
            arquivoEscrita.seekp(-1, ios_base::end); // Move o cursor de escrita para o último caractere
            arquivoEscrita << ","; // Substitui o colchete por uma vírgula
            arquivoEscrita.close();
        }
        else
        {
            cerr << "Erro ao abrir o arquivo para escrita." << endl;
        }
    }
}


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
    pacienteJson["CPF"] = paciente.getCpf();
    pacienteJson["convenio"] = string(1, paciente.getConvenio());

    ifstream Correcao_do_arquivo("pacientes.json");
    ofstream arquivo("pacientes.json", ios_base::app);
    if (arquivo.is_open()) {
        if (arquivo.tellp() == 0) { // Se o arquivo estiver vazio, adiciona um '[' no início
            arquivo << "[";
        } else {
            //
            CorrigirUltimoCaractere(Correcao_do_arquivo); // Verifica e corrige o último caractere do arquivo
            //arquivo << ","; // Adiciona vírgula entre os objetos, exceto no primeiro
        }
        arquivo << pacienteJson.dump(4); // Escreve o objeto JSON no arquivo
        arquivo.close();
        arquivo.open("pacientes.json", ios_base::app);
        arquivo << "]"; // Fecha o array JSON
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
        Buscar_Paciente();
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
    string cpfPaciente;
    char convenioPaciente;
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
    cout << "|== CPF (SOMENTE NÚMEROS)                    ==|" << endl;
    cin >> cpfPaciente;
    NovoPaciente.setCpf(cpfPaciente);
    //----------------------------------------------------------------//
    cout << "|== CONVÊNIO ( S ou N)" << endl;
    cin >> convenioPaciente;
    NovoPaciente.setConvenio(convenioPaciente);
    //----------------------------------------------------------------//
    NovoPaciente.setId(nextId);   // Atribui o ID atual ao paciente
    NovoPaciente.setStatus(true); // Define o status do paciente como ativo
    NovoPaciente.ExibirDadosCadastrados(); // exibe os dados cadastrados
    SalvarPacienteJson(NovoPaciente); // Salva todos os dados em arquivo JSON
    nextId++; // Incrementa o ID para o próximo paciente
    //----------------------------------------------------------------//
}

void Buscar_Paciente() 
{
    string cpfBusca;
    cout << "CPF do Paciente: " << endl;
    cin >> cpfBusca;
    ifstream arquivo("pacientes.json");
    if (arquivo.is_open()) {
        json pacientes;
        arquivo >> pacientes;

        for (const auto& paciente : pacientes) {
            string cpf = paciente["CPF"];
            if (cpf == cpfBusca) {
                // CPF encontrado, exibir os dados do paciente
                cout << "Paciente encontrado:" << endl;
                cout << "ID: " << paciente["id"] << endl;
                cout << "Nome: " << paciente["nome"] << endl;
                cout << "Data de nascimento: " << paciente["nascimento"][0] << "/" << paciente["nascimento"][1] << "/" << paciente["nascimento"][2] << endl;
                cout << "Sexo: " << paciente["genero"] << endl;
                cout << "Telefone: " << paciente["telefone"] << endl;
                cout << "Endereço: " << paciente["endereco"] << endl;
                cout << "E-mail: " << paciente["email"] << endl;
                cout << "CPF: " << paciente["CPF"] << endl;
                cout << "Convenio: " << paciente["convenio"] << endl;
                return; // Encerra a busca após encontrar o paciente
            }
        }
        cout << "Paciente não encontrado." << endl;
    } else {
        cerr << "Erro ao abrir o arquivo de pacientes." << endl;
    }
}