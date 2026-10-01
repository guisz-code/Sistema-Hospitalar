# 🏥 Sistema Hospitalar

Sistema de gerenciamento hospitalar desenvolvido em **C++** como parte de um trabalho acadêmico realizado no primeiro semestre de 2026 (2026.1).

O projeto foi desenvolvido com o objetivo de aplicar na prática conceitos fundamentais de programação, estruturas de dados, funções, condicionais, estruturas de repetição e organização de informações.

## 📌 Sobre o projeto

O sistema funciona através de um menu no terminal e permite realizar o gerenciamento de diferentes informações de um ambiente hospitalar.

É possível cadastrar, consultar, editar e excluir **médicos, pacientes e medicamentos**, além de registrar e consultar **consultas médicas**.

## ⚙️ Funcionalidades

### 👨‍⚕️ Médicos

* Cadastrar médico
* Listar médicos
* Editar dados
* Excluir médico
* Identificação por ID
* Cadastro de CRM e especialidade

### 🧑‍⚕️ Pacientes

* Cadastrar paciente
* Listar pacientes
* Editar dados
* Excluir paciente
* Identificação por ID
* Cadastro de CPF e telefone

### 💊 Medicamentos

* Cadastrar medicamento
* Listar medicamentos
* Editar dados
* Excluir medicamento
* Identificação por ID
* Cadastro do fabricante

### 📋 Consultas

* Registrar consultas
* Listar consultas
* Buscar consulta por ID
* Excluir consultas
* Associar médico e paciente
* Registrar data e diagnóstico

## 🛠️ Tecnologias utilizadas

* **C++**
* Biblioteca `iostream`
* Biblioteca `string`
* Estruturas (`struct`)
* Arrays
* Funções
* Estruturas condicionais
* Estruturas de repetição
* Menu interativo no terminal

## 📚 Conceitos aplicados

Durante o desenvolvimento foram utilizados conceitos fundamentais da linguagem C++, como:

* Declaração e utilização de variáveis
* Tipos de dados
* `struct`
* Arrays
* Funções
* Parâmetros e retorno de funções
* `if/else`
* `switch/case`
* Loops `for` e `do while`
* Busca de registros por ID
* Validação de campos
* Organização do código em diferentes funções

Os dados de médicos, pacientes, medicamentos e consultas são organizados em estruturas próprias e armazenados em arrays com capacidade de até 100 registros para cada categoria.

## 🖥️ Funcionamento

Ao iniciar o programa, o usuário encontra um menu principal com acesso aos módulos do sistema:

```text
============================================
        SISTEMAS HOSPITALAR
============================================

========== MENU PRINCIPAL ==========
1. Médicos
2. Pacientes
3. Medicamentos
4. Consultas
0. Sair do sistema
=====================================
```

Cada módulo possui suas próprias opções de gerenciamento, permitindo navegar pelo sistema diretamente pelo terminal.

## 🎓 Contexto acadêmico

Este projeto foi desenvolvido em **2026.1** para uma atividade acadêmica, tendo também como objetivo a apresentação do sistema e a demonstração dos conceitos de programação utilizados durante seu desenvolvimento.

O projeto representa uma aplicação prática dos conteúdos estudados no início da graduação, utilizando uma situação fictícia de gerenciamento hospitalar para exercitar a construção de um sistema completo em C++.

## 🚀 Como executar

### Pré-requisitos

É necessário possuir um compilador C++ instalado, como:

* MinGW / GCC
* Visual Studio
* Code::Blocks
* Dev-C++

### Compilação pelo terminal

```bash
g++ sistema_hospitalar.cpp -o sistema_hospitalar
```

Depois, execute:

```bash
./sistema_hospitalar
```

No Windows, também pode ser executado como:

```bash
sistema_hospitalar.exe
```

## ⚠️ Observações

Este é um **projeto acadêmico** desenvolvido para fins de estudo. Os dados são armazenados apenas durante a execução do programa, pois o sistema utiliza estruturas em memória e não possui banco de dados ou persistência de informações.

O sistema também possui limites definidos de até **100 médicos, 100 pacientes, 100 medicamentos e 100 consultas**.

---

**Projeto desenvolvido em C++ — 2026.1**
