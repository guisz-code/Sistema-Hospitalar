#include <iostream>  
#include <string>    
#include <cstdlib>   // system("cls") e system("clear")
using namespace std;


// Ficha do medico - guarda os dados de cada medico cadastrado
struct Medico {
    int    id;           
    string nome;         
    string crm;          
    string especialidade;
};

// Ficha do paciente - guarda os dados de cada paciente
struct Paciente {
    int id;      
    string nome;    
    string cpf;     
    string telefone;
};

// Ficha do medicamento - guarda os dados de cada medicamento
struct Medicamento {
    int id;       
    string nome;      
    string fabricante;
};

// Ficha da consulta - relaciona medico, paciente, data e diagnostico
struct Consulta {
    int id;        
    int id_medico; 
    int id_paciente;
    string data;       
    string diagnostico;
};


Medico      medicos[100];      
Paciente    pacientes[100];    
Medicamento medicamentos[100]; 
Consulta    consultas[100];    


int totalMedicos      = 0; // quantos medicos foram cadastrados ate agora
int totalPacientes    = 0; // quantos pacientes foram cadastrados ate agora
int totalMedicamentos = 0; // quantos medicamentos foram cadastrados ate agora
int totalConsultas    = 0; // quantas consultas foram cadastradas ate agora

int proximoIdMedico      = 1; // proximo ID a ser usado para medico
int proximoIdPaciente    = 1; // proximo ID a ser usado para paciente
int proximoIdMedicamento = 1; // proximo ID a ser usado para medicamento
int proximoIdConsulta    = 1; // proximo ID a ser usado para consulta


void linha() {
    cout << "--------------------------------------------"<<endl;
}


// Limpa a tela do terminal para deixar os menus mais organizados.
void limparTela() {
    system("cls");
}

// Pausa o programa e espera o usuario pressionar Enter para continuar
void pausar() {
    cout << "Pressione Enter para continuar..."<< endl;
    cin.get();    // aguarda o usuario pressionar Enter
}

// Verifica se uma string esta vazia (sem nenhum texto digitado)
// Retorna true se tiver texto, false se estiver vazia
bool naoEstaVazio(string texto) {
    if (texto == "") {
        cout << "ERRO: Este campo nao pode ficar vazio!"<<endl;
        return false;
    }
    return true;
}

// Busca o nome de um medico pelo seu ID
// Percorre o array de medicos e retorna o nome quando encontrar
// Retorna uma mensagem de erro se nao encontrar
string nomeMedico(int id) {
    for (int i = 0; i < totalMedicos; i++) {
        if (medicos[i].id == id) {
            return medicos[i].nome;
        }
    }
    return "[Medico nao encontrado]";
}

// Busca o nome de um paciente pelo seu ID
// Funciona igual ao nomeMedico, mas para pacientes
string nomePaciente(int id) {
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i].id == id) {
            return pacientes[i].nome;
        }
    }
    return "[Paciente nao encontrado]";
}




// Cadastra um novo medico no array de medicos
void cadastrarMedico() {
    // Verifica se ainda ha espaco no array
    if (totalMedicos >= 100) {
        cout << "ERRO: Limite de 100 medicos atingido!"<< endl;
        return;
    }

    cout << "=== CADASTRAR MEDICO ==="<< endl;
    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    // Cria uma variavel temporaria para guardar os dados digitados
    Medico m;
    m.id = proximoIdMedico; // atribui o proximo ID disponivel

    cout << "Nome: ";
    getline(cin, m.nome); // getline le a linha inteira, incluindo espacos
    if (!naoEstaVazio(m.nome)) return;

    cout << "CRM (ex: CRM/BA 123456): ";
    getline(cin, m.crm);
    if (!naoEstaVazio(m.crm)) return;

    cout << "Especialidade (ex: Cardiologista): ";
    getline(cin, m.especialidade);
    if (!naoEstaVazio(m.especialidade)) return;

    // Salva o medico na proxima posicao livre do array
    medicos[totalMedicos] = m;
    totalMedicos++;      // incrementa o contador
    proximoIdMedico++;   // incrementa o gerador de ID

    cout << "Medico cadastrado com sucesso! ID: " << m.id << endl;
}

