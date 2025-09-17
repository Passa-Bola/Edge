# Guia de Teste Renovado - Projeto Passa a Bola
**Versão Corrigida e Direto ao Ponto (Foco em Windows)**

Este guia foi ajustado para resolver os problemas comuns encontrados durante a configuração inicial, como erros de ativação de ambiente e pacotes faltando.

## Pré-requisitos Essenciais

### 1. Python 3.11+
- **Download**: [python.org/downloads](https://www.python.org/downloads/)
- **Instalação (Windows)**: Execute o instalador e **marque a opção "Add Python to PATH"**. Isso é crucial.
- **Verificação**: Abra o **PowerShell** e digite `python --version`. O resultado deve ser `Python 3.11.x` ou superior.

### 2. Git
- **Download**: [git-scm.com/downloads](https://git-scm.com/downloads)
- **Instalação (Windows)**: Pode manter as configurações padrão.
- **Verificação**: No **PowerShell**, digite `git --version`.

### 3. VS Code (Recomendado)
- **Download**: [code.visualstudio.com](https://code.visualstudio.com/)
- **Dica**: Use o terminal integrado do VS Code (Ctrl+Shift+'). Certifique-se de que ele está configurado para usar **PowerShell**.

---

## Passo a Passo Completo do Teste

### Etapa 1: Preparar o Projeto

#### 1.1. Clonar o Repositório
Abra o **PowerShell** (ou o terminal do VS Code) e execute os comandos abaixo, um por um.

```powershell
# Crie uma pasta para seus projetos (se ainda não tiver)
mkdir C:\projetos
cd C:\projetos

# Clone o projeto e entre na pasta
git clone https://github.com/Passa-Bola/Edge.git
cd Edge
```

### Etapa 2: Configurar o Ambiente Virtual (venv)

Esta é a etapa mais crítica. Preste atenção aos diretórios.

#### 2.1. Navegar para a Pasta do Simulador
Ainda no terminal, entre na pasta correta. O ambiente virtual (`venv`) deve ser criado aqui.

```powershell
cd simulator_chuteira
```
*Seu terminal deve mostrar o caminho `C:\projetos\Edge\simulator_chuteira`.*

#### 2.2. Criar e Ativar o Ambiente Virtual
```powershell
# Criar a venv
python -m venv venv

# Ativar a venv
.\venv\Scripts\Activate.ps1
```
**Resultado Esperado**: O prompt do seu terminal mudará, mostrando `(venv)` no início.
**Se der erro de "execução de scripts desabilitada"**:
Execute este comando no PowerShell (como administrador) uma única vez e confirme com 'S':
`Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser`
Depois, tente ativar a `venv` novamente.

#### 2.3. Instalar as Dependências (Com Verificação)
Com a `venv` ativa, instale os pacotes necessários.

```powershell
pip install -r requirements.txt
```
**Plano de Contingência (se der `ModuleNotFoundError`)**:
Se, mais tarde, algum script reclamar que um módulo não foi encontrado (como `requests`, `flask` ou `paho-mqtt`), reinstale-os manualmente.
```powershell
pip install requests flask paho-mqtt
```
#### 2.4. Verificar a Instalação
Confirme se os pacotes estão na sua `venv`.
```powershell
pip list
```
**Resultado Esperado**: A lista deve conter `Flask`, `paho-mqtt` e `requests`. Se estiverem lá, a configuração está **concluída com sucesso**.

---

### Etapa 3: Executar e Testar os Componentes

Você precisará de **dois terminais** abertos, ambos na pasta `C:\projetos\Edge\simulator_chuteira` e com a `venv` ativa.

#### Terminal 1: Rodar o Servidor Mock

1.  Abra um novo terminal no VS Code (Ctrl+Shift+').
2.  Navegue até a pasta e ative a venv:
    ```powershell
    cd C:\projetos\Edge\simulator_chuteira
    .\venv\Scripts\Activate.ps1
    ```
3.  Inicie o servidor mock:
    ```powershell
    python mock_fiware_iot_agent.py
    ```
**Resultado Esperado**: O terminal mostrará que o servidor está rodando na porta 5000. **Deixe este terminal aberto.**

#### Terminal 2: Rodar o Simulador da Chuteira

1.  Abra um segundo terminal.
2.  Navegue até a pasta e ative a venv (sim, de novo):
    ```powershell
    cd C:\projetos\Edge\simulator_chuteira
    .\venv\Scripts\Activate.ps1
    ```
3.  Inicie o simulador:
    ```powershell
    python simulator.py
    ```
**Resultado Esperado**:
*   **No Terminal 2**: Mensagens de "Publicado:..." aparecerão a cada 2 segundos.
*   **No Terminal 1**: Mensagens de "[MOCK FIWARE] Dados recebidos..." aparecerão, confirmando a comunicação.

---

### Etapa 4: Visualizar o Dashboard

1.  Abra seu navegador (Chrome, Firefox, etc.).
2.  Pressione `Ctrl+O` para abrir um arquivo local.
3.  Navegue e abra o seguinte arquivo:
    `C:\projetos\Edge\dashboard\index.html`

**Resultado Esperado**:
*   O título "🦶 Chuteira Inteligente" aparece.
*   O status mostra "Conectado ao Simulador" com um ponto verde.
*   Os cards ("Toques na Bola", "Passes", etc.) atualizam seus valores automaticamente.

---

### Etapa 5: Verificação Final e Limpeza

#### Checklist de Sucesso
- [ ] O Terminal 1 (Mock) está recebendo dados.
- [ ] O Terminal 2 (Simulador) está enviando dados.
- [ ] O Dashboard no navegador está com o status "Conectado" e os números estão mudando.

Se tudo isso estiver funcionando, **o projeto está 100% funcional!**

#### Para Parar Tudo
1.  Pressione `Ctrl+C` nos dois terminais.
2.  Digite `deactivate` em cada um para desativar a `venv`.

---

Este guia revisado deve ser suficiente para que qualquer pessoa consiga executar o projeto sem problemas.

---

