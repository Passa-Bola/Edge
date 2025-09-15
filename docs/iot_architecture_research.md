# Pesquisa para Arquitetura IoT - Projeto "Passa a Bola"

## 1. Conceitos de IoT e Aplicação no Projeto

A Internet das Coisas (IoT) refere-se à rede de objetos físicos incorporados com sensores, software e outras tecnologias com o propósito de conectar e trocar dados com outros dispositivos e sistemas pela internet. No contexto do projeto "Passa a Bola", a aplicação de IoT visa transformar uma chuteira comum em um dispositivo inteligente, capaz de coletar dados de desempenho da jogadora em tempo real.

**Valor Agregado pela IoT:**
*   **Monitoramento em Tempo Real:** Acompanhamento instantâneo de métricas de desempenho durante uma partida ou treino.
*   **Análise de Dados:** Coleta de dados brutos que podem ser processados para gerar estatísticas avançadas e insights sobre o desempenho da jogadora.
*   **Automação (futuro):** Potencial para acionar alertas ou feedback automático com base em padrões de desempenho.
*   **Otimização de Treinamento:** Treinadores e jogadoras podem usar os dados para identificar pontos fortes e fracos, ajustando estratégias de treinamento.

**Relevância da IoT:** A IoT é relevante hoje por sua capacidade de conectar o mundo físico ao digital, permitindo a coleta massiva de dados que, quando analisados, podem otimizar processos, melhorar a tomada de decisões e criar novas experiências em diversas áreas, incluindo esportes.

## 2. Sensores para Chuteira Inteligente

Para medir o número de toques, passes, força de chute e participação da jogadora, os seguintes tipos de sensores são adequados:

*   **Sensores de Pressão/Força (Load Cells/FSRs - Force Sensing Resistors):** Essenciais para detectar o contato com a bola e a intensidade do impacto. Podem ser integrados na palmilha ou em pontos estratégicos da chuteira. Artigos mencionam palmilhas com 300 sensores de pressão para análise detalhada.
*   **Sensores de Toque (Capacitivos ou Resistivos):** Podem complementar os sensores de pressão para identificar o momento exato do toque na bola.
*   **Acelerômetros e Giroscópios (IMU - Unidade de Medição Inercial):** Embora não explicitamente solicitados para esta fase inicial, são comuns em wearables esportivos para medir movimento, velocidade, aceleração e orientação, o que poderia enriquecer as estatísticas futuras (e.g., velocidade do pé no momento do chute, tipo de movimento).

Para esta fase inicial, focaremos nos sensores de pressão/força para detectar toques e passes.

## 3. Plataformas de Gerenciamento IoT

As plataformas de gerenciamento IoT fornecem a infraestrutura para conectar, gerenciar e processar dados de dispositivos IoT. As opções mencionadas são FIWARE, HiveMQ e Node-RED.

*   **FIWARE:** Uma plataforma de código aberto que oferece um conjunto de componentes (Generic Enablers) para desenvolver soluções inteligentes. É robusta e escalável, mas pode ter uma curva de aprendizado mais acentuada.
*   **HiveMQ:** Um broker MQTT de alto desempenho, focado na comunicação de mensagens entre dispositivos. É excelente para a camada de conectividade, mas não é uma plataforma "full-stack" de gerenciamento IoT por si só.
*   **Node-RED:** Uma ferramenta de programação visual baseada em fluxo para conectar dispositivos de hardware, APIs e serviços online. É muito flexível e fácil de usar para prototipagem e integração, especialmente com MQTT.

Considerando a fase inicial do projeto e a necessidade de demonstrar coleta e transmissão de dados de forma simples, o **Node-RED** combinado com um broker **MQTT (como o HiveMQ ou um broker MQTT público/local)** parece ser a opção mais prática e rápida para a demonstração.

## 4. Protocolos de Comunicação

*   **MQTT (Message Queuing Telemetry Transport):** Um protocolo de mensagens leve, publish-subscribe, ideal para dispositivos com recursos limitados e redes com largura de banda restrita. É amplamente utilizado em IoT devido à sua eficiência e confiabilidade. Permite comunicação bidirecional entre dispositivos e servidores.
*   **HTTP (Hypertext Transfer Protocol):** Protocolo fundamental da web. Embora possa ser usado em IoT, é mais "pesado" que o MQTT e geralmente menos eficiente para comunicação em tempo real e em larga escala com dispositivos restritos. É mais adequado para interações cliente-servidor tradicionais.

Para a chuteira inteligente, o **MQTT** é a escolha preferencial devido à sua eficiência e ao modelo publish-subscribe, que se encaixa bem na transmissão de dados de sensores para uma plataforma centralizada.



## 5. Arquitetura Inicial Proposta para o Projeto "Passa a Bola"

Com base na pesquisa, a arquitetura inicial da aplicação IoT para a chuteira inteligente será composta pelos seguintes elementos:

1.  **Dispositivo IoT (Chuteira Inteligente):**
    *   **Sensores:** Sensores de pressão/força (simulados para esta fase inicial) para detectar toques e passes na bola.
    *   **Microcontrolador:** Um microcontrolador (ex: ESP32, ESP8266, ou simulado) para ler os dados dos sensores, processá-los minimamente e enviá-los.
    *   **Módulo de Comunicação:** Wi-Fi (para simulação ou protótipo) para conectar-se à rede e enviar dados.

2.  **Protocolo de Comunicação:**
    *   **MQTT:** Utilizado para a comunicação entre o dispositivo IoT e a plataforma de gerenciamento, devido à sua leveza e eficiência.