// Lista todos os medicos cadastrados no array
void listarMedicos() {
    cout << "=== LISTA DE MEDICOS ==="<< endl;
    cout << "Total cadastrado: " << totalMedicos << endl;

    // Verifica se o array esta vazio
    if (totalMedicos == 0) {
        cout << "Nenhum medico cadastrado ainda."<< endl;
        return;
    }

    // Percorre o array do inicio ate o total de medicos cadastrados
    for (int i = 0; i < totalMedicos; i++) {
        linha();
        cout << "ID: "            << medicos[i].id            << endl;
        cout << "Nome: "          << medicos[i].nome          << endl;
        cout << "CRM: "           << medicos[i].crm           << endl;
        cout << "Especialidade: " << medicos[i].especialidade << endl;
    }
    linha();
}

// Busca um medico pelo ID e retorna a posicao dele no array
// Retorna -1 se nao encontrar (valor convencional para "nao encontrado")
int buscarMedicoPorId(int id) {
    for (int i = 0; i < totalMedicos; i++) {
        if (medicos[i].id == id) {
            return i; // retorna a posicao no array (indice)
        }
    }
    return -1; // nao encontrou ninguem com esse ID
}

// Edita os dados de um medico ja cadastrado
void editarMedico() {
    cout << "=== EDITAR MEDICO ==="<< endl;
    listarMedicos();

    if (totalMedicos == 0) return; // nada para editar

    int id;
    cout << "Digite o ID do medico que deseja editar: ";
    cin >> id;
    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    // Busca a posicao do medico no array
    int pos = buscarMedicoPorId(id);
    if (pos == -1) {
        cout << "Medico com ID " << id << " nao encontrado!"<< endl;
        return;
    }

    cout << "Editando: " << medicos[pos].nome << endl;
    cout << "(Deixe em branco e pressione Enter para manter o valor atual)"<<endl;

    string novoValor;
    
    // Para cada campo, le um novo valor. Se o usuario nao digitar nada,
    // o campo permanece com o valor antigo.
    cout << "Nome [" << medicos[pos].nome << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") medicos[pos].nome = novoValor;

    cout << "CRM [" << medicos[pos].crm << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") medicos[pos].crm = novoValor;

    cout << "Especialidade [" << medicos[pos].especialidade << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") medicos[pos].especialidade = novoValor;

    cout << "[OK] Medico atualizado com sucesso!"<<endl;
}

// Exclui um medico do array pelo ID
// A exclusao e feita substituindo o medico excluido pelo ultimo do array
void excluirMedico() {
    cout << "=== EXCLUIR MEDICO ==="<< endl;
    listarMedicos();

    if (totalMedicos == 0) return; // nada para excluir

    int id;
    cout << "Digite o ID do medico que deseja excluir: ";
    cin >> id;

    int pos = buscarMedicoPorId(id);
    if (pos == -1) {
        cout << "Medico com ID " << id << " nao encontrado!"<< endl;
        return;
    }

    cout << "Tem certeza que deseja excluir " << medicos[pos].nome << "? (s/n): ";
    char resposta;
    cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
        // Substitui o medico excluido pelo ultimo do array
        // Isso preenche o "buraco" que ficaria no array
        medicos[pos] = medicos[totalMedicos - 1];
        totalMedicos--; // reduz o contador (o ultimo foi movido para o lugar do excluido)
        cout << "[OK] Medico excluido com sucesso!"<< endl;
    } else {
        cout << "Operacao cancelada."<< endl;
    }
}


void cadastrarPaciente() {
    if (totalPacientes >= 100) {
        cout << "ERRO: Limite de 100 pacientes atingido!"<<endl;
        return;
    }

    cout << "=== CADASTRAR PACIENTE ==="<<endl;

    Paciente p;
    p.id = proximoIdPaciente;

    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    cout << "Nome completo: ";
    getline(cin, p.nome);
    if (!naoEstaVazio(p.nome)) return;

    cout << "CPF (ex: 111.222.333-44): ";
    getline(cin, p.cpf);
    if (!naoEstaVazio(p.cpf)) return;

    cout << "Telefone: ";
    getline(cin, p.telefone);
    if (!naoEstaVazio(p.telefone)) return;

    // Salva o paciente no array
    pacientes[totalPacientes] = p;
    totalPacientes++;
    proximoIdPaciente++;

    cout << "[OK] Paciente cadastrado com sucesso! ID: " << p.id << endl;
}

