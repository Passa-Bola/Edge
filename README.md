# Projeto "Passa a Bola": Chuteira Inteligente - Sprint 3

## Integrantes do Grupo

*   Lucas Toledo Cortonezi

## Descrição Clara do Projeto

Este projeto, parte da Sprint 3 do "Passa a Bola", visa desenvolver a arquitetura inicial de uma aplicação IoT focada em uma chuteira inteligente. O objetivo principal é coletar dados de desempenho de jogadoras de futebol em tempo real, fornecendo estatísticas valiosas para análise e aprimoramento. A solução proposta é simplificada para facilitar a execução e demonstração, com foco na coleta de dados de toque e passe, e no cálculo de métricas básicas de participação em jogo.

A chuteira inteligente atuará como um dispositivo de borda (edge device), equipada com sensores para detectar interações com a bola. Os dados coletados serão transmitidos para uma plataforma de gerenciamento IoT, onde serão processados, armazenados e visualizados. Esta abordagem inicial estabelece as bases para futuras expansões e funcionalidades mais avançadas, como análise de movimento, mapeamento de calor de contato e integração com sistemas de treinamento.

## Arquitetura Proposta

A arquitetura da aplicação IoT é dividida em quatro camadas principais: Dispositivo IoT (Chuteira Inteligente), Comunicação, Plataforma de Gerenciamento IoT e Aplicação/Visualização. Abaixo, o diagrama ilustra o fluxo de dados e a interação entre os componentes:

![Diagrama de Arquitetura IoT](arquitetura_iot.png)

### Explicação dos Componentes:

*   **Chuteira Inteligente (Dispositivo IoT):** É o coração da coleta de dados. Equipada com um **Sensor de Pressão/Força** para detectar o contato com a bola e um **ESP32 com Acelerômetro** para processar os dados e gerenciar a comunicação. O **Módulo Bluetooth Low Energy (BLE)** permite a transmissão eficiente e de baixo consumo dos dados.

*   **Comunicação:** Os dados da chuteira são enviados via BLE para um **Gateway Local**, que pode ser um smartphone ou um dispositivo dedicado (como um Raspberry Pi). Este gateway, por sua vez, retransmite os dados para a plataforma de gerenciamento utilizando protocolos como **MQTT ou HTTP**.

*   **Plataforma de Gerenciamento IoT (Thinger.io):** Para esta versão simplificada, utilizamos o **Thinger.io** como a plataforma central. Ele recebe os dados do gateway, os processa (contagem de toques, passes, taxa de uso), armazena e os disponibiliza para visualização. O Thinger.io oferece uma interface intuitiva para configuração e criação de dashboards.

*   **Aplicação/Visualização (Frontend):** O **Usuário Final** acessa um dashboard no Thinger.io para visualizar as estatísticas e métricas coletadas em tempo real, proporcionando insights sobre o desempenho da jogadora.




## Recursos Necessários

Para replicar e entender esta aplicação, os seguintes recursos são utilizados:

### Hardware (Simulado/Conceitual):

*   **Chuteira Inteligente:** Dispositivo conceitual que integra os sensores e o microcontrolador.
*   **Sensor de Pressão/Força:** Para detecção de toques e intensidade de impacto na bola.
*   **ESP32:** Microcontrolador com Wi-Fi e Bluetooth Low Energy (BLE) integrado, responsável pelo processamento dos dados dos sensores e comunicação.
*   **Acelerômetro:** Integrado ao ESP32, para detecção de movimento e filtragem de eventos.

### Software e Plataformas:

*   **Thinger.io:** Plataforma de gerenciamento IoT em nuvem, utilizada para receber, processar, armazenar e visualizar os dados dos dispositivos. Oferece uma interface intuitiva para criação de dashboards sem código.
*   **Wokwi:** Simulador online para ESP32 e Arduino, utilizado para desenvolver e testar o código do dispositivo IoT sem a necessidade de hardware físico. Permite simular o comportamento dos sensores e a comunicação.
*   **Arduino IDE (ou VS Code com PlatformIO):** Ambiente de desenvolvimento para programar o ESP32 (código em C++).

### Linguagens e Protocolos:

