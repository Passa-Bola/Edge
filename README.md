# Projeto Passa a Bola - Chuteira Inteligente IoT

## Integrantes do Grupo

- Leonardo Silva - 564929
- Samuel Monteiro - 564391
- Yan Barutti - 566412
- Guilherme Araujo - 561848
- Lucas Toledo - 563271

## Descrição do Projeto

O projeto "Passa a Bola" consiste no desenvolvimento de uma **chuteira inteligente** equipada com sensores IoT para monitoramento de performance em tempo real durante partidas de futebol. O sistema coleta dados sobre toques na bola, passes, tempo de posse e pressão exercida, fornecendo estatísticas avançadas para análise de desempenho dos jogadores.

### Propósito

Criar uma solução IoT inovadora que permita:
- Monitoramento em tempo real da participação de jogadores em partidas
- Coleta automatizada de estatísticas de performance
- Análise de dados para melhoria do desempenho esportivo
- Demonstração prática de conceitos de Internet das Coisas (IoT)

### Escopo

Esta primeira versão (Sprint 3) foca na arquitetura básica do sistema, incluindo:
- Simulador da chuteira inteligente em Python
- Plataforma IoT para coleta e processamento de dados
- Dashboard de visualização em tempo real
- Integração entre componentes via protocolos IoT padrão

### Contexto

O projeto é desenvolvido como parte do Challenge "Passa a Bola", visando aplicar conceitos de IoT em um cenário real e prático do mundo esportivo.



## Arquitetura Proposta

### Diagrama da Arquitetura

```
┌─────────────────┐    HTTP POST     ┌──────────────────┐    Dados     ┌─────────────────┐
│   Chuteira      │ ───────────────► │ Mock FIWARE      │ ──────────► │   Dashboard     │
│   Inteligente   │                  │ IoT Agent        │             │   Web           │
│   (Simulador)   │                  │ (Flask Server)   │             │   (HTML/CSS/JS) │
└─────────────────┘                  └──────────────────┘             └─────────────────┘
        │                                      │
        │                                      │
   ┌────▼────┐                            ┌────▼────┐
   │ Sensor  │                            │ API     │
   │ FSR     │                            │ REST    │
   │ (Force  │                            │ /iot/   │
   │ Sensor) │                            │ json    │
   └─────────┘                            └─────────┘
```

### Componentes da Arquitetura

#### 1. Dispositivo IoT (Chuteira Inteligente)
- **Hardware Simulado**: Sensor de pressão FSR (Force Sensitive Resistor)
- **Microcontrolador**: ESP32 (WiFi/Bluetooth integrado)
- **Implementação**: Simulador Python que gera dados realísticos

#### 2. Plataforma IoT
- **Tecnologia**: FIWARE (padrão europeu para IoT)
- **Implementação Atual**: Mock HTTP Server (Flask)
- **Protocolo**: HTTP POST com JSON payload
- **Endpoint**: `/iot/json`

#### 3. Interface de Visualização
- **Tecnologia**: Dashboard web responsivo
- **Implementação**: HTML5, CSS3, JavaScript
- **Funcionalidades**: Visualização em tempo real, estatísticas, logs

### Fluxo de Dados

1. **Coleta**: O simulador da chuteira gera dados do sensor FSR a cada 1-3 segundos
2. **Transmissão**: Dados são enviados via HTTP POST para o Mock FIWARE IoT Agent
3. **Processamento**: O Mock Agent recebe e registra os dados
4. **Visualização**: Dashboard exibe estatísticas em tempo real (simuladas)

### Protocolos e Padrões

- **Comunicação**: HTTP/HTTPS
- **Formato de Dados**: JSON
- **Padrão IoT**: FIWARE NGSI-LD (simulado)
- **Arquitetura**: RESTful API


## Recursos Necessários

