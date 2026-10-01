# 🏥 Sistema Hospitalar

Projeto acadêmico desenvolvido em **C++ no semestre 2026.1**, com o objetivo de aplicar conceitos fundamentais de programação na criação de um sistema de gerenciamento hospitalar.

O projeto possui duas partes independentes:

* **Backend:** sistema principal desenvolvido em C++ e executado pelo terminal.
* **Front-End:** interface web independente, desenvolvida com HTML, CSS e JavaScript, criada como uma representação visual das funcionalidades presentes no sistema em C++.

> **Importante:** o Front-End e o sistema em C++ não possuem integração entre si. São implementações independentes das mesmas funcionalidades.

## 📁 Estrutura do projeto

```text
Sistema-Hospitalar/
│
├── frontEnd/
│   ├── css/style.css
│   ├── js/script.js
│   └── shWeb.html
│
├── backend/
│   └── sistemaHospitalar.cpp
│
├── exe/
│   └── sistemaHospitalar.exe
│
└── README.md
```

## 💻 Sistema em C++

O sistema principal foi desenvolvido em **C++** como parte de um trabalho acadêmico.

A aplicação funciona diretamente pelo terminal e permite gerenciar:

* Médicos
* Pacientes
* Medicamentos
* Consultas

Entre as funcionalidades estão:

* Cadastro de registros
* Listagem
* Edição
* Exclusão
* Busca de consultas por ID
* Associação entre médicos e pacientes em consultas

O sistema utiliza conceitos como `struct`, arrays, funções, estruturas condicionais, estruturas de repetição e busca de registros por ID.

### 📂 Backend

O código-fonte está localizado em:

```text
backend/sistemaHospitalar.cpp
```

### ▶️ Executável

Também está disponível uma versão compilada do sistema:

```text
exe/sistemaHospitalar.exe
```

O executável pode ser aberto diretamente, sem a necessidade de abrir o projeto no Visual Studio ou Visual Studio Code.

## 🌐 Front-End

A pasta `frontEnd/` contém uma interface web criada com:

* HTML
* CSS
* JavaScript

A interface possui funcionalidades equivalentes às apresentadas no sistema em C++, servindo como uma representação visual do projeto.

```text
frontEnd/
├── css/style.css
├── js/script.js
└── shWeb.html
```

O Front-End é **independente do sistema C++** e não realiza comunicação com o arquivo `sistema_hospitalar.cpp`.

## 🎓 Contexto acadêmico

Este projeto foi desenvolvido durante o semestre **2026.1** para uma atividade acadêmica, incluindo a apresentação do sistema e a demonstração dos conceitos de programação utilizados durante seu desenvolvimento.

O objetivo principal foi colocar em prática os conhecimentos adquiridos em C++, utilizando um cenário de gerenciamento hospitalar como exemplo de aplicação.

## 🛠️ Tecnologias

### Sistema principal

* C++
* `iostream`
* `string`
* `struct`
* Arrays
* Funções

### Interface

* HTML
* CSS
* JavaScript

## ⚠️ Observação

Este projeto possui finalidade **acadêmica e educacional**. O sistema em C++ utiliza armazenamento em memória e não possui banco de dados ou integração com o Front-End.