*   **C++:** Linguagem de programação utilizada para o firmware do ESP32.
*   **Bluetooth Low Energy (BLE):** Protocolo de comunicação de baixo consumo para a transmissão de dados da chuteira para o gateway local.
*   **MQTT/HTTP:** Protocolos utilizados para a comunicação entre o gateway local (smartphone/dispositivo) e a plataforma Thinger.io.




## Instruções de Uso

Este projeto é demonstrado através de um código simulado para o ESP32 no Wokwi e a configuração de um dashboard no Thinger.io. As instruções abaixo guiam você através da configuração e execução.

### Pré-requisitos:

*   Conta no [Thinger.io](https://thinger.io/)
*   Acesso à internet para o Thinger.io e Wokwi
*   Conhecimento básico de Arduino/ESP32 (para entender o código, embora a simulação simplifique a execução)

### 1. Configuração do Dispositivo no Thinger.io

Siga o guia `thinger_io_config_guide.md` para criar seu dispositivo e dashboard no Thinger.io. Certifique-se de anotar o `USERNAME`, `DEVICE_ID` e `DEVICE_CREDENTIAL` que você definir, pois serão necessários no código do ESP32.

### 2. Simulação do Dispositivo IoT (ESP32) no Wokwi

1.  Acesse o [Wokwi](https://wokwi.com/) e crie um novo projeto ESP32.
2.  Copie o conteúdo do arquivo `esp32_chuteira_simulada.ino` para o editor de código do Wokwi.
3.  **Atualize as credenciais no código:**
    *   Substitua `USERNAME`, `DEVICE_ID` e `DEVICE_CREDENTIAL` pelos valores que você configurou no Thinger.io.
    *   Substitua `WIFI_SSID` e `WIFI_PASSWORD` pelas credenciais de uma rede Wi-Fi válida (o Wokwi simula a conexão Wi-Fi).
4.  Inicie a simulação no Wokwi. Você deverá ver a saída serial indicando a conexão Wi-Fi e o envio de dados para o Thinger.io.

### 3. Visualização dos Dados no Thinger.io

1.  Com a simulação do Wokwi em execução, acesse o dashboard que você criou no Thinger.io.
2.  Você deverá ver os dados de `forca`, `toque`, `contagem_toques`, `contagem_passes` e `usage_rate` sendo atualizados em tempo real.

### 4. Entendendo o Código do Dispositivo (`esp32_chuteira_simulada.ino`)

O código simula a leitura de um sensor de pressão/força e calcula estatísticas básicas:

*   `forca_simulada`: Gera um valor aleatório para simular a força do toque.
*   `toque_simulado`: Define um toque como verdadeiro se a força simulada exceder um limite.
*   `contagem_toques`: Incrementa a cada toque detectado.
*   `contagem_passes`: Incrementa a cada 3 toques (lógica simplificada para demonstração).
*   `usage_rate`: Uma métrica de exemplo para a taxa de uso.

Os dados são enviados para o Thinger.io através do recurso `dados_chuteira` a cada 5 segundos.

### 5. Scripts de Configuração da Plataforma (Conceitual)

Para o Thinger.io, a configuração é primariamente feita através da interface web. O arquivo `thinger_io_config_guide.md` serve como um "script" conceitual para guiar a configuração manual da plataforma, eliminando a necessidade de scripts de automação complexos para esta fase inicial.




## Códigos Fonte

Este repositório contém os seguintes arquivos essenciais para replicar a aplicação:

*   **`esp32_chuteira_simulada.ino`**: Este é o código-fonte para o dispositivo IoT (ESP32). Ele simula a leitura de sensores de pressão/força e acelerômetro, calcula estatísticas básicas (toques, passes, usage rate) e envia esses dados para a plataforma Thinger.io via Wi-Fi. Este código é projetado para ser executado em um simulador como o Wokwi ou em um ESP32 físico.

*   **`thinger_io_config_guide.md`**: Este arquivo é um guia passo a passo para configurar a plataforma Thinger.io. Ele detalha como criar uma conta, adicionar o dispositivo `chuteira_inteligente`, e configurar um dashboard para visualizar os dados enviados pelo ESP32 simulado. Ele serve como um "script de configuração" conceitual, orientando a configuração manual da plataforma.

Estes arquivos fornecem a base para entender e replicar a arquitetura inicial da chuteira inteligente, desde a coleta de dados simulada até a visualização na plataforma IoT.


