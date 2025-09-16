# Guia de Teste Detalhado - Projeto Passa a Bola
**Para pessoas sem programas ou dependências instaladas**

## Pré-requisitos: Instalação do Zero

### 1. Instalação do Python

#### Windows:
1. Acesse [python.org/downloads](https://www.python.org/downloads/)
2. Baixe a versão mais recente do Python 3.11+
3. **IMPORTANTE**: Durante a instalação, marque "Add Python to PATH"
4. Execute o instalador como administrador
5. Teste no Prompt de Comando:
   ```cmd
   python --version
   ```
   **Resultado esperado**: `Python 3.11.x` ou superior

#### macOS:
1. **Opção 1 - Homebrew (recomendado)**:
   - Instale o Homebrew: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
   - Instale Python: `brew install python3`
   
2. **Opção 2 - Site oficial**:
   - Baixe de [python.org/downloads](https://www.python.org/downloads/)
   - Execute o instalador .pkg

3. Teste no Terminal:
   ```bash
   python3 --version
   ```

#### Linux (Ubuntu/Debian):
```bash
sudo apt update
sudo apt install python3 python3-pip python3-venv
python3 --version
```

### 2. Instalação do Git

#### Windows:
1. Acesse [git-scm.com](https://git-scm.com/)
2. Baixe "Git for Windows"
3. Execute o instalador com configurações padrão
4. Teste no Git Bash ou Prompt:
   ```cmd
   git --version
   ```

#### macOS:
```bash
# Com Homebrew
brew install git

# Ou instale Xcode Command Line Tools
xcode-select --install
```

#### Linux:
```bash
sudo apt install git
```

### 3. Editor de Texto (Opcional mas Recomendado)
- **Visual Studio Code**: [code.visualstudio.com](https://code.visualstudio.com/)
- **Notepad++** (Windows): [notepad-plus-plus.org](https://notepad-plus-plus.org/)

## Passo a Passo Completo do Teste

### Etapa 1: Preparação do Ambiente

#### 1.1 Criar Diretório de Trabalho
```bash
# Windows (Prompt de Comando)
mkdir C:\projetos
cd C:\projetos

# macOS/Linux (Terminal)
mkdir ~/projetos
cd ~/projetos
```

#### 1.2 Clonar o Repositório
```bash
git clone https://github.com/Passa-Bola/Edge.git
cd Edge
```

**Resultado esperado**: Pasta `Edge` criada com os arquivos do projeto.

#### 1.3 Verificar Estrutura do Projeto
```bash
# Windows
dir

# macOS/Linux
ls -la
```

**Você deve ver**:
```
simulator_chuteira/
dashboard/
README.md
ROTEIRO_VIDEO.md
GUIA_TESTE_DETALHADO.md
```

### Etapa 2: Configuração do Ambiente Python

#### 2.1 Navegar para o Diretório do Simulador
```bash
cd simulator_chuteira
```

#### 2.2 Criar Ambiente Virtual
```bash
# Windows
python -m venv venv

# macOS/Linux
python3 -m venv venv
```

**Resultado esperado**: Pasta `venv` criada.

#### 2.3 Ativar Ambiente Virtual
```bash
# Windows
venv\Scripts\activate

# macOS/Linux
source venv/bin/activate
```

**Resultado esperado**: Prompt muda para mostrar `(venv)` no início.

#### 2.4 Verificar Ativação
```bash
# Windows
where python

# macOS/Linux
which python
```

**Resultado esperado**: Caminho deve apontar para dentro da pasta `venv`.

#### 2.5 Instalar Dependências
```bash
pip install -r requirements.txt
```

**Resultado esperado**:
```
Successfully installed Flask-2.3.3 requests-2.31.0 paho-mqtt-1.6.1
```

#### 2.6 Verificar Instalação
```bash
pip list
```

**Você deve ver**:
```
Flask                    2.3.3
requests                 2.31.0
paho-mqtt               1.6.1
```

### Etapa 3: Teste dos Componentes

#### 3.1 Teste do Mock FIWARE IoT Agent

**Terminal 1** (manter aberto):
```bash
python mock_fiware_iot_agent.py
```

**Resultado esperado**:
```
[MOCK FIWARE] Servidor Mock FIWARE IoT Agent iniciado na porta 5000
 * Running on all addresses (0.0.0.0)
 * Running on http://127.0.0.1:5000
 * Running on http://192.168.x.x:5000
```

**Se der erro "Address already in use"**:
1. Feche outros programas que possam usar a porta 5000
2. Ou modifique a porta no arquivo `mock_fiware_iot_agent.py`

#### 3.2 Teste Manual do Endpoint (Opcional)

**Novo terminal** (manter o Terminal 1 rodando):
```bash
# Windows (PowerShell)
Invoke-RestMethod -Uri "http://localhost:5000/health" -Method GET

# macOS/Linux (se curl estiver instalado)
curl http://localhost:5000/health

# Alternativa: Abrir no navegador
# http://localhost:5000/health
```

**Resultado esperado**:
```json
{"status": "UP", "service": "Mock FIWARE IoT Agent"}
```

#### 3.3 Teste do Simulador da Chuteira

**Terminal 2** (novo terminal, ativar venv novamente):
```bash
cd simulator_chuteira
# Windows
venv\Scripts\activate
# macOS/Linux
source venv/bin/activate

python simulator.py
```

**Resultado esperado**:
```
Simulador da Chuteira Inteligente (chuteira001) iniciado.
Enviando dados para o Mock FIWARE IoT Agent em: http://localhost:5000/iot/json
Publicado: {"id": "chuteira001", "type": "SmartShoe", "pressure_sensor": 80, "total_touches": 0, "total_passes": 0, "possession_time": 0} - Resposta: 200
Publicado: {"id": "chuteira001", "type": "SmartShoe", "pressure_sensor": 760, "total_touches": 1, "total_passes": 0, "possession_time": 0.23} - Resposta: 200
...
```

**No Terminal 1**, você deve ver:
```
[MOCK FIWARE] Dados recebidos do dispositivo: {'id': 'chuteira001', 'type': 'SmartShoe', ...}
```

### Etapa 4: Teste do Dashboard

#### 4.1 Abrir Dashboard no Navegador

**Método 1 - Caminho direto**:
1. Abra seu navegador (Chrome, Firefox, Safari, Edge)
2. Pressione `Ctrl+O` (Windows/Linux) ou `Cmd+O` (macOS)
3. Navegue até a pasta do projeto: `Edge/dashboard/index.html`
4. Selecione e abra o arquivo

**Método 2 - Barra de endereços**:
```
# Windows
file:///C:/projetos/Edge/dashboard/index.html

# macOS
file:///Users/[seu-usuario]/projetos/Edge/dashboard/index.html

# Linux
file:///home/[seu-usuario]/projetos/Edge/dashboard/index.html
```

#### 4.2 Verificar Funcionamento do Dashboard

**Você deve ver**:
1. Título: "🦶 Chuteira Inteligente"
2. Status: "Conectado ao Simulador" (ponto verde piscando)
3. Quatro cards com estatísticas:
   - Toques na Bola
   - Passes
   - Tempo de Posse
   - Pressão Atual
4. Log de dados em tempo real (dados simulados)

**Os números devem mudar automaticamente a cada 2 segundos.**

### Etapa 5: Verificação Completa do Sistema

#### 5.1 Checklist de Funcionamento

- [ ] Mock FIWARE IoT Agent rodando (Terminal 1)
- [ ] Simulador enviando dados (Terminal 2)
- [ ] Dados sendo recebidos pelo Mock Agent
- [ ] Dashboard carregando no navegador
- [ ] Estatísticas atualizando no dashboard

#### 5.2 Teste de Integração

1. **Pare o simulador** (Ctrl+C no Terminal 2)
2. **Observe**: Mock Agent para de receber dados
3. **Reinicie o simulador**: `python simulator.py`
4. **Observe**: Dados voltam a ser enviados

#### 5.3 Teste de Robustez

1. **Pare o Mock Agent** (Ctrl+C no Terminal 1)
2. **Observe no Terminal 2**: Mensagens de erro de conexão
3. **Reinicie o Mock Agent**: `python mock_fiware_iot_agent.py`
4. **Observe**: Simulador volta a enviar dados com sucesso

## Solução de Problemas Detalhada

### Problema: "python não é reconhecido"
**Solução Windows**:
1. Reinstale Python marcando "Add to PATH"
2. Ou adicione manualmente ao PATH:
   - Painel de Controle → Sistema → Configurações Avançadas
   - Variáveis de Ambiente → PATH → Adicionar caminho do Python

### Problema: "pip não é reconhecido"
**Solução**:
```bash
python -m pip install --upgrade pip
```

### Problema: "Permissão negada" (macOS/Linux)
**Solução**:
```bash
chmod +x *.py
```

### Problema: "Porta 5000 em uso"
**Solução**:
1. **Encontrar processo**:
   ```bash
   # Windows
   netstat -ano | findstr :5000
   
   # macOS/Linux
   lsof -i :5000
   ```

2. **Matar processo** ou **mudar porta no código**

### Problema: Dashboard não carrega
**Soluções**:
1. Verifique se o arquivo existe na pasta correta
2. Use caminho absoluto completo
3. Teste em navegador diferente
4. Verifique se JavaScript está habilitado

## Comandos de Limpeza

### Para Parar Tudo
1. **Ctrl+C** em ambos os terminais
2. **Desativar ambiente virtual**:
   ```bash
   deactivate
   ```

### Para Limpar Instalação
```bash
# Remover ambiente virtual
rm -rf venv  # macOS/Linux
rmdir /s venv  # Windows

# Remover projeto
cd ..
rm -rf Edge  # macOS/Linux
rmdir /s Edge  # Windows
```

## Contatos e Suporte

- **Repositório**: https://github.com/Passa-Bola/Edge
- **Documentação**: README.md no repositório
- **Issues**: Use a aba Issues do GitHub para reportar problemas

---

**Este guia foi testado em Windows 10/11, macOS 12+, e Ubuntu 20.04+**