### Hardware (Para Implementação Real)
- **Microcontrolador**: ESP32 DevKit
- **Sensor**: FSR (Force Sensitive Resistor) 
- **Conectividade**: WiFi (integrado no ESP32)
- **Alimentação**: Bateria Li-Po 3.7V
- **Encapsulamento**: Case resistente à água para integração na chuteira

### Software e Ferramentas

#### Linguagens de Programação
- **Python 3.11+**: Simulador e Mock IoT Agent
- **HTML5/CSS3/JavaScript**: Dashboard web
- **C++ (Arduino IDE)**: Para programação do ESP32 (implementação futura)

#### Frameworks e Bibliotecas
- **Flask**: Servidor web para Mock IoT Agent
- **Requests**: Cliente HTTP para comunicação
- **Paho-MQTT**: Cliente MQTT (para versões futuras)

#### Plataformas IoT
- **FIWARE**: Plataforma IoT open source
  - Orion Context Broker
  - IoT Agent for JSON
- **MongoDB**: Banco de dados para armazenamento
- **Mosquitto**: Broker MQTT

#### Ferramentas de Desenvolvimento
- **Git**: Controle de versão
- **Docker**: Containerização (para FIWARE completo)
- **Python pip**: Gerenciador de pacotes Python
- **Navegador Web**: Para visualização do dashboard

### Dependências Python
```
Flask==2.3.3
requests==2.31.0
paho-mqtt==1.6.1
```


## Instruções de Instalação e Configuração

### Pré-requisitos

Antes de iniciar, certifique-se de ter instalado em seu sistema:

1. **Python 3.11 ou superior**
   - **Windows**: Baixe de [python.org](https://www.python.org/downloads/)
     - ⚠️ **IMPORTANTE**: Durante a instalação, marque a opção "Add Python to PATH"
     - **Verificação**: Abra o PowerShell e digite `python --version`
   - **macOS**: `brew install python3` ou baixe de python.org
   - **Linux**: `sudo apt-get install python3 python3-pip`

2. **Git**
   - **Windows**: Baixe de [git-scm.com](https://git-scm.com/)
   - **macOS**: `brew install git` ou use Xcode Command Line Tools
   - **Linux**: `sudo apt-get install git`
   - **Verificação**: No terminal, digite `git --version`

3. **Editor de Código (Recomendado)**
   - **VS Code**: [code.visualstudio.com](https://code.visualstudio.com/)
     - Configure o terminal integrado para usar PowerShell (Windows)
     - Use Ctrl+Shift+' para abrir terminal integrado

4. **Navegador Web Moderno**
   - Chrome, Firefox, Safari ou Edge

### Configuração Adicional (Windows)

Se você usar PowerShell e encontrar erros de "execução de scripts desabilitada", execute este comando **uma única vez** como administrador:

```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

### Passo 1: Clonar o Repositório

Abra o terminal (PowerShell no Windows ou Terminal no macOS/Linux):

```bash
# Crie uma pasta para seus projetos (opcional, mas recomendado)
mkdir projetos
cd projetos

# Clone o projeto e entre na pasta
git clone https://github.com/Passa-Bola/Edge.git
cd Edge
```

### Passo 2: Configurar o Ambiente Virtual Python

⚠️ **Esta é a etapa mais crítica**. Preste atenção aos diretórios.

#### 2.1. Navegar para a Pasta do Simulador
```bash
cd simulator_chuteira
```

#### 2.2. Criar e Ativar o Ambiente Virtual

**No Windows (PowerShell):**
```powershell
# Criar a venv
python -m venv venv

# Ativar a venv
.\venv\Scripts\Activate.ps1
```

**No macOS/Linux:**
```bash
# Criar a venv
python3 -m venv venv

# Ativar a venv
source venv/bin/activate
```

**Resultado Esperado**: O prompt do terminal deve mostrar `(venv)` no início, indicando que o ambiente virtual está ativo.

#### 2.3. Instalar as Dependências

Com a venv ativa, instale os pacotes necessários:

```bash
pip install -r requirements.txt
```

**Se ocorrer erro de ModuleNotFoundError futuramente**, reinstale manualmente:
```bash
pip install requests flask paho-mqtt
```

### Passo 3: Verificar a Instalação

Confirme que as bibliotecas foram instaladas corretamente:

```bash
pip list
```

**Você deve ver na lista**:
- Flask
- paho-mqtt  
- requests

Se estes pacotes aparecerem, a configuração está **concluída com sucesso**.


## Instruções de Execução

### Executando o Sistema Completo

Para testar o sistema completo, você precisará executar dois componentes em **terminais separados**. Ambos devem estar na pasta `simulator_chuteira` com a venv ativa.

#### Terminal 1: Mock FIWARE IoT Agent

1. Abra um terminal (VS Code: Ctrl+Shift+')
2. Navegue até a pasta e ative a venv:

**Windows (PowerShell):**
```powershell
cd projetos\Edge\simulator_chuteira
.\venv\Scripts\Activate.ps1
```

**macOS/Linux:**
```bash
cd projetos/Edge/simulator_chuteira
source venv/bin/activate
```

3. Inicie o Mock Agent:
```bash
python mock_fiware_iot_agent.py
```

**Saída esperada:**
```
[MOCK FIWARE] Servidor Mock FIWARE IoT Agent iniciado na porta 5000
 * Running on all addresses (0.0.0.0)
 * Running on http://127.0.0.1:5000
 * Running on http://[seu-ip]:5000
```

**⚠️ Deixe este terminal aberto e rodando.**

#### Terminal 2: Simulador da Chuteira

1. Abra um **segundo terminal**
2. Navegue até a pasta e ative a venv (novamente):

**Windows (PowerShell):**
```powershell
cd projetos\Edge\simulator_chuteira
.\venv\Scripts\Activate.ps1
```

**macOS/Linux:**
```bash
cd projetos/Edge/simulator_chuteira
source venv/bin/activate
```

3. Inicie o simulador:
```bash
python simulator.py
```

**Saída esperada:**
```
Simulador da Chuteira Inteligente (chuteira001) iniciado.
Enviando dados para o Mock FIWARE IoT Agent em: http://localhost:5000/iot/json
Publicado: {"id": "chuteira001", "type": "SmartShoe", "pressure_sensor": 80, "total_touches": 0, "total_passes": 0, "possession_time": 0} - Resposta: 200
Publicado: {"id": "chuteira001", "type": "SmartShoe", "pressure_sensor": 760, "total_touches": 1, "total_passes": 0, "possession_time": 0.23} - Resposta: 200
...
```

**Resultado Esperado**:
- **Terminal 2**: Mensagens de "Publicado:..." aparecerão a cada 2 segundos
- **Terminal 1**: Mensagens de "[MOCK FIWARE] Dados recebidos..." aparecerão, confirmando a comunicação

#### Visualizando o Dashboard

1. Abra seu navegador (Chrome, Firefox, etc.)
2. **Opção 1 - Abrir arquivo diretamente**: 
   - Pressione `Ctrl+O` no navegador
   - Navegue até a pasta do projeto e abra: `[caminho]/Edge/dashboard/index.html`
   - **Windows**: `C:\projetos\Edge\dashboard\index.html`
3. **Opção 2 - URL direta**: Digite no navegador: `file:///[caminho-completo]/Edge/dashboard/index.html`

**Resultado Esperado**:
- O título "🦶 Chuteira Inteligente" aparece
- O status mostra "Conectado ao Simulador" com um ponto verde
- Os cards ("Toques na Bola", "Passes", etc.) atualizam seus valores automaticamente

### Verificação Final de Sucesso

✅ **Checklist**:
- [ ] Terminal 1 (Mock) está recebendo dados
- [ ] Terminal 2 (Simulador) está enviando dados
- [ ] Dashboard no navegador mostra status "Conectado" e números mudando

Se tudo isso estiver funcionando, **o projeto está 100% operacional!**

### Parando a Execução

- **Para parar qualquer componente**: Pressione `Ctrl+C` no terminal correspondente
- **Para desativar a venv**: Digite `deactivate` em cada terminal
- **Para parar todos**: Feche todos os terminais

### Testando Componentes Individualmente

#### Teste do Mock IoT Agent

```bash
# Terminal 1: Iniciar o Mock Agent
python mock_fiware_iot_agent.py

# Terminal 2: Testar com curl
curl -X POST http://localhost:5000/iot/json \
  -H "Content-Type: application/json" \
  -d '{"id": "test", "pressure": 500}'

# Teste de Health Check
curl http://localhost:5000/health
```

#### Teste do Simulador (sem Mock Agent)

```bash
python simulator.py
```

**Nota**: Se o Mock Agent não estiver rodando, você verá mensagens de erro de conexão, o que é esperado.

### Parando a Execução

- **Para parar qualquer componente**: Pressione `Ctrl+C` no terminal correspondente
- **Para parar todos**: Feche todos os terminais ou pressione `Ctrl+C` em cada um


## Solução de Problemas

### Problemas Comuns e Soluções

#### 1. Erro: "Execução de scripts desabilitada" (Windows PowerShell)

**Problema**: `.\venv\Scripts\Activate.ps1 cannot be loaded because running scripts is disabled on this system`

**Solução**: Execute este comando **uma única vez** como administrador no PowerShell:
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```
Depois tente ativar a venv novamente.

#### 2. Erro: "ModuleNotFoundError: No module named 'flask'"

**Problema**: Dependências não instaladas corretamente ou venv não ativa.

**Soluções**:
1. **Verificar se a venv está ativa**: O prompt deve mostrar `(venv)`
2. **Reinstalar dependências**:
```bash
pip install -r requirements.txt
# OU manualmente:
pip install requests flask paho-mqtt
```

#### 3. Erro: "Python não é reconhecido como comando" (Windows)

**Problema**: Python não foi adicionado ao PATH durante a instalação.

**Soluções**:
1. **Reinstalar Python**: Baixe novamente e marque "Add Python to PATH"
2. **Usar py command**: Substitua `python` por `py` nos comandos
3. **Adicionar ao PATH manualmente**: Procurar por "Variáveis de Ambiente" no Windows

#### 4. Erro: "Address already in use" (Porta 5000 ocupada)

**Problema**: Outro processo está usando a porta 5000.

**Soluções**:
```bash
# Opção 1: Encontrar e parar o processo
lsof -i :5000  # Linux/macOS
netstat -ano | findstr :5000  # Windows

# Opção 2: Modificar a porta no arquivo mock_fiware_iot_agent.py
# Altere a linha: app.run(host='0.0.0.0', port=5000, debug=False)
# Para: app.run(host='0.0.0.0', port=5001, debug=False)
# E também atualize o simulator.py: MOCK_FIWARE_URL = "http://localhost:5001/iot/json"
```

#### 5. Erro de Conexão no Simulador

**Problema**: "Erro de conexão: Certifique-se de que o Mock FIWARE IoT Agent está rodando"

**Solução**: 
1. Verifique se o Mock Agent está rodando no Terminal 1
2. Confirme que não há erros na inicialização do Mock Agent
3. Teste o endpoint manualmente com curl

#### 6. Dashboard não carrega ou não exibe dados

**Problema**: Arquivo HTML não abre ou dados não aparecem.

**Soluções**:
1. **Para abrir o arquivo**: Use o caminho completo no navegador
2. **Para dados simulados**: O dashboard usa dados simulados próprios, independente do simulador Python
3. **Para integração real**: Seria necessário modificar o JavaScript para consumir dados do Mock Agent

#### 7. Permissões negadas (Linux/macOS)

**Problema**: Erro de permissão ao executar scripts.

**Solução**:
```bash
chmod +x *.py
```

### Verificação do Sistema

#### Health Check do Mock Agent

```bash
curl http://localhost:5000/health
```

**Resposta esperada**:
```json
{"status": "UP", "service": "Mock FIWARE IoT Agent"}
```

#### Verificação de Logs

Os logs aparecem diretamente no terminal onde cada componente está rodando. Monitore ambos os terminais para identificar problemas.

### Contato para Suporte

Em caso de problemas não cobertos nesta documentação, entre em contato com a equipe de desenvolvimento através do repositório GitHub.


## Comandos Úteis

### Comandos de Desenvolvimento

#### Verificar versão do Python
```bash
python --version
# ou
python3 --version
```

#### Listar pacotes instalados
```bash
pip list
```

#### Atualizar dependências
```bash
pip install --upgrade -r requirements.txt
```

#### Verificar sintaxe dos arquivos Python
```bash
python -m py_compile simulator.py
python -m py_compile mock_fiware_iot_agent.py
```

### Comandos de Teste

#### Teste manual do endpoint IoT
```bash
# Teste básico
curl -X POST http://localhost:5000/iot/json \
  -H "Content-Type: application/json" \
  -d '{"id": "chuteira001", "type": "SmartShoe", "pressure_sensor": 750, "total_touches": 5, "total_passes": 2, "possession_time": 1.5}'

# Health check
curl http://localhost:5000/health
```

#### Monitoramento de rede
```bash
# Verificar portas em uso
netstat -tulpn | grep :5000  # Linux
netstat -an | findstr :5000  # Windows
lsof -i :5000  # macOS
```

### Comandos de Git

#### Verificar status do repositório
```bash
git status
```

#### Adicionar e commitar mudanças
```bash
git add .
git commit -m "Descrição das mudanças"
git push origin main
```

#### Atualizar repositório local
```bash
git pull origin main
```

### Comandos de Limpeza

#### Limpar cache Python
```bash
find . -type d -name "__pycache__" -delete  # Linux/macOS
for /d /r . %d in (__pycache__) do @if exist "%d" rd /s /q "%d"  # Windows
```

#### Desativar ambiente virtual
```bash
deactivate
```

## Estrutura do Projeto

```
Edge/
├── simulator_chuteira/
│   ├── simulator.py              # Simulador principal da chuteira
│   ├── mock_fiware_iot_agent.py  # Mock do FIWARE IoT Agent
│   └── requirements.txt          # Dependências Python
├── dashboard/
│   └── index.html               # Dashboard web de visualização
└── README.md                    # Este arquivo
```

## Próximos Passos

### Melhorias Futuras

1. **Integração Real com FIWARE**: Implementar containers Docker com Orion Context Broker completo
2. **Banco de Dados**: Adicionar persistência de dados com MongoDB
3. **Dashboard Avançado**: Implementar gráficos em tempo real conectados ao Mock Agent
4. **Hardware Real**: Desenvolver protótipo físico com ESP32 e sensor FSR
5. **Análise de Dados**: Implementar algoritmos de machine learning para análise de performance
6. **Interface Mobile**: Desenvolver aplicativo móvel para visualização

### Contribuições

Para contribuir com o projeto:
1. Faça um fork do repositório
2. Crie uma branch para sua feature (`git checkout -b feature/nova-funcionalidade`)
3. Commit suas mudanças (`git commit -am 'Adiciona nova funcionalidade'`)
4. Push para a branch (`git push origin feature/nova-funcionalidade`)
5. Abra um Pull Request

---

**Projeto desenvolvido para o Challenge "Passa a Bola" - Sprint 3**  
**Equipe**: Leonardo Silva, Samuel Monteiro, Yan Barutti, Guilherme Araujo, Lucas Toledo

