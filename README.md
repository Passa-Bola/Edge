# Projeto Challenge "Passa a Bola" - Sprint 3: Arquitetura Inicial de uma Aplicação IoT

## Nomes dos Integrantes do Grupo:

*   [Nome do Integrante 1]
*   [Nome do Integrante 2]
*   [Nome do Integrante 3]

## Descrição Clara do Projeto:

Este projeto visa desenvolver a arquitetura inicial de uma aplicação IoT para o "Passa a Bola", focando na criação de uma chuteira inteligente. O objetivo é coletar e transmitir dados de desempenho de jogadoras em tempo real, como número de toques na bola, passes e outras métricas básicas de participação. Esta primeira versão estabelece as bases para um sistema de estatísticas avançadas, permitindo futuras expansões e análises mais complexas.

O escopo desta sprint inclui a definição da arquitetura, a simulação de um dispositivo IoT (chuteira), a configuração de uma plataforma de gerenciamento IoT (Node-RED com MQTT) para receber e processar os dados, e a criação de um vídeo explicativo e um repositório GIT com toda a documentação e códigos fonte.

## Arquitetura Proposta:

A arquitetura IoT proposta é modular e baseada em padrões abertos, garantindo escalabilidade e flexibilidade. Ela é composta por:

1.  **Dispositivo IoT (Chuteira Inteligente):** Equipada com sensores de pressão/força e um microcontrolador com módulo Wi-Fi para coletar e enviar dados.
2.  **Protocolo de Comunicação MQTT:** Utilizado para a transmissão eficiente e leve dos dados dos dispositivos para a plataforma.
3.  **Broker MQTT:** Atua como intermediário, recebendo mensagens dos dispositivos e as encaminhando para a plataforma de gerenciamento.
4.  **Plataforma de Gerenciamento IoT (Node-RED):** Responsável por receber, processar, armazenar (temporariamente) e visualizar os dados em um dashboard intuitivo.

Para uma representação visual detalhada, consulte o diagrama de arquitetura: `assets/iot_architecture_diagram.png`

## Recursos Necessários:

### Dispositivos (Simulados/Prototipados):
*   **Chuteira Inteligente:** Simulada por um script Python que gera eventos de toque/passe.
*   **Sensores:** Sensores de pressão/força (simulados).
*   **Microcontrolador:** ESP32 ou ESP8266 (simulado no código Python).

### Ferramentas e Plataformas:
*   **Node-RED:** Plataforma de programação visual para fluxos de IoT.
*   **Broker MQTT:** HiveMQ Public Broker (para demonstração) ou Mosquitto (para auto-hospedagem).
*   **Python 3:** Para o script de simulação do dispositivo.
*   **npm:** Gerenciador de pacotes para Node.js (para instalação do Node-RED).

### Linguagens e Frameworks:
*   **Python:** Para o simulador do dispositivo IoT.
*   **JavaScript/Node.js:** Base do Node-RED.
*   **MQTT:** Protocolo de comunicação.
*   **JSON:** Formato de dados para as mensagens MQTT.

## Instruções de Uso:

### 1. Requisitos e Dependências:
*   Python 3.x instalado.
*   pip (gerenciador de pacotes Python).
*   Node.js e npm instalados.

### 2. Instalação e Configuração:

#### a. Configuração do Simulador de Dispositivo (Python):
1.  Navegue até a pasta `code` do repositório:
    ```bash
    cd passa_a_bola_iot/code
    ```
2.  Instale as dependências Python:
    ```bash
    pip install -r requirements.txt
    ```
3.  Execute o simulador:
    ```bash
    python device_simulator.py
    ```
    Este script começará a publicar mensagens MQTT no tópico `passabola/chuteira/jogadorA/eventos` no broker público `broker.hivemq.com`.

#### b. Configuração da Plataforma IoT (Node-RED):
1.  Instale o Node-RED globalmente (se ainda não tiver):
    ```bash
    npm install -g node-red
    ```
2.  Inicie o Node-RED:
    ```bash
    node-red
    ```
3.  Abra seu navegador e acesse a interface do Node-RED (geralmente em `http://localhost:1880`).
4.  Importe o fluxo `node_red_flow.json`:
    *   No Node-RED, clique no menu superior direito (três linhas horizontais).
    *   Selecione `Import` -> `Clipboard`.
    *   Abra o arquivo `passa_a_bola_iot/code/node_red_flow.json` em um editor de texto, copie todo o conteúdo e cole na caixa de texto de importação do Node-RED.
    *   Clique em `Import`.
5.  Implante o fluxo clicando no botão `Deploy` no canto superior direito.
6.  Acesse o dashboard do Node-RED (geralmente em `http://localhost:1880/ui`) para visualizar as estatísticas em tempo real.

### 3. Execução da Aplicação:

1.  Certifique-se de que o simulador `device_simulator.py` esteja em execução.
2.  Certifique-se de que o Node-RED esteja em execução e o fluxo importado e implantado.
3.  Observe os dados de "Total de Toques" e "Total de Passes" sendo atualizados no dashboard do Node-RED em tempo real, conforme o simulador envia eventos.

