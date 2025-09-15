# Projeto "Passa a Bola": Arquitetura Inicial de uma Aplicação IoT

## Integrantes do Grupo

*   Leonardo Silva - 564929
*   Samuel Monteiro - 564391
*   Yan Barutti - 566412
*   Guilherme Araujo - 561848
*   Lucas Cortonezi - 563271

## Descrição Clara do Projeto

O projeto "Passa a Bola" visa desenvolver uma aplicação IoT inovadora para aprimorar a análise de desempenho de jogadoras de futebol. O foco inicial é na criação de uma chuteira inteligente equipada com sensores capazes de detectar e quantificar eventos como toques na bola e passes. Os dados coletados serão transmitidos para uma plataforma IoT centralizada, onde serão processados para gerar estatísticas básicas de desempenho. Esta primeira versão estabelece a arquitetura fundamental para um sistema escalável, permitindo futuras expansões e a integração de funcionalidades mais complexas de análise e feedback.

## Arquitetura Proposta

Para uma descrição detalhada da arquitetura, consulte o arquivo `docs/arquitetura.md`.

![Diagrama de Arquitetura IoT - Passa a Bola](docs/diagrama_arquitetura.png) <!-- Placeholder para o diagrama, será gerado e adicionado posteriormente -->

## Recursos Necessários

### Hardware (para implementação futura):

*   **Sensor:** Force Sensitive Resistor (FSR)
*   **Microcontrolador:** ESP32

### Ferramentas e Plataformas:

*   **Plataforma IoT:** FIWARE (Orion Context Broker, IoT Agent for MQTT)
*   **Broker MQTT:** Mosquitto (ou similar)
*   **Linguagem de Programação para Simulador:** C/C++
*   **Ferramentas de Desenvolvimento C/C++:** Compilador GCC, Make (ou CMake)
*   **Bibliotecas C/C++:** Biblioteca MQTT para C (ex: `paho.mqtt.c`)
*   **Dashboard Web:** HTML, CSS, JavaScript (com bibliotecas como Chart.js para gráficos)

## Instruções de Uso (Teste Virtual)

Para replicar e executar a demonstração virtual do projeto, siga os passos abaixo:

### Pré-requisitos:

*   Docker e Docker Compose (recomendado para configurar o ambiente FIWARE e Mosquitto).
*   Compilador C/C++ (GCC).
*   Biblioteca Paho MQTT C instalada.

### 1. Configuração do Ambiente FIWARE e MQTT Broker

Utilize Docker Compose para levantar o ambiente FIWARE e o Mosquitto MQTT Broker. Um arquivo `docker-compose.yml` será fornecido na pasta `infra/`.

```bash
cd infra
docker-compose up -d
```

Verifique se os serviços estão rodando:

```bash
docker-compose ps
```

### 2. Configuração da Entidade no FIWARE

Após o FIWARE estar ativo, configure a entidade `ChuteiraVirtual01` e o IoT Agent para processar as mensagens MQTT. As instruções detalhadas e os comandos `curl` para essa configuração serão fornecidos em `docs/fiware_setup.md`.

### 3. Compilação e Execução do Simulador em C/C++

O código-fonte do simulador estará localizado em `src/simulator/`. Para compilá-lo e executá-lo:

```bash
cd src/simulator
make # ou o comando de compilação específico
./simulator # ou o nome do executável gerado
```

O simulador começará a enviar eventos de "toque" e "passe" para o broker MQTT.

### 4. Visualização no Dashboard Web

O código do dashboard web estará em `src/dashboard/`. Abra o arquivo `index.html` em seu navegador ou configure um servidor web local para servi-lo.

```bash
cd src/dashboard
# Abra index.html diretamente ou use um servidor simples como:
python3 -m http.server 8000
# E acesse http://localhost:8000 no navegador
```

O dashboard exibirá as estatísticas em tempo real, atualizando-se conforme o simulador envia os dados para o FIWARE.

## Estrutura do Repositório

```
.
├── README.md
├── docs/
│   ├── arquitetura.md
│   ├── roteiro_video.md
│   └── fiware_setup.md
├── infra/
│   └── docker-compose.yml
└── src/
    ├── simulator/
    │   ├── simulator.c
    │   └── Makefile
    └── dashboard/
        ├── index.html
        ├── style.css
        └── script.js
```