void listarPacientes() {
    cout << "=== LISTA DE PACIENTES ==="<< endl;
    cout << "Total cadastrado: " << totalPacientes << endl;

    if (totalPacientes == 0) {
        cout << "Nenhum paciente cadastrado ainda."<<endl;
        return;
    }

    for (int i = 0; i < totalPacientes; i++) {
        linha();
        cout << "ID: "       << pacientes[i].id       << endl;
        cout << "Nome: "     << pacientes[i].nome     << endl;
        cout << "CPF: "      << pacientes[i].cpf      << endl;
        cout << "Telefone: " << pacientes[i].telefone << endl;
    }
    linha();
}

int buscarPacientePorId(int id) {
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i].id == id) {
            return i;
        }
    }
    return -1;
}

void editarPaciente() {
    cout << "=== EDITAR PACIENTE ==="<<endl;
    listarPacientes();

    if (totalPacientes == 0) return;

    int id;
    cout << "Digite o ID do paciente que deseja editar: ";
    cin >> id;

    int pos = buscarPacientePorId(id);
    if (pos == -1) {
        cout << "Paciente com ID " << id << " nao encontrado!"<<endl;
        return;
    }

    cout << "Editando: " << pacientes[pos].nome << endl;
    cout << "(Deixe em branco e pressione Enter para manter)"<<endl;

    string novoValor;
    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    cout << "Nome [" << pacientes[pos].nome << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") pacientes[pos].nome = novoValor;

    cout << "CPF [" << pacientes[pos].cpf << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") pacientes[pos].cpf = novoValor;

    cout << "Telefone [" << pacientes[pos].telefone << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") pacientes[pos].telefone = novoValor;

    cout << "Paciente atualizado com sucesso!"<<endl;
}

void excluirPaciente() {
    cout << "=== EXCLUIR PACIENTE ==="<<endl;
    listarPacientes();

    if (totalPacientes == 0) return;

    int id;
    cout << "Digite o ID do paciente que deseja excluir: ";
    cin >> id;

    int pos = buscarPacientePorId(id);
    if (pos == -1) {
        cout << "Paciente com ID " << id << " nao encontrado!"<<endl;
        return;
    }

    cout << "Tem certeza que deseja excluir " << pacientes[pos].nome << "? (s/n): ";
    char resposta;
    cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
        // Move o ultimo paciente para a posicao do excluido
        pacientes[pos] = pacientes[totalPacientes - 1];
        totalPacientes--;
        cout << "Paciente excluido com sucesso!"<<endl;
    } else {
        cout << "Operacao cancelada."<<endl;
    }
}


void cadastrarMedicamento() {
    if (totalMedicamentos >= 100) {
        cout << "ERRO: Limite de 100 medicamentos atingido!"<<endl;
        return;
    }

    cout << "=== CADASTRAR MEDICAMENTO ==="<<endl;

    Medicamento med;
    med.id = proximoIdMedicamento;

    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    cout << "Nome do medicamento (ex: Paracetamol): ";
    getline(cin, med.nome);
    if (!naoEstaVazio(med.nome)) return;

    cout << "Fabricante (ex: EMS Pharma): ";
    getline(cin, med.fabricante);
    if (!naoEstaVazio(med.fabricante)) return;

    // Salva o medicamento no array
    medicamentos[totalMedicamentos] = med;
    totalMedicamentos++;
    proximoIdMedicamento++;

    cout << "Medicamento cadastrado com sucesso! ID: " << med.id << endl;
}

