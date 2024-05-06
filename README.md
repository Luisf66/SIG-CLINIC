# SIG-CLINIC
Repositório voltado para a criação do projeto SIG-CLINIC na linguagem de programação C++, o presente projeto propõe um sistema capaz de auxiliar no agendamento de consultas dos pacientes, gerenciando profissionais vinculados à clínica, horários e pagamentos de consultas, convênios e exibindo relatórios de atendimento.

## Modelo Conceitual

### Diagrama de Classes usando Mermaid

```mermaid
classDiagram    
    Usuário <|-- Paciente
    Usuário <|-- Profissional
    Profissional "" -- "" Agendamento
    Paciente "" -- "" Pagamento
    Paciente "" -- "" Consulta
    Profissional "" -- "" Consulta
    Profissional "" -- "" Horário
    class Usuário {
        -string Nome
        -date Nascimento
        -char Gênero
        -string Endereço
        -int Telefone
        -string E-mail

    }
    class Paciente {
        -int id_paciente
        -string Histórico 
        -string Convênio 
        -string Consultas 
        -string Pagamentos

    }
    class Profissional {
        -int id_profissional
        -string Especialidade 
        -string Registro
        -string Horários
    }
    class Agendamento {
        -int id_agendamento
        -date Data
        -int Hora
        -string Paciente_Nome
        -string Profissional_Nome
        -string status
    }
    class Consulta {
        -int id_consulta
        -date Data_retorno
        -int Hora_Retorno
        -string Paciente_Nome
        -string Profissional_Nome
        -string status
        -string Diagnostico
    }
    class Pagamento {
        -int id
        -double Valor
        -date Data
        -string Método
        -int id_consulta
        -string status
    }
    class Horário {
        -string Horário
        -string Disponibilidade
    }
```
### Descrição das Entidades

Descrição sucinta das entidades presentes no sistema.

| Entidade | Descrição |
|----------|-----------|
| Usuário  | A entidade usuário será responsável por representar o papel de usuário no sistema, tendo os atributos... e os métodos... |
| Paciente | O paciente representará o paciente da clínica e herda os atributos e métodos da classe Usuário... |
| Profissional | O profissional representará o profissional da clínica e herda os atributos e métodos da classe Usuário... |
| Agendamento | No agendamento um profissional capacitado irá agendar uma consulta no horário disponível e requisitado pelo paciente, seus atributos e métodos são... |
| Consulta | Na consulta o profissional preencherá todas as informações cabiveis a cerca do paciente, realizará a consulta, dará um diagnostico e marcará o retorno, seus atributos e métodos são... | 
| Pagamento | No pagamento o paciente irá escolher um método de pagamento e irá pagar pela consulta requisitada, seus atributos e métodos são... |
| Horário | Os horários serão informados pelos profissionais para facilitar o agendamento de consultas, seus atributos e métodos são... |