3.  **Plataforma de Gerenciamento IoT:**
    *   **Node-RED:** Será usado como a plataforma principal para receber, processar e visualizar os dados. Sua interface visual facilita a prototipagem e a demonstração.
    *   **Broker MQTT:** Um broker MQTT (pode ser um serviço público, um auto-hospedado como Mosquitto, ou o próprio HiveMQ para fins de demonstração) para intermediar as mensagens entre a chuteira e o Node-RED.

4.  **Armazenamento e Análise (Básico para esta fase):**
    *   **Node-RED:** Pode ser configurado para armazenar dados em um arquivo local ou em um banco de dados simples (ex: SQLite, ou mesmo um fluxo para visualização direta) e realizar análises básicas (contagem de toques/passes).

**Fluxo de Dados:**
1.  A chuteira inteligente detecta um toque/passe através dos sensores de pressão/força.
2.  O microcontrolador (simulado) lê os dados do sensor.
3.  Os dados são formatados e enviados via MQTT para o Broker MQTT.
4.  O Node-RED se inscreve nos tópicos MQTT relevantes, recebe os dados.
5.  No Node-RED, os dados são processados (ex: incrementa contador de toques/passes) e visualizados em um dashboard simples.

Esta arquitetura permite demonstrar os conceitos fundamentais de coleta e transmissão de dados IoT de forma eficaz para a Sprint 3.




## Descrição Detalhada da Arquitetura Proposta

### 1. Dispositivo IoT (Chuteira Inteligente)

*   **Sensores de Pressão/Força:** Estes sensores serão integrados em pontos estratégicos da chuteira, como na área de contato com a bola (peito do pé, parte interna/externa) e na palmilha. Eles serão responsáveis por detectar o impacto da bola e a pressão exercida pelo pé, permitindo a identificação de toques e passes. Para a implementação inicial, podemos simular a leitura desses sensores, gerando dados aleatórios ou baseados em eventos.
*   **Microcontrolador com Módulo Wi-Fi:** Um microcontrolador de baixo custo e baixo consumo de energia, como um ESP32 ou ESP8266, será o cérebro da chuteira. Ele será responsável por:
    *   Ler os dados dos sensores de pressão/força.
    *   Processar esses dados para identificar eventos como "toque na bola" ou "passe".
    *   Conectar-se a uma rede Wi-Fi.
    *   Publicar os dados processados em um broker MQTT.

### 2. Protocolo de Comunicação: MQTT

O MQTT (Message Queuing Telemetry Transport) será o protocolo de comunicação principal entre a chuteira inteligente e a plataforma de gerenciamento. Suas características de leveza, baixo consumo de largura de banda e modelo publish/subscribe o tornam ideal para dispositivos IoT. A chuteira atuará como um cliente MQTT, publicando mensagens em tópicos específicos (ex: `passabola/chuteira/<ID_jogadora>/dados`) sempre que um evento (toque, passe) for detectado.

### 3. Broker MQTT

O Broker MQTT é o intermediário central na comunicação MQTT. Ele recebe as mensagens publicadas pelos dispositivos (chuteiras) e as encaminha para todos os clientes que estão inscritos nos tópicos correspondentes. Para a demonstração, pode-se utilizar:

*   **Broker MQTT público:** Para testes rápidos e sem necessidade de infraestrutura local.
*   **Broker MQTT auto-hospedado (ex: Mosquitto):** Para um ambiente mais controlado e seguro.
*   **HiveMQ:** Uma solução de broker MQTT de nível empresarial, que pode ser utilizada para fins de demonstração de suas capacidades de escalabilidade e confiabilidade.

### 4. Plataforma de Gerenciamento IoT: Node-RED

O Node-RED será a ferramenta principal para a plataforma de gerenciamento IoT nesta fase. Ele oferece um ambiente de programação visual baseado em fluxos que facilita a:

*   **Inscrição em Tópicos MQTT:** O Node-RED se conectará ao Broker MQTT e se inscreverá nos tópicos onde a chuteira publica seus dados.
*   **Processamento de Dados:** Os dados recebidos serão processados. Por exemplo, um fluxo pode contar o número de mensagens recebidas (representando toques/passes), calcular a frequência ou até mesmo filtrar dados.
*   **Dashboard de Visualização:** O Node-RED possui um módulo de dashboard que permite criar interfaces gráficas simples para visualizar os dados em tempo real (ex: contadores de toques, gráficos de frequência de passes).

### Fluxo de Dados Detalhado

1.  **Detecção de Evento:** A jogadora toca na bola. Os sensores de pressão/força na chuteira detectam o evento.
2.  **Leitura e Processamento no Microcontrolador:** O microcontrolador lê os valores dos sensores. Um algoritmo simples determina se o evento é um "toque" ou um "passe" com base na intensidade e duração da pressão.
3.  **Publicação MQTT:** O microcontrolador formata os dados (ex: `{ "tipo": "toque", "timestamp": "..." }`) e os publica em um tópico MQTT (ex: `passabola/chuteira/ID_JOGADORA/eventos`).
4.  **Recebimento pelo Broker MQTT:** O Broker MQTT recebe a mensagem e a armazena temporariamente.
5.  **Inscrição e Recebimento pelo Node-RED:** O Node-RED, inscrito no tópico `passabola/chuteira/+/eventos`, recebe a mensagem.
6.  **Processamento no Node-RED:** Um fluxo no Node-RED extrai o tipo de evento e atualiza contadores ou outras métricas.
7.  **Visualização:** Os dados processados são exibidos em um dashboard do Node-RED, fornecendo feedback em tempo real sobre o desempenho da jogadora.

Esta arquitetura modular e baseada em padrões abertos permite uma fácil expansão futura, como a integração com bancos de dados mais robustos, serviços de nuvem e algoritmos de análise mais complexos.