void listarMedicamentos() {
    cout << "=== LISTA DE MEDICAMENTOS ==="<<endl;
    cout << "Total cadastrado: " << totalMedicamentos << endl;

    if (totalMedicamentos == 0) {
        cout << "Nenhum medicamento cadastrado ainda."<<endl;
        return;
    }

    for (int i = 0; i < totalMedicamentos; i++) {
        linha();
        cout << "ID: "         << medicamentos[i].id         << endl;
        cout << "Nome: "       << medicamentos[i].nome       << endl;
        cout << "Fabricante: " << medicamentos[i].fabricante << endl;
    }
    linha();
}

int buscarMedicamentoPorId(int id) {
    for (int i = 0; i < totalMedicamentos; i++) {
        if (medicamentos[i].id == id) {
            return i;
        }
    }
    return -1;
}

void editarMedicamento() {
    cout << "=== EDITAR MEDICAMENTO =="<<endl;
    listarMedicamentos();

    if (totalMedicamentos == 0) return;

    int id;
    cout << "Digite o ID do medicamento que deseja editar: ";
    cin >> id;

    int pos = buscarMedicamentoPorId(id);
    if (pos == -1) {
        cout << "Medicamento com ID " << id << " nao encontrado!"<<endl;
        return;
    }

    cout << "Editando: " << medicamentos[pos].nome << endl;
    cout << "(Deixe em branco e pressione Enter para manter)"<<endl;

    string novoValor;
    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    cout << "Nome [" << medicamentos[pos].nome << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") medicamentos[pos].nome = novoValor;

    cout << "Fabricante [" << medicamentos[pos].fabricante << "]: ";
    getline(cin, novoValor);
    if (novoValor != "") medicamentos[pos].fabricante = novoValor;

    cout << "Medicamento atualizado com sucesso!"<<endl;
}

void excluirMedicamento() {
    cout << "=== EXCLUIR MEDICAMENTO ==="<<endl;
    listarMedicamentos();

    if (totalMedicamentos == 0) return;

    int id;
    cout << "Digite o ID do medicamento que deseja excluir: ";
    cin >> id;

    int pos = buscarMedicamentoPorId(id);
    if (pos == -1) {
        cout << "Medicamento com ID " << id << " nao encontrado!"<<endl;
        return;
    }

    cout << "Tem certeza que deseja excluir " << medicamentos[pos].nome << "? (s/n): ";
    char resposta;
    cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
        // Move o ultimo medicamento para o lugar do excluido
        medicamentos[pos] = medicamentos[totalMedicamentos - 1];
        totalMedicamentos--;
        cout << "Medicamento excluido com sucesso!";
    } else {
        cout << "Operacao cancelada."<<endl;
    }
}



void cadastrarConsulta() {
    if (totalConsultas >= 100) {
        cout << "ERRO: Limite de 100 consultas atingido!"<<endl;
        return;
    }

    // Verifica se existem medicos e pacientes cadastrados
    if (totalMedicos == 0) {
        cout << "ERRO: Cadastre ao menos um medico antes de registrar uma consulta!\n";
        return;
    }
    if (totalPacientes == 0) {
        cout << "ERRO: Cadastre ao menos um paciente antes de registrar uma consulta!\n";
        return;
    }

    cout << "=== REGISTRAR CONSULTA ==="<<endl;

    Consulta c;
    c.id = proximoIdConsulta;

    // Exibe os medicos disponiveis para facilitar a escolha
    listarMedicos();
    cout << "Digite o ID do medico responsavel: ";
    cin >> c.id_medico;

    // Verifica se o ID do medico digitado existe no array
    if (buscarMedicoPorId(c.id_medico) == -1) {
        cout << "ERRO: Medico com ID " << c.id_medico << " nao encontrado!"<<endl;
        return;
    }

    // Exibe os pacientes disponiveis para facilitar a escolha
    listarPacientes();
    cout << "Digite o ID do paciente: ";
    cin >> c.id_paciente;

    // Verifica se o ID do paciente digitado existe no array
    if (buscarPacientePorId(c.id_paciente) == -1) {
        cout << "ERRO: Paciente com ID " << c.id_paciente << " nao encontrado!"<<endl;
        return;
    }

    // Limpa o buffer de entrada removendo o Enter pendente,
// evitando que o getline() leia uma linha vazia.
    cin.ignore();

    cout << "Data da consulta (ex: 28/03/2024): ";
    getline(cin, c.data);
    if (!naoEstaVazio(c.data)) return;

    cout << "Diagnostico: ";
    getline(cin, c.diagnostico);
    if (!naoEstaVazio(c.diagnostico)) return;

    // Salva a consulta no array
    consultas[totalConsultas] = c;
    totalConsultas++;
    proximoIdConsulta++;

    cout << "Consulta registrada com sucesso! ID: " << c.id << endl;
    cout << "Medico:   " << nomeMedico(c.id_medico)   << endl;
    cout << "Paciente: " << nomePaciente(c.id_paciente) << endl;
}

