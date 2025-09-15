# Arquitetura Inicial da Aplicação IoT: Projeto "Passa a Bola"

## 1. Introdução

Este documento detalha a arquitetura inicial da aplicação IoT para o projeto "Passa a Bola", focando na coleta de dados de uma chuteira inteligente para análise de desempenho de jogadoras. O objetivo é monitorar toques e passes na bola, fornecendo estatísticas básicas que podem ser visualizadas em tempo real. A arquitetura proposta é modular e escalável, permitindo futuras expansões e a integração de funcionalidades mais complexas.

## 2. Visão Geral da Arquitetura

A arquitetura da aplicação "Passa a Bola" é composta por quatro camadas principais:

1.  **Dispositivo IoT (Edge):** A chuteira inteligente, equipada com sensores e um microcontrolador, responsável pela coleta primária de dados.
2.  **Conectividade:** O protocolo de comunicação que permite a transmissão segura e eficiente dos dados do dispositivo para a plataforma central.
3.  **Plataforma IoT (Cloud/Backend):** O ambiente centralizado para ingestão, processamento, armazenamento e gerenciamento dos dados IoT.
4.  **Aplicação de Visualização:** Uma interface gráfica que apresenta as estatísticas coletadas de forma clara e em tempo real para os usuários.

![Diagrama de Arquitetura IoT - Passa a Bola](https://i.imgur.com/example_architecture_diagram.png) <!-- Placeholder para o diagrama, será gerado posteriormente se necessário -->

## 3. Componentes Detalhados da Arquitetura

### 3.1. Dispositivo IoT: Chuteira Inteligente

*   **Sensor:** **Force Sensitive Resistor (FSR)**. Será integrado na sola da chuteira. O FSR é um sensor de pressão que varia sua resistência elétrica de acordo com a força aplicada. Isso permite detectar o impacto da bola e a pressão exercida durante toques e passes.
    *   **Função:** Detectar eventos de toque e pressão na bola, convertendo a força mecânica em um sinal elétrico.
*   **Microcontrolador:** **ESP32**. Este microcontrolador foi escolhido devido à sua capacidade de processamento, baixo custo e, crucialmente, sua conectividade Wi-Fi e Bluetooth integrada.
    *   **Função:** Ler os dados do sensor FSR, processar esses dados para identificar eventos de toque/passe (baseado em limiares de pressão), e transmitir essas informações para a plataforma IoT.

### 3.2. Conectividade

*   **Protocolo:** **MQTT (Message Queuing Telemetry Transport)** via Wi-Fi.
    *   **Função:** O MQTT é um protocolo de mensagens leve, ideal para dispositivos IoT com largura de banda limitada e alta latência. O ESP32 utilizará sua conectividade Wi-Fi para se conectar a um *broker* MQTT e publicar os eventos detectados (toques, passes) em tópicos específicos. Isso garante uma comunicação eficiente e em tempo real entre a chuteira e a plataforma.

### 3.3. Plataforma IoT: FIWARE

*   **Plataforma:** **FIWARE**. Uma plataforma open source robusta, que oferece um conjunto de componentes (Generic Enablers) para construir soluções IoT. É particularmente forte em gerenciamento de contexto e interoperabilidade.
    *   **Componentes Chave (Exemplos):**
        *   **Orion Context Broker:** O coração do FIWARE, responsável por gerenciar o contexto das entidades (neste caso, as chuteiras e jogadoras). Ele receberá os dados via MQTT (através de um IoT Agent) e os disponibilizará para consulta.
        *   **IoT Agent for MQTT:** Atuará como um adaptador, traduzindo as mensagens MQTT recebidas do ESP32 para o formato NGSI (Next Generation Service Interface) compreendido pelo Orion Context Broker.
        *   **QuantumLeap (Opcional para Histórico):** Para armazenamento de dados históricos em um banco de dados de séries temporais (como TimescaleDB ou CrateDB), permitindo análises retrospectivas.
    *   **Função:** Ingestão de dados do dispositivo, gerenciamento do estado das entidades (chuteiras/jogadoras), processamento inicial dos dados (contagem de toques/passes) e disponibilização desses dados para a camada de visualização.

### 3.4. Estatísticas Básicas

*   **Métricas Iniciais:**
    *   **Número de Toques na Bola:** Contagem total de vezes que a chuteira detecta um contato significativo com a bola.
    *   **Número de Passes:** Contagem de eventos de passe (que podem ser diferenciados de toques por padrões de pressão ou duração).
    *   **Tempo de Posse (futuro):** Embora não seja uma estatística de contador simples, a base para ela pode ser estabelecida registrando o tempo entre toques consecutivos ou a duração de um toque prolongado.
    *   **Usage Rate:** A frequência com que a jogadora interage com a bola durante um período específico.
*   **Processamento:** A contagem dessas estatísticas será realizada dentro do FIWARE, atualizando os atributos das entidades em tempo real à medida que os eventos chegam do dispositivo.

### 3.5. Interface de Visualização: Dashboard em Tempo Real

*   **Tipo:** **Dashboard Web com Gráficos em Tempo Real.**
    *   **Tecnologias (Sugestão):** Pode ser desenvolvido com tecnologias web padrão (HTML, CSS, JavaScript) e bibliotecas de gráficos (como Chart.js ou D3.js) para criar visualizações dinâmicas. O frontend se comunicaria diretamente com o Orion Context Broker do FIWARE para obter os dados mais recentes.
    *   **Função:** Apresentar as estatísticas coletadas (toques, passes, etc.) de forma visualmente atraente e atualizada em tempo real. Isso permitirá que treinadores e jogadoras monitorem o desempenho durante ou após uma partida.

## 4. Fluxo de Dados

1.  O sensor FSR na chuteira detecta um toque/pressão.
2.  O ESP32 lê o sinal do FSR, interpreta como um evento (toque/passe) e formata a informação.
3.  O ESP32 publica a mensagem do evento via MQTT para o *broker*.
4.  O IoT Agent for MQTT do FIWARE recebe a mensagem do *broker*.
5.  O IoT Agent traduz a mensagem para NGSI e a envia para o Orion Context Broker.
6.  O Orion Context Broker atualiza a entidade correspondente à chuteira/jogadora, incrementando os contadores de toques/passes.
7.  O Dashboard Web consulta o Orion Context Broker e exibe as estatísticas atualizadas em tempo real.

## 5. Teste Virtual (Simulador em C/C++)

Para a Sprint 3, um simulador em C/C++ será desenvolvido para emular o comportamento da chuteira. Este simulador se conectará ao *broker* MQTT e enviará mensagens de eventos (toques/passes) em intervalos aleatórios, permitindo a demonstração completa do fluxo de dados e da funcionalidade da plataforma e do dashboard sem a necessidade do hardware físico. O código do simulador será parte do repositório Git.

## 6. Próximos Passos

Com esta arquitetura inicial definida, os próximos passos incluem a criação do roteiro para o vídeo explicativo, a estruturação do repositório Git com o `README.md` detalhado e o desenvolvimento do simulador em C/C++.
