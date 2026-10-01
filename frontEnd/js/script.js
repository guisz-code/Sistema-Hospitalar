// Estruturas de dados (arrays)
        let medicos = [];
        let pacientes = [];
        let medicamentos = [];
        let consultas = [];

        // Contadores de ID
        let proximoIdMedico = 1;
        let proximoIdPaciente = 1;
        let proximoIdMedicamento = 1;
        let proximoIdConsulta = 1;

        function atualizarStats() {
            document.getElementById('statMedicos').textContent = medicos.length;
            document.getElementById('statPacientes').textContent = pacientes.length;
            document.getElementById('statMedicamentos').textContent = medicamentos.length;
            document.getElementById('statConsultas').textContent = consultas.length;
        }

        function showMessage(panel, msg, type) {
            const container = document.getElementById(panel + 'Content');
            const msgDiv = document.createElement('div');
            msgDiv.className = `message ${type}`;
            msgDiv.textContent = msg;
            container.insertBefore(msgDiv, container.firstChild);
            setTimeout(() => msgDiv.remove(), 3000);
        }

        function showMainMenu() {
            document.querySelectorAll('.content-panel').forEach(p => p.classList.remove('active'));
            document.getElementById('mainMenu').style.display = 'grid';
        }

        function showPanel(panel) {
            document.getElementById('mainMenu').style.display = 'none';
            document.querySelectorAll('.content-panel').forEach(p => p.classList.remove('active'));
            document.getElementById(panel + 'Panel').classList.add('active');
        }

        // ========== MÉDICOS ==========
        function showMedicoForm() {
            const container = document.getElementById('medicoContent');
            container.innerHTML = `
                <form onsubmit="cadastrarMedico(event)">
                    <div class="form-group"><label>Nome:</label><input type="text" id="medicoNome" required></div>
                    <div class="form-group"><label>CRM:</label><input type="text" id="medicoCRM" required></div>
                    <div class="form-group"><label>Especialidade:</label><input type="text" id="medicoEspecialidade" required></div>
                    <button type="submit">Cadastrar Médico</button>
                </form>
            `;
        }

        function cadastrarMedico(event) {
            event.preventDefault();
            const nome = document.getElementById('medicoNome').value;
            const crm = document.getElementById('medicoCRM').value;
            const especialidade = document.getElementById('medicoEspecialidade').value;
            
            medicos.push({ id: proximoIdMedico++, nome, crm, especialidade });
            atualizarStats();
            showMessage('medico', '✅ Médico cadastrado com sucesso!', 'success');
            showMedicoForm();
        }

        function listarMedicos() {
            const container = document.getElementById('medicoContent');
            if (medicos.length === 0) {
                container.innerHTML = '<p>Nenhum médico cadastrado.</p>';
                return;
            }
            let html = '<div class="table-container"><table><tr><th>ID</th><th>Nome</th><th>CRM</th><th>Especialidade</th></tr>';
            medicos.forEach(m => {
                html += `<tr><td>${m.id}</td><td>${m.nome}</td><td>${m.crm}</td><td>${m.especialidade}</td></tr>`;
            });
            html += '</table></div>';
            container.innerHTML = html;
        }

        function showEditarMedico() {
            const container = document.getElementById('medicoContent');
            if (medicos.length === 0) {
                container.innerHTML = '<p>Nenhum médico cadastrado para editar.</p>';
                return;
            }
            let html = '<div class="search-box"><input type="text" id="buscaMedicoEdit" placeholder="Buscar médico por nome ou ID..." onkeyup="filtrarMedicosEdit()"></div>';
            html += '<div id="listaMedicosEdit">';
            medicos.forEach(m => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>${m.id} - ${m.nome}</strong> (${m.especialidade})
                            <button class="action-btn edit" onclick="editarMedicoById(${m.id})">Editar</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function editarMedicoById(id) {
            const medico = medicos.find(m => m.id === id);
            const container = document.getElementById('medicoContent');
            container.innerHTML = `
                <form onsubmit="salvarEdicaoMedico(event, ${id})">
                    <div class="form-group"><label>Nome (${medico.nome}):</label><input type="text" id="editNome" placeholder="Deixe em branco para manter"></div>
                    <div class="form-group"><label>CRM (${medico.crm}):</label><input type="text" id="editCRM" placeholder="Deixe em branco para manter"></div>
                    <div class="form-group"><label>Especialidade (${medico.especialidade}):</label><input type="text" id="editEsp" placeholder="Deixe em branco para manter"></div>
                    <button type="submit">Salvar Alterações</button>
                    <button type="button" onclick="showEditarMedico()" style="background:#95a5a6">Cancelar</button>
                </form>
            `;
        }

        function salvarEdicaoMedico(event, id) {
            event.preventDefault();
            const medico = medicos.find(m => m.id === id);
            const novoNome = document.getElementById('editNome').value;
            const novoCRM = document.getElementById('editCRM').value;
            const novoEsp = document.getElementById('editEsp').value;
            
            if (novoNome) medico.nome = novoNome;
            if (novoCRM) medico.crm = novoCRM;
            if (novoEsp) medico.especialidade = novoEsp;
            
            showMessage('medico', '✅ Médico atualizado com sucesso!', 'success');
            showEditarMedico();
        }

        function showExcluirMedico() {
            const container = document.getElementById('medicoContent');
            if (medicos.length === 0) {
                container.innerHTML = '<p>Nenhum médico cadastrado para excluir.</p>';
                return;
            }
            let html = '<div class="search-box"><input type="text" id="buscaMedicoExcluir" placeholder="Buscar médico..." onkeyup="filtrarMedicosExcluir()"></div>';
            html += '<div id="listaMedicosExcluir">';
            medicos.forEach(m => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>${m.id} - ${m.nome}</strong>
                            <button class="action-btn delete" onclick="excluirMedicoConfirm(${m.id})">Excluir</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function excluirMedicoConfirm(id) {
            if (confirm('Tem certeza que deseja excluir este médico?')) {
                const index = medicos.findIndex(m => m.id === id);
                if (index !== -1) {
                    medicos.splice(index, 1);
                    atualizarStats();
                    showMessage('medico', '🗑️ Médico excluído com sucesso!', 'success');
                    showExcluirMedico();
                }
            }
        }

        // ========== PACIENTES (Funções similares) ==========
        function showPacienteForm() {
            const container = document.getElementById('pacienteContent');
            container.innerHTML = `
                <form onsubmit="cadastrarPaciente(event)">
                    <div class="form-group"><label>Nome:</label><input type="text" id="pacienteNome" required></div>
                    <div class="form-group"><label>CPF:</label><input type="text" id="pacienteCPF" required></div>
                    <div class="form-group"><label>Telefone:</label><input type="text" id="pacienteTelefone" required></div>
                    <button type="submit">Cadastrar Paciente</button>
                </form>
            `;
        }

        function cadastrarPaciente(event) {
            event.preventDefault();
            pacientes.push({ 
                id: proximoIdPaciente++, 
                nome: document.getElementById('pacienteNome').value,
                cpf: document.getElementById('pacienteCPF').value,
                telefone: document.getElementById('pacienteTelefone').value
            });
            atualizarStats();
            showMessage('paciente', '✅ Paciente cadastrado com sucesso!', 'success');
            showPacienteForm();
        }

        function listarPacientes() {
            const container = document.getElementById('pacienteContent');
            if (pacientes.length === 0) {
                container.innerHTML = '<p>Nenhum paciente cadastrado.</p>';
                return;
            }
            let html = '<div class="table-container"><table><tr><th>ID</th><th>Nome</th><th>CPF</th><th>Telefone</th></tr>';
            pacientes.forEach(p => {
                html += `<tr><td>${p.id}</td><td>${p.nome}</td><td>${p.cpf}</td><td>${p.telefone}</td></tr>`;
            });
            html += '</table></div>';
            container.innerHTML = html;
        }

        function showEditarPaciente() {
            const container = document.getElementById('pacienteContent');
            if (pacientes.length === 0) {
                container.innerHTML = '<p>Nenhum paciente cadastrado.</p>';
                return;
            }
            let html = '<div id="listaPacientesEdit">';
            pacientes.forEach(p => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>${p.id} - ${p.nome}</strong>
                            <button class="action-btn edit" onclick="editarPacienteById(${p.id})">Editar</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function editarPacienteById(id) {
            const paciente = pacientes.find(p => p.id === id);
            const container = document.getElementById('pacienteContent');
            container.innerHTML = `
                <form onsubmit="salvarEdicaoPaciente(event, ${id})">
                    <div class="form-group"><label>Nome (${paciente.nome}):</label><input type="text" id="editNome" placeholder="Deixe em branco para manter"></div>
                    <div class="form-group"><label>CPF (${paciente.cpf}):</label><input type="text" id="editCPF" placeholder="Deixe em branco para manter"></div>
                    <div class="form-group"><label>Telefone (${paciente.telefone}):</label><input type="text" id="editTel" placeholder="Deixe em branco para manter"></div>
                    <button type="submit">Salvar</button>
                    <button type="button" onclick="showEditarPaciente()">Cancelar</button>
                </form>
            `;
        }

        function salvarEdicaoPaciente(event, id) {
            event.preventDefault();
            const paciente = pacientes.find(p => p.id === id);
            if (document.getElementById('editNome').value) paciente.nome = document.getElementById('editNome').value;
            if (document.getElementById('editCPF').value) paciente.cpf = document.getElementById('editCPF').value;
            if (document.getElementById('editTel').value) paciente.telefone = document.getElementById('editTel').value;
            showMessage('paciente', '✅ Paciente atualizado!', 'success');
            showEditarPaciente();
        }

        function showExcluirPaciente() {
            const container = document.getElementById('pacienteContent');
            if (pacientes.length === 0) {
                container.innerHTML = '<p>Nenhum paciente cadastrado.</p>';
                return;
            }
            let html = '<div id="listaPacientesExcluir">';
            pacientes.forEach(p => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>${p.id} - ${p.nome}</strong>
                            <button class="action-btn delete" onclick="excluirPacienteConfirm(${p.id})">Excluir</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function excluirPacienteConfirm(id) {
            if (confirm('Excluir este paciente?')) {
                const index = pacientes.findIndex(p => p.id === id);
                if (index !== -1) {
                    pacientes.splice(index, 1);
                    atualizarStats();
                    showMessage('paciente', '✅ Paciente excluído!', 'success');
                    showExcluirPaciente();
                }
            }
        }

        // ========== MEDICAMENTOS (Simplificado) ==========
        function showMedicamentoForm() {
            const container = document.getElementById('medicamentoContent');
            container.innerHTML = `
                <form onsubmit="cadastrarMedicamento(event)">
                    <div class="form-group"><label>Nome:</label><input type="text" id="medNome" required></div>
                    <div class="form-group"><label>Fabricante:</label><input type="text" id="medFabricante" required></div>
                    <button type="submit">Cadastrar Medicamento</button>
                </form>
            `;
        }

        function cadastrarMedicamento(event) {
            event.preventDefault();
            medicamentos.push({ 
                id: proximoIdMedicamento++, 
                nome: document.getElementById('medNome').value,
                fabricante: document.getElementById('medFabricante').value
            });
            atualizarStats();
            showMessage('medicamento', '✅ Medicamento cadastrado!', 'success');
            showMedicamentoForm();
        }

        function listarMedicamentos() {
            const container = document.getElementById('medicamentoContent');
            if (medicamentos.length === 0) {
                container.innerHTML = '<p>Nenhum medicamento cadastrado.</p>';
                return;
            }
            let html = '<div class="table-container"><table><tr><th>ID</th><th>Nome</th><th>Fabricante</th></tr>';
            medicamentos.forEach(m => {
                html += `<tr><td>${m.id}</td><td>${m.nome}</td><td>${m.fabricante}</td></tr>`;
            });
            html += '</table></div>';
            container.innerHTML = html;
        }

        function showEditarMedicamento() {
            const container = document.getElementById('medicamentoContent');
            if (medicamentos.length === 0) {
                container.innerHTML = '<p>Nenhum medicamento cadastrado.</p>';
                return;
            }
            let html = '<div id="listaMedEdit">';
            medicamentos.forEach(m => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>${m.id} - ${m.nome}</strong>
                            <button class="action-btn edit" onclick="editarMedicamentoById(${m.id})">Editar</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function editarMedicamentoById(id) {
            const med = medicamentos.find(m => m.id === id);
            const container = document.getElementById('medicamentoContent');
            container.innerHTML = `
                <form onsubmit="salvarEdicaoMedicamento(event, ${id})">
                    <div class="form-group"><label>Nome (${med.nome}):</label><input type="text" id="editNome"></div>
                    <div class="form-group"><label>Fabricante (${med.fabricante}):</label><input type="text" id="editFab"></div>
                    <button type="submit">Salvar</button>
                    <button type="button" onclick="showEditarMedicamento()">Cancelar</button>
                </form>
            `;
        }

        function salvarEdicaoMedicamento(event, id) {
            event.preventDefault();
            const med = medicamentos.find(m => m.id === id);
            if (document.getElementById('editNome').value) med.nome = document.getElementById('editNome').value;
            if (document.getElementById('editFab').value) med.fabricante = document.getElementById('editFab').value;
            showMessage('medicamento', '✅ Medicamento atualizado!', 'success');
            showEditarMedicamento();
        }

        function showExcluirMedicamento() {
            const container = document.getElementById('medicamentoContent');
            if (medicamentos.length === 0) {
                container.innerHTML = '<p>Nenhum medicamento cadastrado.</p>';
                return;
            }
            let html = '<div id="listaMedExcluir">';
            medicamentos.forEach(m => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>${m.id} - ${m.nome}</strong>
                            <button class="action-btn delete" onclick="excluirMedicamentoConfirm(${m.id})">Excluir</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function excluirMedicamentoConfirm(id) {
            if (confirm('Excluir este medicamento?')) {
                const index = medicamentos.findIndex(m => m.id === id);
                if (index !== -1) {
                    medicamentos.splice(index, 1);
                    atualizarStats();
                    showMessage('medicamento', '✅ Medicamento excluído!', 'success');
                    showExcluirMedicamento();
                }
            }
        }

        // ========== CONSULTAS ==========
        function nomeMedico(id) {
            const m = medicos.find(m => m.id === id);
            return m ? m.nome : '[Não encontrado]';
        }

        function nomePaciente(id) {
            const p = pacientes.find(p => p.id === id);
            return p ? p.nome : '[Não encontrado]';
        }

        function showConsultaForm() {
            if (medicos.length === 0 || pacientes.length === 0) {
                document.getElementById('consultaContent').innerHTML = '<div class="message error">⚠️ É necessário ter pelo menos um médico e um paciente cadastrados!</div>';
                return;
            }
            let medicoOptions = medicos.map(m => `<option value="${m.id}">${m.id} - ${m.nome} (${m.especialidade})</option>`).join('');
            let pacienteOptions = pacientes.map(p => `<option value="${p.id}">${p.id} - ${p.nome}</option>`).join('');
            
            const container = document.getElementById('consultaContent');
            container.innerHTML = `
                <form onsubmit="cadastrarConsulta(event)">
                    <div class="form-group"><label>Médico:</label><select id="consultaMedico" required>${medicoOptions}</select></div>
                    <div class="form-group"><label>Paciente:</label><select id="consultaPaciente" required>${pacienteOptions}</select></div>
                    <div class="form-group"><label>Data:</label><input type="text" id="consultaData" placeholder="DD/MM/AAAA" required></div>
                    <div class="form-group"><label>Diagnóstico:</label><textarea id="consultaDiagnostico" rows="3" required></textarea></div>
                    <button type="submit">Registrar Consulta</button>
                </form>
            `;
        }

        function cadastrarConsulta(event) {
            event.preventDefault();
            consultas.push({
                id: proximoIdConsulta++,
                id_medico: parseInt(document.getElementById('consultaMedico').value),
                id_paciente: parseInt(document.getElementById('consultaPaciente').value),
                data: document.getElementById('consultaData').value,
                diagnostico: document.getElementById('consultaDiagnostico').value
            });
            atualizarStats();
            showMessage('consulta', '✅ Consulta registrada com sucesso!', 'success');
            showConsultaForm();
        }

        function listarConsultas() {
            const container = document.getElementById('consultaContent');
            if (consultas.length === 0) {
                container.innerHTML = '<p>Nenhuma consulta registrada.</p>';
                return;
            }
            let html = '<div class="table-container"><table><tr><th>ID</th><th>Médico</th><th>Paciente</th><th>Data</th><th>Diagnóstico</th></tr>';
            consultas.forEach(c => {
                html += `<tr>
                            <td>${c.id}</td>
                            <td>${nomeMedico(c.id_medico)} (ID: ${c.id_medico})</td>
                            <td>${nomePaciente(c.id_paciente)} (ID: ${c.id_paciente})</td>
                            <td>${c.data}</td>
                            <td>${c.diagnostico}</td>
                         </tr>`;
            });
            html += '<table></div>';
            container.innerHTML = html;
        }

        function showBuscarConsulta() {
            const container = document.getElementById('consultaContent');
            container.innerHTML = `
                <div class="search-box">
                    <input type="number" id="buscaConsultaId" placeholder="Digite o ID da consulta">
                    <button onclick="buscarConsultaPorId()" style="margin-top:10px">🔍 Buscar</button>
                </div>
                <div id="resultadoBusca"></div>
            `;
        }

        function buscarConsultaPorId() {
            const id = parseInt(document.getElementById('buscaConsultaId').value);
            const consulta = consultas.find(c => c.id === id);
            const resultado = document.getElementById('resultadoBusca');
            
            if (!consulta) {
                resultado.innerHTML = '<div class="message error">❌ Consulta não encontrada!</div>';
                return;
            }
            
            resultado.innerHTML = `
                <div style="background:#f8f9fa; padding:20px; border-radius:10px; margin-top:20px;">
                    <h3>Detalhes da Consulta #${consulta.id}</h3>
                    <p><strong>👨‍⚕️ Médico:</strong> ${nomeMedico(consulta.id_medico)} (ID: ${consulta.id_medico})</p>
                    <p><strong>👤 Paciente:</strong> ${nomePaciente(consulta.id_paciente)} (ID: ${consulta.id_paciente})</p>
                    <p><strong>📅 Data:</strong> ${consulta.data}</p>
                    <p><strong>📝 Diagnóstico:</strong> ${consulta.diagnostico}</p>
                </div>
            `;
        }

        function showExcluirConsulta() {
            const container = document.getElementById('consultaContent');
            if (consultas.length === 0) {
                container.innerHTML = '<p>Nenhuma consulta registrada.</p>';
                return;
            }
            let html = '<div id="listaConsultasExcluir">';
            consultas.forEach(c => {
                html += `<div style="margin:10px 0; padding:10px; border:1px solid #ddd; border-radius:8px;">
                            <strong>ID: ${c.id}</strong> - ${nomeMedico(c.id_medico)} → ${nomePaciente(c.id_paciente)} (${c.data})
                            <button class="action-btn delete" onclick="excluirConsultaConfirm(${c.id})">Excluir</button>
                         </div>`;
            });
            html += '</div>';
            container.innerHTML = html;
        }

        function excluirConsultaConfirm(id) {
            if (confirm('Excluir esta consulta?')) {
                const index = consultas.findIndex(c => c.id === id);
                if (index !== -1) {
                    consultas.splice(index, 1);
                    atualizarStats();
                    showMessage('consulta', '✅ Consulta excluída!', 'success');
                    showExcluirConsulta();
                }
            }
        }

        // Funções auxiliares de busca
        function filtrarMedicosEdit() {
            const termo = document.getElementById('buscaMedicoEdit').value.toLowerCase();
            const lista = document.getElementById('listaMedicosEdit');
            if (!lista) return;
            const divs = lista.querySelectorAll('div');
            divs.forEach(div => {
                const texto = div.textContent.toLowerCase();
                div.style.display = texto.includes(termo) ? 'block' : 'none';
            });
        }

        function filtrarMedicosExcluir() {
            const termo = document.getElementById('buscaMedicoExcluir').value.toLowerCase();
            const lista = document.getElementById('listaMedicosExcluir');
            if (!lista) return;
            const divs = lista.querySelectorAll('div');
            divs.forEach(div => {
                const texto = div.textContent.toLowerCase();
                div.style.display = texto.includes(termo) ? 'block' : 'none';
            });
        }

        // Inicialização
        carregarDadosExemplo();
        showMainMenu();