void listarConsultas() {
    cout << "=== LISTA DE CONSULTAS ==="<< endl;
    cout << "Total registrado: " << totalConsultas << endl;

    if (totalConsultas == 0) {
        cout << "Nenhuma consulta registrada ainda."<< endl;
        return;
    }

    // Percorre o array e exibe cada consulta
    // As funcoes nomeMedico e nomePaciente buscam o nome a partir do ID
    for (int i = 0; i < totalConsultas; i++) {
        linha();
        cout << "ID Consulta: " << consultas[i].id          << endl;
        cout << "Medico:      " << nomeMedico(consultas[i].id_medico)
             << " (ID: "        << consultas[i].id_medico   << ")"<<endl;
        cout << "Paciente:    " << nomePaciente(consultas[i].id_paciente)
             << " (ID: "        << consultas[i].id_paciente << ")"<<endl;
        cout << "Data:        " << consultas[i].data        << endl;
        cout << "Diagnostico: " << consultas[i].diagnostico << endl;
    }
    linha();
}

int buscarConsultaPorId(int id) {
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Exibe os detalhes de uma unica consulta buscada pelo ID
void buscarConsulta() {
    cout << "=== BUSCAR CONSULTA POR ID ==="<<endl;

    if (totalConsultas == 0) {
        cout << "Nenhuma consulta registrada ainda."<<endl;
        return;
    }

    int id;
    cout << "Digite o ID da consulta: ";
    cin >> id;

    int pos = buscarConsultaPorId(id);
    if (pos == -1) {
        cout << "Consulta com ID " << id << " nao encontrada!"<<endl;
        return;
    }

    linha();
    cout << "ID Consulta: " << consultas[pos].id          << endl;
    cout << "Medico:      " << nomeMedico(consultas[pos].id_medico)
         << " (ID: "        << consultas[pos].id_medico   << ")"<<endl;
    cout << "Paciente:    " << nomePaciente(consultas[pos].id_paciente)
         << " (ID: "        << consultas[pos].id_paciente << ")"<<endl;
    cout << "Data:        " << consultas[pos].data        << endl;
    cout << "Diagnostico: " << consultas[pos].diagnostico << endl;
    linha();
}

void excluirConsulta() {
    cout << "=== EXCLUIR CONSULTA ==="<<endl;
    listarConsultas();

    if (totalConsultas == 0) return;

    int id;
    cout << "Digite o ID da consulta que deseja excluir: ";
    cin >> id;

    int pos = buscarConsultaPorId(id);
    if (pos == -1) {
        cout << "Consulta com ID " << id << " nao encontrada!"<<endl;
        return;
    }

    cout << "Tem certeza que deseja excluir esta consulta? (s/n): ";
    char resposta;
    cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
        // Move a ultima consulta para o lugar da excluida
        consultas[pos] = consultas[totalConsultas - 1];
        totalConsultas--;
        cout << "Consulta excluida com sucesso!"<<endl;
    } else {
        cout << "Operacao cancelada."<<endl;
    }
}


// Submenu de opcoes para gerenciar medicos
void menuMedico() {
    limparTela();
    int opcao;

    do {
        cout << "===== MENU MEDICO ====="<<endl;
        cout << "1. Cadastrar medico"<<endl;
        cout << "2. Listar medicos"<<endl;
        cout << "3. Editar medico"<<endl;
        cout << "4. Excluir medico"<<endl;
        cout << "0. Voltar ao menu principal"<<endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarMedico(); pausar(); break;
            case 2: listarMedicos();   pausar(); break;
            case 3: editarMedico();    pausar(); break;
            case 4: excluirMedico();   pausar(); break;
            case 0: break; // sai do loop e volta ao menu principal
            default: cout << "Opcao invalida! Tente novamente."<<endl;
        }
    } while (opcao != 0);
}

// Submenu de opcoes para gerenciar pacientes
void menuPaciente() {
    limparTela();
    int opcao;

    do {
        cout << "===== MENU PACIENTE ====="<<endl;
        cout << "1. Cadastrar paciente"<<endl;
        cout << "2. Listar pacientes"<<endl;
        cout << "3. Editar paciente"<<endl;
        cout << "4. Excluir paciente"<<endl;
        cout << "0. Voltar ao menu principal"<<endl;
        cout << "Opcao: "<< endl;
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarPaciente(); pausar(); break;
            case 2: listarPacientes();   pausar(); break;
            case 3: editarPaciente();    pausar(); break;
            case 4: excluirPaciente();   pausar(); break;
            case 0: break;
            default: cout << "Opcao invalida! Tente novamente."<<endl;
        }
    } while (opcao != 0);
}

// Submenu de opcoes para gerenciar medicamentos
void menuMedicamento() {
    limparTela();
    int opcao;

    do {
        cout << "===== MENU MEDICAMENTO ====="<<endl;
        cout << "1. Cadastrar medicamento"<<endl;
        cout << "2. Listar medicamentos"<<endl;
        cout << "3. Editar medicamento"<<endl;
        cout << "4. Excluir medicamento"<<endl;
        cout << "0. Voltar ao menu principal"<<endl;
        cout << "Opcao: "<<endl;
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarMedicamento(); pausar(); break;
            case 2: listarMedicamentos();   pausar(); break;
            case 3: editarMedicamento();    pausar(); break;
            case 4: excluirMedicamento();   pausar(); break;
            case 0: break;
            default: cout << "Opcao invalida! Tente novamente."<<endl;
        }
    } while (opcao != 0);
}

// Submenu de opcoes para gerenciar consultas
void menuConsulta() {
    limparTela();
    int opcao;

    do {
        cout << "===== MENU CONSULTA ====="<<endl;
        cout << "1. Registrar consulta"<<endl;
        cout << "2. Listar consultas"<< endl;
        cout << "3. Buscar consulta por ID"<< endl;
        cout << "4. Excluir consulta"<< endl;
        cout << "0. Voltar ao menu principal"<< endl;
        cout << "Opcao: "<<endl;
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarConsulta(); pausar(); break;
            case 2: listarConsultas();   pausar(); break;
            case 3: buscarConsulta();    pausar(); break;
            case 4: excluirConsulta();   pausar(); break;
            case 0: break;
            default: cout << "Opcao invalida! Tente novamente."<< endl;
        }
    } while (opcao != 0);
}


int main() {

  
    cout << "============================================"<<endl;
    cout << "        SISTEMAS HOSPITALAR"<<endl;
    cout << "============================================"<<endl;

    int opcao;

    // Loop principal do programa
    // O programa fica rodando ate o usuario escolher a opcao 0 (Sair)
    do {
        limparTela();
        
        cout << "============================================"<<endl;
        cout << "        SISTEMAS HOSPITALAR"<<endl;
        cout << "============================================"<<endl;

        cout << "========== MENU PRINCIPAL =========="<<endl;
        cout << "1. Medicos"<<endl;
        cout << "2. Pacientes"<<endl;
        cout << "3. Medicamentos"<<endl;
        cout << "4. Consultas"<<endl;
        cout << "0. Sair do sistema"<<endl;
        cout << "====================================="<<endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: menuMedico();      break;
            case 2: menuPaciente();    break;
            case 3: menuMedicamento(); break;
            case 4: menuConsulta();    break;
            case 0: cout << "'Encerrando o sistema. Ate logo!"<<endl; break;
            default: cout << "Opcao invalida! Digite um numero entre 0 e 4."<<endl;
        }

    } while (opcao != 0);

    return 0; 
}